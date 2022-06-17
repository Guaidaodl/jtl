#include "jtl.h"

#include "pch.h"

int JtlApplication(int argc, char *argv[]) {
  Options options;
  int parse_result = ParseArguments(argc, argv, options);
  if (parse_result != 0) {
    std::cout << "Parse Failed: " << parse_result;
    return parse_result;
  }

  return RunTask(options);
}

int ParseArguments(int argc, char *argv[], Options &options) {
  CLI::App app{"jtl"};

  std::string task{"default"};
  app.add_option("-t,--task,task", options.task, "task name");

  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }

  return 0;
}

int RunTask(Options &options) {
  if (options.task.empty()) {
    return 101;
  }

  BuildTask task;
  auto load_result = loadTask(options.task, task);
  if (load_result != 0) {
    return load_result;
  }

  return RunBuildTask(task);
}

int loadTask(std::string &taskName, BuildTask &task) {
  auto jtl_file = FindJtlFile();
  if (jtl_file.empty()) {
    std::cerr << "can not find .jtl file\n";
    return 201;
  }

  try {
    const auto config = toml::parse(jtl_file);
    const auto &taskConfig = toml::find(config, taskName);
    if (!taskConfig.is_table()) {
      std::cerr << "Task config must be a table\n";
      return 202;
    }

    const auto taskTable = taskConfig.as_table();
    if (taskTable.count("url") < 1) {
      std::cerr << "Task config must has a url\n";
      return 203;
    }
    task.url = toml::find<std::string>(taskConfig, "url");

    return 0;
  } catch (toml::syntax_error &e) {
    std::cerr << "Parse failed!! File Path: " << jtl_file << std::endl
              << e.what();
    return 298;
  } catch (std::runtime_error &e) {
    std::cerr << "Parse failed!! File Path: " << jtl_file << std::endl
              << "runtime error: " << e.what() << std::endl;
    return 299;
  }
}

/// 获取 .jtl 的路径.
std::string FindJtlFile() {
  // !!todo 扩展复杂的实现
  if (std::filesystem::exists(".jtl")) {
    return ".jtl";
  } else {
    return "";
  }
}

int RunBuildTask(const BuildTask &task) { 
  std::cout << "Run Task:\n"
            << "url = " << task.url << std::endl;

  return 0;
}

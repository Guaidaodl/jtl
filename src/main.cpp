#include <iostream>

#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"

class Options {
 public:
  std::string task{"default"};
};

int main(int argc, char *argv[]) {
  CLI::App app{"jtl"};

  bool debug{false};
  app.add_flag("-d,--debug", debug, "debug mode");

  std::string task{"default"};
  app.add_option("-t,--task,task", task, "task name");

  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }

  std::cout << debug << std::endl;
  std::cout << "task name:" << task << std::endl;
  return 0;
}

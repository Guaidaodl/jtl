#ifndef JTL_JTL_H_
#define JTL_JTL_H_

#include "pch.h"
#include <string>

int JtlApplication(int argc, char *argv[]);

struct Options {
 public:
  /// 需要运行的任务名
  std::string task{"default"};
};

/// 解析命令行参数
int ParseArguments(int argc, char *argv[], Options &options);

/// 运行任务
int RunTask(Options &options);

struct BuildTask {
 public:
  std::string url;
};

/// 加载指定的任务数据. 
int loadTask(std::string &taskName, BuildTask &task);

/// 获取 .jtl 的地址. 未找到则返回 ""
std::string FindJtlFile();


#endif // JTL_JTL_H_

# Jenkins Task launcher(jtl)

通过 .jtl.toml 来配置服务器和任务参数. 并提供内置的变量. 方便构建.

变量:
- `jtl_git_branch` 当前所在 git 相关的分支名

配置的格式如下:
```toml
[dev] # 任务名
url="https://xxx.jenkdins.com/task"
branch="$(jtl_git_branch)"
other_custom_task_param="xxxx"
```



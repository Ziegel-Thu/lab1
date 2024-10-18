# 五子棋游戏

这是一个使用Qt框架开发的五子棋游戏。

## 编译和运行说明

### 前提条件

- Qt 6.0或更高版本
- C++11兼容的编译器

### Qt入门

可以从[官网](https://www.qt.io/download-qt-installer-oss)下载qt，请参考[安装教程](https://meeting.tencent.com/crm/NXBPkX8K4c)。

如果安装过程中出现网络错误，可以尝试重新下载或更换上网方式。

除了官方下载器，linux & MacOS的自带包管理器也可以安装qt开发环境，该方法需要有一定的命令行基础。

#### Qt的对象生命周期

Qt中的对象生命周期由`QObject`的`parent`属性决定。当一个对象的`parent`被设置为另一个对象时，当父对象被析构时，它的子对象也会被析构。
这种情况下，我们称父对象拥有子对象的所有权（take ownership）。
而大部分Qt对象都是`QObject`的子类，也就是说，所有对象构成了一颗树，我们`delete`其中一个对象时，整颗子树也会被`delete`。

在本项目中，`addWidget`、`addItem`等方法都会掌管对象。具体哪些操作会获得所有权，以及哪些操作会释放所有权、哪些操作会删除对象，需要查阅具体函数的文档。
一般来说，在父对象被删除之前手动删除子对象是最安全的选择。

#### Qt参考文档

* [Qt官方文档](https://doc.qt.io/qt-6/index.html)
* [Qt组件大全](https://doc.qt.io/qt-6/gallery.html)
* [Qt的对象树](https://doc.qt.io/qt-6/objecttrees.html)

### Git使用教程

Git的教程比较多，我们在这里推荐几个：

- [cpp.studio](https://cpp.studio/toolchain/git/)
- 其他教程：
    * [Git工作流和核心原理](https://www.bilibili.com/video/BV1r3411F7kn)：Bilibili视频，约20分钟
    * [Git教程 - 廖雪峰](https://www.liaoxuefeng.com/wiki/896043488029600)：网页，较详细
    * [Git 原理入门（阮一峰）](http://www.ruanyifeng.com/blog/2018/10/git-internals.html)：网页，简要入门教程
- 上传到[清华`git`](https://git.tsinghua.edu.cn/)时登录验证失败怎么办？
    * 参考上述视频，在[账户设置](https://git.tsinghua.edu.cn/-/profile/personal_access_tokens)中添加一个Personal Access Token；
    * 或者在[账户设置](https://git.tsinghua.edu.cn/-/profile/keys)中添加一个SSH公钥（推荐）
- 如何更改本网站语言：右上角头像-Preferences-底部Localization-Language-选择“Chinese”，然后点击页面底部的“Save changes”，可以切换到中文版。

初始仓库里除了main分支，还有一个被保护的down分支。如果之后实验的基础代码有更新，我们会把新的版本push到down分支上。

<details>
<summary>
本项目可能会用到的`git`操作速查表
</summary>

#### 基础操作

以下所有命令中`<word>`需要替换为你自己的内容。

设置用户名和邮箱：
```bash
git config --global user.email "<your email>"
git config --global user.name "<your name>"
# 例：
git config --global user.email "email@example.com"
git config --global user.name "San Zhang"
```

将代码从网上下载至本地：
```bash
git clone <repo-url>
# 例：
git clone https://git.tsinghua.edu.cn/adv-prog/2022/leveldb-sk/
```

进入仓库目录，查看当前仓库状态：
```bash
git status
```

添加文件到暂存区：
```bash
git add <files>
# 例：添加当前目录下的所有文件。“.”表示当前目录。
git add .
```

提交暂存区的文件至版本库：
```bash
git commit -m "<your message>"
# 例：
git commit -m "Create a new file"
```

#### 同步操作

添加一个远程地址：
```bash
git remote add <remote_name> <remote_url>
# 例：
git remote add upstream https://git.tsinghua.edu.cn/adv-prog/2022/leveldb-sk/
```

推送版本库的文件至远程仓库（如清华`git`）：
```bash
git push <remote> <branch>
# 例：
git push origin main
```

从远程库中下载更新：
```bash
git fetch origin main
git merge origin/main # 合并origin远程的main分支到本地的当前分支
# 或将两步合为一步：
git pull
```

#### 分支操作

创建一个新分支：
```bash
git branch <branch_name>
# 例：
git branch patch_1
```

切换到某分支：
```bash
git checkout <branch_name>
# 例：
git checkout patch_1
# 切换回来main分支：
git checkout main
```

</details>

### 编译运行

1. 完成cursor/vscode的安装，以及推荐扩展的安装，并生成本机的公钥后添加到清华git上，使用cursor/vscode将代码仓库克隆到本地。
   - 推荐扩展：
     - ms-vscode.cpptools-extension-pack
     - theqtcompany.qt-cpp-pack
     - Gruntfuggly.todo-tree
     - eamodio.gitlens
   - Clone with ssh: `git@git.tsinghua.edu.cn:adv-prog/2024/lab1.git`

2. 打开终端,进入项目根目录。

3. 创建一个build文件夹并进入：
   1. 打开命令面板（Windows/Linux快捷键：`Ctrl+Shift+P` ，MacOS快捷键：`Cmd+Shift+P`）；
   2. 输入 `tasks: run task` 并运行此命令；
   3. 选择 `mkdir` 任务并运行。

4. 运行qmake生成Makefile:
   1. 打开命令面板（Windows/Linux快捷键：`Ctrl+Shift+P` ，MacOS快捷键：`Cmd+Shift+P`）；
   2. 输入 `tasks: run task` 并运行此命令；
   3. 选择 `qmake-release` 任务并运行。

5. 编译项目:
   1. 打开命令面板（Windows/Linux快捷键：`Ctrl+Shift+P` ，MacOS快捷键：`Cmd+Shift+P`）；
   2. 输入 `tasks: run task` 并运行此命令；
   3. 选择 `make-release` 任务并运行。

6. 运行项目:
   1. 打开命令面板（Windows/Linux快捷键：`Ctrl+Shift+P` ，MacOS快捷键：`Cmd+Shift+P`）；
   2. 输入 `tasks: run task` 并运行此命令；
   3. 选择 `run-release` 任务并运行。

#### 注意事项

- 步骤3只需要运行一次，也就是只需要创建一次build文件夹。
- 步骤4-6可以直接通过运行步骤6来实现，也就是直接运行 `run-release` 任务。
  - 因为配置了 `run-release` 依赖于 `make-release` ， `make-release` 依赖于 `qmake-release` 
  - 所以 `run-release` 会自动执行 `qmake-release` 和 `make-release` 任务
- 如出现编译运行的问题且长时间未解决，可尝试将build文件夹删除后重新执行上述步骤3-6。

## lab1 内容

- 学习并熟悉 Qt 框架
- 利用栈实现悔棋功能

### 修改范围

- `OperationWidget.cpp`: TODO 所在行
- `MainWindow.cpp`: TODO 所在行
- `Board.h`: 全部
- `Board.cpp`: 全部（不仅限于 TODO 部分）

### 关于CI

持续集成（Continuous Integration）系统会在每次代码推送后自动执行，检查代码是否能够成功编译。

您可以在GitLab界面左侧的“构建”部分查看编译结果。

CI系统还会生成一个压缩包，包含编译后的Windows可执行程序。这个压缩包可以在页面左侧的菜单栏中，通过“构建”-“产物”选项被浏览。

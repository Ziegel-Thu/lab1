# 五子棋游戏

这是一个使用Qt框架开发的五子棋游戏。

## 编译和运行说明

### 前提条件

- Qt 6.0或更高版本
- C++11兼容的编译器

### Qt入门

可以从[官网](https://www.qt.io/download-qt-installer-oss)下载qt与集成开发环境。

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



### 编译运行

1. 克隆或下载此项目到本地。

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

CI(continuous integration)会在每一次push之后自动检查是否编译通过，结果可以在GitLab左侧的CI/CD中找到。
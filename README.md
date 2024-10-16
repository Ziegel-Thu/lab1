# 五子棋游戏

这是一个使用Qt框架开发的五子棋游戏。

## 编译和运行说明

### 前提条件

- Qt 6.0或更高版本
- C++17兼容的编译器

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



### 编译步骤

1. 克隆或下载此项目到本地。

2. 打开终端,进入项目根目录。

3. 创建一个build文件夹并进入:

   ```
   mkdir build
   cd build
   ```

4. 运行qmake生成Makefile:

   ```
   qmake ../lab1.pro
   ```

5. 编译项目:

   ```
   make
   ```

6. 如出现编译问题且长时间未解决，可尝试将build文件夹删除后重新执行上述步骤。

### 运行游戏

编译完成后,在build目录下会生成可执行文件。运行方式如下:

- 在macOS上:
  ```
  open lab1.app
  ```

- 在Linux或其他Unix系统上:
  ```
  ./lab1
  ```

- 在Windows上:
  ```
  lab1.exe
  ```

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

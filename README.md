# 五子棋游戏

这是一个使用Qt框架开发的五子棋游戏。

## 编译和运行说明

### 前提条件

- Qt 6.0或更高版本
- C++17兼容的编译器

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
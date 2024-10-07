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
   qmake ../Gomoku.pro
   ```

5. 编译项目:

   ```
   make
   ```

### 运行游戏

编译完成后,在build目录下会生成可执行文件。运行方式如下:

- 在macOS上:
  ```
  open Gomoku.app
  ```

- 在Linux或其他Unix系统上:
  ```
  ./Gomoku
  ```

- 在Windows上:
  ```
  Gomoku.exe
  ```
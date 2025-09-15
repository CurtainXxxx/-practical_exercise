# 商品信息管理系统（C 语言 | 模块化 | CMake | CLion）

一个用 **C 语言** 实现的商品信息管理系统，采用模块化设计（`include/` + `src/`），支持商品的 **增加 / 删除 / 修改 / 查询 / 列表显示**，并通过二进制文件进行持久化。项目提供基于菜单的命令行交互以及使用 Unity 框架的单元测试示例。适合作为 C 语言练手项目、课程作业或小型练习项目。

---

## 目录结构（简要）

commodity_manager/
├─ CMakeLists.txt
├─ data/
│ └─ comm_file.dat # 默认数据文件（相对路径常量 DATA_FILE）
├─ include/
│ ├─ commodity.h # 常量与商品数据结构声明
│ ├─ comm_operation.h # 商品增删改查接口声明
│ ├─ file_io.h # 文件读写相关接口声明
│ └─ menu.h # 菜单与用户交互声明
├─ src/
│ ├─ main.c
│ ├─ comm_operation.c
│ ├─ file_io.c
│ └─ menu.c
├─ test/
│ └─ test_commodity.c # 使用 Unity 的单元测试示例
└─ README.md


---

## 功能特性

- 添加商品（通过交互式菜单）
- 删除商品（按编号/索引/条件）
- 修改商品（更新指定商品信息）
- 查询商品（按关键字或条件）
- 显示所有商品
- 数据持久化到磁盘文件（`data/comm_file.dat`）
- 使用 Unity 框架的单元测试样例
- 基于 CMake 构建，兼容 CLion、Linux、Windows（MinGW/MSYS）等

---

## 依赖 / 环境

- C 语言编译器（GCC / Clang / MSVC）
- CMake (>= 3.x)
- （可选）CLion，用于 IDE 开发与调试
- （可选）Unity 单元测试框架（项目中已包含测试代码）

---

## 快速构建与运行（命令行）

假设你在 `commodity_manager/` 目录下：

```bash
# 1. 创建构建目录
mkdir -p build
cd build

# 2. 运行 cmake（生成 Makefile / Ninja 等）
cmake ..

# 3. 编译
make

# 4. 运行可执行文件（项目中可执行文件名可能为 test_commodity 或其他，请以 CMake 配置为准）
# Linux / macOS:
./test_commodity

# Windows (MinGW/MSYS)：
./test_commodity.exe

注意：项目中 DATA_FILE 常量（在 commodity.h）指定了默认数据文件路径，例如 ../data/comm_file.dat，请保证运行时当前工作目录正确或调整该路径。

在 CLion 中打开（IDE）

启动 CLion，选择 Open 并定位到项目根目录（包含 CMakeLists.txt 的目录）。

CLion 会自动解析 CMake，并在左侧显示 targets（可执行文件）。

选择 test_commodity（或对应的 target）进行 Run / Debug。

可在 Run 窗口中进行交互式输入操作。

使用示例（交互式菜单示例）

程序启动后，会显示一个文本菜单，典型交互（示例）：
================ 商品管理系统 ================
0. 退出
1. 添加商品
2. 查询商品
3. 删除商品
4. 修改商品
5. 商品排序
6. 显示所有商品
7. 统计总数
请选择操作: 1
请输入商品名称: 手机
请输入商品价格: 1999.99
请输入商品数量: 10
添加成功！
按任意键继续...

查询 / 删除 / 修改 的交互类似，按提示输入对应的编号或关键字即可。添加或修改后，程序会把数据写回到 comm_file.dat（或 DATA_FILE 指定的路径）。


数据结构与配置（快速说明）

NAME_LEN：商品名称长度上限（头文件中定义）

MAX_COMMODITIES：内存中可容纳的最大商品数量

DATA_FILE：默认数据文件路径（相对路径），例如 ../data/comm_file.dat

商品结构体（在 commodity.h 中定义）保存每个商品的主要属性（名称、编号、价格、数量等）


单元测试（Unity 框架）

项目包含 test/test_commodity.c，使用 Unity 进行单元测试示例。

运行方式（在构建后）：

# 假设测试目标已添加到 CMake 并生成可执行文件 test_commodity
./test_commodity


如果想将单元测试拆成独立 target，或集成到 CI（如 GitHub Actions），可以在 CMakeLists.txt 中添加对应的 test target 或使用 ctest。


已知问题 / 注意事项

程序对输入可能没有做非常严格的容错（取决于源码实现），在输入字符串/数字时请按提示输入合法值。

数据文件路径为相对路径，运行时的当前工作目录会影响文件读写位置。推荐在项目根目录运行（或调整 DATA_FILE 为绝对路径）。

如果遇到中文编码显示问题，请确认终端/IDE 使用 UTF-8 编码。





贡献 & 许可证

欢迎提交 Issue、PR 或联系我（在仓库中留下你的联系方式）。
默认许可证示例（可根据需要改为 MIT / GPL 等）：

MIT License

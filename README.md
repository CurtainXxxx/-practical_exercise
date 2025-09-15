# 商品信息管理系统（C 语言 | 模块化 | CMake | CLion）

> 一个轻量级的商品信息管理系统，用 C 语言实现，采用模块化设计（`include/` + `src/`），支持基本的增删改查（CRUD）、持久化存储与单元测试。适合用于课程作业、练习项目或作为 C 语言学习示例。

---

## 目录结构（项目根目录）

```
commodity_manager/
├─ CMakeLists.txt
├─ data/
│  └─ comm_file.dat         # 默认二进制数据文件（运行后会创建或更新）
├─ include/                 # 头文件：常量、结构体、接口声明
│  ├─ commodity.h
│  ├─ comm_operation.h
│  ├─ file_io.h
│  └─ menu.h
├─ src/                     # 源文件：实现逻辑
│  ├─ main.c
│  ├─ comm_operation.c
│  ├─ file_io.c
│  └─ menu.c
├─ test/
│  └─ test_commodity.c      # 基于 Unity 的单元测试示例
└─ README.md
```

---

## 项目亮点

- **模块化设计**：数据结构、业务操作、文件 I/O、菜单交互分离，便于维护与扩展。  
- **持久化存储**：使用二进制文件存储商品信息（默认路径由 `DATA_FILE` 宏定义）。  
- **单元测试示例**：集成 Unity 测试示例，便于学习如何编写 C 的单元测试。  
- **跨平台构建**：基于 CMake，支持在 CLion、Linux、Windows（MinGW/MSYS）等编译运行环境。

---

## 功能一览

- 添加商品（Add）  
- 删除商品（Delete）  
- 修改商品（Modify）  
- 查询商品（Search）  
- 列表显示所有商品（Display All）  
- 商品排序（按名称/价格/数量，视实现而定）  
- 统计商品总数（Total Count）  
- 数据读写到本地文件（持久化）

> 注意：具体交互菜单与功能细节请参考 `menu.c`、`comm_operation.c`、`file_io.c` 的实现。

---

## 快速开始（命令行）

在 `commodity_manager` 根目录下执行：

```bash
# 1. 创建构建目录并进入
mkdir -p build
cd build

# 2. 运行 cmake（或在 CLion 打开项目）
cmake ..

# 3. 编译
cmake --build .

# 4. 运行可执行文件（target 名称按 CMakeLists.txt 配置）
# Linux / macOS:
./test_commodity

# Windows（MinGW/MSYS）:
./test_commodity.exe
```

如果在运行过程中提示找不到数据文件，确保当前工作目录与 `DATA_FILE` 中配置的相对路径一致，或在 `commodity.h` 中修改 `DATA_FILE` 为绝对路径。

---

## 在 CLion 中运行

1. 打开 CLion，选择 `Open` 并定位到包含 `CMakeLists.txt` 的项目根目录。  
2. 等待 CMake 配置完成，左侧会出现 targets（可执行文件）。  
3. 选择 `test_commodity`（或项目中定义的其他 target）点击运行/调试。  
4. 在 Run 窗口中按提示进行交互输入。

---

## 交互示例

程序启动后会显示文本菜单，示例（假设菜单与实现一致）：

```
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
```

---

## 常量与说明（示例）

- `NAME_LEN`：商品名称最大长度（在头文件中定义）。  
- `MAX_COMMODITIES`：程序内存中允许的最大商品数量。  
- `DATA_FILE`：默认数据文件路径（例如 `../data/comm_file.dat`）。

> 如果你希望我把头文件中商品结构体（`struct Commodity`）的字段逐项列出来并写上说明，我可以把实际字段名和类型直接插入此节（现在 README 使用概述式说明以确保通用性）。

---

## 单元测试（Unity）

项目提供 `test/test_commodity.c`，使用 Unity 编写测试例。构建后直接运行测试可输出测试结果：

```bash
# 假设测试 target 已生成可执行文件 test_commodity
./test_commodity
```

若要将测试合并到 CMake 的 test target 中，可以在 `CMakeLists.txt` 中添加相应 target 并启用 `enable_testing()` / `add_test()`，或使用 `ctest` 运行。

---

## 推荐改进（可选）

1. **导入/导出**：支持 CSV / JSON 导入导出，便于在外部查看与备份。  
2. **错误处理**：增强输入检查，避免非法值导致数据错乱或崩溃。  
3. **索引/查找优化**：对大量数据时考虑建立索引或使用二分/哈希查找。  
4. **数据库支持**：使用 SQLite 替代二进制文件以支持更复杂查询。  
5. **CI 集成**：添加 GitHub Actions，在每次 push 时构建并运行测试。  
6. **更友好的 UI**：使用 ncurses 或基于 web 的界面。

---

## .gitignore 建议

```
# CMake / CLion / build artifacts
cmake-build-debug/
build/
CMakeFiles/
CMakeCache.txt
*.o
*.obj
*.exe
*.log
*.ilk
*.pdb
*.DS_Store
data/comm_file.dat
```

> 建议把生成的二进制数据文件 `data/comm_file.dat` 加入 `.gitignore`，避免提交运行时数据。

---

## 许可证（示例）

```
MIT License
```

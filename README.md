# Maze Game - 终端迷宫冒险游戏
一个基于 C++ 模块化开发的终端迷宫游戏，支持多地图选择、角色移动、陷阱机制与生命值系统。项目提供 **Docker 一键运行** 和 **本地编译** 两种方式，无需复杂环境配置，开箱即用。


## 📋 项目介绍
- **核心玩法**：控制角色在迷宫中寻找出口，避开陷阱，保持生命值直至通关。
- **技术栈**：C++（面向对象设计）、CMake（编译管理）、Docker（环境封装）。
- **特点**：
  - 模块化架构：将地图、角色、游戏逻辑拆分封装，便于扩展。
  - 跨环境兼容：通过 Docker 实现“一次构建，到处运行”。
  - 轻量无依赖：本地编译仅需基础 C++ 工具链，无需额外库。


## 📂 项目结构
```
maze_game/
├── include/        # 头文件目录（类声明）
│   ├── Map.h       # 地图类：生成迷宫、管理陷阱与出口
│   ├── Player.h    # 角色类：控制移动、管理生命值
│   ├── Game.h      # 游戏类：核心逻辑（菜单、回合循环、通关判定）
│   └── Utils.h     # 工具类：终端输出美化、输入处理
├── src/            # 源文件目录（类实现）
│   ├── Map.cpp
│   ├── Player.cpp
│   ├── Game.cpp
│   ├── Utils.cpp
│   └── main.cpp    # 程序入口
├── CMakeLists.txt  # CMake 编译配置文件
├── Dockerfile      # Docker 构建配置文件
├── .dockerignore   # Docker 构建忽略文件（排除无用内容）
└── README.md       # 项目说明文档（本文档）
```


## 🚀 快速开始
### Docker 一键运行（推荐，无需配置环境）
#### 前提条件
本地已安装 Docker

#### 步骤
1. **克隆仓库**
   ```bash
   git clone https://github.com/lycbee/maze-game.git
   cd maze-game
   ```

2. **构建 Docker 镜像**
   ```bash
   docker build -t maze-game:v1 .
   ```

3. **启动游戏**
   ```bash
   docker run -it --rm maze-game:v1
   ```
   - `-it`：启用终端交互（必须添加，否则无法用键盘控制角色）。
   - `--rm`：游戏退出后自动删除容器，不残留垃圾文件。

## 🎮 游戏操作指南
| 按键 | 功能                 |
|------|----------------------|
| `w`  | 角色向上移动         |
| `s`  | 角色向下移动         |
| `a`  | 角色向左移动         |
| `d`  | 角色向右移动         |
| `q`  | 退出游戏             |

### 游戏规则
1. 启动后选择地图（1 或 2），不同地图陷阱分布与出口位置不同。
2. 角色初始生命值为 3，踩中陷阱会减少 1 点生命值，生命值为 0 则游戏失败。
3. 找到迷宫中的“出口”（通常标记为 `E`）即通关。


## 🔧 开发与扩展
若需二次开发（如添加新地图、增加道具系统），可参考以下方向：
1. **添加新地图**：修改 `Map.h`/`Map.cpp` 中的 `generateMap()` 方法，自定义迷宫尺寸、陷阱数量。
2. **增加道具**：在 `Player.h` 中添加道具属性，在 `Game.cpp` 中实现道具拾取与效果逻辑。
3. **优化视觉**：修改 `Utils.h` 中的终端输出函数，调整颜色、迷宫符号样式。

开发完成后，重新编译（本地）或重建镜像（Docker）即可生效。


## <a id="appendix"></a> 📌 附录：常见问题解决
### 1. Docker 拉取镜像超时
问题：构建镜像时提示 `context deadline exceeded` 或 `403 Forbidden`。  
解决：配置国内 Docker 镜像加速器：
```bash
# 创建 Docker 配置目录
sudo mkdir -p /etc/docker
# 写入网易镜像源（或替换为其他源，如腾讯云：https://mirror.ccs.tencentyun.com）
sudo tee /etc/docker/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://hub-mirror.c.163.com"]
}
EOF
# 重启 Docker 生效
sudo systemctl daemon-reload && sudo systemctl restart docker
```

### 2. 本地编译提示“头文件找不到”
问题：`fatal error: Map.h: No such file or directory`。  
解决：确保 `CMakeLists.txt` 中已正确包含 `include` 目录，无需手动修改（项目默认配置已包含）。

### 3. 游戏键盘控制无响应
问题：按下 `wasd` 无反应。  
解决：
- Docker 方式：确保运行命令添加了 `-it` 参数。
- 本地方式：检查终端是否支持标准输入（如 VS Code 终端需切换为“集成终端”）。


## 📄 许可证
本项目为开源学习项目，可自由用于个人学习、非商业用途。如需商业使用，请联系作者获取授权。


## ✨ 致谢
感谢您使用本项目！若有 Bug 反馈或功能建议，欢迎在 GitHub 仓库提交 Issues 或 Pull Requests。

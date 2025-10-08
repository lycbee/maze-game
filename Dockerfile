# 基础镜像：使用 Ubuntu 22.04（稳定版）
FROM ubuntu:22.04

# 设置非交互模式（避免 apt 安装时弹出配置界面）
ENV DEBIAN_FRONTEND=noninteractive

# 安装编译依赖（g++、cmake、make 等）
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*  # 清理缓存，减小镜像体积

# 设置工作目录（容器内的项目根目录）
WORKDIR /app

# 复制项目文件到容器（.dockerignore 会排除不需要的文件）
COPY . .

# 创建 build 目录并编译项目
# 注意：使用 \ 换行时，行尾不能有注释
RUN mkdir -p build && cd build \
    && cmake .. \
    && make

# 容器启动时自动运行游戏（必须使用 bash 确保终端交互正常）
CMD ["/bin/bash", "-c", "/app/build/maze_game"]

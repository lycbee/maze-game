cmake_minimum_required(VERSION 3.10)
project(MazeGame)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 收集源文件
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(maze_game ${SOURCES})

# 链接必要的库
target_link_libraries(maze_game pthread)

# 安装目标
install(TARGETS maze_game DESTINATION bin)

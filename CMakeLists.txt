cmake_minimum_required(VERSION 3.15)

project(Bacterium)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(matplotplusplus/)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# 生成可执行文件
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE matplot)

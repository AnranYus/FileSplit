cmake_minimum_required(VERSION 3.28)
project(FileSplit)

# 设置 C++ 标准为 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 强制使用静态运行时库（仅适用于 MSVC 编译器）
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# 禁用共享库，强制静态链接
set(BUILD_SHARED_LIBS OFF)

# 静态链接选项（适用于 GCC/Clang）
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

# 添加可执行文件
add_executable(fileSplit
    main.cpp
    File.cpp
    File.h
)

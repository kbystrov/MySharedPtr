cmake_minimum_required(VERSION 3.12)
project(MySharedPtr)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra \
-I${PROJECT_SOURCE_DIR}/MySharedPtr \
-I${PROJECT_SOURCE_DIR}/MySharedPtr/ProxyPtr \
-I${PROJECT_SOURCE_DIR}/Common ")

add_executable(mySharedPtr main.cpp MySharedPtr/MySharedPtr.cpp MySharedPtr/MySharedPtr.h MySharedPtr/ProxyPtr/ProxyPtr.cpp MySharedPtr/ProxyPtr/ProxyPtr.h Common/err_codes.h Common/proj_macros.h)
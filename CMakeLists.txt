cmake_minimum_required(VERSION 3.23)
project(cfetch C)

set(CMAKE_C_STANDARD 99)
include_directories(/usr/local/cellar/cjson/1.7.15/include)
include_directories(/usr/local/cellar/curl/7.86.0/include)

add_executable(cfetch main.c)
target_link_libraries(cfetch /Users/Fabboy/CLionProject/frogengine/cfetch/cmake-build-debug/libcfetch.dylib)
#add_library(cfetch SHARED fetch/include/GlobalLibs.h fetch/include/Fetch.h fetch/src/Fetch.c)

target_link_libraries(cfetch /usr/local/cellar/cjson/1.7.15/lib/libcjson.dylib)
target_link_libraries(cfetch /usr/local/cellar/curl/7.86.0/lib/libcurl.dylib)
 cmake_minimum_required(VERSION 3.27)
 project(ajro)

 set(CMAKE_CXX_STANDARD 23)

 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")


 add_executable(ajro src/main.cpp
         src/Lexer.cpp
         src/Lexer.h)

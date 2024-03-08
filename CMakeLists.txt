 cmake_minimum_required(VERSION 3.22)
 project(ajro)

 set(CMAKE_CXX_STANDARD 23)

 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")


 add_executable(ajro src/main.cpp
         src/Lexer.cpp
         src/Lexer.h
         src/TokenEnum.h
         src/TokenStruct.h
         src/Parser.cpp
         src/Parser.h
         src/Compiler.cpp
         src/Compiler.h
         src/Refiner.cpp
         src/Refiner.h)

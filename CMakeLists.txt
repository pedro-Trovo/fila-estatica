cmake_minimum_required(VERSION 3.10)
project(fila_estatica C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(fila_estatica
        src/main.c
        src/fila.c
)

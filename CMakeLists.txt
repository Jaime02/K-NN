cmake_minimum_required(VERSION 3.17)
project(YgK_NN C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(K_NN knn.c list.c list.h maxMonticulo.c maxMonticulo.h)

add_executable(WILL wilson.c list.c list.h maxMonticulo.c maxMonticulo.h)

add_executable(CONV convertir.c)

add_executable(EXMM ejecutarMinMonticulo.c maxMonticulo.c maxMonticulo.h)


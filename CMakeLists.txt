cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wno-unused-result -Wno-format-overflow")

project(YgK_NN C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(K_NN knn.c list.c list.h maxMonticulo.c maxMonticulo.h)

add_executable(WILL wilson.c list.c list.h maxMonticulo.c maxMonticulo.h)

add_executable(CONV convertir.c)

add_executable(EXMM ejecutarMinMonticulo.c maxMonticulo.c maxMonticulo.h)

target_link_libraries(WILL m)
target_link_libraries(K_NN m)

add_library(LinListLib STATIC LinkedList.cpp LinkedList.h)

add_executable(linkedList main.cpp)

target_link_libraries(linkedList LinListLib)

add_library(LinListLib STATIC LinkedList.cpp LinkedList.h LinkedListIterator.h LinkedListIterator.cpp)

add_executable(linkedList main.cpp)

target_link_libraries(linkedList LinListLib)

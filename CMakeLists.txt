cmake_minimum_required (VERSION 3.0)

project (Complex VERSION 1.0.0 LANGUAGES C CXX)

add_library (complex_number STATIC complex_number.cpp)

add_executable(compl main.cpp)

add_subdirectory (test)

target_link_libraries (compl complex_number)

#install (TARGETS compl DESTINATION bin)
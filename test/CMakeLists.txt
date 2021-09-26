cmake_minimum_required (VERSION 3.0)

project (ComplexT VERSION 1.0.0 LANGUAGES C CXX)

set(Boost_USE_STATIC_LIBS OFF)

add_executable(test test.cpp)

find_package (Boost 1.68 COMPONENTS unit_test_framework QUIET)
target_link_libraries (test complex_number)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries (test ${Boost_LIBRARIES})
endif()

#install (TARGETS test DESTINATION bin)
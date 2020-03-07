

cmake_minimum_required(VERSION 3.15)

project(2188HW5)

set(CMAKE_CXX_STANDARD 17)

add_executable(2188HW5 main.cpp dictionary.cpp dictionary.h DictEntry.h functions.cpp functions.h)

find_package(Boost 1.72.0 COMPONENTS system filesystem REQUIRED)
if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

add_executable(BoostTest main.cpp)
if (Boost_FOUND)
    target_link_libraries(BoostTest ${Boost_LIBRARIES})
endif ()
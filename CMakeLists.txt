cmake_minimum_required(VERSION 3.15)

project(lpaggreg_py LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(external/lpaggreg)

add_subdirectory(external/pybind11)
set(PYBIND11_FINDPYTHON ON)

add_subdirectory(src)

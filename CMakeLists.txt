cmake_minimum_required(VERSION 3.15)

project(lpaggreg-py LANGUAGES CXX)

set(PYBIND11_FINDPYTHON ON)
add_subdirectory(external/lpaggreg)
add_subdirectory(external/pybind11)
add_subdirectory(lpaggreg-py)
#install(TARGETS example DESTINATION .)

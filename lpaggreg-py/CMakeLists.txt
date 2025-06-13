pybind11_add_module(lpaggreg-py src/library-exports.cpp)

target_include_directories(lpaggreg-py PRIVATE lpaggreg)
target_link_libraries(lpaggreg-py PRIVATE lpaggreg)

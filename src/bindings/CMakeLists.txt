pybind11_add_module(_lpaggreg MODULE src/library-exports.cpp)

target_include_directories(_lpaggreg PRIVATE lpaggreg)
target_link_libraries(_lpaggreg PRIVATE lpaggreg)

set_target_properties(_lpaggreg PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src/lpaggreg_py")

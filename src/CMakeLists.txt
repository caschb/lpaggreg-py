set(SOURCES
    library_exports.cpp
    bindings/bindings.hpp
    bindings/bind_ovalues.cpp
    bindings/bind_quality.cpp
    bindings/bind_tradeoff.cpp
    bindings/bind_utmatrix.cpp
)

pybind11_add_module(_lpaggreg MODULE ${SOURCES})

target_include_directories(_lpaggreg PRIVATE lpaggreg)
target_link_libraries(_lpaggreg PRIVATE lpaggreg)

set_target_properties(_lpaggreg PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src/lpaggreg_py")

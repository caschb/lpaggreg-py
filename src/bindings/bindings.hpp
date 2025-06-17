#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

#define BIND(x) void bind_##x(py::module_& m)

BIND(ovalues);
BIND(ovalues_n1);
BIND(ovalues_n2);
BIND(ovalues_n3);
BIND(ovalues_n4);
BIND(quality);
BIND(utmatrix_double);

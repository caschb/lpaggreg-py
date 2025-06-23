#include "bindings.hpp"
#include "oqualities.h"
#include "ovalues.h"
#include <memory>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace lpaggreg;

BIND(oqualities) {
  py::class_<OQualities>(m, "OQualities")
      .def(py::init<oqualities>())
      .def(py::init<shared_ptr<OValues>>())
      .def("normalize", &OQualities::normalize)
      .def("computeQualities", &OQualities::computeQualities)
      .def("size", &OQualities::size)
      .def("__len__", &OQualities::size)
      .def("getQualities", &OQualities::getQualities);
}

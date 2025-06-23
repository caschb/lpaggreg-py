#include "bindings.hpp"
#include "opartition.h"
#include "oqualities.h"
#include "partition.h"
#include "quality.h"
#include <memory>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

namespace py = pybind11;
using namespace lpaggreg;

BIND(partition) {
  py::class_<Partition, shared_ptr<Partition>>(m, "Partition")
      .def(py::init<float>())
      .def("getParameter", &Partition::getParameter)
      .def("getQuality", &Partition::getQuality);
}

BIND(opart) {
  py::class_<OPart>(m, "OPart")
      .def(py::init<int, int, shared_ptr<Quality>>())
      .def("getStart", &OPart::getStart)
      .def("getEnd", &OPart::getEnd)
      .def("getSize", &OPart::getSize)
      .def("__len__", &OPart::getSize)
      .def(py::self == py::self)
      .def(py::self != py::self)
      .def("getQuality", &OPart::getQuality);
}

BIND(opartition) {
  py::class_<OPartition, Partition, shared_ptr<OPartition>>(m, "OPartition")
      .def(py::init<std::vector<int>, oqualities, float>())
      .def("getCuts", &OPartition::getCuts)
      .def("getParts", &OPartition::getParts)
      .def("getQualities", &OPartition::getQualities)
      .def(py::self == py::self)
      .def(py::self != py::self);
}

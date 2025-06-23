#include "bindings.hpp"
#include "opartitioner.h"
#include "oqualities.h"
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace lpaggreg;

BIND(opartitioner) {
  py::class_<OPartitioner>(m, "OPartitioner")
      .def(py::init<oqualities>())
      .def(py::init<OQualities>())
      .def("computeBestPartitions", &OPartitioner::computeBestPartitions)
      .def("computeBestPartition", &OPartitioner::computeBestPartitions)
      .def("getPartitions", &OPartitioner::getPartitions)
      .def("getPartitionsTuples", &OPartitioner::getPartitionsTuples);
}

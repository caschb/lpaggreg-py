#include "bindings.hpp"
#include "oaggregation.h"
#include "oaggregationn.h"
#include "opartition.h"
#include "ovaluesn.h"
#include <memory>
#include <pybind11/pybind11.h>

#define OAGGREGATE_N_X(x)                                                      \
  BIND(oaggregaten##x) {                                                       \
    py::class_<OAggregateN##x>(m, "OAggregateN"#x)                \
        .def(py::init<OPart, shared_ptr<OValuesN##x>>())                       \
        .def("getSum", &OAggregateN##x::getSum)                                \
        .def("getMean", &OAggregateN##x::getMean);                             \
  }

#define OAGGREGATION_N_X(x)                                                    \
  BIND(oaggregationn##x) {                                                     \
    py::class_<OAggregationN##x, OAggregation>(m, "OAggregationN" #x)          \
        .def(py::init<shared_ptr<OPartition>, shared_ptr<OValuesN##x>>())      \
        .def("getAggregates", &OAggregationN##x::getAggregates);               \
  }

namespace py = pybind11;
using namespace lpaggreg;

// BIND(oaggregate) {
//   py::class_<OAggregate, shared_ptr<OAggregate>>(m, "OAggregate")
//       .def(py::init<OPart>())
//       .def("getPart", &OAggregate::getPart);
// }

OAGGREGATE_N_X(1)
OAGGREGATE_N_X(2)
OAGGREGATE_N_X(3)
OAGGREGATE_N_X(4)

BIND(oaggregation) {
  py::class_<OAggregation>(m, "OAggregation")
      .def(py::init<shared_ptr<OPartition>>());
}

OAGGREGATION_N_X(1)
OAGGREGATION_N_X(2)
OAGGREGATION_N_X(3)
OAGGREGATION_N_X(4)

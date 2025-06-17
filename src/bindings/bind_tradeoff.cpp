#include <memory>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include "bindings.hpp"
#include "lpglobal.h"
#include "tradeoff.h"
#include "quality.h"

namespace py = pybind11;
using namespace lpaggreg;

BIND(tradeoff) {
  py::class_<Tradeoff>(m, "Tradeoff")
    .def(py::init<>())
    .def(py::init<shared_ptr<Quality>>())
    .def(py::init<lp_quality_type, shared_ptr<Quality>>())
    .def(py::init<shared_ptr<Quality>, float>())
    .def("computePIC", &Tradeoff::computePIC)
    .def(py::self += py::self)
    .def(py::self -= py::self)
    .def(py::self *= py::self)
    .def(py::self /= py::self)
    .def("set", &Tradeoff::set)
    .def("getQuality", &Tradeoff::getQuality)
    .def("getValue", &Tradeoff::getValue)
    .def(py::self + py::self)
    .def(py::self - py::self)
    .def(py::self * py::self)
    .def(py::self / py::self)
    .def(py::self == py::self)
    .def(py::self != py::self)
    .def(py::self >= py::self)
    .def(py::self <= py::self)
    .def(py::self > py::self)
    .def(py::self < py::self);
}

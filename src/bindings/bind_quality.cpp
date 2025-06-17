#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "bindings.hpp"
#include "quality.h"

namespace py = pybind11;
using namespace lpaggreg;

BIND(quality) {
  py::class_<Quality>(m, "Quality")
    .def(py::init<>())
    .def(py::init<lp_quality_type, lp_quality_type>())
    .def("getGain", &Quality::getGain)
    .def("setGain", &Quality::setGain)
    .def("getLoss", &Quality::getLoss)
    .def("setLoss", &Quality::setLoss)
    .def("addToGain", &Quality::addToGain)
    .def("addToLoss", &Quality::addToLoss)
    .def("iadd",
	 [](Quality &self, Quality &other) {
	   self += other;
	   return self;
	 })
    .def("isub",
	 [](Quality &self, Quality &other) {
	   self -= other;
	   return self;
	 })
    .def("imul",
	 [](Quality &self, Quality &other) {
	   self *= other;
	   return self;
	 })
    .def("idiv",
	 [](Quality &self, Quality &other) {
	   self /= other;
	   return self;
	 })
    .def(py::self + py::self)
    .def(py::self - py::self)
    .def(py::self * py::self)
    .def(py::self / py::self)
    .def(py::self == py::self)
    .def(py::self != py::self)
    .def("__repr__", [](const Quality &q) {
      std::ostringstream os;
      os << q;
      return os.str();
    });
}

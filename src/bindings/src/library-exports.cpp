#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ovaluesn.h"

namespace py = pybind11;
using namespace lpaggreg;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(_lpaggreg, m) {
  py::class_<OValues>(m, "OValues")
    .def("getVsize", &OValues::getVsize)
    .def("getOsize", &OValues::getOsize);
  
  py::class_<OValuesN1, OValues>(m, "OValuesN1")
    .def(py::init<std::vector<double>>())
    .def(py::init<unsigned int>())
    .def("__getitem__", &OValuesN1::operator[])
    .def("__call__",
	 static_cast<double (OValuesN1::*)(unsigned int)>(&OValuesN1::operator()))
    .def("__call__",
	 static_cast<void (OValuesN1::*)(unsigned int, double)>(&OValuesN1::operator()));

  py::class_<OValuesN2, OValues>(m, "OValuesN2")
    .def(py::init<std::vector<std::vector<double>>>())
    .def(py::init<unsigned int, unsigned int>())
    .def("__getitem__", &OValuesN2::operator[])
    .def("__call__",
	 static_cast<double (OValuesN2::*)(unsigned int, unsigned int)>(&OValuesN2::operator()))
    .def("__call__",
	 static_cast<void (OValuesN2::*)(unsigned int, unsigned int, double)>(&OValuesN2::operator()));

  py::class_<OValuesN3, OValues>(m, "OValuesN3")
    .def(py::init<std::vector<std::vector<std::vector<double>>>>())
    .def(py::init<unsigned int, unsigned int, unsigned int>())
    .def("__getitem__", &OValuesN3::operator[])
    .def("__call__",
	 static_cast<double (OValuesN3::*)(unsigned int, unsigned int, unsigned int)>(&OValuesN3::operator()))
    .def("__call__",
	 static_cast<void (OValuesN3::*)(unsigned int, unsigned int, unsigned int, double)>(&OValuesN3::operator()))
    .def("getI", &OValuesN3::getI)
    .def("getJ", &OValuesN3::getJ);

  py::class_<OValuesN4, OValues>(m, "OValuesN4")
    .def(py::init<std::vector<std::vector<std::vector<std::vector<double>>>>>())
    .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int>())
    .def("__getitem__", &OValuesN4::operator[])
    .def("__call__",
	 static_cast<double (OValuesN4::*)(unsigned int, unsigned int, unsigned int, unsigned int)>(&OValuesN4::operator()))
    .def("__call__",
	 static_cast<void (OValuesN4::*)(unsigned int, unsigned int, unsigned int, unsigned int, double)>(&OValuesN4::operator()))
    .def("getI", &OValuesN4::getI)
    .def("getJ", &OValuesN4::getJ)
    .def("getK", &OValuesN4::getK);
}

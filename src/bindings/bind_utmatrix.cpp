#include "bindings.hpp"
#include "quality.h"
#include "uppertriangularmatrix.h"
#include <memory>
#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace lpaggreg;

typedef UpperTriangularMatrix<shared_ptr<Quality>> utquality;

BIND(utmatrix_double) {
  py::class_<UpperTriangularMatrix<double>>(m, "UpperTriangularMatrixDouble")
      .def(py::init<unsigned int>())
      .def(py::init<unsigned int, double>())
      .def("__call__", static_cast<double (UpperTriangularMatrix<double>::*)(
                           unsigned int, unsigned int)>(
                           &UpperTriangularMatrix<double>::operator()))
      .def("__call__", static_cast<void (UpperTriangularMatrix<double>::*)(
                           unsigned int, unsigned int, double)>(
                           &UpperTriangularMatrix<double>::operator()))
      .def("__getitem__",
           static_cast<double (UpperTriangularMatrix<double>::*)(unsigned int)>(
               &UpperTriangularMatrix<double>::operator[]))
      .def("getSize", &UpperTriangularMatrix<double>::getSize)
      .def("getElements", &UpperTriangularMatrix<double>::getElements)
      .def_readwrite("matrix", &UpperTriangularMatrix<double>::matrix);
}

BIND(utmatrix_quality) {
  py::class_<utquality, shared_ptr<utquality>>(m, "utquality")
      .def(py::init<unsigned int>())
      .def(py::init<unsigned int, shared_ptr<Quality>>())
      .def("__call__", static_cast<shared_ptr<Quality> (utquality::*)(
                           unsigned int, unsigned int)>(&utquality::operator()))
      .def("__call__", static_cast<void (utquality::*)(
                           unsigned int, unsigned int, shared_ptr<Quality>)>(
                           &utquality::operator()))
      .def("__getitem__",
           static_cast<shared_ptr<Quality> (utquality::*)(unsigned int)>(
               &utquality::operator[]))
      .def("getSize", &utquality::getSize)
      .def("getElements", &utquality::getElements)
      .def_readwrite("matrix", &utquality::matrix);
}

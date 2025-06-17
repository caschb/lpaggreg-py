#include <pybind11/pybind11.h>
#include "bindings.hpp"
#include "uppertriangularmatrix.h"

namespace py = pybind11;

using namespace lpaggreg;

BIND(utmatrix_double) {
   py::class_<UpperTriangularMatrix<double>>(m, "UpperTriangularMatrixDouble")
    .def(py::init<unsigned int>())
    .def(py::init<unsigned int, double>())
    .def("__call__",
        static_cast<double (UpperTriangularMatrix<double>::*)(unsigned int, unsigned int)>(&UpperTriangularMatrix<double>::operator()))
    .def("__call__",
	 static_cast<void (UpperTriangularMatrix<double>::*)(unsigned int, unsigned int, double)>(&UpperTriangularMatrix<double>::operator()))
    .def("__getitem__",
        static_cast<double (UpperTriangularMatrix<double>::*)(unsigned int)>(&UpperTriangularMatrix<double>::operator[]))
    .def("getSize", &UpperTriangularMatrix<double>::getSize)
    .def("getElements", &UpperTriangularMatrix<double>::getElements)
    .def_readwrite("matrix", &UpperTriangularMatrix<double>::matrix);
}

 

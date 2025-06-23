#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

#define BIND(x) void bind_##x(py::module_ &m)

// bind_aggregation.cpp
// BIND(oaggregate);
BIND(oaggregaten1);
BIND(oaggregaten2);
BIND(oaggregaten3);
BIND(oaggregaten4);
BIND(oaggregation);
BIND(oaggregationn1);
BIND(oaggregationn2);
BIND(oaggregationn3);
BIND(oaggregationn4);

// bind_ovalues.cpp
BIND(ovalues);
BIND(ovalues_n1);
BIND(ovalues_n2);
BIND(ovalues_n3);
BIND(ovalues_n4);

// bind_partition.cpp
BIND(partition);
BIND(opart);
BIND(opartition);

// bind_partitioner.cpp
BIND(opartitioner);

// bind_qualities.cpp
BIND(oqualities);

// bind_quality.cpp
BIND(quality);

// bind_tradeoff.cpp
BIND(tradeoff);

// bind_utmatrix.cpp
BIND(utmatrix_double);
BIND(utmatrix_quality);

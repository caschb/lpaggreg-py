#include "bindings/bindings.hpp"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(_lpaggreg, m) {
  // bind_aggregation.cpp
  // bind_oaggregate(m);
  bind_oaggregaten1(m);
  bind_oaggregaten2(m);
  bind_oaggregaten3(m);
  bind_oaggregaten4(m);
  bind_oaggregation(m);
  bind_oaggregationn1(m);
  bind_oaggregationn2(m);
  bind_oaggregationn3(m);
  bind_oaggregationn4(m);
  
  // bind_ovalues.cpp
  bind_ovalues(m);
  bind_ovalues_n1(m);
  bind_ovalues_n2(m);
  bind_ovalues_n3(m);
  bind_ovalues_n4(m);

  // bind_partition.cpp
  bind_partition(m);
  bind_opart(m);
  bind_opartition(m);

  // bind_partitioner.cpp
  bind_opartitioner(m);

  // bind_qualities.cpp
  bind_oqualities(m);

  // bind_quality.cpp
  bind_quality(m);

  // bind_tradeoff.cpp
  bind_tradeoff(m);

  // bind_utmatrix.cpp
  bind_utmatrix_double(m);
  bind_utmatrix_quality(m);
}

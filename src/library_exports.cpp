#include <pybind11/pybind11.h>
#include "bindings/bindings.hpp"

PYBIND11_MODULE(_lpaggreg, m) {
  bind_ovalues(m);
  bind_ovalues_n1(m);
  bind_ovalues_n2(m);
  bind_ovalues_n3(m);
  bind_ovalues_n4(m);
  bind_quality(m);
  bind_tradeoff(m);
  bind_utmatrix_double(m);
  bind_utmatrix_quality(m);
}

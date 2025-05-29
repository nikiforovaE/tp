#ifndef OPERATIONSWITHSHAPES_H
#define OPERATIONSWITHSHAPES_H
#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace nikiforova {

  using shapePtr = std::unique_ptr< nikiforova::Shape >;
  using arrShapesPtr = std::unique_ptr < shapePtr[] >;

  void scaleShape(Shape&, const point_t&, double);
  void addToArray(arrShapesPtr&&, shapePtr&&, size_t&, size_t&);
  double getSumArea(const arrShapesPtr&, const size_t&);

}

#endif

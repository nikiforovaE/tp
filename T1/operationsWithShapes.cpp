#include "operationsWithShapes.h"
#include <iostream>

void nikiforova::scaleShape(Shape& shape, const point_t& point, double k)
{
  point_t frameCenter1 = shape.getFrameRect().pos_;
  shape.move(point);
  point_t frameCenter2 = shape.getFrameRect().pos_;
  double x = frameCenter1.x_ - frameCenter2.x_;
  double y = frameCenter1.y_ - frameCenter2.y_;
  shape.doScale(k);
  shape.move(x * k, y * k);
}

double nikiforova::getSumArea(const arrShapesPtr& arr, const size_t& size)
{
  double res = 0;
  for (size_t i = 0; i < size; i++)
  {
    res += arr[i]->getArea();
  }
  return res;
}

void nikiforova::addToArray(arrShapesPtr&& arr, shapePtr&& shape, size_t& count, size_t& size)
{
  if (count < size)
  {
    arr[count++] = std::move(shape);
  }
  else
  {
    arrShapesPtr newArr = std::make_unique< shapePtr[] >(size * 1.6);
    for (size_t i = 0; i < count; i++)
    {
      newArr[i] = std::move(arr[i]);
    }
    newArr[count++] = std::move(shape);
    arr = std::move(newArr);
    size *= 1.6;
  }
  return;
}

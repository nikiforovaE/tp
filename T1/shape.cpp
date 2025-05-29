#include "shape.hpp"
#include <stdexcept>

void nikiforova::Shape::doScale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scale argument");
  }
  scale(k);
}

#include "base-types.hpp"
#include <iostream>
#include <iomanip>

std::ostream& nikiforova::operator<<(std::ostream& out, const rectangle_t& rect)
{
  double lowLeftX = rect.pos_.x_ - rect.width_ / 2;
  double lowLeftY = rect.pos_.y_ - rect.height_ / 2;
  double uppRightX = rect.pos_.x_ + rect.width_ / 2;
  double uppRightY = rect.pos_.y_ + rect.height_ / 2;
  out << std::fixed << std::setprecision(1);
  out << lowLeftX << " " << lowLeftY << " " << uppRightX << " " << uppRightY;
  return out;
}

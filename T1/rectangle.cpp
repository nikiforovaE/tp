#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

nikiforova::Rectangle::Rectangle(const point_t& lowLeft, const point_t& uppRight):
  rectangle_({ uppRight.x_ - lowLeft.x_, uppRight.y_ - lowLeft.y_ , { (lowLeft.x_ + uppRight.x_) / 2, (lowLeft.y_ + uppRight.y_) / 2} })
{
  if ((lowLeft.x_ >= uppRight.x_) || (lowLeft.y_ >= uppRight.y_))
  {
    throw std::logic_error("Incorrect points for rectangle");
  }
}

double nikiforova::Rectangle::getArea() const
{
  return rectangle_.width_ * rectangle_.height_;
}

nikiforova::rectangle_t nikiforova::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void nikiforova::Rectangle::move(const point_t& p)
{
  rectangle_.pos_ = p;
}

void nikiforova::Rectangle::move(double dx, double dy)
{
  rectangle_.pos_.x_ += dx;
  rectangle_.pos_.y_ += dy;
}

void nikiforova::Rectangle::scale(double k)
{
  rectangle_.height_ *= k;
  rectangle_.width_ *= k;
}

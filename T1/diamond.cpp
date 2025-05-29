#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

namespace {
  nikiforova::point_t getCenterPoint(const nikiforova::point_t& a, const nikiforova::point_t& b, const nikiforova::point_t& c)
  {
    if (((a.x_ == b.x_) && (a.y_ == c.y_)) || ((a.x_ == c.x_) && (a.y_ == b.y_)))
    {
      return a;
    }
    else if (((b.x_ == c.x_) && (b.y_ == a.y_)) || ((b.x_ == a.x_) && (b.y_ == c.y_)))
    {
      return b;
    }
    else if (((c.x_ == a.x_) && (c.y_ == b.y_)) || ((c.x_ == b.x_) && (c.y_ == a.y_)))
    {
      return c;
    }
    else
    {
      throw std::logic_error("Incorrect points for diamond");
    }
  }

  nikiforova::point_t getPointOnHorizontal(const nikiforova::point_t& a, const nikiforova::point_t& b, const nikiforova::point_t& c)
  {
    nikiforova::point_t center = ::getCenterPoint(a, b, c);
    if ((center.y_ == a.y_) && (center.x_ != a.x_))
    {
      return a;
    }
    else if ((center.y_ == b.y_) && (center.x_ != b.x_))
    {
      return b;
    }
    else
    {
      return c;
    }
  }

  nikiforova::point_t getPointOnVertical(const nikiforova::point_t& a, const nikiforova::point_t& b, const nikiforova::point_t& c)
  {
    nikiforova::point_t center = ::getCenterPoint(a, b, c);
    if ((center.x_ == a.x_) && (center.y_ != a.y_))
    {
      return a;
    }
    else if ((center.x_ == b.x_) && (center.y_ != b.y_))
    {
      return b;
    }
    else
    {
      return c;
    }
  }
}

nikiforova::Diamond::Diamond(const point_t& a, const point_t& b, const point_t& c):
  centerP_(::getCenterPoint(a, b, c)),
  onHorizontalP_(::getPointOnHorizontal(a, b, c)),
  onVerticalP_(::getPointOnVertical(a, b, c))
{}


double nikiforova::Diamond::getArea() const
{
  return 2 * (std::abs(centerP_.x_ - onHorizontalP_.x_) * std::abs(centerP_.y_ - onVerticalP_.y_));
}

nikiforova::rectangle_t nikiforova::Diamond::getFrameRect() const
{
  double width = 2 * std::abs(onHorizontalP_.x_ - centerP_.x_);
  double height = 2 * std::abs(onVerticalP_.y_ - centerP_.y_);
  return rectangle_t{ width, height, centerP_ };
}

void nikiforova::Diamond::move(const point_t& p)
{
  double dx = p.x_ - centerP_.x_;
  double dy = p.y_ - centerP_.y_;
  move(dx, dy);
}

void nikiforova::Diamond::move(double dx, double dy)
{
  centerP_.x_ += dx;
  centerP_.y_ += dy;
  onHorizontalP_.x_ += dx;
  onHorizontalP_.y_ += dy;
  onVerticalP_.x_ += dx;
  onVerticalP_.y_ += dy;
}

void nikiforova::Diamond::scale(double k)
{
  onHorizontalP_.x_ = centerP_.x_ + (onHorizontalP_.x_ - centerP_.x_) * k;
  onHorizontalP_.y_ = centerP_.y_ + (onHorizontalP_.y_ - centerP_.y_) * k;
  onVerticalP_.x_ = centerP_.x_ + (onVerticalP_.x_ - centerP_.x_) * k;
  onVerticalP_.y_ = centerP_.y_ + (onVerticalP_.y_ - centerP_.y_) * k;
}

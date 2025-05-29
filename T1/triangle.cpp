#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include "base-types.hpp"

nikiforova::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  double ab = std::sqrt(std::pow(a.x_ - b.x_, 2) + std::pow(a.y_ - b.y_, 2));
  double bc = std::sqrt(std::pow(b.x_ - c.x_, 2) + std::pow(b.y_ - c.y_, 2));
  double ca = std::sqrt(std::pow(c.x_ - a.x_, 2) + std::pow(c.y_ - a.y_, 2));
  if (!(ab < (bc + ca) && bc < (ab + ca) && ca < (ab + bc)))
  {
    throw std::logic_error("Incorrect points for triangle");
  }
}

double nikiforova::Triangle::getArea() const
{
  double ab = getAB();
  double bc = getBC();
  double ca = getAC();
  double p = (ab + bc + ca) / 2;
  return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

nikiforova::point_t nikiforova::Triangle::getCenter() const
{
  return { (a_.x_ + b_.x_ + c_.x_) / 3, (a_.y_ + b_.y_ + c_.y_) / 3 };
}

double nikiforova::Triangle::getAB() const
{
  return std::sqrt(std::pow(a_.x_ - b_.x_, 2) + std::pow(a_.y_ - b_.y_, 2));
}

double nikiforova::Triangle::getBC() const
{
  return  std::sqrt(std::pow(b_.x_ - c_.x_, 2) + std::pow(b_.y_ - c_.y_, 2));
}

double nikiforova::Triangle::getAC() const
{
  return std::sqrt(std::pow(c_.x_ - a_.x_, 2) + std::pow(c_.y_ - a_.y_, 2));
}

nikiforova::rectangle_t nikiforova::Triangle::getFrameRect() const
{
  double left = std::min(std::min(a_.x_, b_.x_), c_.x_);
  double right = std::max(std::max(a_.x_, b_.x_), c_.x_);
  double top = std::max(std::max(a_.y_, b_.y_), c_.y_);
  double bottom = std::min(std::min(a_.y_, b_.y_), c_.y_);
  point_t pos{ left + (right - left) / 2, bottom + (top - bottom) / 2 };
  return rectangle_t{ right - left, top - bottom, pos };
}

void nikiforova::Triangle::move(const point_t& p)
{
  move(p.x_ - getCenter().x_, p.y_ - getCenter().y_);
}

void nikiforova::Triangle::move(double a, double b)
{
  a_.x_ += a;
  a_.y_ += b;
  b_.x_ += a;
  b_.y_ += b;
  c_.x_ += a;
  c_.y_ += b;
}

void nikiforova::Triangle::scale(double k)
{
  point_t center = getCenter();
  a_.x_ = center.x_ + (a_.x_ - center.x_) * k;
  a_.y_ = center.y_ + (a_.y_ - center.y_) * k;
  b_.x_ = center.x_ + (b_.x_ - center.x_) * k;
  b_.y_ = center.y_ + (b_.y_ - center.y_) * k;
  c_.x_ = center.x_ + (c_.x_ - center.x_) * k;
  c_.y_ = center.y_ + (c_.y_ - center.y_) * k;
}

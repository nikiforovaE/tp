#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace nikiforova {
  class Triangle: public Shape
  {
  public:
    Triangle(const point_t&, const point_t&, const point_t&);
    ~Triangle() = default;

    double getArea() const override;
    point_t getCenter() const;
    double getAB() const;
    double getBC() const;
    double getAC() const;

    rectangle_t getFrameRect() const override;
    void move(const point_t&) override;
    void move(double, double) override;

  private:
    point_t a_;
    point_t b_;
    point_t c_;
    void scale(double) override;
  };
}

#endif

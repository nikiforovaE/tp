#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikiforova {
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t&, const point_t&);
    ~Rectangle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t&) override;
    void move(double, double) override;

  private:
    rectangle_t rectangle_;
    void scale(double) override;
  };
}
#endif

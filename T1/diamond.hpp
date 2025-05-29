#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace nikiforova {
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t&, const point_t&, const point_t&);
    ~Diamond() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t&) override;
    void move(double, double) override;

  private:
    point_t centerP_;
    point_t onHorizontalP_;
    point_t onVerticalP_;
    void scale(double) override;
  };
}

#endif

#ifndef BASETYPE_HPP
#define BASETYPE_HPP
#include <iosfwd>

namespace nikiforova {
  struct point_t {
    double x_;
    double y_;
  };

  struct rectangle_t {
    double width_;
    double height_;
    point_t pos_;
  };

  std::ostream& operator<<(std::ostream&, const rectangle_t&);

}
#endif

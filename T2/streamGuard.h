#ifndef STREAMGUARD_H
#define STREAMGUARD_H
#include <ios>

namespace nikiforova {
  class StreamGuard
  {
  public:
    StreamGuard(std::ios&);
    ~StreamGuard();

  private:
    std::ios& s_;
    std::streamsize precision_;
    std::ios::fmtflags flags_;
  };
}

#endif

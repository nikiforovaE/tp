#include "streamGuard.h"

nikiforova::StreamGuard::StreamGuard(std::ios& s):
  s_(s),
  precision_(s.precision()),
  flags_(s.flags())
{}

nikiforova::StreamGuard::~StreamGuard()
{
  s_.precision(precision_);
  s_.flags(flags_);
}

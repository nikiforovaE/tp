#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <string>

namespace nikiforova {

  struct DataStruct
  {
    double key1;
    unsigned long long key2;
    std::string key3;
  };

  std::istream& operator>>(std::istream&, DataStruct&);
  std::ostream& operator<<(std::ostream&, const DataStruct&);
  bool operator<(const DataStruct& left, const DataStruct& right);

}

#endif

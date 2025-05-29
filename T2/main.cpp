#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include "dataStruct.h"

int main()
{
  using nikiforova::DataStruct;
  std::vector< DataStruct > data;
  while (!std::cin.eof())
  {
    std::copy(std::istream_iterator< DataStruct >(std::cin), std::istream_iterator< DataStruct >(), std::back_inserter(data));
    if (std::cin.rdstate() == std::ios::failbit)
    {
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      std::cin.clear();
    }
  }
  std::sort(data.begin(), data.end());
  std::copy(std::begin(data), std::end(data), std::ostream_iterator< DataStruct >(std::cout, "\n"));
  return 0;
}

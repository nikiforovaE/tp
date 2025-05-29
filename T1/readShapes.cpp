#include "readShapes.h"

nikiforova::point_t nikiforova::getPoint(std::string& str)
{
  double x = std::stod(nikiforova::getWord(str));
  double y = std::stod(nikiforova::getWord(str));
  nikiforova::point_t res{ x, y };
  return res;
}

std::string nikiforova::getWord(std::string& str)
{
  std::string word = "";
  if (str[0] == ' ')
  {
    str.erase(0, 1);
  }
  word = str.substr(0, str.find(" "));
  str = str.erase(0, str.find(" "));
  return word;
}

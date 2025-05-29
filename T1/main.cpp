#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "operationsWithShapes.h"
#include "readShapes.h"

int main()
{
  size_t arrSize = 2;
  nikiforova::arrShapesPtr arrShapes = std::make_unique< nikiforova::shapePtr[] >(arrSize);
  size_t count = 0;
  bool scale = 0;
  bool error = 0;
  std::string errorMessage = "";
  try
  {
    while (!std::cin.eof())
    {
      std::string str = "";
      std::getline(std::cin, str);
      if (!str.empty())
      {
        std::string command = nikiforova::getWord(str);
        try
        {
          if (command == "RECTANGLE")
          {
            nikiforova::point_t p1 = nikiforova::getPoint(str);
            nikiforova::point_t p2 = nikiforova::getPoint(str);
            nikiforova::Rectangle rect(p1, p2);
            nikiforova::shapePtr shape = std::make_unique< nikiforova::Rectangle >(rect);
            nikiforova::addToArray(std::move(arrShapes), std::move(shape), count, arrSize);
          }
          else if (command == "TRIANGLE")
          {
            nikiforova::point_t p1 = nikiforova::getPoint(str);
            nikiforova::point_t p2 = nikiforova::getPoint(str);
            nikiforova::point_t p3 = nikiforova::getPoint(str);
            nikiforova::Triangle triangle(p1, p2, p3);
            nikiforova::shapePtr shape = std::make_unique< nikiforova::Triangle >(triangle);
            nikiforova::addToArray(std::move(arrShapes), std::move(shape), count, arrSize);
          }
          else if (command == "DIAMOND")
          {
            nikiforova::point_t p1 = nikiforova::getPoint(str);
            nikiforova::point_t p2 = nikiforova::getPoint(str);
            nikiforova::point_t p3 = nikiforova::getPoint(str);
            nikiforova::Diamond diamond(p1, p2, p3);
            nikiforova::shapePtr shape = std::make_unique< nikiforova::Diamond >(diamond);
            nikiforova::addToArray(std::move(arrShapes), std::move(shape), count, arrSize);
          }
        }
        catch (const std::exception& e)
        {
          error = 1;
          errorMessage = e.what();
        }
        if (command == "SCALE")
        {
          scale = 1;
          if (count < 1)
          {
            std::cerr << "Nothing to scale\n";
            return 1;
          }
          nikiforova::point_t point = nikiforova::getPoint(str);
          double k = std::stod(nikiforova::getWord(str));
          if (k <= 0)
          {
            throw std::logic_error("Incorrect scale coefficient");
          }
          std::cout << std::fixed << std::setprecision(1);
          std::cout << nikiforova::getSumArea(arrShapes, count);
          for (size_t i = 0; i < count; i++)
          {
            nikiforova::rectangle_t frame = arrShapes[i]->getFrameRect();
            std::cout << " " << frame;
            nikiforova::scaleShape(*arrShapes[i], point, k);
          }
          std::cout << "\n";
          std::cout << nikiforova::getSumArea(arrShapes, count);
          for (size_t i = 0; i < count; i++)
          {
            nikiforova::rectangle_t frame = arrShapes[i]->getFrameRect();
            std::cout << " " << frame;
          }
          std::cout << "\n";
        }
        str = "";
      }
    }
    if (error)
    {
      std::cerr << errorMessage << "\n";
    }
    if (!scale)
    {
      std::cerr << "Expected scale command\n";
      return 1;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}

#include "dataStruct.h"
#include <iostream>
#include <iomanip>
#include "streamGuard.h"

namespace nikiforova
{
  struct DelimiterIO {
    char exp;
  };

  struct DoubleIO {
    double& ref;
  };

  struct UnsignedLongLongIO {
    unsigned long long& ref;
  };

  struct StringIO {
    std::string& ref;
  };

  std::istream& operator>>(std::istream& in, DelimiterIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    char sep;
    in >> sep;
    if (in && (sep != dest.exp))
    {
      in.setstate(std::ios::failbit);
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, DoubleIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    in >> dest.ref;
    char temp = in.get();
    if (temp != 'd' && temp != 'D')
    {
      in.setstate(std::ios::failbit);
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, UnsignedLongLongIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    in >> DelimiterIO{ '0' } >> DelimiterIO{ 'x' };
    return in >> std::hex >> dest.ref;
  }

  std::istream& operator>>(std::istream& in, StringIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    return std::getline(in >> DelimiterIO{ '"' }, dest.ref, '"');
  }

  std::istream& operator>>(std::istream& in, DataStruct& data)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    in >> DelimiterIO{ '(' } >> DelimiterIO{ ':' };
    DataStruct temp;
    for (int i = 0; i < 3; ++i)
    {
      std::string keyNumber;
      in >> keyNumber;
      if (keyNumber == "key1")
      {
        in >> DoubleIO{ temp.key1 };
      }
      else if (keyNumber == "key2")
      {
        in >> UnsignedLongLongIO{ temp.key2 };
      }
      else if (keyNumber == "key3")
      {
        in >> StringIO{ temp.key3 };
      }
      else
      {
        in.setstate(std::ios::failbit);
        return in;
      }
      in >> DelimiterIO{ ':' };
    }
    in >> DelimiterIO{ ')' };
    if (in)
    {
      data = temp;
    }
    return in;
  }

  std::ostream& operator<<(std::ostream& out, const DataStruct& data)
  {
    std::ostream::sentry sentry(out);
    if (!sentry)
    {
      return out;
    }
    StreamGuard guard(out);
    out << std::fixed << std::setprecision(1);
    out << '(';
    out << ":key1 " << data.key1 << "d";
    out << ":key2 " << "0x" << std::hex << std::uppercase << data.key2;
    out << ":key3 " << "\"" << data.key3 << "\"";
    out << ":)";
    return out;
  }
  bool operator<(const DataStruct& left, const DataStruct& right)
  {
    if (left.key1 != right.key1)
    {
      return left.key1 < right.key1;
    }
    else if (left.key2 != right.key2)
    {
      return left.key2 < right.key2;
    }
    else
    {
      return left.key3.length() < right.key3.length();
    }
  }

}

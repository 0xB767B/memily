#include <algorithm>
#include <iterator>

extern "C"
{
  struct ctor_type
  {
    typedef void(*vfp)();
    typedef std::reverse_iterator<const vfp*> const_reverse_iterator;
  };

  extern ctor_type::vfp _ctorsEnd[];
  extern ctor_type::vfp _ctorsBegin[];
}

namespace crt
{
  void init_ctors();
}

void crt::init_ctors()
{
  std::for_each(ctor_type::const_reverse_iterator(_ctorsEnd),
		        ctor_type::const_reverse_iterator(_ctorsBegin),
                [](const ctor_type::vfp ctor){ ctor(); });
}

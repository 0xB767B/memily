#include <algorithm>
#include <iterator>

extern "C"
{
  struct ctor_type
  {
    typedef void(*vfp)();
    typedef std::reverse_iterator<const vfp*> const_reverse_iterator;
  };

  extern ctor_type::vfp _ctors_begin[];
  extern ctor_type::vfp _ctors_end[];
}

namespace crt
{
  void init_ctors();
}

void crt::init_ctors()
{
  std::for_each(ctor_type::const_reverse_iterator(_ctors_end),
		        ctor_type::const_reverse_iterator(_ctors_begin),
                [](const ctor_type::vfp ctor){ ctor(); });
}

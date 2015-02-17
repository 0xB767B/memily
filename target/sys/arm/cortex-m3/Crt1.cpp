#include <algorithm>
#include <iterator>

extern "C"
{
  struct CtorType
  {
    typedef void(*FunctionType)();
    typedef std::reverse_iterator<const FunctionType*> ConstReverseIterator;
  };

  extern CtorType::FunctionType _ctorsEnd[];
  extern CtorType::FunctionType _ctorsBegin[];
}

namespace crt
{
  void InitCtors();
}

void crt::InitCtors()
{
  std::for_each(CtorType::ConstReverseIterator(_ctorsEnd),
		  CtorType::ConstReverseIterator(_ctorsBegin),
                [](const CtorType::FunctionType pf)
                {
                  pf();
                });
}
#include "Exception.h"

extern char __initialStackPointer;

typedef void (* pvf)();

extern "C" void ResetHandler();
extern "C" void DefaultExceptionHandler();

namespace exception {
__attribute__ ((section(".exception_vector")))
    pvf exceptionVector[] = {
    pvf(&__initialStackPointer),
    ResetHandler,// 0x0004
    NmiHandler,// 0x0008
    HardFaultHandler,// 0x000C
    MemManageHandler,// 0x0010
    BusFaultHandler,// 0x0014
    UsageFaultHandler,// 0x0018
    0,// 0x001C
    0,// 0x0020
    0,// 0x0024
    0,// 0x0028
    SVCallHandler,// 0x002C
    DebugMonHandler,// 0x0030
    0,// 0x0034
    PendSvHandler,// 0x0038
    SysTickHandler,// 0x003C
  };
}

extern "C" void DefaultExceptionHandler()
{
  while (true) {
  }
}

// core exceptions
#pragma weak NmiHandler = DefaultExceptionHandler
#pragma weak HardFaultHandler = DefaultExceptionHandler
#pragma weak MemManageHandler = DefaultExceptionHandler
#pragma weak BusFaultHandler = DefaultExceptionHandler
#pragma weak UsageFaultHandler = DefaultExceptionHandler
#pragma weak SVCallHandler = DefaultExceptionHandler
#pragma weak DebugMonHandler = DefaultExceptionHandler
#pragma weak PendSvHandler = DefaultExceptionHandler
#pragma weak SysTickHandler = DefaultExceptionHandler

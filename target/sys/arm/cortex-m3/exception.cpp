#include "exception.h"

extern char __initialStackPointer;

typedef void (* pvf)();

extern "C" void reset_handler();
extern "C" void default_exception_handler();

namespace exception {
    __attribute__ ((section(".exception_vector"),used))
    pvf exceptionVector[] = {
            pvf(&__initialStackPointer),
            reset_handler,// 0x0004
            nmi_handler,// 0x0008
            hardfault_handler,// 0x000C
            memmanage_handler,// 0x0010
            busfault_handler,// 0x0014
            usagefault_handler,// 0x0018
            0,// 0x001C
            0,// 0x0020
            0,// 0x0024
            0,// 0x0028
            svcall_handler,// 0x002C
            debugmon_handler,// 0x0030
            0,// 0x0034
            pendsv_handler,// 0x0038
            systick_handler,// 0x003C
    };
}

extern "C" void default_exception_handler()
{
    while (true) {
    }
}

// core exceptions
#pragma weak nmi_handler = default_exception_handler
#pragma weak hardfault_handler = default_exception_handler
#pragma weak memmanage_handler = default_exception_handler
#pragma weak busfault_handler = default_exception_handler
#pragma weak usagefault_handler = default_exception_handler
#pragma weak svcall_handler = default_exception_handler
#pragma weak debugmon_handler = default_exception_handler
#pragma weak pendsv_handler = default_exception_handler
#pragma weak systick_handler = default_exception_handler
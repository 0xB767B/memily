#pragma once

namespace exception {
    extern "C" {
    void nmi_handler();
    void hardfault_handler();
    void memmanage_handler();
    void busfault_handler();
    void usagefault_handler();
    void svcall_handler();
    void debugmon_handler();
    void pendsv_handler();
    void systick_handler();
    }
}

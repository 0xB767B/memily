#pragma once

namespace exception {
    extern "C" {
    void NmiHandler();
    void HardFaultHandler();
    void MemManageHandler();
    void BusFaultHandler();
    void UsageFaultHandler();
    void SVCallHandler();
    void DebugMonHandler();
    void PendSvHandler();
    void SysTickHandler();
    }
}

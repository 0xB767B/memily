namespace crt
{
  void InitRam();
  void InitCtors();
}

extern "C" void ResetHandler() __attribute__((used, noinline));
void ResetHandler()
{
  // TODO  mcal::cpu::init();
  crt::InitRam();
  // TODO mcal::wdg::secure::trigger();
  crt::InitCtors();
  // TODO mcal::wdg::secure::trigger();

  // call main (and hopefully never return)
  asm volatile("b main");
  while(1);
}

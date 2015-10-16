namespace crt
{
    void InitRam();
    void InitCtors();
}

extern "C" void reset_handler() __attribute__((used, noinline));
extern "C" int main();

void reset_handler()
{
  // TODO  mcal::cpu::init();
  crt::InitRam();
  // TODO mcal::wdg::secure::trigger();
  crt::InitCtors();
  // TODO mcal::wdg::secure::trigger();

  // call main (and hopefully never return)
  main();
  while(1);
}

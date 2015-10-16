namespace crt
{
    void init_ram();
    void init_ctors();
}

extern "C" void reset_handler() __attribute__((used, noinline));
extern "C" int main();

void reset_handler()
{
  // TODO  mcal::cpu::init();
  crt::init_ram();
  // TODO mcal::wdg::secure::trigger();
  crt::init_ctors();
  // TODO mcal::wdg::secure::trigger();

  main(); // call user-main
  while(1); // should never get here! todo: trap, log, hunk, etc.
}

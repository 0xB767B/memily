extern "C" int main()
{
  static int foo;
  foo = 2;
  while(1) {
	foo *= foo;
  }
}

extern "C" int main()
{
	static volatile int foo = 2;
	while(1) {
		foo *= foo;
	}
}

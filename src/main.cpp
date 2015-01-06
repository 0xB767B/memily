extern "C" int main()
{
	static volatile int foo = 0;
	while(1) {
		foo++;
	}
}

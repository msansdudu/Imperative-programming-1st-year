#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Compiler: ");
	
	#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
	printf("GCC\n");
	#else
	#if defined (__TINYC__)
	printf("TCC\n");	
	#else
	printf("clang\n");
	#endif
	#endif
	
	printf("Bitness: ");
	
	#if __x86_64__
	printf("64\n");
	#else
	printf("32\n");
	#endif
	
	printf("Asserts: ");
	
	#if NDEBUG
	printf("disabled");
	#else
	printf("enabled");
	#endif
	return 0;
}


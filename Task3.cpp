#include <iostream>
#pragma warning( disable : 4731 )
//ñèììåòðè÷íîñòü ÷èñëà
using namespace std;

void test(int a)
{
	int result = 1;
	int t = 2;
	int d = 10;
	__asm
	{
		mov eax, a
		xor ecx, ecx
		mov ebx, d
	count_digits_and_making_stack :
		
		cmp eax, 0
		je beg
		cdq
		div ebx
		inc ecx
		push edx
		jmp count_digits_and_making_stack
	beg :
		mov eax, a
		
	is_symm :
		mov ebx, d
		cdq
		div ebx
		xor ebx, ebx
		pop ebx
		cmp edx, ebx
		jne not_symm
	is_symm2:
		loop is_symm
		jmp end_
	not_symm :
		mov result, 0
		jmp is_symm2
	end_ :

	}
		if (result != 0)
			cout << "Number " << a << " is symmetric :)" << endl;
		else
			cout << "Number " << a << " is not symmetric :(" << endl;
}

int main()
{
	test(1234321);
	test(123321);
	test(1221);
	test(12345678);
	test(1488);
	test(228);
	test(1337);

	return 0;
}

#include <iostream>
//подсчет четных чисел
using namespace std;

void test(int a)
{
	int result=0;
	__asm
	{
		mov eax, a
		mov esp, 0
	beg:
		cmp eax, 0
		je end_
		cdq
		mov ecx, 10
		div ecx
		mov ebx, eax 
		mov eax, edx
		cdq
		mov ecx, 2
		div ecx
		cmp edx, 0
		jnz end_cycle
		inc esp
	end_cycle:
		mov eax, ebx
		jmp beg
	end_:
		mov result, esp
	};
	cout << endl << "There are " << result << " even digits in this a" << endl;
}

int main()
{
	test(12345678);
	test(1488);
	test(228);
	test(1337);
	test(2);
	return 0;
}
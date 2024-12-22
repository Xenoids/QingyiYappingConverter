#include <stdio.h>
#include <windows.h>

int convert_yapping(int angka_input, int remainder, int base, int dec);

int main()
{
	int N;
	int angka_input = 0; 
	int binary, dec = 0;
	int base = 1;
	int remainder;
	
	// container untuk mengambil semua char digabung jadi 1 string / kata
	char yapping_container[50];
	
	SetConsoleTitle("Program QingYi Yapping");
	
	puts("=============PROGRAM PENERJEMAH YAPPING QINGYI===========");
	puts("Masukkin jumlah input : ");
	printf(">>");
	scanf("%d",&N);
	getchar();
	puts("");
	
	for(int i = 0;i<N;i++)
	{
		angka_input = 0;
		dec = 0;
		remainder = 0;
		
		puts("Masukkin Yappingan QingYi [angka gajelas] :");
		printf(">>");
		scanf("%d",&angka_input);
		getchar();
		puts("");

		binary = angka_input;
		dec = convert_yapping(angka_input, remainder, base, dec);
		
		printf("Asal Yappingnya : %d\n",binary); // harus 8 digit!
		printf("Artinya huruf yappingnya : %c\n",dec);
		puts("");
		yapping_container[i] = (char)dec;
	}
	
	printf("Yang dimaksud dari Yappingnya QingYi adalah %s\n",yapping_container);
	
	system("pause");
	
	return 0;
}

int convert_yapping(int angka_input, int remainder, int base, int dec)
{
	while(angka_input > 0)
	{								  
		remainder = angka_input % 10; // 1001 % 10 = 1 | 100 % 10 = 0 | 10 % 10 = 0 | 1 % 10 = 1           || Remainder
		dec += remainder * base; // 0 + 1 * 1 = 1 | 1 + 0 * 2 = 1 | 1 + 0 * 4 = 1 | 1 + 1 * 8 = 9 (output) || Decimal
		angka_input /= 10; // 1001 / 10 = 100 | 100 / 10 = 10 | 10 / 10 = 1 | 1 / 10 = 0 		           || angka_input
		base *= 2; // 1 * 2 = 2 | 2 * 2 = 4 | 4 * 2 = 8 | 8 * 2 = 16					                   || Base binary
	}
	return dec;
}



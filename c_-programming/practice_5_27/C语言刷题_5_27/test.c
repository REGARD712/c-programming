#define _CRT_SECURE_NO_WARNINGS

// 1.Ê±¼ä×ª»»
#include <stdio.h>

int main()
{
	int input = 0;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	scanf("%d", &input);
	
	hours = input / 3600;
	minutes = input / 60 % 60;
	seconds = input % 60;
	printf("%d %d %d\n", hours, minutes, seconds);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//// 清空输入缓冲区函数
//void clear_stdin()
//{
//	int c;
//	while ((c = getchar()) != '\n' && c != EOF);
//}
//
//int main()
//{
//	int num = 0;
//	char ch;
//	scanf("%d", &num);		// 123a
//	clear_stdin();
//	scanf("%c", &ch);
//	clear_stdin();
//	printf("num = %d, ch = %c\n", num, ch);
//	// scanf会直接读取剩余的字符'a'放入变量'ch'
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int term = 1;
//	int sum = 0;
//	for(i = 1; i <= n; i++)
//	{
//		term *= i;
//		printf("%d! = %d\n", i, term);
//		sum += term;
//	}
//	printf("sum = %d\n", sum);
//
//	return 0;
//}

// 常见的时间复杂度：
// O(N^2)  O(N)  O(logN)  O(1)

#define _CRT_SECURE_NO_WARNINGS

// 输出十进制整数1234对应的八进制和十六进制（字母大写），
// 用空格分开，并且要求，在八进制前显示前导0，在十六进制数前显示前导0X

// printf可以使用格式控制串“%o”、“%X”分别输出八进制整数和十六进制整数，
// 并使用修饰符“#”控制前导显示

//#include<stdio.h>
//
//int main()
//{
//	printf("%#o ", 1234);
//	printf("%#X", 1234);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    char a;
//    while (scanf("%c", &a) == 1)
//    {
//        //getchar();    // 吸收换行符\n
//        if (a >= 'A' && a <= 'Z')
//        {
//            printf("%c\n", a + 32);
//        }
//        else
//        {
//            printf("%c\n", a - 32);
//        }
//    }
//    return 0;
//}

// 输出十六进制整数ABCDEF转十进制后的数，所占域宽为15
//#include<stdio.h>
//
//int main()
//{
//	printf("%15d\n", 0xABCDEF);
//
//	return 0;
//}

// printf函数的返回值是打印的字符的个数
//#include<stdio.h>
//
//int main()
//{
//	int n = printf("Hello World!\n");
//	printf("%d\n", n);// 13
//
//	return 0;
//}

// 判断字母
//# include<stdio.h>
//# include<ctype.h>
//
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (isalpha(ch))
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//		getchar();	// 吸收\n
//	}
//
//	return 0;
//}

// 打印用*组成的金字塔图案

//#include <stdio.h>
//
//int main() {
//    int n = 0;
//    int i, j, k;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 1; i <= n; i++)    // 控制金字塔行数
//        {
//            for (j = 1; j <= n - i; j++)    // 控制空格数量
//            {
//                printf(" ");
//            }
//            for (k = 1; k <= i; k++)        // 控制*的数量
//            {
//                printf("* ");
//            }
//            printf("\n");           // 打印完一行换行
//        }
//    }
//
//    return 0;
//}


// 输出用“*”组成的X形图案。

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int i, j;        // 二维数组行、列数
//    while (scanf("%d", &n) != EOF) { // 注意 while 处理多个 case
//        for (i = 0; i < n; i++)      // 控制行数
//        {
//            for (j = 0; j < n; j++)  // 控制列数
//            {
//                if (i == j || (i + j) == n - 1)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf(" ");
//                }
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n = 0;
//    int i, j;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 0; i < n; i++)  // 控制行数
//        {
//            for (j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1)
//                {
//                    printf("* ");
//                }
//                else if (j == 0 || j == n - 1)
//                {
//                    printf("* ");
//                }
//                else {
//                    printf("  ");
//                }
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int a[10] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//		sum += a[i];
//	}
//	printf("%.2lf\n",(double) sum / 10.0);
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int b[10] = { 11,12,13,14,15,16,17,18,19,20 };
//	int temp[10] = { 0 };	// 临时存放
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//		if (i == 9)
//			printf("\n");
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", b[i]);
//		if (i == 9)
//			printf("\n");
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		temp[i] = b[i];
//		b[i] = a[i];
//		a[i] = temp[i];
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//		if (i == 9)
//			printf("\n");
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", b[i]);
//		if (i == 9)
//			printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<Windows.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a1[] = "Welcome!!!";
//	char a2[] = "**********";
//
//	int left = 0;
//	int right = sizeof(a1) / sizeof(a1[0]) - 2;
//
//	printf("%s\n", a2);
//	while (left <= right)
//	{
//		Sleep(1000);
//		system("cls");
//		a2[left] = a1[left];
//		a2[right] = a1[right];
//		left++;
//		right--;
//		printf("%s\n", a2);
//	}
//
//	return 0;
//}

// 二分查找
//#include<stdio.h>
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = 0;
//
//	scanf("%d", &num);
//	int left = 0;
//	int right = sizeof(a) / sizeof(a[0]) - 1;
//	int flag = 0;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] > num)
//		{
//			right = mid - 1;
//		}
//		else if (a[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}

//#include<stdio.h>
//
//int Add(int x, int y)
//{
//	return  x + y;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int sum = 0;
//	sum = Add(a, b);
//	printf("sum = %d\n", sum);
//
//	return 0;
//}



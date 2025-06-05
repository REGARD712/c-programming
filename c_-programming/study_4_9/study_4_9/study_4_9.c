#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//// 占位符
//int main()
//{
//	//int a = 0;
//	//scanf("%d", &a);
//	//int b = a - 5;
//	//printf("%d\n", b);
//	//
//	// 格式化输出：
//	// %[]表示方括号中指定一组匹配的字符（如%[0-9]）遇到不在集合中的字符时匹配会自动停止
//	// %c不会忽略空白字符，只返回读取的第一个字符
//	// 若要跳过读取的空白字符，可写成scanf（"% c",&ch)
//
//	//char s[20] = { 0 };
//	//scanf("%6s", s);    // 用指定宽度限制scanf读取的字符串长度
//	//printf("%s\n",s);
//
//	// 赋值忽略符：*
//	//int year = 0, month = 0, date = 0;
//	//scanf("%d %*c %d %*c %d", &year, &month, &date);
//	//// 读取到的忽略符将不会返回值，会被丢弃
//	//printf("%d %d %d\n", year, month, date);
//
//	return 0;
//}

// 分支结构(if...else...)
//int main()
//{
//	//// 判断所输入的数是否为奇数
//	//int num = 0;
//	//scanf("%d", &num);
//	//if (num % 2 == 1) 
//	//{
//	//	printf("%d是奇数\n", num);
//	//}
//	//else
//	//{
//	//	printf("%d是偶数\n", num);
//	//}
//
//	//// 判断是否成年
//	//int age = 0;
//	//scanf("%d", &age);
//	//if (age >= 18)
//	//{
//	//	printf("已成年\n");
//	//	printf("可以谈恋爱了\n");
//	//}
//	//else
//	//{
//	//	printf("未成年\n");
//	//	printf("不可以早恋哦\n");
//	//}
//
//	// 嵌套if...else if...else...
//	//int num = 0;
//	//scanf("%d", &num);
//	//if (num == 0)
//	//{
//	//	printf("输入的数字是0\n");
//	//}
//	//else if(num > 0)
//	//{
//	//	printf("输入的数字是正数\n");
//	//}
//	//else
//	//{
//	//	printf("输入的数字是负数\n");
//	//}
//
//	//int num = 0;
//	//scanf("%d", &num);
//	//if (num > 0)
//	//{
//	//	if (num % 2 == 1)
//	//	{
//	//		printf("是奇数\n");
//	//	}
//	//	else
//	//	{
//	//		printf("是偶数\n");
//	//	}
//	//}
//	//else
//	//{
//	//	printf("负数\n");
//	//}
//
//	//// 练习
//	//int age = 0;
//	//scanf("%d", &age);
//	//if (age < 18)
//	//{
//	//	printf("少年\n");
//	//}
//	//else if (age <= 44)
//	//{
//	//	printf("青年\n");
//	//}
//	//else if(age <= 59)
//	//{
//	//	printf("中老年\n");
//	//}
//	//else if (age <= 89)
//	//{
//	//	printf("老年\n");
//	//}
//	//else
//	//{
//	//	printf("老寿星\n");
//	//}
//
//	//// else总是跟最近的if相匹配
//	//例如：
//	//int a = 0;
//	//int b = 2;
//	//if (a == 1)
//	//	if (b == 2)
//	//		printf("hehe\n");
//	//else
//	//	printf("haha\n");
//	//// 运行结果是：什么也不输出
//	
//	return 0;
//}

// 关系操作符
//int main()
//{
//	//// i < j < k
//	//// 程序会认为：（i < j）< k
//	//int i = 0;
//	//int j = 1;
//	//int k = 1;
//
//	//printf("%d\n", i < j < k);
//	//// 输出为：1或0
//
//	//// 比较是否相等时（变量和常量），建议将常量放在‘==’的左边，以防出错而不自知
//	//int a = 10;
//	//if (5 == a)
//	//{
//	//	printf("good\n");
//	//}
//	//else
//	//{
//	//	printf("no\n");
//	//}
//
//
//
//	return 0;
//}

//写一个代码打印1-100之间所有3的倍数的数字
//int main()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}

//写代码将三个整数数按从大到小输出。
//输入：2 3 1
//输出：3 2 1
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int temp = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		temp = a;
//		a = b;
//		b = temp;
//		if (a < c)
//		{
//			temp = a;
//			a = c;
//			c = temp;
//		}
//	}
//	else if(a < c)
//	{
//		temp = a;
//		a = c;
//		c = temp;
//		if (a < b)
//		{
//			temp = a;
//			a = b;
//			b = temp;
//		}
//	}
//	else
//	{
//		if (b < c)
//		{
//			temp = b;
//			b = c;
//			c = temp;
//		}
//	}
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}




#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//--a;a--
	//先减再使用；先使用再减

	//int a = -1;
	//int b = ++a;
	/*int c = a--;*/
	//int d = (a++) + (a++) + (a++);

	//printf("a = %d\n", a); 
	//printf("b = %d\n", b); 
	//printf("c = %d\n", c); 
	//printf("d = %d\n", d);
	
	//+,-号运算符
	/*printf("%d\n", +a);
	printf("%d\n", -a);*/

	// 强制类型转换
	/*int a = (int)3.14;
	printf("%d\n", a);*/

	//scanf和printf函数
	
	/*printf("%5d\n", 123456);*/
	
	//int ch = getchar();

	//printf("%c\n", ch);

	//putchar(ch);

	/*char s[20] = { 0 };

	scanf("%s", s);
	printf("%s\n", s);*/

	// 占位符

	/*printf("Zhangsan says it is 10 o'clock\n");
	printf("%s says it is %d o'clock\n","Zhangsan",10);*/

	// printf有n个占位符，其参数就有n+1个

	// %a为十六进制浮点数（打印小写）
	// %A为十六进制浮点数（打印大写）
	// %hd为短整型
	// %zd为size_t类型
	// %Lf为long double类型
	// %e为科学计数法
	
	//int n = -10;
	//printf("%d\n", n);

	//// 无符号整型不能赋负数
	//unsigned int m = -20;
	//printf("%u\n", m);


	//printf("%d\n", 123);
	//printf("%5d\n", 123);// 左边补空格，最少5位(右对齐)
	//printf("%5d\n", 123456);
	//printf("%-5d", 123);// 右边补空格，最少5位(左对齐)
	//printf(".\n");// 参考系

	/*printf("%f\n", 3.14);
	printf("%12f\n", 3.14);
	printf("%-12f", 3.14);
	printf(".\n");*/

	/*printf("%d\n", 2);
	printf("%d\n", -2);*/

	// 若想要显示正号，可以使用+号

	/*printf("%+d\n", 2);
	printf("%+d\n", -2);*/

	/*printf("%10.2f\n", 123.4567);
	printf("%*.*f\n", 10, 2, 123.4567);
	*/// 10和2作为'*'的参数

	//printf("%s\n","Hello,World");
	//printf("%.5s\n","Hello,World");// 只输出前五个字符
	
	//int i = 0;
	//int j = 0;
	//float x = 0.0f;
	//float y = 0.0f;
	//scanf("%d%d%f%f", &i, &j, &x, &y);
	//printf("i = %d\n",i);
	//printf("j = %d\n",j);
	//printf("x = %f\n",x);
	//printf("y = %f\n",y);
	// scanf函数输入数据时，
	// 会自动过滤空白字符：
	// 空格、tab键（制表符）、换行符
	// 
	// scanf处理用户输入的原理：
	// 用户输入的数据先放入缓存，
	// 按下回车键后按照占位符对缓存进行解读
	// 解读输入的字符时，将从上一次解读遗留的第一个字符开始
	// 直到读完缓存或遇到第一个不符合条件的字符为止
	
	//int x = 0;
	//float y = 0.0f;

	//// 用户输入"    -13.45e12# 0"
	//scanf("%d", &x);
	//printf("x = %d\n", x);
	//scanf("%f", &y);
	//printf("y = %f\n", y);

	// scanf的返回值是整型，表示成功读取的变量的个数，
	// 如果没有读取任何项或匹配失败(读取的数据类型和占位符不一致)，返回值为0，
	// 如果成功读取之前，
	// 发生了读取错误或读到了文件的末尾，返回常量EOF（-1）
	
	/*int a = 0, b = 0;
	float f = 0.0f;
	int r = scanf("%d%d%f", &a, &b, &f);
	printf("a = %d,b = %d,f = %f\n", a, b, f);
	printf("r = %d\n", r);*/

	// 按ctrl+z可让scanf不读取任何字符，最终返回EOF（-1）
	



	return 0;
}
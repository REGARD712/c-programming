#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>




//int main()
//{
//	printf("%c\n", '\'');
//	return 0;
//}


//int main()
//{
//	//printf("%s\n", "abcdef");
//	//printf("%s\n", "x");
//	//printf("%s\n", "\"");
//	//printf("''''\n");
//	//printf("%s\n", "''''");
//
//
//	return 0;
//}

//c:\test\test.c
//int main()
//{
//	//\t - tab
//	//printf("c:\\test\\test.c");
//	printf("a\tbc\tdef\tqqqq\twwwww\tx");
//
//	return 0;
//}


//int main()
//{
//	printf("\a");
//
//	return 0;
//}


//int main()
//{
//	printf("xxxx\b\by");
//	getchar();//“函数”，这个函数是用来在键盘上读取一个字符的
//	return 0;
//}


//int main()
//{
//	printf("abc\ndef\nqqqq");
//	return 0;
//}

//
//int main()
//{
//	printf("abc\rxyzqwe");
//	getchar();
//	return 0;
//}
//


//int main()
//{
//	printf("%c\n", '\130');
//	printf("%c\n", '\x33');
//
//	return 0;
//}
//

#include <string.h>

//int main()
//{
//	int len = strlen("abcdef");//strlen - string length - 统计字符串的长度
//	//strlen统计的是字符串中\0之前的字符个数
//	printf("%d\n", len);
//	return 0;
//}
//


//int main()
//{
//	int len = strlen("c:\test\198\abc\test.c");
//	printf("%d\n", len);
//	return 0;
//}


//int main()
//{
//	int len = strlen("c:\test\098\abc\test.c");
//	printf("%d\n", len);
//	return 0;
//}


//
//int main()
//{
//	;//空语句
//	printf("hehe");//调用了printf函数，就是函数调用语句
//	return 0;
//}
//

/*
C语言的注释风格：不支持嵌套注释
fun：函数的名字
参数:
x: xxxxxx
y: xxxxxx
返回值的类型：xxxxx
*/


//int fun(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	printf("hehe\n");/*调用printf函数，打印hehe在屏幕上*/
//
//	return 0;
//}


//int main()
//{
//	//int a = 10;
//	//写一个代码来完成加法操作
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	return 0;
//}
//
#include <stdbool.h>
//
//int main()
//{
//	//_Bool islike = false;
//	bool islike = false;
//	if (islike)
//		printf("I like C\n");
//	else
//		printf("I don't like C\n");
//
//	return 0;
//}
//


//sizeof 计算的值如果要打印的话，格式应该使用%zd
//单位是字节
//int main()
//{
//	//int a = 100;
//	//printf("%zd\n", sizeof(a));
//	//printf("%zd\n", sizeof a);
//
//	//printf("%zd\n", sizeof(3 + 5)); 
//	//printf("%zd\n", sizeof 3 + 5);//先计算3的长度是4，+5=9
//
//	////                    int  int
//	////                      int
//	//printf("%zd\n", sizeof(int));
//
//	//printf("%zd\n", sizeof(3 + 3.5));
//	//                    int  double
//	//                    4    8
//	//                      double
//	//                         8
//
//	printf("%zd\n", sizeof(bool));
//	printf("%zd\n", sizeof(char));
//	printf("%zd\n", sizeof(short));
//	printf("%zd\n", sizeof(int));
//	printf("%zd\n", sizeof(long));
//	printf("%zd\n", sizeof(long long));
//	printf("%zd\n", sizeof(float));
//	printf("%zd\n", sizeof(double));
//	printf("%zd\n", sizeof(long double));
//
//	return 0;
//}
//
//


//#include <stdio.h>
//int main()
//{
//    short s = 2;
//    int b = 10;
//
//    printf("%zd\n", sizeof(s = b   + 1));//2
//    //                         int   int
//    //                   short int
//    //                   short
//    printf("s = %d\n", s);//2
//    //
//    return 0;
//}
//
//int main()
//{
//	int _2b;//?
//	int char;//err
//	return 0;
//}

//
//int main()
//{
//	int age1;
//	int age = 10;//初始化
//	float score = 85.5f;
//	double num = 123.45;
//	char ch = 'w';
//
//	return 0;
//}


//int num2 = 200;//全局变量 - 共享单车
//
//int main()
//{
//	{
//		int num1 = 100;//局部变量 - 私家自行车
//		printf("%d\n", num1);
//	}
//	printf("%d\n", num2);
//
//	return 0;
//}


//int num1 = 200;//全局变量 - 共享单车
//
//int main()
//{
//	{
//		int num1 = 100;//局部变量 - 私家自行车
//		printf("%d\n", num1);
//	}
//
//	return 0;
//}
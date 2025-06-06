#define _CRT_SECURE_NO_WARNINGS

// 文件操作
//#include <stdio.h>
//
//int main()
//{                  //绝对路径         相对路径
//	FILE* pf = fopen("/*./../test.txt*/test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 文件的顺序读写：
// fputc函数：输出数据
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputc('a', pf);  //将数据写入文件流
//	fputc('a', stdout);  //将数据写入标准输出流（屏幕）：无需使用pf
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fgetc函数：读取数据
// 1.当调用时流已处于文件末尾，返回EOF并设置流的文件结束指示器（feof）
// 2.若发生读取错误，函数返回EOF并设置流的错误指示器（fperror）
// 
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//从文件流读取数据
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int ch = fgetc(pf);
//		fputc(ch, stdout);
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//从标准输入流读取数据（键盘）
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int ch = fgetc(stdin);
//		fputc(ch, stdout);
//	}
//
//	return 0;
//}
//
// feof和ferror：
//#include <stdio.h>
//int main()
//{
//	int feof(FILE * stream);  //检测指针所指向的流是否遇到文件末尾
//	int ferror(FILE * stream);	//检测指针所指向的流是否遇到读/写错误
//
//	return 0;
//}
//
// 检测feof
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int c = fgetc(pf);
//		if (c == EOF)
//		{
//			if (feof(pf))
//				printf("遇到文件末尾了\n");
//			else if (ferror(pf))
//				printf("读取发生了错误\n");
//		}
//		else
//		{
//			fputc(c, stdout);
//		}
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 检测ferror
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int c = fgetc(pf);
//	if (c == EOF)
//	{
//		if (feof(pf))
//			printf("遇到文件末尾了\n");
//		else if (ferror(pf))
//			printf("读取发生了错误\n");
//	}
//	else
//	{
//		fputc(c, stdout);
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fputs函数 ———— int fputs( const char* str, FILE * stream );
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abc\n", pf);
//	fputs("def", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fgets函数 ———— char * fgets( char * str, int num, FILE * stream );
//#include <stdio.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	char arr[20] = "xxxxxxxxxxxxxxx";
//	fgets(arr, 20, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fprintf函数
//#include <stdio.h>
//
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}Stu;
//
//int main()
//{
//	Stu s1 = { "Zhangsan", 20 };
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fprintf(pf, "%s %d", s1.name, s1.age);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fscanf函数
//#include <stdio.h>
//
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}Stu;
//
//int main()
//{
//	Stu s2 = { 0 };
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(stdin, "%s %d", s2.name, &(s2.age));
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
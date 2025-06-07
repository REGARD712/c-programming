#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 文件读写函数：fwrite函数和fread函数（以二进制形式）
//
// fwrite函数 ———— 用于将数据块以二进制形式写入文件指针指向的文件流中
// 返回值是实际写入的数据项的数量，若发生错误，可能比count小
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
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fwrite(&s1, sizeof(Stu), 2, pf);  //将结构体变量s1中的数据写入文件
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 例子：
//int main()
//{
//	int data[] = { 1,2,3,4,5 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	if (fwrite(data, sizeof(int), 5, pf) != 5)
//	{
//		perror("fwrite");
//		return -1;
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// fread函数 ———— 用于从文件指针所指向的文件流中读取数据块，将其存储到指针指向的内存缓冲区中
// 返回的是实际读取到的数据项的个数
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}Stu;
//
//int main()
//{
//	Stu s1 = { 0 };
//
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fread(&s1, sizeof(Stu), 2, pf);	 //从文件中读取数据存储到结构体变量s1中
//	printf("%s %d", s1.name, s1.age);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 例子：
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}Stu;
//
//int main()
//{
//	Stu s1 = { 0 };
//
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fread(&s1, sizeof(Stu), 2, pf);	 //从文件中读取数据存储到结构体变量s1中
//	size_t r = fread(&s1, sizeof(Stu), 2, pf);
//	if (r != 1)
//	{
//		if (feof(pf))
//			printf("文件遇到末尾了\n");
//		else if (ferror(pf))
//			printf("文件发生错误了\n");
//	}
//	else
//	{
//		printf("%s %d", s1.name, s1.age);
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

// sprintf函数和sscanf函数：
// 将格式化数据和字符串相互转换的函数
//
// 1.sprintf函数：格式化数据 ——> 字符串
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}stu;
//
//int main()
//{
//	char str[100] = { 0 };
// 
//	stu s1 = { "Zhangsan", 20 };
//	sprintf(str, "%s %d", s1.name, s1.age);  //将结构体变量s1中的数据先格式化再转化成字符串后存储到字符数组str中
//	printf("%s\n", str);
//
//	return 0;
//}
//
// 2.sscanf函数：字符串 ——> 格式化数据
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}stu;
//
//int main()
//{
//	char str[100] = { 0 };
//
//	stu s1 = { "Zhangsan", 20 };
//	sprintf(str, "%s %d", s1.name, s1.age);  //将结构体变量s1中的数据先格式化再转化成字符串后存储到字符数组str中
//	printf("%s\n", str);
//
//	stu s2 = { 0 };
//	sscanf(str, "%s %d", s2.name, &(s2.age));  //从字符数组str中获取字符串并转化成格式化数据后存储到结构体变量s2中
//	printf("%s %d\n", s2.name, s2.age);
//
//	return 0;
//}

// 文件的随机读写函数：
//
// 1.fseek函数:
// 读文件：
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");  //abcdefghi
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int c = fgetc(pf);
//	printf("%c\n", c);
//
//	//fseek(pf, 6, SEEK_SET);  //表示将文件光标从起始位置偏移6个后再操作
//	//fseek(pf, 6, SEEK_CUR);  //表示将文件光标从当前位置偏移6个后再操作
//	//fseek(pf, -1, SEEK_END);  //表示将文件光标从末尾位置偏移-1个后再操作
//
//	c = fgetc(pf);
//	printf("%c\n", c);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 写文件：
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");  //abcdefghi
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abcdefghi", pf);
//
//	fseek(pf, -3, SEEK_END);  //表示从文件末尾位置偏移-3个位置后再操作
//	fputc('x', pf);  //abcdefxhi
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 2.ftell函数：返回当前位置距离起始位置的偏移量
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");  //abcdefghi
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abcdefghi", pf);
//
//	fseek(pf, -3, SEEK_END);  //表示从文件末尾位置偏移-3个位置后再操作
//	fputc('x', pf);  //abcdefxhi
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);  //打印文件光标的偏移量
//
//	fseek(pf, 0, SEEK_END);  //将文件光标移动到文件末尾
//	ret = ftell(pf);
//	printf("文件中数据数量为：%d\n", ret);  //统计文件长度（数据量）
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
// 3.rewind函数：将文件指针重置到文件起始位置
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");  //abcdefghi
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abcdefghi", pf);
//
//	fseek(pf, -3, SEEK_END);  //表示从文件末尾位置偏移-3个位置后再操作
//	fputc('x', pf);  //abcdefxhi
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);  //打印文件光标的偏移量
//
//	fseek(pf, 0, SEEK_END);  //将文件光标移动到文件末尾
//	ret = ftell(pf);
//	printf("文件中数据数量为：%d\n", ret);  //统计文件长度（数据量）
//
//	rewind(pf);  //将文件指针重置到起始位置
//	ret = ftell(pf);
//	printf("目前文件指针的位置是：%d\n", ret);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

// 文件缓冲区函数：
//
// 1.fflush函数：强制刷新文件缓冲区将数据写入文件

// 更新文件操作：打开方式有"r+","w+"和"a+"三种
// 1.写完文件后，若想要继续读文件，需要先使用fflush函数刷新缓冲区；或者使用fseek函数和rewind函数重新定位文件指示器的位置
// 2.读完文件后，若想要继续写文件，需要先使用fseek函数和rewind函数重新定位文件指示器的位置
//int main()
//{
//	FILE* pf = fopen("data.txt", "w+");  //可读可写
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abcdef", pf);  //向文件中写入数据"abcdef"
//	fflush(pf);  //强制刷新文件缓冲区，将数据写入文件中
//	fseek(pf, 0, SEEK_SET);  //重置文件指示器到文件开头以便读取文件数据
//	//rewind(pf);  //也可以使用rewind函数重置指示器
//
//	int c = fgetc(pf);  //从文件中读取一个字符
//	printf("%c\n", c);  //打印读取的字符
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
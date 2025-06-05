#define _CRT_SECURE_NO_WARNINGS

// 笔试题

//#include <stdio.h>
//
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;
//
//	pa++;
//	printf("%s\n", *pa);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	
//	return 0;
//}

// 字符分类函数
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	int r = isdigit('3');
//	printf("%d\n", r);
//
//	return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//
//// 小写字母转为大写字母
//int main()
//{
//	char arr[] = "I Am a Chinese.";
//
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (islower(arr[i]))
//			arr[i] -= 32;
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}

//#include <stdio.h>

// strcpy函数的模拟实现
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//#include <assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;		// 返回目标空间的起始地址
//}
//
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[20] = "xxxxxxxxxxxxxxxxx";
//	
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest != '\0')
//		dest++;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = " world";
//
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    char* str4 = "hello bit.";
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//
//编写一个函数找出这两个只出现一次的数字。
// 
//例如：
//
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//
//只有5和6只出现1次，要找出5和6.
//
//#include <stdio.h>
//
//void FindNum(int arr[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	FindNum(arr, len);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int year = 0;
//    int month = 0;
//    int day = 0;
//
//    while (scanf("%d%d", &year, &month) == 2)
//    {
//        switch (month)
//        {
//        case 1:
//            day = 31;
//            break;
//        case 2:
//            //  判断平闰年确定2月天数
//            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//            {
//                // 闰年
//                day = 29;
//                break;
//            }
//            else {
//                day = 28;
//                break;
//            }
//        case 3:
//            day = 31;
//            break;
//        case 4:
//            day = 30;
//            break;
//        case 5:
//            day = 31;
//            break;
//        case 6:
//            day = 30;
//            break;
//        case 7:
//            day = 31;
//            break;
//        case 8:
//            day = 31;
//            break;
//        case 9:
//            day = 30;
//            break;
//        case 10:
//            day = 31;
//            break;
//        case 11:
//            day = 30;
//            break;
//        case 12:
//            day = 31;
//            break;
//        }
//        printf("%d\n", day);
//    }
//    return 0;
//}

//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//
//arr是一个整形一维数组。
//
//#include <stdio.h>
//
//void Print_arr(int (*parr)[10], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *((*parr) + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print_arr(&arr, len);
//
//	return 0;
//}

//实现一个对整形数组的冒泡排序
//
//#include <stdio.h>
//
//void Swap(int* x, int* y)
//{
//	int t = *x;
//	*x = *y;
//	*y = t;
//}
//
//void Bubblestone_sort(int arr[10], int len)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				Swap(&arr[j], &arr[j + 1]);
//		}
//	}
//}
//
//void Print_arr(int arr[10], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9,5,7,3,2,8,1,6,0,4 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print_arr(arr, len);
//	Bubblestone_sort(arr, len);
//	Print_arr(arr, len);
//
//	return 0;
//}
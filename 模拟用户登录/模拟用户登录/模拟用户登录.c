#define _CRT_SECURE_NO_WARNINGS 1

//编写程序模拟用户登录情景，只允许输入三次
//若输入的密码正确，则显示登陆成功；若三次均错误，则退出程序

#include<stdio.h>
#include<string.h>

int main()
{
	char passward[20] = { 0 };
	// 密码为：abcdef

	int i = 0;
	for (i = 0; i < 3; i++) {		// 只允许输入三次
		printf("请输入密码：");
		scanf("%s", passward);
		if (strcmp(passward, "abcdef") == 0) {
			// 进行字符串内容的比较，只能使用库函数strcmp()，返回值为0表示两个字符串相等
			printf("登陆成功！\n");
			break;
		}
		else {
			printf("密码错误，请重新输入！\n");
		}
	}
	if (i == 3) {
		printf("三次输入均错误，已退出程序。\n");
	}

	return 0;
}
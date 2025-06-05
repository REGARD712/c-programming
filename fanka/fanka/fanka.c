#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define y true
#define n false

struct card 
{
	char id[20];
	char name[20];
	double credit;
	bool check;
};

// 清空输入缓冲区函数
void clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
// 每次使用scanf函数输入数据之后调用该函数，清空输入缓冲区
// 以防止输入错误数据导致死循环

// 判断饭卡号是否重复函数
int Duplicate(FILE* pf, const char* id) 
{
	char d[20] = { 0 };  // 用于存放读取的饭卡号
	rewind(pf);  // 使文件指针指向文件开头
	while (fscanf(pf, "%s", d) != EOF) 
	{
		if (strcmp(d, id) == 0) 
		{
			return 1;  // 饭卡号重复
		}
		// 跳过姓名、金额、是否挂失
		fscanf(pf, "%*s,%*f,%*d");
	}
	return 0;  // 饭卡号不重复
}

void menu() 
{
	printf("\t......................................\n");
	printf("\t.          请输入选项编号(0~7):      .\n");
	printf("\t......................................\n");
	printf("\t.          1——建立饭卡文件           .\n");
	printf("\t.          2——买饭                   .\n");
	printf("\t.          3——续钱                   .\n");
	printf("\t.          4——添加新饭卡             .\n");
	printf("\t.          5——注销旧饭卡             .\n");
	printf("\t.          6——设置与解除挂失         .\n");
	printf("\t.          7——饭卡信息查询           .\n");
	printf("\t.          0——退出系统               .\n");
	printf("\t......................................\n");
}

void Establish() 
{
	struct card stu;

	FILE* pf;
	pf = fopen("card.dat", "a+");  // 追加写入 

	if (pf == NULL) 
	{     // 文件打开错误 
		perror("无法打开文件！\n");
		return;
	}

	while (1) 
	{	// 多次输入饭卡信息
		system("cls");

		printf("若返回，请输入‘#’；\n若不返回，请输入饭卡号："); 
		scanf("%s", stu.id);
		clear_stdin();  // 清空输入缓冲区
		if (strcmp(stu.id, "#") == 0) 
		{ // 输入#返回菜单界面
			break;
		}
		// 判断饭卡号是否重复
		if (Duplicate(pf, stu.id)) 
		{
			printf("饭卡号重复，请重新输入。\n");
			system("pause");
			continue;
		}
		fprintf(pf, "%s ", stu.id);// 将饭卡号写入文件

		printf("请输入姓名："); scanf("%s", stu.name);
		clear_stdin();  // 清空输入缓冲区
		fprintf(pf, "%s ", stu.name);// 将姓名写入文件

		printf("请输入金额："); 
		while (scanf("%lf", &stu.credit) != 1 || stu.credit < 0)
		{  // 检查输入是否有效
			printf("输入无效，请输入一个有效的金额：");
			clear_stdin();  // 清空缓冲区
		}
		clear_stdin();  // 清空缓冲区
		fprintf(pf, "%.2lf ", stu.credit);// 将金额写入文件

		printf("请输入是否挂失（y/n）："); 
		char check_input;  // 用于存放输入的字符
		// 检查输入是否有效
		while (scanf("%c", &check_input) != 1 || (check_input != 'y' && check_input != 'n')) 
		{
			printf("输入无效，请输入y或n：");
			clear_stdin();  // 清空缓冲区
		}
		clear_stdin();  // 清空缓冲区
		stu.check = (check_input == 'y') ? y : n;// 将输入的字符转换为bool类型
		fprintf(pf, "%d ", stu.check);  // 将bool类型转换为整型写入文件

		fprintf(pf, "\n");  // 换行
	}
	
	fclose(pf);  // 关闭文件
	pf = NULL;  // 防止野指针
}

void Consume()
{
	struct card stu;
	FILE* pf;
	FILE* temp;  // 临时文件，用于存储更新后的数据

	pf = fopen("card.dat", "r");  // 只读模式打开原文件
	if (pf == NULL)
	{
		perror("无法打开文件！\n");
		return;
	}

	temp = fopen("temp.dat", "w");  // 写模式打开临时文件
	if (temp == NULL)
	{
		perror("无法创建临时文件！\n");
		fclose(pf);
		return;
	}

	char id_input[20] = { 0 };  // 用于存放输入的饭卡号
	double money = 0.0;         // 用于存放输入的消费金额
	bool found = n;             // 标记是否找到目标饭卡
	bool transaction_done = n;  // 标记是否完成消费

	// 清空屏幕并显示提示信息
	system("cls");
	printf("若返回，请输入‘#’；\n若不返回，请输入饭卡号：");
	scanf("%s", id_input);
	clear_stdin();  // 清空输入缓冲区
	if (strcmp(id_input, "#") == 0)
	{
		fclose(pf);
		fclose(temp);
		remove("temp.dat");  // 删除临时文件
		return;
	}

	rewind(pf);  // 重置文件指针到文件开头

	while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
	{
		if (strcmp(stu.id, id_input) == 0 && !transaction_done)
		{
			found = y;

			if (stu.check == 1)
			{
				printf("本卡已冻结！\n");
			}
			else if (stu.credit < 5)
			{
				printf("余额不够，请续钱！\n");
			}
			else
			{
				printf("您的饭卡余额是：%.2lf\n", stu.credit);
				printf("请输入消费的金额：");
				while (scanf("%lf", &money) != 1)
				{
					printf("输入无效，请重新输入：");
					clear_stdin();  // 清空输入缓冲区
				}
				clear_stdin();  // 清空输入缓冲区

				if (money > stu.credit)
				{
					printf("余额不足，无法完成消费！\n");
				}
				else
				{
					stu.credit -= money;  // 扣除消费金额
					printf("消费成功！您的帐户余额是：%.2lf\n", stu.credit);
				}
			}
			transaction_done = y;  // 标记消费完成
		}

		// 将当前记录写入临时文件
		fprintf(temp, "%s %s %.2lf %d\n", stu.id, stu.name, stu.credit, stu.check);
	}

	if (!found)
	{
		printf("饭卡号不存在，请重新输入！\n");
	}

	fclose(pf);
	fclose(temp);

	// 用临时文件替换原文件
	remove("card.dat");
	rename("temp.dat", "card.dat");
}

void Charge()
{
	struct card stu;
	FILE* pf;
	FILE* temp;  // 临时文件，用于存储更新后的数据

	pf = fopen("card.dat", "r");  // 只读模式打开原文件
	if (pf == NULL)
	{
		perror("无法打开文件！\n");
		return;
	}

	temp = fopen("temp.dat", "w");  // 写模式打开临时文件
	if (temp == NULL)
	{
		perror("无法创建临时文件！\n");
		fclose(pf);
		return;
	}

	char id_input[20] = { 0 };  // 用于存放输入的饭卡号
	double charge_amount = 0.0; // 用于存放续钱金额
	bool found = n;             // 标记是否找到目标饭卡

	// 清空屏幕并显示提示信息
	system("cls");
	printf("若返回，请输入‘#’；\n若不返回，请输入饭卡号：");
	scanf("%s", id_input);
	clear_stdin();  // 清空输入缓冲区
	if (strcmp(id_input, "#") == 0)
	{
		fclose(pf);
		fclose(temp);
		remove("temp.dat");  // 删除临时文件
		return;
	}

	rewind(pf);  // 重置文件指针到文件开头

	while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
	{
		if (strcmp(stu.id, id_input) == 0)
		{
			found = y;
			
			if (stu.check == 1)
			{
				printf("本卡已冻结，无法续钱！\n");
				break;
			}

			printf("当前余额为：%.2lf\n", stu.credit);
			printf("请输入续钱金额：");
			while (scanf("%lf", &charge_amount) != 1 || charge_amount <= 0)
			{
				printf("输入无效，请输入一个大于0的整数：");
				clear_stdin();  // 清空输入缓冲区
			}
			clear_stdin();  // 清空输入缓冲区

			double old_credit = stu.credit;  // 保存续钱前的余额
			stu.credit += charge_amount;    // 更新余额

			printf("续钱成功！\n");
			printf("续钱前余额：%.2lf\n", old_credit);
			printf("续钱后余额：%.2lf\n", stu.credit);
		}

		// 将当前记录写入临时文件
		fprintf(temp, "%s %s %.2lf %d\n", stu.id, stu.name, stu.credit, stu.check);
	}

	if (!found)
	{
		printf("饭卡号不存在，请重新输入！\n");
	}

	fclose(pf);
	fclose(temp);

	// 用临时文件替换原文件
	remove("card.dat");
	rename("temp.dat", "card.dat");
}

void Add()
{
	struct card stu;
	FILE* pf;

	pf = fopen("card.dat", "a+");  // 追加写入模式打开文件
	if (pf == NULL)
	{
		perror("无法打开文件！\n");
		return;
	}

	while (1)
	{
		// 清空屏幕并显示提示信息
		system("cls");
		printf("若返回，请输入‘#’；\n若不返回，请输入新饭卡号：");
		scanf("%s", stu.id);
		clear_stdin();  // 清空输入缓冲区

		// 检查是否输入了返回标志
		if (strcmp(stu.id, "#") == 0)
		{
			break;
		}

		// 检查饭卡号是否重复
		FILE* check_pf = fopen("card.dat", "r");  // 只读模式打开文件用于检查
		if (check_pf == NULL)
		{
			perror("无法打开文件！\n");
			fclose(pf);
			return;
		}

		if (Duplicate(check_pf, stu.id))
		{
			printf("饭卡号重复，请重新输入！\n");
			system("pause");
			fclose(check_pf);
			continue;
		}
		fclose(check_pf);

		// 输入新饭卡的其他信息
		printf("请输入姓名：");
		scanf("%s", stu.name);
		clear_stdin();  // 清空输入缓冲区

		printf("请输入初始金额：");
		while (scanf("%lf", &stu.credit) != 1 || stu.credit < 0)
		{
			printf("输入无效，请输入一个非负金额：");
			clear_stdin();  // 清空输入缓冲区
		}
		clear_stdin();  // 清空输入缓冲区

		printf("请输入是否挂失（y/n）：");
		char check_input;
		while (scanf("%c", &check_input) != 1 || (check_input != 'y' && check_input != 'n'))
		{
			printf("输入无效，请输入y或n：");
			clear_stdin();  // 清空输入缓冲区
		}
		clear_stdin();  // 清空输入缓冲区
		stu.check = (check_input == 'y') ? y : n;

		// 将新饭卡信息写入文件
		fprintf(pf, "%s %s %.2lf %d\n", stu.id, stu.name, stu.credit, stu.check);
		fflush(pf);  // 刷新文件缓冲区，确保数据写入磁盘
		printf("新饭卡添加成功！\n");
		system("pause");
	}

	fclose(pf);  // 关闭文件
}

void Delete()
{
	struct card stu;
	FILE* pf;
	FILE* temp;  // 临时文件，用于存储更新后的数据

	pf = fopen("card.dat", "r");  // 只读模式打开原文件
	if (pf == NULL)
	{
		perror("无法打开文件！\n");
		return;
	}

	temp = fopen("temp.dat", "w");  // 写模式打开临时文件
	if (temp == NULL)
	{
		perror("无法创建临时文件！\n");
		fclose(pf);
		return;
	}

	char id_input[20] = { 0 };  // 用于存放输入的饭卡号
	bool found = n;             // 标记是否找到目标饭卡

	// 清空屏幕并显示提示信息
	system("cls");
	printf("若返回，请输入‘#’；\n若不返回，请输入要注销的饭卡号：");
	scanf("%s", id_input);
	clear_stdin();  // 清空输入缓冲区
	if (strcmp(id_input, "#") == 0)
	{
		fclose(pf);
		fclose(temp);
		remove("temp.dat");  // 删除临时文件
		return;
	}

	rewind(pf);  // 重置文件指针到文件开头

	while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
	{
		if (strcmp(stu.id, id_input) == 0)
		{
			found = y;
			printf("饭卡号 %s 已成功注销！\n", stu.id);
			continue;  // 跳过当前记录，不写入临时文件
		}

		// 将未被注销的记录写入临时文件
		fprintf(temp, "%s %s %.2lf %d\n", stu.id, stu.name, stu.credit, stu.check);
	}

	if (!found)
	{
		printf("饭卡号不存在，请重新输入！\n");
	}

	fclose(pf);
	fclose(temp);

	// 用临时文件替换原文件
	remove("card.dat");
	rename("temp.dat", "card.dat");
}

void Set()
{
	struct card stu;
	FILE* pf;
	FILE* temp;  // 临时文件，用于存储更新后的数据

	pf = fopen("card.dat", "r");  // 只读模式打开原文件
	if (pf == NULL)
	{
		perror("无法打开文件！\n");
		return;
	}

	temp = fopen("temp.dat", "w");  // 写模式打开临时文件
	if (temp == NULL)
	{
		perror("无法创建临时文件！\n");
		fclose(pf);
		return;
	}

	char id_input[20] = { 0 };  // 用于存放输入的饭卡号
	char loss_status;           // 用于存放挂失信息
	bool found = n;             // 标记是否找到目标饭卡

	// 清空屏幕并显示提示信息
	system("cls");
	printf("若返回，请输入‘#’；\n若不返回，请输入饭卡号：");
	scanf("%s", id_input);
	clear_stdin();  // 清空输入缓冲区
	if (strcmp(id_input, "#") == 0)
	{
		fclose(pf);
		fclose(temp);
		remove("temp.dat");  // 删除临时文件
		return;
	}

	rewind(pf);  // 重置文件指针到文件开头

	while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
	{
		if (strcmp(stu.id, id_input) == 0)
		{
			found = y;

			printf("当前挂失状态为：%s\n", stu.check ? "挂失" : "未挂失");
			printf("请输入新的挂失状态（y/n）：");
			while (scanf("%c", &loss_status) != 1 || (loss_status != 'y' && loss_status != 'n'))
			{
				printf("输入无效，请输入y或n：");
				clear_stdin();  // 清空输入缓冲区
			}
			clear_stdin();  // 清空输入缓冲区

			stu.check = (loss_status == 'y') ? y : n;  // 更新挂失状态
			printf("挂失状态更新成功！\n");
		}

		// 将当前记录写入临时文件
		fprintf(temp, "%s %s %.2lf %d\n", stu.id, stu.name, stu.credit, stu.check);
	}

	if (!found)
	{
		printf("饭卡号不存在，请重新输入！\n");
	}

	fclose(pf);
	fclose(temp);

	// 用临时文件替换原文件
	remove("card.dat");
	rename("temp.dat", "card.dat");
}

void Information()
{
	struct card stu;
	FILE* pf;

	int choice = 0;

	while (1)
	{
		// 清空屏幕并显示创新功能菜单
		system("cls");
		printf("\t......................................\n");
		printf("\t.          信息功能菜单              .\n");
		printf("\t......................................\n");
		printf("\t.          1——查询饭卡信息           .\n");
		printf("\t.          2——统计饭卡数据           .\n");
		printf("\t.          0——返回主菜单             .\n");
		printf("\t......................................\n");
		printf("请选择：");
		scanf("%d", &choice);
		clear_stdin();  // 清空输入缓冲区

		if (choice == 0)
		{
			break;  // 返回主菜单
		}

		switch (choice)
		{
		case 1:  // 查询饭卡信息
			pf = fopen("card.dat", "r");
			if (pf == NULL)
			{
				perror("无法打开文件！\n");
				system("pause");
				break;
			}

			char id_input[20];
			bool found = n;

			printf("请输入要查询的饭卡号：");
			scanf("%s", id_input);
			clear_stdin();  // 清空输入缓冲区

			while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
			{
				if (strcmp(stu.id, id_input) == 0)
				{
					found = y;
					printf("\n饭卡信息如下：\n");
					printf("饭卡号：%s\n", stu.id);
					printf("姓名：%s\n", stu.name);
					printf("余额：%.2lf\n", stu.credit);
					printf("挂失状态：%s\n", stu.check ? "挂失" : "未挂失");
					break;
				}
			}

			if (!found)
			{
				printf("未找到该饭卡号！\n");
			}

			fclose(pf);
			system("pause");
			break;

		case 2:  // 统计饭卡数据
			pf = fopen("card.dat", "r");
			if (pf == NULL)
			{
				perror("无法打开文件！\n");
				system("pause");
				break;
			}

			int total_cards = 0;
			int lost_cards = 0;
			double total_balance = 0.0;

			printf("\n文件中所有饭卡号、余额及挂失状态如下：\n");

			while (fscanf(pf, "%s %s %lf %d", stu.id, stu.name, &stu.credit, &stu.check) != EOF)
			{
				total_cards++;
				total_balance += stu.credit;
				if (stu.check)
				{
					lost_cards++;
				}

				// 输出当前饭卡号、余额及挂失状态
				printf("饭卡号：%s，余额：%.2lf，挂失状态：%s\n",
					stu.id,
					stu.credit,
					stu.check ? "挂失" : "未挂失");
			}

			printf("\n统计结果如下：\n");
			printf("总饭卡数量：%d\n", total_cards);
			printf("总余额：%.2lf\n", total_balance);
			printf("平均余额：%.2lf\n", total_cards > 0 ? total_balance / total_cards : 0.0);
			printf("挂失饭卡数量：%d\n", lost_cards);

			fclose(pf);
			system("pause");
			break;
		default:
			printf("输入无效，请重新输入。\n");
			system("pause");
			break;
		}
	}
}

int main()
{
	int input = 0;
	do 
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:
			Establish();
			break;
		case 2:
			Consume();
			break;
		case 3:
			Charge();
			break;
		case 4:
			Add();
			break;
		case 5:
			Delete();
			break;
		case 6:
			Set();
			break;
		case 7:
			Information();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入。\n");
			break;
		}
		if (input) 
		{
			system("pause");
		}
		system("cls");
	} while (input);
	printf("感谢使用本软件！已正常退出，按任意键结束！\n");

	return 0;
}

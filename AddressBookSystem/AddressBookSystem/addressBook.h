#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 64

/* 单个联系人数据 */
typedef struct Contact
{
    char name[MAXN];      /* 姓名 */
    char street[MAXN];    /* 街道 */
    char address[MAXN];   /* 城市 */
    char state[MAXN];     /* 国家 */
    char tel[32];         /* 电话 */
} Contact;

/* 链表节点（双向链表）*/
typedef struct Node
{
    Contact data;
    struct Node* pre;
    struct Node* next;
} Node;

/* 通讯录管理结构（保存头指针和数量）*/
typedef struct AddressBook
{
    Node* head;
    size_t count;
} AddressBook;

/* 函数声明 */
bool enter();      /* 交互式添加联系人 */
void display();    /* 显示所有联系人 */
Node* search();    /* 按照姓名查找信息 */
bool delete();     /* 删除信息 */
bool save();       /* 将信息存盘到指定文件，返回 success */
bool load();       /* 从指定文件装入信息，返回 success */


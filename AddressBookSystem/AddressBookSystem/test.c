#include "addressBook.h"

static AddressBook ab;

/* 菜单 */
void menu()
{
    printf("\t======  欢迎使用通讯录系统  ======\n");
    printf("\t====== 本通讯录系统菜单如下：======\n");
    printf("\t    1. 添加联系人\n");
    printf("\t    2. 显示所有联系人\n");
    printf("\t    3. 输入姓名查找联系人\n");
    printf("\t    4. 输入姓名删除联系人\n");
    printf("\t    5. 保存到文件\n");
    printf("\t    6. 从文件装入\n");
    printf("\t    0. 退出\n");
    printf("\t===================================\n");
    printf("\t请选择操作（输入数字并回车）：");
}

/* 清理输入缓冲区函数 */
void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* 简单合法性检查：非空（含非空白字符）、长度合规且不包含分隔符 '|' */
static bool isValid(const char* s, size_t maxlen)
{
    if (!s) return false;
    size_t len = strlen(s);
    if (len == 0 || len >= maxlen) return false;
    bool has_nonspace = false;
    for (size_t i = 0; i < len; ++i)
    {
        if (s[i] == '|') return false;
        if (!isspace((unsigned char)s[i])) has_nonspace = true;
    }
    return has_nonspace;
}

/* 将节点按姓名升序插入到全局 ab（双向链表）*/
static bool insert_contact_sorted(const Contact* nc)
{
    if (!nc) return false;
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return false;
    node->data = *nc;
    node->pre = node->next = NULL;

    if (!ab.head)
    {
        ab.head = node;
    }
    else
    {
        Node* cur = ab.head;
        Node* prev = NULL;
        while (cur && strcmp(cur->data.name, nc->name) < 0)
        {
            prev = cur;
            cur = cur->next;
        }

        if (!prev) // 插入表头
        {
            node->next = ab.head;
            ab.head->pre = node;
            ab.head = node;
        }
        else
        {
            node->next = prev->next;
            node->pre = prev;
            prev->next = node;
            if (node->next) node->next->pre = node;
        }
    }

    ab.count++;
    return true;
}

/* 新增联系人 */
bool enter(void)
{
    char buf_name[MAXN];
    char buf_street[MAXN];
    char buf_address[MAXN];
    char buf_state[MAXN];
    char buf_tel[32];
    char ans[8];

    size_t ln;

    for (;;) /* 外层循环：用于判重后从姓名重新输入 */
    {
        /* 姓名输入与确认（可 n 重输，输入 '#' 退出）*/
        for (;;)
        {
            printf("请输入新增的联系人的姓名（输入 '#' 取消）：");
            if (!fgets(buf_name, sizeof(buf_name), stdin)) { printf("输入错误！\n"); return false; }
            ln = strlen(buf_name);
            if (ln && (buf_name[ln - 1] == '\n' || buf_name[ln - 1] == '\r'))
            {
                while (ln && (buf_name[ln - 1] == '\n' || buf_name[ln - 1] == '\r')) buf_name[--ln] = '\0';
            }
            else
            {
                /* 输入超长，清空剩余输入行 */
                clear_stdin();
            }

            if (ln == 1 && buf_name[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }

            if (!isValid(buf_name, MAXN)) { printf("输入不合法！\n"); continue; }

            /* 确认（确认也支持输入 '#' 取消），现在只接受小写 y/n */
            for (;;)
            {
                printf("确认添加姓名 \"%s\" ? (y/n，或输入 '#' 取消)：", buf_name);
                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return false; }
                ln = strlen(ans);
                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
                {
                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
                }
                else
                {
                    clear_stdin();
                }
                if (ln == 1 && ans[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }
                if (ans[0] == 'y') break; /* 确认通过，进入下一个字段 */
                if (ans[0] == 'n') { printf("请重新输入姓名。\n"); break; /* 回到姓名重新输入 */ }
                printf("请输入小写 y 或 n（或 '#' 取消）。\n");
            }
            if (ans[0] == 'y') break; /* 跳出姓名输入循环 */
        }

        /* 街道输入与确认（可 n 重输，输入 '#' 退出）*/
        for (;;)
        {
            printf("请输入街道（输入 '#' 取消）：");
            if (!fgets(buf_street, sizeof(buf_street), stdin)) { printf("输入错误！\n"); return false; }
            ln = strlen(buf_street);
            if (ln && (buf_street[ln - 1] == '\n' || buf_street[ln - 1] == '\r'))
            {
                while (ln && (buf_street[ln - 1] == '\n' || buf_street[ln - 1] == '\r')) buf_street[--ln] = '\0';
            }
            else
            {
                clear_stdin();
            }

            if (ln == 1 && buf_street[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }

            if (!isValid(buf_street, MAXN)) { printf("输入不合法！\n"); continue; }

            for (;;)
            {
                printf("确认添加街道 \"%s\" ? (y/n，或输入 '#' 取消)：", buf_street);
                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return false; }
                ln = strlen(ans);
                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
                {
                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
                }
                else
                {
                    clear_stdin();
                }
                if (ln == 1 && ans[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }
                if (ans[0] == 'y') break;
                if (ans[0] == 'n') { printf("请重新输入街道。\n"); break; }
                printf("请输入小写 y 或 n（或 '#' 取消）。\n");
            }
            if (ans[0] == 'y') break;
        }

        /* 城市输入与确认（可 n 重输，输入 '#' 退出）*/
        for (;;)
        {
            printf("请输入城市（输入 '#' 取消）：");
            if (!fgets(buf_address, sizeof(buf_address), stdin)) { printf("输入错误！\n"); return false; }
            ln = strlen(buf_address);
            if (ln && (buf_address[ln - 1] == '\n' || buf_address[ln - 1] == '\r'))
            {
                while (ln && (buf_address[ln - 1] == '\n' || buf_address[ln - 1] == '\r')) buf_address[--ln] = '\0';
            }
            else
            {
                clear_stdin();
            }

            if (ln == 1 && buf_address[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }

            if (!isValid(buf_address, MAXN)) { printf("输入不合法！\n"); continue; }

            for (;;)
            {
                printf("确认添加城市 \"%s\" ? (y/n，或输入 '#' 取消)：", buf_address);
                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return false; }
                ln = strlen(ans);
                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
                {
                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
                }
                else
                {
                    clear_stdin();
                }
                if (ln == 1 && ans[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }
                if (ans[0] == 'y') break;
                if (ans[0] == 'n') { printf("请重新输入城市。\n"); break; }
                printf("请输入小写 y 或 n（或 '#' 取消）。\n");
            }
            if (ans[0] == 'y') break;
        }

        /* 国家/省份输入与确认（可 n 重输，输入 '#' 退出）*/
        for (;;)
        {
            printf("请输入国家/省份（输入 '#' 取消）：");
            if (!fgets(buf_state, sizeof(buf_state), stdin)) { printf("输入错误！\n"); return false; }
            ln = strlen(buf_state);
            if (ln && (buf_state[ln - 1] == '\n' || buf_state[ln - 1] == '\r'))
            {
                while (ln && (buf_state[ln - 1] == '\n' || buf_state[ln - 1] == '\r')) buf_state[--ln] = '\0';
            }
            else
            {
                clear_stdin();
            }

            if (ln == 1 && buf_state[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }

            if (!isValid(buf_state, MAXN)) { printf("输入不合法！\n"); continue; }

            for (;;)
            {
                printf("确认添加国家/省份 \"%s\" ? (y/n，或输入 '#' 取消)：", buf_state);
                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return false; }
                ln = strlen(ans);
                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
                {
                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
                }
                else
                {
                    clear_stdin();
                }
                if (ln == 1 && ans[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }
                if (ans[0] == 'y') break;
                if (ans[0] == 'n') { printf("请重新输入国家/省份。\n"); break; }
                printf("请输入小写 y 或 n（或 '#' 取消）。\n");
            }
            if (ans[0] == 'y') break;
        }

        /* 电话输入与确认（可 n 重输，输入 '#' 退出）*/
        for (;;)
        {
            printf("请输入电话号码（输入 '#' 取消）：");
            if (!fgets(buf_tel, sizeof(buf_tel), stdin)) { printf("输入错误！\n"); return false; }
            ln = strlen(buf_tel);
            if (ln && (buf_tel[ln - 1] == '\n' || buf_tel[ln - 1] == '\r'))
            {
                while (ln && (buf_tel[ln - 1] == '\n' || buf_tel[ln - 1] == '\r')) buf_tel[--ln] = '\0';
            }
            else
            {
                clear_stdin();
            }

            if (ln == 1 && buf_tel[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }

            if (!isValid(buf_tel, sizeof(buf_tel))) { printf("输入不合法！\n"); continue; }

            for (;;)
            {
                printf("确认添加电话号码 \"%s\" ? (y/n，或输入 '#' 取消)：", buf_tel);
                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return false; }
                ln = strlen(ans);
                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
                {
                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
                }
                else
                {
                    clear_stdin();
                }
                if (ln == 1 && ans[0] == '#') { printf("已取消添加，返回菜单。\n"); return false; }
                if (ans[0] == 'y') break;
                if (ans[0] == 'n') { printf("请重新输入电话号码。\n"); break; }
                printf("请输入小写 y 或 n（或 '#' 取消）。\n");
            }
            if (ans[0] == 'y') break;
        }

        /* 构建 Contact 并判重 */
        Contact nc;
        strncpy(nc.name, buf_name, MAXN); nc.name[MAXN - 1] = '\0';
        strncpy(nc.street, buf_street, MAXN); nc.street[MAXN - 1] = '\0';
        strncpy(nc.address, buf_address, MAXN); nc.address[MAXN - 1] = '\0';
        strncpy(nc.state, buf_state, MAXN); nc.state[MAXN - 1] = '\0';
        strncpy(nc.tel, buf_tel, sizeof(nc.tel)); nc.tel[sizeof(nc.tel) - 1] = '\0';

        /* 判重：全部字段相同即认为重复 */
        bool duplicate = false;
        Node* cur = ab.head;
        while (cur)
        {
            if (strcmp(cur->data.name, nc.name) == 0
                && strcmp(cur->data.street, nc.street) == 0
                && strcmp(cur->data.address, nc.address) == 0
                && strcmp(cur->data.state, nc.state) == 0
                && strcmp(cur->data.tel, nc.tel) == 0)
            {
                duplicate = true;
                break;
            }
            cur = cur->next;
        }

        if (duplicate)
        {
            printf("已存在该联系人，请重新输入！\n");
            /* 从姓名重新输入，继续外层循环 */
            continue;
        }

        if (!insert_contact_sorted(&nc))
        {
            printf("添加失败：内存分配错误或其他问题。\n");
            return false;
        }

        printf("联系人 \"%s\" 已添加。\n", nc.name);
        return true;
    }
}

/* 显示所有联系人 */
void display(void)
{
    if (!ab.head)
    {
        printf("当前没有联系人。\n");
        return;
    }

    Node* cur = ab.head;
    printf("共有 %zu 条联系人记录：\n", ab.count);
    while (cur)
    {
        Contact* c = &cur->data;
        printf("\t--------------------\n");
        printf("\t姓名: %s\n", c->name);
        printf("\t街道: %s\n", c->street);
        printf("\t城市: %s\n", c->address);
        printf("\t国家: %s\n", c->state);
        printf("\t电话: %s\n", c->tel);
        cur = cur->next;
    }
    printf("\t--------------------\n");
}


int main()
{
    /* 初始化全局通讯录 */
    ab.head = NULL;
    ab.count = 0;

    int input = 0;
    do
    {
        menu();
        if (scanf("%d", &input) != 1) { clear_stdin(); input = -1; }
        clear_stdin();
        switch (input)
        {
        case 1:
            enter();
            break;

        case 2:
            display();
            break;

        default:
            if (input != 0)
                printf("输入错误，请重新输入！\n");
            break;
        }

        if (input)
        {
            system("pause");
        }
        system("cls");
    } while (input);

    printf("感谢使用本系统，已正常退出，按任意键继续\n");
    return 0;
}


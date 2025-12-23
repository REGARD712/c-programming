//#include "addressBook.h"
//
//static AddressBook ab;
//
///* 辅助函数 */
///* 菜单 */
//void menu()
//{
//    printf("\t\t\t\t\t======  欢迎使用通讯录系统  =======\n");
//    printf("\t\t\t\t\t====== 本通讯录系统菜单如下：======\n");
//    printf("\t\t\t\t\t       1. 添加联系人\n");
//    printf("\t\t\t\t\t       2. 显示所有联系人\n");
//    printf("\t\t\t\t\t       3. 输入姓名查找联系人\n");
//    printf("\t\t\t\t\t       4. 输入姓名删除联系人\n");
//    printf("\t\t\t\t\t       5. 保存到文件\n");
//    printf("\t\t\t\t\t       6. 从文件装入\n");
//    printf("\t\t\t\t\t       0. 退出\n");
//    printf("\t\t\t\t\t===================================\n");
//    printf("\t\t\t\t\t请选择操作（输入数字并回车）：");
//}
//
///* 清理输入缓冲区函数 */
//void clear_stdin()
//{
//    int c;
//    while ((c = getchar()) != '\n' && c != EOF);
//}
//
///* 简单合法性检查：非空（含非空白字符）、长度合规且不包含分隔符 '|' */
//static bool isValid(const char* s, size_t maxlen)
//{
//    if (!s) return false;
//    size_t len = strlen(s);
//    if (len == 0 || len >= maxlen) return false;
//    bool has_nonspace = false;
//    for (size_t i = 0; i < len; ++i)
//    {
//        if (s[i] == '|') return false;
//        if (!isspace((unsigned char)s[i])) has_nonspace = true;
//    }
//    return has_nonspace;
//}
//
///* 将节点按姓名升序插入到全局 ab（双向链表）*/
//static bool insert_contact_sorted(const Contact* nc)
//{
//    if (!nc) return false;
//    Node* node = (Node*)malloc(sizeof(Node));
//    if (!node) return false;
//    node->data = *nc;
//    node->pre = node->next = NULL;
//
//    if (!ab.head)
//    {
//        ab.head = node;
//    }
//    else
//    {
//        Node* cur = ab.head;
//        Node* prev = NULL;
//        while (cur && strcmp(cur->data.name, nc->name) < 0)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//
//        if (!prev) // 插入表头
//        {
//            node->next = ab.head;
//            ab.head->pre = node;
//            ab.head = node;
//        }
//        else
//        {
//            node->next = prev->next;
//            node->pre = prev;
//            prev->next = node;
//            if (node->next) node->next->pre = node;
//        }
//    }
//
//    ab.count++;
//    return true;
//}
//
///* 新增联系人 */
//void enter()
//{
//    char buf_name[MAXN];
//    char buf_street[MAXN];
//    char buf_address[MAXN];
//    char buf_state[MAXN];
//    char buf_tel[32];
//    char ans[8];
//
//    size_t ln;
//
//    for (;;) /* 外层循环：用于判重后从姓名重新输入 */
//    {
//        /* 姓名输入与确认（输入 '#' 重新输入当前字段；输入 "-1" 返回菜单）*/
//        for (;;)
//        {
//            printf("请输入新增的联系人的姓名（输入 '#' 重新输入本字段，输入 -1 取消并返回菜单）：");
//            if (!fgets(buf_name, sizeof(buf_name), stdin)) { printf("输入错误！\n"); return; }
//            ln = strlen(buf_name);
//            if (ln && (buf_name[ln - 1] == '\n' || buf_name[ln - 1] == '\r'))
//            {
//                while (ln && (buf_name[ln - 1] == '\n' || buf_name[ln - 1] == '\r')) buf_name[--ln] = '\0';
//            }
//            else
//            {
//                /* 输入超长，清空剩余输入行 */
//                clear_stdin();
//            }
//
//            if (ln == 1 && buf_name[0] == '#') { printf("请重新输入姓名。\n"); continue; }
//            if (ln == 2 && buf_name[0] == '-' && buf_name[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//
//            if (!isValid(buf_name, MAXN)) { printf("输入不合法！\n"); continue; }
//
//            /* 确认（'#' 重新输入本字段；'-1' 取消并返回菜单），只接受小写 y/n */
//            for (;;)
//            {
//                printf("确认添加姓名 \"%s\" ? (y/n，'#' 重输本字段，输入 -1 取消并返回菜单)：", buf_name);
//                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return; }
//                ln = strlen(ans);
//                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
//                {
//                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
//                }
//                else
//                {
//                    clear_stdin();
//                }
//
//                if (ln == 1 && ans[0] == '#') { printf("请重新输入姓名。\n"); break; /* 回到姓名重新输入 */ }
//                if (ln == 2 && ans[0] == '-' && ans[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//                if (ans[0] == 'y') break; /* 确认通过，进入下一个字段 */
//                if (ans[0] == 'n') { printf("请重新输入姓名。\n"); break; /* 回到姓名重新输入 */ }
//                printf("请输入小写 y 或 n（或 '#' 重输本字段，输入 -1 取消）。\n");
//            }
//            if (ans[0] == 'y') break; /* 跳出姓名输入循环 */
//        }
//
//        /* 街道输入与确认（输入 '#' 重新输入本字段；输入 -1 返回菜单）*/
//        for (;;)
//        {
//            printf("请输入街道（输入 '#' 重新输入本字段，输入 -1 取消并返回菜单）：");
//            if (!fgets(buf_street, sizeof(buf_street), stdin)) { printf("输入错误！\n"); return; }
//            ln = strlen(buf_street);
//            if (ln && (buf_street[ln - 1] == '\n' || buf_street[ln - 1] == '\r'))
//            {
//                while (ln && (buf_street[ln - 1] == '\n' || buf_street[ln - 1] == '\r')) buf_street[--ln] = '\0';
//            }
//            else
//            {
//                clear_stdin();
//            }
//
//            if (ln == 1 && buf_street[0] == '#') { printf("请重新输入街道。\n"); continue; }
//            if (ln == 2 && buf_street[0] == '-' && buf_street[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//
//            if (!isValid(buf_street, MAXN)) { printf("输入不合法！\n"); continue; }
//
//            for (;;)
//            {
//                printf("确认添加街道 \"%s\" ? (y/n，'#' 重输本字段，输入 -1 取消并返回菜单)：", buf_street);
//                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return; }
//                ln = strlen(ans);
//                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
//                {
//                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
//                }
//                else
//                {
//                    clear_stdin();
//                }
//                if (ln == 1 && ans[0] == '#') { printf("请重新输入街道。\n"); break; }
//                if (ln == 2 && ans[0] == '-' && ans[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//                if (ans[0] == 'y') break;
//                if (ans[0] == 'n') { printf("请重新输入街道。\n"); break; }
//                printf("请输入小写 y 或 n（或 '#' 重输本字段，输入 -1 取消）。\n");
//            }
//            if (ans[0] == 'y') break;
//        }
//
//        /* 城市输入与确认（输入 '#' 重新输入本字段；输入 -1 返回菜单）*/
//        for (;;)
//        {
//            printf("请输入城市（输入 '#' 重新输入本字段，输入 -1 取消并返回菜单）：");
//            if (!fgets(buf_address, sizeof(buf_address), stdin)) { printf("输入错误！\n"); return; }
//            ln = strlen(buf_address);
//            if (ln && (buf_address[ln - 1] == '\n' || buf_address[ln - 1] == '\r'))
//            {
//                while (ln && (buf_address[ln - 1] == '\n' || buf_address[ln - 1] == '\r')) buf_address[--ln] = '\0';
//            }
//            else
//            {
//                clear_stdin();
//            }
//
//            if (ln == 1 && buf_address[0] == '#') { printf("请重新输入城市。\n"); continue; }
//            if (ln == 2 && buf_address[0] == '-' && buf_address[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//
//            if (!isValid(buf_address, MAXN)) { printf("输入不合法！\n"); continue; }
//
//            for (;;)
//            {
//                printf("确认添加城市 \"%s\" ? (y/n，'#' 重输本字段，输入 -1 取消并返回菜单)：", buf_address);
//                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return; }
//                ln = strlen(ans);
//                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
//                {
//                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
//                }
//                else
//                {
//                    clear_stdin();
//                }
//                if (ln == 1 && ans[0] == '#') { printf("请重新输入城市。\n"); break; }
//                if (ln == 2 && ans[0] == '-' && ans[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//                if (ans[0] == 'y') break;
//                if (ans[0] == 'n') { printf("请重新输入城市。\n"); break; }
//                printf("请输入小写 y 或 n（或 '#' 重输本字段，输入 -1 取消）。\n");
//            }
//            if (ans[0] == 'y') break;
//        }
//
//        /* 国家/省份输入与确认（输入 '#' 重新输入本字段；输入 -1 返回菜单）*/
//        for (;;)
//        {
//            printf("请输入国家/省份（输入 '#' 重新输入本字段，输入 -1 取消并返回菜单）：");
//            if (!fgets(buf_state, sizeof(buf_state), stdin)) { printf("输入错误！\n"); return; }
//            ln = strlen(buf_state);
//            if (ln && (buf_state[ln - 1] == '\n' || buf_state[ln - 1] == '\r'))
//            {
//                while (ln && (buf_state[ln - 1] == '\n' || buf_state[ln - 1] == '\r')) buf_state[--ln] = '\0';
//            }
//            else
//            {
//                clear_stdin();
//            }
//
//            if (ln == 1 && buf_state[0] == '#') { printf("请重新输入国家/省份。\n"); continue; }
//            if (ln == 2 && buf_state[0] == '-' && buf_state[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//
//            if (!isValid(buf_state, MAXN)) { printf("输入不合法！\n"); continue; }
//
//            for (;;)
//            {
//                printf("确认添加国家/省份 \"%s\" ? (y/n，'#' 重输本字段，输入 -1 取消并返回菜单)：", buf_state);
//                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return; }
//                ln = strlen(ans);
//                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
//                {
//                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
//                }
//                else
//                {
//                    clear_stdin();
//                }
//                if (ln == 1 && ans[0] == '#') { printf("请重新输入国家/省份。\n"); break; }
//                if (ln == 2 && ans[0] == '-' && ans[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//                if (ans[0] == 'y') break;
//                if (ans[0] == 'n') { printf("请重新输入国家/省份。\n"); break; }
//                printf("请输入小写 y 或 n（或 '#' 重输本字段，输入 -1 取消）。\n");
//            }
//            if (ans[0] == 'y') break;
//        }
//
//        /* 电话输入与确认（输入 '#' 重新输入本字段；输入 -1 返回菜单）*/
//        for (;;)
//        {
//            printf("请输入电话号码（输入 '#' 重新输入本字段，输入 -1 取消并返回菜单）：");
//            if (!fgets(buf_tel, sizeof(buf_tel), stdin)) { printf("输入错误！\n"); return; }
//            ln = strlen(buf_tel);
//            if (ln && (buf_tel[ln - 1] == '\n' || buf_tel[ln - 1] == '\r'))
//            {
//                while (ln && (buf_tel[ln - 1] == '\n' || buf_tel[ln - 1] == '\r')) buf_tel[--ln] = '\0';
//            }
//            else
//            {
//                clear_stdin();
//            }
//
//            if (ln == 1 && buf_tel[0] == '#') { printf("请重新输入电话号码。\n"); continue; }
//            if (ln == 2 && buf_tel[0] == '-' && buf_tel[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//
//            if (!isValid(buf_tel, sizeof(buf_tel))) { printf("输入不合法！\n"); continue; }
//
//            for (;;)
//            {
//                printf("确认添加电话号码 \"%s\" ? (y/n，'#' 重输本字段，输入 -1 取消并返回菜单)：", buf_tel);
//                if (!fgets(ans, sizeof(ans), stdin)) { printf("已取消添加\n"); return; }
//                ln = strlen(ans);
//                if (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r'))
//                {
//                    while (ln && (ans[ln - 1] == '\n' || ans[ln - 1] == '\r')) ans[--ln] = '\0';
//                }
//                else
//                {
//                    clear_stdin();
//                }
//                if (ln == 1 && ans[0] == '#') { printf("请重新输入电话号码。\n"); break; }
//                if (ln == 2 && ans[0] == '-' && ans[1] == '1') { printf("已取消添加，返回菜单。\n"); return; }
//                if (ans[0] == 'y') break;
//                if (ans[0] == 'n') { printf("请重新输入电话号码。\n"); break; }
//                printf("请输入小写 y 或 n（或 '#' 重输本字段，输入 -1 取消）。\n");
//            }
//            if (ans[0] == 'y') break;
//        }
//
//        /* 构建 Contact 并判重 */
//        Contact nc;
//        strncpy(nc.name, buf_name, MAXN); nc.name[MAXN - 1] = '\0';
//        strncpy(nc.street, buf_street, MAXN); nc.street[MAXN - 1] = '\0';
//        strncpy(nc.address, buf_address, MAXN); nc.address[MAXN - 1] = '\0';
//        strncpy(nc.state, buf_state, MAXN); nc.state[MAXN - 1] = '\0';
//        strncpy(nc.tel, buf_tel, sizeof(nc.tel)); nc.tel[sizeof(nc.tel) - 1] = '\0';
//
//        /* 判重：全部字段相同即认为重复 */
//        bool duplicate = false;
//        Node* cur = ab.head;
//        while (cur)
//        {
//            if (strcmp(cur->data.name, nc.name) == 0
//                && strcmp(cur->data.street, nc.street) == 0
//                && strcmp(cur->data.address, nc.address) == 0
//                && strcmp(cur->data.state, nc.state) == 0
//                && strcmp(cur->data.tel, nc.tel) == 0)
//            {
//                duplicate = true;
//                break;
//            }
//            cur = cur->next;
//        }
//
//        if (duplicate)
//        {
//            printf("已存在该联系人，请重新输入！\n");
//            /* 从姓名重新输入，继续外层循环 */
//            continue;
//        }
//
//        if (!insert_contact_sorted(&nc))
//        {
//            printf("添加失败：内存分配错误或其他问题。\n");
//            return;
//        }
//
//        printf("联系人 \"%s\" 已添加。\n", nc.name);
//        return;
//    }
//}
//
///* 显示所有联系人 */
//void display()
//{
//    if (!ab.head)
//    {
//        printf("当前没有联系人。\n");
//        return;
//    }
//
//    Node* cur = ab.head;
//    printf("共有 %zu 条联系人记录：\n", ab.count);
//    while (cur)
//    {
//        Contact* c = &cur->data;
//        printf("\t--------------------\n");
//        printf("\t  姓名: %s\n", c->name);
//        printf("\t  街道: %s\n", c->street);
//        printf("\t  城市: %s\n", c->address);
//        printf("\t  国家: %s\n", c->state);
//        printf("\t  电话: %s\n", c->tel);
//        cur = cur->next;
//    }
//    printf("\t--------------------\n");
//}
//
///* 通过姓名查找联系人的相关信息 */
//void search()
//{
//    char name[MAXN];
//    size_t ln;
//
//    for (;;)
//    {
//        printf("请输入要查找的联系人的姓名（输入 '#' 返回菜单）：");
//        if (!fgets(name, sizeof(name), stdin))
//        {
//            printf("输入错误！\n");
//            return;
//        }
//
//        ln = strlen(name);
//        if (ln && (name[ln - 1] == '\n' || name[ln - 1] == '\r'))
//        {
//            while (ln && (name[ln - 1] == '\n' || name[ln - 1] == '\r'))
//                name[--ln] = '\0';
//        }
//        else
//        {
//            /* 输入被截断，清空剩余输入行 */
//            clear_stdin();
//        }
//
//        if (ln == 1 && name[0] == '#')
//        {
//            /* 返回菜单 */
//            return;
//        }
//
//        if (!isValid(name, MAXN))
//        {
//            printf("输入错误！请重新输入\n");
//            continue;
//        }
//
//        /* 在链表中查找第一个 name 字段匹配的节点 */
//        Node* cur = ab.head;
//        while (cur)
//        {
//            if (strcmp(cur->data.name, name) == 0)
//            {
//                Contact* c = &cur->data;
//                printf("\t---------------------------\n");
//                printf("\t  该联系人的所有信息如下：\n");
//                printf("\t   姓名: %s\n", c->name);
//                printf("\t   街道: %s\n", c->street);
//                printf("\t   城市: %s\n", c->address);
//                printf("\t   国家: %s\n", c->state);
//                printf("\t   电话: %s\n", c->tel);
//                printf("\t---------------------------\n");
//                return;
//            }
//            cur = cur->next;
//        }
//
//        printf("\t没找到，请检查是否输入错误~\n");
//        /* 继续循环，允许用户再次输入 */
//    }
//}
//
///* 删除指定联系人的所有信息 */
//void delete()
//{
//    char name[MAXN];
//    size_t ln;
//
//    for (;;)
//    {
//        printf("请输入要删除的联系人的姓名（输入 '#' 返回菜单）：");
//        if (!fgets(name, sizeof(name), stdin))
//        {
//            printf("输入错误！\n");
//            return;
//        }
//
//        ln = strlen(name);
//        if (ln && (name[ln - 1] == '\n' || name[ln - 1] == '\r'))
//        {
//            while (ln && (name[ln - 1] == '\n' || name[ln - 1] == '\r'))
//                name[--ln] = '\0';
//        }
//        else
//        {
//            /* 输入被截断，清空剩余输入行 */
//            clear_stdin();
//        }
//
//        if (ln == 1 && name[0] == '#')
//        {
//            /* 用户取消，返回菜单 */
//            return;
//        }
//
//        if (!isValid(name, MAXN))
//        {
//            printf("输入错误！请重新输入\n");
//            continue;
//        }
//
//        /* 在链表中查找第一个 name 字段匹配的节点并删除 */
//        Node* cur = ab.head;
//        while (cur)
//        {
//            if (strcmp(cur->data.name, name) == 0)
//            {
//                /* 调整链接并释放节点 */
//                if (cur->pre) cur->pre->next = cur->next;
//                else ab.head = cur->next;
//
//                if (cur->next) cur->next->pre = cur->pre;
//
//                free(cur);
//                if (ab.count > 0) ab.count--;
//                printf("已成功删除该联系人\n");
//                return;
//            }
//            cur = cur->next;
//        }
//
//        printf("没找到，请检查是否输入错误~\n");
//        /* 允许用户再次输入 */
//    }
//}
//
///* 将当前的所有联系人信息存入文件 */
//void save()
//{
//    /* 优先判断链表是否为空 */
//    if (!ab.head)
//    {
//        printf("当前没有联系人，先存入联系人吧~\n");
//        return;
//    }
//
//    /* 构建保存路径：优先按照可执行文件所在目录下的 ./AddressBookSystem/information.txt */
//    char filepath[4096] = { 0 };
//#ifdef _WIN32
//    /* 在函数内包含 windows API 头以避免改动文件顶部包含 */
//#include <windows.h>
//    char exePath[MAX_PATH] = { 0 };
//    DWORD len = GetModuleFileNameA(NULL, exePath, MAX_PATH);
//    if (len > 0 && len < MAX_PATH)
//    {
//        /* 去掉可执行文件名，保留目录 */
//        char* p = strrchr(exePath, '\\');
//        if (p) *p = '\0';
//
//        /* 目标子目录：AddressBookSystem（与项目结构一致）*/
//        char folder[MAX_PATH];
//        _snprintf_s(folder, sizeof(folder), _TRUNCATE, "%s\\AddressBookSystem", exePath);
//
//        /* 若目录不存在则尝试创建（若已存在 CreateDirectory 会失败但无影响） */
//        CreateDirectoryA(folder, NULL);
//
//        /* 最终文件路径 */
//        _snprintf_s(filepath, sizeof(filepath), _TRUNCATE, "%s\\information.txt", folder);
//    }
//    else
//    {
//        /* 回退到当前工作目录下的相对文件名 */
//        strncpy(filepath, "information.txt", sizeof(filepath) - 1);
//    }
//#else
//    /* 非 Windows 平台回退到当前工作目录下的文件 */
//    strncpy(filepath, "information.txt", sizeof(filepath) - 1);
//#endif
//
//    /* 打开文件写入 */
//    FILE* fp = fopen(filepath, "w");
//    if (!fp)
//    {
//        printf("保存失败：无法打开文件进行写入（%s）。\n", filepath[0] ? filepath : "information.txt");
//        return;
//    }
//
//    /* 每条记录按一行保存，字段使用 '|' 分隔：name|street|address|state|tel */
//    Node* cur = ab.head;
//    while (cur)
//    {
//        Contact* c = &cur->data;
//        if (fprintf(fp, "%s|%s|%s|%s|%s\n",
//            c->name, c->street, c->address, c->state, c->tel) < 0)
//        {
//            fclose(fp);
//            printf("保存失败：写入文件时出错。\n");
//            return;
//        }
//        cur = cur->next;
//    }
//
//    fclose(fp);
//    printf("已成功存入文件（%s）\n", filepath[0] ? filepath : "information.txt");
//    return;
//}
//
///* 从文件中读取通讯录信息 */
//void load()
//{
//    /* 构建文件路径，与 save() 保持一致 */
//    char filepath[4096] = { 0 };
//#ifdef _WIN32
//    /* 在函数内包含 windows API 头以避免改动文件顶部包含 */
//#include <windows.h>
//    char exePath[MAX_PATH] = { 0 };
//    DWORD len = GetModuleFileNameA(NULL, exePath, MAX_PATH);
//    if (len > 0 && len < MAX_PATH)
//    {
//        char* p = strrchr(exePath, '\\');
//        if (p) *p = '\0';
//
//        char folder[MAX_PATH];
//        _snprintf_s(folder, sizeof(folder), _TRUNCATE, "%s\\AddressBookSystem", exePath);
//        CreateDirectoryA(folder, NULL);
//
//        _snprintf_s(filepath, sizeof(filepath), _TRUNCATE, "%s\\information.txt", folder);
//    }
//    else
//    {
//        strncpy(filepath, "information.txt", sizeof(filepath) - 1);
//    }
//#else
//    strncpy(filepath, "information.txt", sizeof(filepath) - 1);
//#endif
//
//    /* 若链表非空，询问用户是否继续载入 */
//    if (ab.head)
//    {
//        char ans[8];
//        printf("当前有未存入的联系人信息哦，要继续载入吗？(y/n)：");
//        if (!fgets(ans, sizeof(ans), stdin))
//        {
//            printf("读取输入失败，返回菜单。\n");
//            return;
//        }
//        /* 去掉换行 */
//        size_t aln = strlen(ans);
//        while (aln && (ans[aln - 1] == '\n' || ans[aln - 1] == '\r')) ans[--aln] = '\0';
//
//        if (aln == 0 || ans[0] != 'y')
//        {
//            printf("已取消载入，返回菜单。\n");
//            return;
//        }
//    }
//
//    FILE* fp = fopen(filepath, "r");
//    if (!fp)
//    {
//        printf("装入失败：无法打开文件（%s）。\n", filepath[0] ? filepath : "information.txt");
//        return;
//    }
//
//    /* 清空现有链表（避免重复加载）*/
//    Node* n = ab.head;
//    while (n)
//    {
//        Node* nx = n->next;
//        free(n);
//        n = nx;
//    }
//    ab.head = NULL;
//    ab.count = 0;
//
//    char line[512];
//    while (fgets(line, sizeof(line), fp))
//    {
//        /* 去掉末尾换行 */
//        size_t ln = strlen(line);
//        while (ln && (line[ln - 1] == '\n' || line[ln - 1] == '\r')) line[--ln] = '\0';
//        if (ln == 0) continue;
//
//        /* 解析字段 name|street|address|state|tel */
//        char* tok = strtok(line, "|");
//        if (!tok) continue;
//
//        Contact c;
//        strncpy(c.name, tok, MAXN); c.name[MAXN - 1] = '\0';
//
//        tok = strtok(NULL, "|"); if (!tok) continue; strncpy(c.street, tok, MAXN); c.street[MAXN - 1] = '\0';
//        tok = strtok(NULL, "|"); if (!tok) continue; strncpy(c.address, tok, MAXN); c.address[MAXN - 1] = '\0';
//        tok = strtok(NULL, "|"); if (!tok) continue; strncpy(c.state, tok, MAXN); c.state[MAXN - 1] = '\0';
//        tok = strtok(NULL, "|"); if (!tok) continue; strncpy(c.tel, tok, sizeof(c.tel)); c.tel[sizeof(c.tel) - 1] = '\0';
//
//        /* 简单校验，若任一字段不合法则跳过该行 */
//        if (!isValid(c.name, MAXN) || !isValid(c.street, MAXN) || !isValid(c.address, MAXN) || !isValid(c.state, MAXN) || !isValid(c.tel, sizeof(c.tel)))
//            continue;
//
//        /* 插入到链表（按姓名排序）*/
//        if (!insert_contact_sorted(&c))
//        {
//            /* 内存分配失败：清理并退出 */
//            Node* m = ab.head;
//            while (m)
//            {
//                Node* nx = m->next;
//                free(m);
//                m = nx;
//            }
//            ab.head = NULL;
//            ab.count = 0;
//            fclose(fp);
//            printf("装入失败：内存分配错误。\n");
//            return;
//        }
//    }
//
//    fclose(fp);
//    printf("已成功载入信息\n");
//    return;
//}
//
//int main()
//{
//    /* 初始化全局通讯录 */
//    ab.head = NULL;
//    ab.count = 0;
//
//    int input = 0;
//    do
//    {
//        menu();
//        if (scanf("%d", &input) != 1) { clear_stdin(); input = -1; }
//        clear_stdin();
//        switch (input)
//        {
//        case 1:
//            enter();
//            break;
//
//        case 2:
//            display();
//            break;
//
//        case 3:
//            search();
//            break;
//
//        case 4:
//            delete();
//            break;
//
//        case 5:
//            save();
//            break;
//
//        case 6:
//            load();
//            break;
//
//        default:
//            if (input != 0)
//                printf("输入错误，请重新输入！\n");
//            break;
//        }
//
//        if (input)
//        {
//            system("pause");
//        }
//        system("cls");
//    } while (input);
//
//    printf("感谢使用本系统，已正常退出，按任意键继续\n");
//    return 0;
//}

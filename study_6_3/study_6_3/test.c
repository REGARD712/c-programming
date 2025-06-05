#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    char s[20] = { 0 };
    char s_reverse[20] = { 0 };

    gets(s[20]);
    char* ps = &s[0];
    char* p = &s_reverse[0];
    
    int i = 0;
    int count = 0;
    while (*p)
    {
        count++;
        p++;
    }
    while (*p)
    {
        *(p + i) = *(ps + count - 1);
        i++;
        count--;
    }

    return 0;
}
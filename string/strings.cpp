//
// Created by 周舟 on 2022/5/11.
//
#include "iostream"
#include <stdio.h>

using namespace std;
typedef struct {
    char *ch;
    int length;
} Str;

void initstr(Str *str);//初始化字符串
int strassign(Str &str, char *ch);//赋值
void printstring(Str str);//输出字符串
int strlength(Str str);//求字符串长度
int strcompare(Str s1, Str s2);//比较两个字符串
int concat(Str &str, Str str1, Str str2);//连接两个字符串
int substring(Str &subsstr, Str str, int pos, int len);//取主串的子串
int clearstring(Str &str);//清空字符串
int main() {
    Str str, s1, s2, strcat, substr;
    char ch1[50], ch2[50];
    initstr(&str);
    initstr(&s1);
    initstr(&s2);
    initstr(&strcat);
    initstr(&substr);
    strassign(str, "输入字符串");
    printstring(str);
    cout << "字符串的长度为：" << strlength(str) << endl;

    cout << "请输入串1：";
    fgets(ch1, 50, stdin);
    cout << "请输入串2：";
    fgets(ch2, 50, stdin);
    strassign(s1, ch1);
    strassign(s2, ch2);

    cout << "两串比较，若结果大于0，则串1 ASCII大于串2 ASCII。结果为：";
    cout << strcompare(s1, s2) << endl;

    concat(strcat, s1, s2);
    cout << "两串连接后为：";
    printstring(strcat);


    cout << "取得子串为：";
    substring(substr, strcat, 3, 7);
    printstring(substr);


    cout << "清空所有字符串。" << endl;
    clearstring(str);
    clearstring(s1);
    clearstring(s2);
    clearstring(strcat);
    clearstring(substr);
    cout << "所有字符串均被清空。" << endl;
    return 0;
}

void initstr(Str *str) {
    str->ch = NULL;
    str->length = 0;
}

int strassign(Str &str, char *ch) {
    if (str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while (*c) {
        ++len;
        ++c;
    }
    if (len == 0) {
        str.ch = NULL;
        str.length = 0;
        return 1;
    } else {
        str.ch = (char *) malloc(sizeof(char) * (len + 1));
        if (str.ch == NULL)
            return 0;
        else {
            c = ch;
            for (int i = 0; i <= len; ++i) {
                str.ch[i] = *c;
                ++c;
            }
            str.length = len;
            return 1;
        }
    }
}

void printstring(Str str) {
    for (int i = 0; i < str.length; ++i)
        cout << str.ch[i];
    cout << endl;
}

int strlength(Str str) {
    return str.length;
}

int strcompare(Str s1, Str s2) {
    for (int i = 0; i < s1.length && i < s2.length; ++i)
        if (s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    return s1.length - s2.length;
}

int concat(Str &str, Str str1, Str str2) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *) malloc(sizeof(char) * (str1.length + str2.length + 1));
    if (str.ch == NULL)
        return 0;
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        i++;
    }
    int j = 0;
    while (j <= str2.length) {
        str.ch[i + j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

int substring(Str &substr, Str str, int pos, int len) {
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
        return 0;
    if (substr.ch) {
        free(substr.ch);
        substr.ch = NULL;
    }
    if (len == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char *) malloc(sizeof(char) * (len + 1));
        int i = pos;
        int j = 0;
        while (i < pos + len) {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

int clearstring(Str &str) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}



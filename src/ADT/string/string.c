#include "string.h"

int strLength(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    };

    return i;
};

string concat(string s1, string s2)
{
    string ret = malloc((strLength(s1) + strLength(s2) + 1) * sizeof(char));
    string p = ret;
    while (*s1 != '\0')
    {
        *p++ = *s1++;
    }
    while (*s2 != '\0')
    {
        *p++ = *s2++;
    }
    *p = '\0';
    return ret;
}

void strCopy(string s1, string s2)
{
    while (*s2 != '\0')
    {
        *s1++ = *s2++;
    }
    *s1 = '\0';
}

boolean isCharInString(string s, char c)
{
    int i = 0, length;
    boolean found = false;
    length = strLength(s);

    while (i < length && !found)
    {
        if (s[i] == c)
        {
            found = true;
        }
        i++;
    }
    return found;
}

int strCompare(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }

    if (*s1 != '\0') {
        return 1; // s1 lebih panjang
    } else if (*s2 != '\0') {
        return -1; // s2 lebih panjang
    }

    return 0; // Equal
}

void intToString(int num, char *str) {
    sprintf(str, "%d", num);
}
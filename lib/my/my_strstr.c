/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strst
*/

#include "my.h"

static void find_start(char *str, char const *to_find, int i, int *s)
{
    int to_find_len = my_strlen(to_find);
    int start = 0;
    int count = 0;
    for (int j = 0; to_find[j] != '\0'; j += 1) {
        if (count >= to_find_len)
            return;
        if (str[i + j] == to_find[j]) {
            count += 1;
            start = i;
        } else {
            return;
        }
    }
    *s = start;
}

char *my_strstr(char *str, char const *to_find)
{
    int start = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        find_start(str, to_find, i, &start);
    }
    return &str[start];
}

/*
** EPITECH PROJECT, 2021
** day8
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int is_al(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static void find_nb_words(char const *str, int *len, int *word)
{
    if (is_al(str[0]) == 1)
        *word += 1;
    for (int i = 0; i < *len; i += 1) {
        if (is_al(str[i + 1]) == 1 && is_al(str[i]) == 0)
            *word += 1;
        else if (is_al(str[i]) == 0)
            *len -= 1;
    }
}

static void find(char **words, char const *str, int *starts, int *ends)
{
    int c = 0;
    int str_len = my_strlen(str);
    for (int i = 0; i < str_len; i += 1) {
        if (is_al(str[i]) == 1 && is_al(str[i - 1]) == 0) {
            starts[c] = i;
            c += 1;
        }
        int a = is_al(str[i]);
        int b = is_al(str[i + 1]);
        if ((a == 1 && b == 0) || (a == str_len - 1)) {
            ends[c - 1] = i;
            words[c - 1] = malloc(sizeof(char) *
            (ends[c - 1] - starts[c - 1] + 1));
        }
    }
}

char **my_str_to_word_array(char const *str)
{
    int len = my_strlen(str), word = 0;
    int *starts, *ends;
    char **words;
    find_nb_words(str, &len, &word);
    words = malloc(sizeof(char *) * (word + 1));
    starts = malloc(sizeof(int) * word);
    ends = malloc(sizeof(int) * word);
    find(words, str, starts, ends);
    words[word] = 0;
    for (int i = 0; words[i] != 0; i += 1) {
        my_strncpy(words[i], &str[starts[i]], ends[i] - starts[i] + 1);
    }
    return words;
}

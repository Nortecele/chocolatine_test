/*
** EPITECH PROJECT, 2021
** day8
** File description:
** my_show_word_array
*/

#include "my.h"
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    int total_len = 0;
    char *concated_strings;
    for (int i = 0; tab[i] != NULL; i += 1)
        total_len += my_strlen(tab[i]) + 1;
    concated_strings = malloc(sizeof(char) * total_len);
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_strcat(concated_strings, tab[i]);
        my_strcat(concated_strings, "\n");
    }
    my_putstr(concated_strings);
    return (0);
}

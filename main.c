/*
** EPITECH PROJECT, 2022
** dpicks
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    if (new_str == NULL)
        return (NULL);
    int i = 0;

    if (new_str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

int arg_counter(char *str, const char *delim)
{
    int j = 0;
    char *str2 = my_strdup(str);
    char *temp = malloc(sizeof(char) * my_strlen(str));
    if (str2 == NULL || temp == NULL)
        return (0);
    temp = strtok(str2, delim);
    j++;
    while (temp) {
        temp = strtok(NULL, delim);
        j++;
    }
    free(str2);
    free(temp);
    return j;
}

char **my_str_to_word_array(char *str)
{
    char *tmp = my_strdup(str);
    int nb = arg_counter(str, ",");
    char **array = malloc(sizeof(char *) * (nb + 1));
    if (array == NULL || tmp == NULL)
        return (NULL);

    array[0] = my_strdup(strtok(tmp, ","));
    for (int i = 1; i < nb - 1; i++)
        array[i] = my_strdup(strtok(NULL, ","));
    array[nb] = NULL;
    return array;
}

int ratio(char *point, char *word)
{
    char **points = my_str_to_word_array(point);
    if (!points)
        return 84;
    int total = 0;
    for (int i = 0; word[i]; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            total += atoi(points[word[i] - 'A']);
        if (word[i] >= 'a' && word[i] <= 'z')
            total += atoi(points[word[i] - 'a']);
    }
    if (printf("%d\n", total) == -1)
        return 84;
    return 0;
}

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int error_handling(char **av)
{
    if (!av[1])
        return 84;
    if (av[2][0] == '\0')
        return 84;
    for (int i = 0; av[2][i]; i++)
        if (!is_alpha(av[2][i]))
            return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2 || ac < 3)
        return (84);
    if (error_handling(av))
        return 84;
    if (ratio(av[1], av[2]))
        return (84);
    return (0);
}

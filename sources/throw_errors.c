/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** throw_errors.c file.
*/

#include "core.h"

void throw_errors(int ac, char **av)
{
    if (ac != 5
        || strtol(av[1], NULL, 10) < 1
        || strtol(av[2], NULL, 10) < 1
        || strtol(av[3], NULL, 10) < 1
        || strtol(av[4], NULL, 10) < 1) {
        printf("Some arguments are invalid\n");
        exit(84);
    }
}

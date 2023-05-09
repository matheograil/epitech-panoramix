/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** my_free.c file.
*/

#include "core.h"

void my_free(void *ptr)
{
    if (ptr != NULL) {
        free(ptr);
    }
}

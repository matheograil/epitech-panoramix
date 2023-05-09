/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** free.c file.
*/

#include "core.h"

void free_villagers(villager_t *villagers)
{
    villager_t *temp = NULL;

    while (villagers != NULL) {
        temp = villagers;
        villagers = villagers->next;
        my_free(temp);
    }
}

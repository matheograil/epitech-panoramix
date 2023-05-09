/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** add.c file.
*/

#include "core.h"

void add_villager(villager_t *villagers, unsigned int nb_fights)
{
    villager_t *new_villager = malloc(sizeof(villager_t));
    unsigned int villagers_nb = -1;

    if (new_villager == NULL) {
        return;
    }
    while (villagers->next != NULL) {
        villagers = villagers->next;
        villagers_nb++;
    }
    new_villager->id = (int)villagers_nb;
    new_villager->remaining_fights = nb_fights;
    new_villager->next = NULL;
    new_villager->thread = 0;
    villagers->next = new_villager;
}

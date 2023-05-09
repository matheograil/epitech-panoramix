/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

pot_t *init_pot(unsigned int pot_size)
{
    pot_t *pot = malloc(sizeof(pot_t));

    if (pot == NULL) {
        return (NULL);
    }
    pot->size = pot_size;
    return (pot);
}

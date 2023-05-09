/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** free.c file.
*/

#include "core.h"

void free_parameters(parameters_t *parameters)
{
    if (parameters != NULL) {
        free_villagers(parameters->villagers);
        my_free(parameters->pot);
        my_free(parameters->druid);
        my_free(parameters->args);
    }
    my_free(parameters);
}

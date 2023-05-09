/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

parameters_t *init_parameters(villager_t *villagers, arguments_t *arguments,
    pot_t *pot, druid_t *druid)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    if (parameters == NULL) {
        return (NULL);
    }
    parameters->villagers = villagers;
    parameters->args = arguments;
    parameters->pot = pot;
    parameters->druid = druid;
    return (parameters);
}

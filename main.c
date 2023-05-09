/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** main.c file.
*/

#include "core.h"

int main(int ac, char **av)
{
    parameters_t *params = NULL;

    if (ac == 1) {
        print_help();
        return (0);
    }
    throw_errors(ac, av);
    if ((params = init_structures(av)) == NULL)
        return (84);
    if (init_mutexes_and_semaphores(params) == false
        || create_threads(params) == false) {
        free_parameters(params);
        return (84);
    }
    if (join_threads(params) == false) {
        (destroy_mutexes_and_semaphores(params), free_parameters(params));
        return (84);
    }
    (destroy_mutexes_and_semaphores(params), free_parameters(params));
    return (0);
}

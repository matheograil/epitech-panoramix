/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init.c file.
*/

#include "core.h"

bool init_mutexes_and_semaphores(parameters_t *params)
{
    if (pthread_mutex_init(&params->druid->mutex, NULL) != 0) {
        return (false);
    }
    if (pthread_mutex_init(&params->druid->villagers_mutex, NULL) != 0) {
        pthread_mutex_destroy(&params->druid->mutex);
        return (false);
    }
    if (pthread_mutex_init(&params->pot->mutex, NULL) != 0) {
        pthread_mutex_destroy(&params->druid->mutex);
        pthread_mutex_destroy(&params->druid->villagers_mutex);
        return (false);
    }
    if (sem_init(&params->pot->semaphore, 0, params->args->pot_size) != 0) {
        pthread_mutex_destroy(&params->druid->mutex);
        pthread_mutex_destroy(&params->druid->villagers_mutex);
        pthread_mutex_destroy(&params->pot->mutex);
        return (false);
    }
    return (true);
}

bool create_threads(parameters_t *p)
{
    villager_thread_t *villager_thread = NULL;

    if (pthread_create(&p->druid->thread, NULL, start_druid_thread, p) != 0)
        return (false);
    for (; p->villagers != NULL; p->villagers = p->villagers->next) {
        if (p->villagers->id == -1)
            continue;
        villager_thread = malloc(sizeof(villager_thread_t));
        if (villager_thread == NULL)
            continue;
        villager_thread->villager = p->villagers;
        villager_thread->params = p;
        if (pthread_create(&p->villagers->thread, NULL, start_villager_thread,
            villager_thread) != 0) {
            my_free(villager_thread);
            return (false);
        }
    }
    return (true);
}

bool join_threads(parameters_t *params)
{
    if (pthread_join(params->druid->thread, NULL) != 0) {
        return (false);
    }
    while (params->villagers != NULL) {
        if (params->villagers->id == -1) {
            params->villagers = params->villagers->next;
            continue;
        }
        if (pthread_join(params->villagers->thread, NULL) != 0) {
            return (false);
        }
        params->villagers = params->villagers->next;
    }
    return (true);
}

void destroy_mutexes_and_semaphores(parameters_t *params)
{
    pthread_mutex_destroy(&params->druid->mutex);
    pthread_mutex_destroy(&params->druid->villagers_mutex);
    pthread_mutex_destroy(&params->pot->mutex);
    sem_destroy(&params->pot->semaphore);
}

/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** druid.c file.
*/

#include "core.h"

void *start_druid_thread(void *arg)
{
    parameters_t *params = (parameters_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (params->druid->remaining_fills != 0
        && are_fights_over(params) == false) {
        pthread_mutex_lock(&params->druid->mutex);
        if (params->druid->fill_requested == true) {
            fill_pot(params);
        }
        pthread_mutex_unlock(&params->druid->mutex);
    }
    if (params->druid->remaining_fills == 0) {
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    }
    return (NULL);
}

void fill_pot(parameters_t *params)
{
    pthread_mutex_lock(&params->pot->mutex);
    for (unsigned int i = 0; i < params->args->pot_size; i++) {
        sem_post(&params->pot->semaphore);
    }
    params->pot->size = params->args->pot_size;
    pthread_mutex_unlock(&params->pot->mutex);
    params->druid->fill_requested = false;
    params->druid->remaining_fills--;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only "
        "make %d more refills after this one.\n",
        params->druid->remaining_fills);
}

bool are_fights_over(parameters_t *params)
{
    pthread_mutex_lock(&params->druid->villagers_mutex);
    if (params->druid->villagers_fights_nb != params->args->nb_fights
        * params->args->nb_villagers) {
        pthread_mutex_unlock(&params->druid->villagers_mutex);
        return (false);
    }
    pthread_mutex_unlock(&params->druid->villagers_mutex);
    return (true);
}

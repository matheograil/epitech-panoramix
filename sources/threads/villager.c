/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** villager.c file.
*/

#include "core.h"

void *start_villager_thread(void *arg)
{
    villager_thread_t *villager_thread = (villager_thread_t *)arg;

    printf("Villager %d: Going into battle!\n", villager_thread->villager->id);
    while (villager_thread->villager->remaining_fights != 0
        && can_druid_cook(villager_thread) == true) {
        if (drink_portion(villager_thread) == false) {
            ask_pot_filling(villager_thread);
        }
        fight(villager_thread);
    }
    if (villager_thread->villager->remaining_fights == 0) {
        printf("Villager %d: I'm going to sleep now.\n",
            villager_thread->villager->id);
    }
    my_free(villager_thread);
    return (NULL);
}

void ask_pot_filling(villager_thread_t *villager_thread)
{
    pthread_mutex_lock(&villager_thread->params->druid->mutex);
    if (villager_thread->params->druid->fill_requested == true) {
        pthread_mutex_unlock(&villager_thread->params->druid->mutex);
        return;
    }
    villager_thread->params->druid->fill_requested = true;
    pthread_mutex_unlock(&villager_thread->params->druid->mutex);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        villager_thread->villager->id, 0);
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        villager_thread->villager->id);
}

bool drink_portion(villager_thread_t *villager_thread)
{
    pthread_mutex_lock(&villager_thread->params->pot->mutex);
    if (villager_thread->params->pot->size == 0) {
        pthread_mutex_unlock(&villager_thread->params->pot->mutex);
        return (false);
    }
    sem_wait(&villager_thread->params->pot->semaphore);
    villager_thread->params->pot->size--;
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        villager_thread->villager->id, villager_thread->params->pot->size);
    pthread_mutex_unlock(&villager_thread->params->pot->mutex);
    return (true);
}

void fight(villager_thread_t *villager_thread)
{
    pthread_mutex_lock(&villager_thread->params->druid->villagers_mutex);
    villager_thread->params->druid->villagers_fights_nb++;
    pthread_mutex_unlock(&villager_thread->params->druid->villagers_mutex);
    villager_thread->villager->remaining_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        villager_thread->villager->id,
        villager_thread->villager->remaining_fights);
}

bool can_druid_cook(villager_thread_t *villager_thread)
{
    pthread_mutex_lock(&villager_thread->params->druid->mutex);
    pthread_mutex_lock(&villager_thread->params->pot->mutex);
    if (villager_thread->params->druid->remaining_fills == 0
        && villager_thread->params->pot->size == 0) {
        pthread_mutex_unlock(&villager_thread->params->pot->mutex);
        pthread_mutex_unlock(&villager_thread->params->druid->mutex);
        return (false);
    }
    pthread_mutex_unlock(&villager_thread->params->pot->mutex);
    pthread_mutex_unlock(&villager_thread->params->druid->mutex);
    return (true);
}

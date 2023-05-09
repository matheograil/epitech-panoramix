/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** structures.h file.
*/

#pragma once

typedef struct arguments_s {
    unsigned int nb_villagers;
    unsigned int pot_size;
    unsigned int nb_fights;
    unsigned int nb_refills;
} arguments_t;

typedef struct villager_s {
    int id;
    unsigned int remaining_fights;
    struct villager_s *next;
    pthread_t thread;
} villager_t;

typedef struct pot_s {
    sem_t semaphore;
    unsigned int size;
    pthread_mutex_t mutex;
} pot_t;

typedef struct druid_s {
    bool fill_requested;
    unsigned int remaining_fills;
    unsigned int villagers_fights_nb;
    pthread_t thread;
    pthread_mutex_t mutex;
    pthread_mutex_t villagers_mutex;
} druid_t;

typedef struct parameters_s {
    arguments_t *args;
    villager_t *villagers;
    pot_t *pot;
    druid_t *druid;
} parameters_t;

typedef struct villager_thread_s {
    parameters_t *params;
    villager_t *villager;
} villager_thread_t;

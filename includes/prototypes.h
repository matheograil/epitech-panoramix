/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** prototypes.h file.
*/

#pragma once

arguments_t *init_arguments(char **);

druid_t *init_druid(unsigned int);

void free_parameters(parameters_t *);

parameters_t *init_parameters(villager_t *, arguments_t *, pot_t *, druid_t *);

pot_t *init_pot(unsigned int);

void *start_villager_thread(void *);
void ask_pot_filling(villager_thread_t *);
bool drink_portion(villager_thread_t *);
void fight(villager_thread_t *);
bool can_druid_cook(villager_thread_t *);

bool init_mutexes_and_semaphores(parameters_t *);
bool create_threads(parameters_t *);
bool join_threads(parameters_t *);
void destroy_mutexes_and_semaphores(parameters_t *);

void *start_druid_thread(void *);
void fill_pot(parameters_t *);
bool are_fights_over(parameters_t *);

void my_free(void *);

void add_villager(villager_t *, unsigned int);

void free_villagers(villager_t *);

villager_t *init_villagers(unsigned int, unsigned int);

parameters_t *init_structures(char **);
void *free_sub_structures(arguments_t *, villager_t *, pot_t *, druid_t *);

void print_help(void);

void throw_errors(int, char **);

int main(int, char **);

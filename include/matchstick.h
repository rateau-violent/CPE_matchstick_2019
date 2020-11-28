/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** header
*/

#include "my.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct game_s
{
    int map_size;
    int max_matches;
    int *arr_matches;
    int total_matches;
    int game_status;
    int line;
    int matches;
} game_t;


int matchstick(char **av);
game_t *init_game(char **av);
void display_map(game_t *game);
int player(game_t *game);
void ai(game_t *game);
char *read_term(void);
void update_map(game_t *game);
bool is_number(char const *str);
int get_matches_player(game_t *game);
bool is_end_game(game_t *game);

#endif /* !MATCHSTICK_H_ */

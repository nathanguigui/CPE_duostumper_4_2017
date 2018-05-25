/*
** EPITECH PROJECT, 2018
** stumper4
** File description:
** stumper4
*/

#ifndef STUMPER_H_
#define STUMPER_H_

#include "my.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct stumper_s {
	char *file;
	char **words;
	char **grid;
	int *placed;
	int size;
} stumper_t;

int place_diag(int x, int y, char *word, stumper_t *stumper);
int place_reverse_diag(int x, int y, char *word, stumper_t *stumper);
int place_oposite_diag(int x, int y, char *word, stumper_t *stumper);
int place_reverse_oposite_diag(int x, int y, char *word, stumper_t *stumper);

int place_reverse_vert(int x, int y, char *word, stumper_t *stumper);
int place_vert(int x, int y, char *word, stumper_t *stumper);
int place_reverse_hori(int x, int y, char *word, stumper_t *stumper);
int place_hori(int x, int y, char *word, stumper_t *stumper);

void free_stumper(stumper_t *stumper);
int fill_stumper(stumper_t *stumper, int ac, char **av);
void algo_stumper(stumper_t *stumper,
int (*fnt)(int, int, char *, stumper_t *));

#endif

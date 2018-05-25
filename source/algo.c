/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** stumper
*/

#include "stumper.h"

int place_word(stumper_t *stumper, char *word, int y,
int (*fnt)(int, int, char *, stumper_t *))
{
	for (int x = 0; stumper->grid[y][x] != '\0'; x = x + 1) {
		if (fnt(x, y, word, stumper))
			return (1);
	}
	return (0);
}

void algo_stumper(stumper_t *stumper, int (*fnt)(int, int, char *, stumper_t *))
{
	int toto = 0;

	for (int i = 0; stumper->words[i]; i = i + 1) {
		for (i = i; stumper->words[i] && stumper->placed[i] == 1; i++);
		if (!stumper->words[i])
			return;
		toto = 0;
		for (int y = 0; stumper->grid[y] && toto == 0; y = y + 1)
			toto = place_word(stumper, stumper->words[i], y, fnt);
		if (toto == 1)
			stumper->placed[i] = 1;
	}
}

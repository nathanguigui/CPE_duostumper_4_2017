/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** stumper
*/

#include "stumper.h"

int place_reverse_vert(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y >= 0 && word[i]; y = y - 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
	}
	if (word[i] != '\0')
		return (0);
	y = y + i;
	for (i = 0; y >= 0 && word[i]; y = y - 1) {
		stumper->grid[y][x] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_vert(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y < stumper->size && word[i]; y = y + 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
	}
	if (word[i] != '\0')
		return (0);
	y = y - i;
	for (i = 0; y < stumper->size && word[i]; y = y + 1) {
		stumper->grid[y][x] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_reverse_hori(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; x >= 0 && word[i]; x = x - 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
	}
	if (word[i] != '\0')
		return (0);
	x = x + i;
	for (i = 0; x >= 0 && word[i]; x = x - 1) {
		stumper->grid[y][x] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_hori(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; x < stumper->size && word[i]; x = x + 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
	}
	if (word[i] != '\0')
		return (0);
	x = x - i;
	for (i = 0; x < stumper->size && word[i]; x = x + 1) {
		stumper->grid[y][x] = word[i];
		i = i + 1;
	}
	return (1);
}


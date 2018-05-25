/*
** EPITECH PROJECT, 2018
** stumper4
** File description:
** main.c
*/

#include "stumper.h"

void display_stumper(stumper_t *stumper)
{
	int nb = 0;
	int len = 0;

	for (len = 0; stumper->words[len]; len = len + 1);
	for (int i = 0; i < len; i = i + 1)
		if (stumper->placed[i] == 1)
			nb = nb + 1;
	printf("%d/%d words inserted in the grid.\n", nb, len);
	for (int i = 0; i < stumper->size + 2; i = i + 1)
		my_putchar('+');
	my_putchar('\n');
	for (int i = 0; stumper->grid[i] != NULL; i = i + 1) {
		my_putchar('|');
		my_putstr(stumper->grid[i]);
		my_putstr("|\n");
	}
	for (int i = 0; i < stumper->size + 2; i = i + 1)
		my_putchar('+');
	my_putchar('\n');
}

void clean_stumper(stumper_t *stumper)
{
	char **grid = stumper->grid;

	for (int i = 0; grid[i] != NULL; i = i + 1) {
		for (int j = 0; grid[i][j] != '\0'; j = j + 1)
			grid[i][j] = (grid[i][j] == ' ' ? my_rand('a', 'z')
			: grid[i][j]);
	}
}

int main(int ac, char **av)
{
	stumper_t stumper2 = {.size = 8, .file = NULL, .words = NULL};
	stumper_t *stumper = &stumper2;
	int (*fnt[])(int, int, char *, stumper_t *) = {&place_hori,
		&place_reverse_hori, &place_reverse_vert, &place_vert,
		&place_reverse_diag, &place_diag, &place_reverse_oposite_diag,
		&place_oposite_diag, NULL};

	my_srand();
	if (fill_stumper(stumper, ac, av) == 84) {
		free_stumper(stumper);
		return (84);
	}
	for (int i = 0; fnt[i] != NULL; i = i + 1)
		algo_stumper(stumper, fnt[i]);
	clean_stumper(stumper);
	display_stumper(stumper);
	free_stumper(stumper);
	return (0);
}

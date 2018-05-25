/*
** EPITECH PROJECT, 2018
** stumper4
** File description:
** struct.c
*/

#include "stumper.h"

int get_words(stumper_t *stumper)
{
	int fd = open(stumper->file, O_RDONLY);
	int len = 0;

	if (fd == -1)
		return (fd);
	for (char *str = get_next_line(fd); str != NULL;
		str = get_next_line(fd))
		realloc_tab((void ***)&stumper->words, str);
	if (stumper->words == NULL)
		return (fd);
	len = my_strlen(stumper->words[0]);
	for (int i = 0; stumper->words[i] != NULL; i = i + 1)
		if (len != my_strlen(stumper->words[i])) {
			stumper->words = NULL;
			return (fd);
		} else
			len = my_strlen(stumper->words[i]);
	return (fd);
}

void my_calloc(stumper_t *stumper)
{
	int a = 0;

	stumper->grid = malloc(sizeof(char *) * (stumper->size + 1));
	for (a = 0; stumper->words[a]; a = a + 1);
	stumper->placed = malloc(sizeof(int) * a);
	for (a = 0; stumper->words[a]; a = a + 1)
		stumper->placed[a] = 0;
	for (int i = 0; i < stumper->size; i = i + 1) {
		stumper->grid[i] = malloc(sizeof(char) * (stumper->size + 1));
		for (int j = 0; j < stumper->size; j = j + 1)
			stumper->grid[i][j] = ' ';
		stumper->grid[i][stumper->size] = '\0';
	}
	stumper->grid[stumper->size] = NULL;
	if (my_strlen(stumper->words[0]) > stumper->size) {
		free_array((void **)stumper->words);
		stumper->words = NULL;
	}
}

int fill_stumper(stumper_t *stumper, int ac, char **av)
{
	if (ac < 2)
		return (84);
	for (int i = 1; av[i] != NULL; i = i + 1) {
		if (my_strcmp(av[i], "-f") && av[i + 1] != NULL) {
			stumper->file = av[i + 1];
			i = i + 1;
		} else if (my_strcmp(av[i], "-s") && av[i + 1] != NULL &&
		is_number(av[i + 1])) {
			stumper->size = my_getnbr(av[i + 1]);
			i = i + 1;
		} else
			return (84);
	}
	close(get_words(stumper));
	if (stumper->file == NULL || stumper->words == NULL)
		return (84);
	my_calloc(stumper);
	if (stumper->file == NULL || stumper->words == NULL)
		return (84);
	return (1);
}

void free_stumper(stumper_t *stumper)
{
	free_array((void **)stumper->words);
	free_array((void **)stumper->grid);
	free(stumper->placed);
}

/*
** EPITECH PROJECT, 2017
** diag.c
** File description:
** 
*/

int place_diag(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y < stumper->size && x < stumper->size && word[i]; y++) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
		x = x + 1;
	}
	if (word[i] != '\0')
		return (0);
	y = y - i;
	x = x - i;
	for (i = 0; y < stumper->size && x + i < stumper->size &&
	word[i]; y++) {
		stumper->grid[y][x + i] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_reverse_diag(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y >= 0 && word[i] && x >= 0; y = y - 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
		x = x - 1;
	}
	if (word[i] != '\0')
		return (0);
	y = y + i;
	x = x + i;
	for (i = 0; y >= 0 && word[i] && x - i >= 0; y = y - 1) {
		stumper->grid[y][x - i] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_reverse_oposite_diag(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y < stumper->size && x >= 0 && word[i]; x = x - 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
		y = y + 1;
	}
	if (word[i] != '\0')
		return (0);
	x = x + i;
	y = y - i;
	for (i = 0; y + i < stumper->size && x >= 0 && word[i]; x = x - 1) {
		stumper->grid[y + i][x] = word[i];
		i = i + 1;
	}
	return (1);
}

int place_oposite_diag(int x, int y, char *word, stumper_t *stumper)
{
	int i = 0;

	for (i = 0; y >= 0 && x < stumper->size && word[i]; x = x + 1) {
		if (stumper->grid[y][x] == ' ' ||
			stumper->grid[y][x] == word[i])
			i = i + 1;
		else
			return (0);
		y = y - 1;
	}
	if (word[i] != '\0')
		return (0);
	x = x - i;
	y = y + i;
	for (i = 0; y - i >= 0 && x < stumper->size && word[i]; x = x + 1) {
		stumper->grid[y - i][x] = word[i];
		i = i + 1;
	}
	return (1);
}

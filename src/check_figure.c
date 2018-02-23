
#include "header.h"											// сделать шапку

int		pairing_func(int k1, int k2)
{
	return ((((k1 + k2) * (k1 + k2 + 1)) / 2) + k2);
}

int		control_sum(f_figure4x4 *figure)					// большое количество строк, уменьшить до 5 переменных
{
	int rows[4] = {0, 0, 0, 0};
	int cols[4] = {0, 0, 0, 0};
	int i;
	int j;
	int row;
	int col;
	int sum;

	i = -1;
	while (++i < FIELD_SIZE)
	{
		j = -1;
		while (++j < FIELD_SIZE)
		{
			rows[j] += (figure->data[i][j] == '#') ? 1 : 0;
			cols[i] += (figure->data[i][j] == '#') ? 1 : 0;
		}
	}
	i = -1;
	row = 0;
	col = 0;
	while (++i < FIELD_SIZE)
	{
		row = 10 * row + rows[i];
		col = 10 * col + cols[i];
	}
	sum = pairing_func(row, col);
	return (sum);
}

int		check_figure(f_figure4x4 *figure)
{
	int			sum;
	int			i;
	static int	valid [] = {8907430, 2930530, 5817865, 13576765, 5817055,
							2930710, 8909410, 13577755, 13064827, 13067716,
							5817955, 5817955, 5816965, 9684400,
							3152605, 9293305, 9291415, 3152515};

	i = -1;
	sum = control_sum(figure);

	while (++i < 18)												// нету тела в цыкле вайл
		if (valid[i] == sum)
			return (1);
	return (0);
}

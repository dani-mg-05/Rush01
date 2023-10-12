/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:53:59 by damedina          #+#    #+#             */
/*   Updated: 2023/07/16 22:07:12 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		test(int **matrix, int**params, int size);
int		test_up(int **matrix, int col, int up, int size);
int		test_down(int **matrix, int col, int down, int size);
int		test_left(int **matrix, int row, int left, int size);
int		test_right(int **matrix, int row, int right, int size);
int		**create_matrix(int n);
void	show_matrix(int **matrix, int size);
int		**obtain_params(char *argv, int size);
int		rush(int **matrix, int **params, int posibilities[24][4], int size);
int		correct_params(int **params, int size);
int		count_n(int **params, int size, int n);
int		count_params(int num, int n);
int		check_opposite(int **params, int size);
int		check_opposite_number(int n1, int n2);

int	errors_argv(char *argv, int size)
{
	int	i;
	int	num_params;

	i = 0;
	num_params = 0;
	while (argv[i] != '\0' && argv[i + 1] != '\0')
	{
		if (argv[i] >= '1' && argv[i] <= (size + '0') && (argv[i + 1] == ' '))
			num_params++;
		else
			return (1);
		i += 2;
	}
	if (argv[i] >= '1' && argv[i] <= (size + '0') && (argv[i + 1] == '\0'))
		num_params++;
	if (num_params == (size * size))
		return (0);
	return (1);
}

int	complete(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (matrix[i][j] < 1 || matrix[i][j] > size)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	no_repeats(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (matrix[0][i] == matrix[1][i] || matrix[0][i] == matrix[2][i] ||
				matrix[0][i] == matrix[3][i])
			return (0);
		if (matrix[1][i] == matrix[2][i] || matrix[1][i] == matrix[3][i])
			return (0);
		if (matrix[2][i] == matrix[3][i])
			return (0);
		i++;
	}
	return (1);
}

int	try_posibilities(int **matrix, int posibilities[24][4],
		int **params, int size)
{
	int	row1;
	int	row2;
	int	row3;
	int	row4;

	row1 = 0;
	while (row1 < 24)
	{
		row2 = 0;
		while (row2 < 24)
		{
			row3 = 0;
			while (row3 < 24)
			{
				row4 = 0;
				while (row4 < 24)
				{
					matrix[0] = posibilities[row1];
					matrix[1] = posibilities[row2];
					matrix[2] = posibilities[row3];
					matrix[3] = posibilities[row4];
					if (complete(matrix, size) == 1
						&& test(matrix, params, size) == 1
						&& no_repeats(matrix, size) == 1)
					{
						show_matrix(matrix, size);
						return (1);
					}
					row4++;
				}
				row3++;
			}
			row2++;
		}
		row1++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	size;
	int	result;
	int	**matrix;
	int	**params;
	int	posibilities[24][4] = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2}, {1, 4, 2, 3}, {1, 4, 3, 2},
	{2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4}, {2, 3, 4, 1}, {2, 4, 1, 3}, {2, 4, 3, 1},
	{3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, {3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1},
	{4, 1, 2, 3}, {4, 1, 3, 2}, {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};

	size = 4;
	if (argc != 2 || errors_argv(argv[1], size) == 1)
	{
		write(1, "Error de sintaxis\n", 18);
		return (1);
	}
	matrix = create_matrix(size);
	params = obtain_params(argv[1], size);
	result = rush(matrix, params, posibilities, size);
	free(matrix);
	free(params);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:59:29 by damedina          #+#    #+#             */
/*   Updated: 2023/07/16 21:46:36 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		test(int **matrix, int**params, int size);
int		test_up(int **matrix, int col, int up, int size);
int		test_down(int **matrix, int col, int down, int size);
int		test_left(int **matrix, int row, int left, int size);
int		test_right(int **matrix, int row, int right, int size);
int		correct_params(int **params, int size);
int		count_n(int **params, int size, int n);
int		count_params(int num, int n);
int		check_opposite(int **params, int size);
int		check_opposite_number(int n1, int n2);
int		try_posibilities(int **matrix, int posibilities[24][4],
			int **params, int size);

int	**create_matrix(int n)
{
	int	**matrix;
	int	i;

	i = 0;
	matrix = (int **)malloc(n * 8);
	while (i < n)
	{
		matrix[i] = (int *)malloc(n * 4);
		i++;
	}
	return (matrix);
}

void	show_matrix(int **matrix, int size)
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	**obtain_params(char *argv, int size)
{
	int	**params;
	int	i;
	int	j;
	int	index;

	params = create_matrix(size);
	index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			params[i][j] = (int)(argv[index] - '0');
			j++;
			index += 2;
		}
		i++;
	}
	return (params);
}

int	rush(int **matrix, int **params, int posibilities[24][4], int size)
{
	if (correct_params(params, size) == 0 || check_opposite(params, size) == 0)
	{
		write(1, "Error de argumentos\n", 18);
		return (1);
	}
	if (try_posibilities(matrix, posibilities, params, size) == 0)
	{
		write(1, "Error de posibilidades\n", 18);
		return (1);
	}
	return (0);
}

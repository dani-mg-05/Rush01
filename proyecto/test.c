/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:53:01 by damedina          #+#    #+#             */
/*   Updated: 2023/07/16 20:53:41 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_up(int **matrix, int col, int up, int size)
{
	int	i;
	int	biggest;
	int	num;

	i = 0;
	num = 1;
	biggest = matrix[0][col];
	while (i < size - 1)
	{
		if (biggest < matrix [i + 1][col])
		{
			num++;
			biggest = matrix[i + 1][col];
		}
		i++;
	}
	if (num == up)
		return (1);
	return (0);
}

int	test_down(int **matrix, int col, int down, int size)
{
	int	i;
	int	biggest;
	int	num;

	i = size - 1;
	num = 1;
	biggest = matrix[size - 1][col];
	while (i > 0)
	{
		if (biggest < matrix[i - 1][col])
		{
			num++;
			biggest = matrix[i - 1][col];
		}
		i--;
	}
	if (num == down)
		return (1);
	return (0);
}

int	test_left(int **matrix, int row, int left, int size)
{
	int	i;
	int	biggest;
	int	num;

	i = 0;
	num = 1;
	biggest = matrix[row][0];
	while (i < size - 1)
	{
		if (biggest < matrix[row][i + 1])
		{
			num++;
			biggest = matrix[row][i + 1];
		}
		i++;
	}
	if (num == left)
		return (1);
	return (0);
}

int	test_right(int **matrix, int row, int right, int size)
{
	int	i;
	int	biggest;
	int	num;

	i = size - 1;
	num = 1;
	biggest = matrix[row][size - 1];
	while (i > 0)
	{
		if (biggest < matrix[row][i - 1])
		{
			num++;
			biggest = matrix[row][i - 1];
		}
		i--;
	}
	if (num == right)
		return (1);
	return (0);
}

int	test(int **matrix, int**params, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (test_up(matrix, i, params[0][i], size) == 0)
			return (0);
		if (test_down(matrix, i, params[1][i], size) == 0)
			return (0);
		if (test_left(matrix, i, params[2][i], size) == 0)
			return (0);
		if (test_right(matrix, i, params[3][i], size) == 0)
			return (0);
		i++;
	}
	return (1);
}

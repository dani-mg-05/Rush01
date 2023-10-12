/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:32:13 by damedina          #+#    #+#             */
/*   Updated: 2023/07/16 21:34:40 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_opposite_number(int n1, int n2)
{
	if ((n1 == 1) && (n2 == 2 || n2 == 3 || n2 == 4))
		return (1);
	if ((n1 == 2) && (n2 == 1 || n2 == 2 || n2 == 3))
		return (1);
	if ((n1 == 3) && (n2 == 1 || n2 == 2))
		return (1);
	if ((n1 == 4) && (n2 == 1))
		return (1);
	return (0);
}

int	check_opposite(int **params, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (check_opposite_number (params[i][j], params[i + 1][j]) == 0)
				return (0);
			j++;
		}
		i += 2;
	}
	return (1);
}

int	count_params(int num, int n)
{
	if (n == 1 && num == 1)
		return (1);
	if (n == 2 && num <= 3)
		return (1);
	if (n == 3 && num <= 2)
		return (1);
	if (n == 4 && num <= 1)
		return (1);
	return (0);
}

int	count_n(int **params, int size, int n)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < size)
	{
		num = 0;
		j = 0;
		while (j < size)
		{
			if (params[i][j] == n)
				num++;
			j++;
		}
		if (count_params(num, n) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	correct_params(int **params, int size)
{
	if (count_n(params, size, 1) != 1)
		return (0);
	if (count_n(params, size, 2) != 1)
		return (0);
	if (count_n(params, size, 3) != 1)
		return (0);
	if (count_n(params, size, 4) != 1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:48 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/06 14:17:10 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* return number of digits of an int */
int	ft_digitcount(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

/* return number of digits of an int (hex) */
int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

/* return number of digits in a int (long hex)*/
int	ft_hexlen_long(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

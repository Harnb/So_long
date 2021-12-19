/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:30:29 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/18 10:57:21 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoalloc(size_t size)
{
	char	*str;

	if (!size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_memset(str, '\0', size + 1);
	return (str);
}

static int	ft_count_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	char		*dst;
	int			count;
	int			i;
	long int	n;

	n = num;
	count = ft_count_size(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	dst = ft_itoalloc(count);
	if (!dst)
		return (NULL);
	if (n < 0 && i++ != -1)
	{
		n *= -1;
		dst[0] = '-';
	}
	while (count-- > i)
	{
		dst[count] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}

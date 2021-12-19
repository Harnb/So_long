/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:42 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/06 13:59:21 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* return 1 if 'C' is a letter. else 0 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* return : 1 if c is uppercase, 0 lowercase, -1 not a letter */
int	ft_isupperalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (0);
	return (-1);
}

/* return lowercase or the same char if 'c' is not uppercase letter */
int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c <= 'Z')
		return (c + 32);
	return (c);
}

/* Same as lowercase but uppercase */
int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a')
		return (c - 32);
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:21:56 by rlachau           #+#    #+#             */
/*   Updated: 2021/11/30 10:25:54 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m_zero;

	m_zero = malloc(count * size);
	if (m_zero == NULL)
		return (NULL);
	ft_bzero(m_zero, size * count);
	return (m_zero);
}

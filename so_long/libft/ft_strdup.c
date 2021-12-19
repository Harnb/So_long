/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*	 ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:59:03 by rlachau           #+#    #+#             */
/*   Updated: 2021/10/29 02:31:49 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dup_src;

	i = 0;
	len = ft_strlen(s1);
	dup_src = (char *)malloc(sizeof(*dup_src) * (len + 1));
	if (dup_src == NULL)
		return (NULL);
	while (i < len)
	{
		dup_src[i] = s1[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}

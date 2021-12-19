/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:41:38 by rlachau           #+#    #+#             */
/*   Updated: 2021/10/29 02:36:37 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_f;

	i = -1;
	if (!s || !f)
		return (NULL);
	s_f = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s_f)
		return (NULL);
	while (s[++i])
		s_f[i] = f(i, s[i]);
	s_f[i] = '\0';
	return (s_f);
}

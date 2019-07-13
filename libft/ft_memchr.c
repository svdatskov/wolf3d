/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:24:21 by sdatskov          #+#    #+#             */
/*   Updated: 2018/10/24 16:24:25 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*arr;
	size_t	i;

	arr = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)arr[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:25:51 by hguo              #+#    #+#             */
/*   Updated: 2025/04/23 12:26:30 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;
	size_t				i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		if (p[i] == (unsigned char)value)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

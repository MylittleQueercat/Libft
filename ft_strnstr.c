/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:48 by hguo              #+#    #+#             */
/*   Updated: 2025/04/23 13:26:49 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	if (!*to_find)
		return ((char *)str);
	while (*str && len > 0)
	{
		i = 0;
		while (str[i] == to_find[i] && to_find[i] && (i < len))
			i++;
		if (!to_find[i])
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}

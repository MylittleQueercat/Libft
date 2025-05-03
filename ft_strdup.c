/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:21:25 by hguo              #+#    #+#             */
/*   Updated: 2025/04/23 13:21:26 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	while (src[i])
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		copy[j] = src[j];
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

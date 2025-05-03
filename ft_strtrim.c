/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:27:07 by hguo              #+#    #+#             */
/*   Updated: 2025/05/01 19:02:45 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end == 0 || start == end)
		return (ft_strdup(""));
	end--;
	while (end > start && ft_isset(s1[end], set))
		end--;
	result = (char *)malloc(end - start + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*res1;
	char	*res2;

	res1 = ft_strtrim("!code!", "!co");
	res2 = ft_strtrim("..happy...", ".");
	printf("%s\n", res1);
	printf("%s\n", res2);
	return (0);
}*/

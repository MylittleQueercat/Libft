/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:19:13 by hguo              #+#    #+#             */
/*   Updated: 2025/04/23 13:44:11 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char character, char sep)
{
	return (character == sep);
}

static int	count_words(const char *str, char sep)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_sep(str[i], sep))
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*allocate_word(const char *str, char sep)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_sep(str[i], sep))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	array = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_sep(s[i], c))
		{
			array[j] = allocate_word(&s[i], c);
			if (!array[j])
				return (NULL);
			while (s[i] && !is_sep(s[i], c))
				i++;
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}

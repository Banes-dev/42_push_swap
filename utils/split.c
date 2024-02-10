/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:31:16 by ehay              #+#    #+#             */
/*   Updated: 2024/02/01 13:56:45 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**_free(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

void	ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**split(char const *s, char *sep)
{
	char		**split;
	size_t		split_count;
	size_t		i;

	split_count = ft_count_word(s, sep);
	split = malloc((split_count + 1) * sizeof(char *));
	if (split)
	{
		i = 0;
		while (i < split_count + 1)
		{
			while (*s && ft_strchr(sep, *s))
				s++;
			split[i] = ft_strndup(s, ft_word_len(s, sep));
			if (!split[i])
				return (_free(split, i));
			while (*s && !ft_strchr(sep, *s))
				s++;
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}

// static int	count_words(char *s, char c)
// {
// 	int		count;
// 	int		inside_word;

// 	count = 0;
// 	while (*s)
// 	{
// 		inside_word = 0;
// 		while (*s == c)
// 			++s;
// 		while (*s != c && *s)
// 		{
// 			if (!inside_word)
// 			{
// 				++count;
// 				inside_word = 1;
// 			}
// 			++s;
// 		}
// 	}
// 	return (count);
// }

// static char	*get_next_word(char *s, char c)
// {
// 	static int	cursor = 0;
// 	char		*next_word;
// 	int			len;
// 	int			i;

// 	len = 0;
// 	i = 0;
// 	while (s[cursor] == c)
// 		++cursor;
// 	while ((s[cursor + len] != c) && s[cursor + len])
// 		++len;
// 	next_word = malloc((size_t)len * sizeof(char) + 1);
// 	if (!next_word)
// 		return (NULL);
// 	while ((s[cursor] != c) && s[cursor])
// 		next_word[i++] = s[cursor++];
// 	next_word[i] = '\0';
// 	return (next_word);
// }

// char	**split(char *s, char c)
// {
// 	int		words_count;
// 	char	**result_array;
// 	int		i;

// 	i = 0;
// 	words_count = count_words(s, c);
// 	if (!words_count)
// 		exit(1);
// 	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
// 	if (!result_array)
// 		return (NULL);
// 	while (words_count-- >= 0)
// 	{
// 		if (i == 0)
// 		{
// 			result_array[i] = malloc(sizeof(char));
// 			if (!result_array[i])
// 				return (NULL);
// 			result_array[i++][0] = '\0';
// 			continue ;
// 		}
// 		result_array[i++] = get_next_word(s, c);
// 	}
// 	result_array[i] = NULL;
// 	return (result_array);
// }

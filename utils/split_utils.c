/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:26:24 by ehay              #+#    #+#             */
/*   Updated: 2024/01/31 13:27:23 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_word_len(char const *str, char const *sep)
{
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && !ft_strchr(sep, str[word_len]))
		word_len++;
	return (word_len);
}

size_t	ft_count_word(char const *str, char const *sep)
{
	size_t	word_count;
	size_t	word_len;

	word_count = 0;
	while (*str)
	{
		word_len = ft_word_len(str, sep);
		if (word_len)
		{
			str += word_len;
			word_count++;
		}
		else
			str++;
	}
	return (word_count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (len < n && s[len])
		len++;
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s, len + 1);
	return (dst);
}

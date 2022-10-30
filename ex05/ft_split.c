/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:27:36 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/29 23:33:29 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_word(char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 1;
	if (*charset == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j] == str[i + j])
		{
			if (charset[j + 1] == '\0')
			{
				word++;
			}
			j++;
		}
		i++;
	}
	return (word);
}

int	char_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

void	write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_word(char **res, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], charset) == 0)
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(res[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = count_word(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words - 1] = 0;
	split_word(res, str, charset);
	return (res);
}

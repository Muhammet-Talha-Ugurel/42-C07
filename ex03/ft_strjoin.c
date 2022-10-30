/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:07:16 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/29 02:32:02 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*total_lenght(int size, char **strs, char *size_sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (i > size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (size <= 0)
				len = 1;
	len += ft_strlen(size_sep);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	joined = total_lenght(size, strs, sep);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			joined[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			joined[k++] = sep[j];
			j++;
		}
	}
	joined[k] = '\0';
	return (joined);
}

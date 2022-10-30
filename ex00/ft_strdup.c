/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:00:17 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/28 23:47:59 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpstr;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	cpstr = (char *)malloc(i + 1 * sizeof(char));
	if (cpstr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cpstr[i] = src[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}

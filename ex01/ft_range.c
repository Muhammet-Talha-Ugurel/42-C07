/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:28:51 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/28 23:47:57 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*arry;

	len = max - min;
	if (min >= max)
		return (NULL);
	arry = (int *)malloc(len * sizeof(int));
	if (arry == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (++i < max - min)
		{
			arry[i] = min + i;
		}
	}
	return (arry);
}

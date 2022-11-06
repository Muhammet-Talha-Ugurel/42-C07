/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:48:32 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/29 20:32:13 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

void	ft_baserror(char *base, int *erreur)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		*erreur = 1;
	while (base[i] && *erreur == 0)
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				*erreur = 1;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.'
			|| base[i] < 33 || base[i] > 126)
			*erreur = 1;
		else
			i++;
	}
}

void	ft_putnbr_base_len(int nbr, char *base, int *len)
{
	int	erreur;
	int	basel;
	int	n;

	n = nbr;
	basel = 0;
	erreur = 0;
	ft_baserror(base, &erreur);
	if (n < 0 && erreur == 0)
	{
		n *= -1;
		nbr *= -1;
		*len = *len + 1;
	}
	while (base[basel] != '\0' && erreur == 0)
		basel++;
	if (nbr >= basel && erreur == 0)
	{
		ft_putnbr_base_len(n / basel, base, len);
		ft_putnbr_base_len(n % basel, base, len);
	}
	else if (erreur == 0)
	{
		*len = *len + 1;
	}
}

void	ft_putnbr_base(int nbr, char *base, int *i, char **ret)
{
	int		basel;
	int		n;

	n = nbr;
	basel = 0;
	if (n < 0)
	{
		n *= -1;
		nbr *= -1;
		ret[0][*i] = '-';
		*i = *i + 1;
	}
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		ft_putnbr_base(n / basel, base, i, ret);
		ft_putnbr_base(n % basel, base, i, ret);
	}
	else
	{
		ret[0][*i] = base[n];
		*i = *i + 1;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from;
	int		i;
	char	*ret;
	int		len;

	i = 0;
	len = 0;
	from = ft_atoi_base(nbr, base_from);
	ft_putnbr_base_len(from, base_to, &len);
	ret = (char *)malloc((len + 1) * sizeof(char));
	ft_putnbr_base(from, base_to, &i, &ret);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:04:05 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/12 11:23:14 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_nbrbase_rec(unsigned int nbr, int bytes, int b_len, char *base)
{
	if (nbr < b_len)
	{
		write(1, &base[nbr], 1);
		bytes++;
	}
	else
	{
		pf_nbrbase_rec(nbr / b_len, bytes, b_len, base);
		write(1, &base[nbr % b_len], 1);
		bytes++;
	}
}

void	ft_puthex_lower(unsigned int nbr, int bytes)
{
	pf_nbrbase_rec(nbr, bytes, 16, "0123456789abcdef");
}

void	ft_puthex_upper(unsigned int nbr, int bytes)
{
	pf_nbrbase_rec(nbr, bytes, 16, "0123456789ABCDEF");
}

void	ft_putunbr(unsigned int nbr, int bytes)
{
	char	*base;

	base = "0123456789";
	if (nbr < 10)
	{
		write(1, &base[nbr], 1);
		bytes++;
	}
	else
	{
		ft_putunbr(nbr / 10, bytes);
		write(1, &base[nbr % 10], 1);
		bytes++;
	}
}

void	ft_putnbr_pf(int nbr, int bytes)
{
	char	*base;

	base = "0123456789";
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		bytes = bytes + 11;
	}
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
			bytes++;
		}
		if (nbr < 10)
		{
			write(1, &base[nbr], 1);
			bytes++;
		}
		else
		{
			ft_putnbr_pf(nbr / 10, bytes);
			write(1, &base[nbr % 10], 1);
			bytes++;
		}
	}
}

void	ft_putaddr(intptr_t ptr, int bytes)
{
	char		*hex;

	hex = "0123456789abcdef";
	if (ptr < 16)
	{
		write(1, "0x", 2);
		write(1, &hex[ptr], 1);
		bytes += 3;
		return ;
	}
	else
	{
		ft_putaddr(ptr / 16, bytes);
		write(1, &hex[ptr % 16], 1);
		bytes++;
	}
}

void	ft_putchar_pf(char c, int bytes)
{
	write(1, &c, 1);
	bytes++;
}

void	ft_putstr_pf(char *str, int bytes)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	bytes = bytes + len;
}

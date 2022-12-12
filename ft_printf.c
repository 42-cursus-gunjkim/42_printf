/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:47:03 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/12 11:16:28 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char cur_type, va_list arg, int bytes)
{
	if (cur_type == 'd' || cur_type == 'i')
		ft_putnbr_pf(va_arg(arg, int), bytes);
	else if (cur_type == 'c')
		ft_putchar_pf((char)va_arg(arg, int), bytes);
	else if (cur_type == 's')
		ft_putstr_pf(va_arg(arg, char *), bytes);
	else if (cur_type == 'p')
		ft_putaddr(va_arg(arg, intptr_t), bytes);
	else if (cur_type == 'u')
		ft_putunbr(va_arg(arg, unsigned int), bytes);
	else if (cur_type == 'x')
		ft_puthex_lower(va_arg(arg, unsigned int), bytes);
	else if (cur_type == 'X')
		ft_puthex_upper(va_arg(arg, unsigned int), bytes);
	else if (cur_type == '%')
		ft_putchar_pf('%', bytes);
}

int	ft_printf(const char *str, ...)
{
	int			index;
	static int	bytes;
	va_list		arg;

	index = 0;
	bytes = 0;
	va_start(arg, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			print_format(str[index], arg, bytes);
		}
		else
			ft_putchar_pf(str[index], 1);
		index++;
	}
	va_end(arg);
	return (bytes);
}

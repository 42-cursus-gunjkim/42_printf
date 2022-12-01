/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:47:03 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/01 23:57:56 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "ft_printf.h"

void	*find_cur(va_list *arg, const char c)
{
	void	*cur;

	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		cur = va_arg(*arg, int);
	else if (c == 'c')
		cur = va_arg(*arg, char);
	else if (c == 'u')
		cur = va_arg(*arg, unsigned int);
	else if (c == 's')
		cur = va_arg(*arg, const char *);
	else if (c == 'p')
		cur = va_arg(*arg, void *);
	else
		cur = NULL;
	return (cur);
}

void	print_format(t_format cur)
{
	if (cur.type == 'd' || cur.type == 'i')
		ft_putnbr_fd(cur.content, 1);
	else if (cur.type == 'c')
		ft_putchar_fd(cur.content, 1);
	else if (cur.type == 's')
		ft_putstr_fd(cur.content, 1);
	else if (cur.type == 'p')
		ft_put_addr(cur, 1);
	else if (cur.type == 'u')
		ft_put_unbr(cur, 1);
	else if (cur.type == 'x')
		ft_put_hex_lower(cur, 1);
	else if (cur.type == 'X')
		ft_put_hex_upper(cur, 1);
}

int	ft_printf(const char *str, ...)
{
	int			index;
	va_list		arg;
	t_format	cur;

	index = 0;
	va_start(arg, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			if (str[index] == '%')
				ft_putchar_fd('%', 1);
			else
			{
				cur.content = find_cur(&arg, str[index]);
				if (cur.content == NULL)
					return (-1);
				cur.type = str[index];
				print_format(cur);
			}
		}
		else
			ft_putchar_fd(str[index], 1);
		index++;
	}
	va_end(arg);
	return (index);
}

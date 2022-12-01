/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:04:05 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/01 23:57:54 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft.h"
//0~int 최대까지만 정상적으로 출력
//음수는 overflow 된 상태로 출력됨

static void	hex_recur_part(char *hex, unsigned int nbr, int fd)
{
	if (nbr < 16)
		write(fd, hex[nbr], 1);
	else
	{
		hex_recur_part(hex, nbr / 16, 1);
		write(fd, hex[nbr % 16], 1);
	}
}

static void	ft_put_hex_lower(t_format t, int fd)
{
	char			*hex;
	unsigned int	nbr;

	nbr = (unsigned int)(*(t.content));
	hex = "0123456789abcdef";
	hex_recur_part(hex, nbr, fd);
}

static void	ft_put_hex_upper(t_format t, int fd)
{
	char			*hex;
	unsigned int	nbr;

	nbr = (unsigned int)(*(t.content));
	hex = "0123456789ABCDEF";
	hex_recur_part(hex, nbr, fd);
}

static void	ft_put_unbr(t_format t, int fd);
static void	ft_put_addr(t_format t, int fd);
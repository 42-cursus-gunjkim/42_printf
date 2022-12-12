/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:50:46 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/12 11:16:19 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	void	*content;
	char	type;
}	t_format;

int		ft_printf(const char *str, ...);
void	ft_puthex_lower(unsigned int nbr, int bytes);
void	ft_puthex_upper(unsigned int nbr, int bytes);
void	ft_putunbr(unsigned int nbr, int bytes);
void	ft_putaddr(intptr_t ptr, int bytes);
void	ft_putchar_pf(char c, int bytes);
void	ft_putstr_pf(char *str, int bytes);
void	ft_putnbr_pf(int nbr, int bytes);

#endif

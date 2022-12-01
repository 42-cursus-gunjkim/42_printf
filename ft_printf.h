/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:50:46 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/01 19:12:06 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_format
{
	void	*content;
	char	type;
}	t_format;

int	ft_printf(const char *str, ...);
static void	ft_put_hex_lower(t_format t, int fd);
static void	ft_put_hex_upper(t_format t, int fd);
static void	ft_put_unbr(t_format t, int fd);
static void	ft_put_addr(t_format t, int fd);

#endif

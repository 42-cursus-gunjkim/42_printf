/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:04:05 by gunjkim           #+#    #+#             */
/*   Updated: 2022/12/01 19:12:05 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex_lower(t_format t, int fd);
static void	ft_put_hex_upper(t_format t, int fd);
static void	ft_put_unbr(t_format t, int fd);
static void	ft_put_addr(t_format t, int fd);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:56:36 by egaraz            #+#    #+#             */
/*   Updated: 2018/04/03 17:56:37 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_iter(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->i_max)
	{
		e->mdb->tmp = e->mdb->zr;
		e->mdb->zr = e->mdb->zr * e->mdb->zr - e->mdb->zi * e->mdb->zi +
			e->mdb->cr;
		e->mdb->zi = 2 * e->mdb->zi * e->mdb->tmp + e->mdb->ci;
		if (e->mdb->zr * e->mdb->zr + e->mdb->zi * e->mdb->zi >= 4)
			return (i);
	}
	return (i);
}

void		mandelbrot(t_env *e)
{
	intmax_t	x;
	intmax_t	y;

	x = e->x;
	while (++x < e->win_width + e->x)
	{
		y = e->y;
		while (++y < e->win_height + e->y)
		{
			e->mdb->zr = 0;
			e->mdb->zi = 0;
			e->mdb->cr = (long double)x / e->z + e->mdb->x1;
			e->mdb->ci = (long double)y / e->z + e->mdb->y1;
			put_pxl(e, x - e->x, y - e->y, get_color(mandelbrot_iter(e), e));
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_info(e);
}

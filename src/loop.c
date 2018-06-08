/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:57:12 by egaraz            #+#    #+#             */
/*   Updated: 2018/04/03 17:57:13 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		loop_hook(t_env *e)
{
	if (e->psychedelic == 1)
	{
		psychedelic(e);
		e->fractal(e);
	}
	if (e->zoom_auto == 1)
	{
		zoom_auto(e);
		e->fractal(e);
	}
	return (0);
}

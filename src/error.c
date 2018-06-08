/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:57:43 by egaraz            #+#    #+#             */
/*   Updated: 2018/04/03 17:57:44 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_arg(void)
{
	write(1, "Usage <filename> [mandelbrot/julia/burningship]\n", 48);
	exit(1);
}

void	error_malloc(void)
{
	write(1, "Malloc error\n", 13);
}

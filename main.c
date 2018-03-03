#include "fractol.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct  s_map
{
    void    *img;
    void    *ptr;
    void    *win;
    int     zoom;
    char    *str;
}               t_map;

void    zoom(t_map *map)
{
    double  c_re;
    double  c_im;
    int     max;
    int     i;
    int     len;
    int     j;
    double  x;
    double  y;
    int     interation;
    double  x_new;

    mlx_clear_window(map->ptr, map->win);
    len = 1000;
    ft_bzero(map->str, len * len * 4);
    max = 25;
    i = -1;
    while (++i < len)
    {
        j = -1;
        while (++j < len)
        {
			if (j != 0)
			{
           		c_re = (j - map->zoom / 2.0) * 4.0 / map->zoom;
                c_im = (i - map->zoom / 2.0) * 4.0 / map->zoom;
			}
            x = 0;
            y = 0;
            interation = 0;
            while (x * x + y * y <= 4 && interation < max)
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                interation++;
            }
            if (interation < max && i > 0 && i < len && j > 0 && j < len)
                *(int*)(map->str + (j + i * len) * 4) = 0xffffff;
            else if (i > 0 && i < len && j > 0 && j < len)
                *(int*)(map->str + (j + i * len) * 4) = 0x670000;
        }
    }
    map->zoom *= 1.5;
    mlx_put_image_to_window(map->ptr, map->win, map->img, 0, 0);
}

int    key_hook(int keycode, t_map *map)
{
    if (keycode == 53)
    {
        mlx_destroy_window(map->ptr, map->win);
        exit(0);
    }
    if (keycode == 7)
        zoom(&*map);
    return(0);
}

int main(int a, char **s)
{
    int     j;
    int     i;
    double  c_re;
    double  c_im;
    int  len;
    double  x;
    double  y;
    double  x_new;
    int     interation;
    int     max;
    int     b;
    int     size;
    int     e;
    t_map   map;

    
    len = 1000;
    map.zoom = len;
    (void)s;
    if (a == 1)
        (void)s;
    map.ptr = mlx_init();
    map.win = mlx_new_window(map.ptr, len, len, "fractol");
    map.img = mlx_new_image(map.ptr, len, len);
    map.str = mlx_get_data_addr(map.img, &b, &size, &e);
    ft_bzero(map.str, len * len * 4);
    max = 25;
    i = -1;
    while (++i < len)
    {
        j = -1;
        while (++j < len)
        {
			if (j != 0)
			{
           		c_re = (j - map.zoom / 2.0) * 4.0 / map.zoom;
                c_im = (i - map.zoom / 2.0) * 4.0 / map.zoom;
			}
            x = 0;
            y = 0;
            interation = 0;
            while (x * x + y * y <= 4 && interation < max)
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                interation++;
            }
            if (interation < max && i > 0 && i < len && j > 0 && j < len)
            {
                *(int*)(map.str + (j + i * len) * 4) = 0xffffff;
            }
            else if (i > 0 && i < len && j > 0 && j < len)
            {
                *(int*)(map.str + (j + i * len) * 4) = 0x670000;
            }
        }
    }
    map.zoom *= 1.5;
    mlx_put_image_to_window(map.ptr, map.win, map.img, 0, 0);
    mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.ptr);
	return (0);
}

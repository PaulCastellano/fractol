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
    int     max;
    int     b;
    int     size;
    int     e;
    int     len;
}               t_map;

void    zoom(t_map *map)
{
    double  c_re;
    double  c_im;
    int     i;
    int     j;
    double  x;
    double  y;
    int     interation;
    double  x_new;
    int     cor;

    map->zoom += 500;
    mlx_clear_window(map->ptr, map->win);
    mlx_destroy_image(map->ptr, map->img);
    map->img = mlx_new_image(map->ptr, map->zoom, map->zoom);
    map->str = mlx_get_data_addr(map->img, &map->b, &map->size, &map->e);
    ft_bzero(map->str, map->zoom * map->zoom * 4);
    if (map->max != 200)
        map->max += 20;
    i = -1;
    while (++i < map->zoom)
    {
        j = -1;
        while (++j < map->zoom)
        {
			if (j != 0)
			{
           		c_re = (j - map->zoom / 2.0) * 4.0 / map->zoom;
                c_im = (i - map->zoom / 2.0) * 4.0 / map->zoom;
			}
            x = 0;
            y = 0;
            interation = 0;
            while (x * x + y * y <= 4 && interation < map->max)
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                interation++;
            }
            if (interation < map->max && i > 0 && i < map->zoom && j > 0 && j < map->zoom)
                *(int*)(map->str + (j + i * map->zoom) * 4) = 0xffffff;
            else if (i > 0 && i < map->zoom && j > 0 && j < map->zoom)
                *(int*)(map->str + (j + i * map->zoom) * 4) = 0x670000;
        }
    }
    mlx_put_image_to_window(map->ptr, map->win, map->img, 0 - 300, 0 - 300);
}

int    key_hook(int keycode, t_map *map)
{
    ft_printf("%d",keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(map->ptr, map->win);
        exit(0);
    }
    if (keycode == 120)
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
    int     b;
    int     size;
    int     e;
    t_map   map;

    
    len = 1000;
    map.zoom = len;
    map.len = len;
    (void)s;
    if (a == 1)
        (void)s;
    map.ptr = mlx_init();
    map.win = mlx_new_window(map.ptr, len, len, "fractol");
    map.img = mlx_new_image(map.ptr, len, len);
    map.str = mlx_get_data_addr(map.img, &map.b, &map.size, &map.e);
    ft_bzero(map.str, map.zoom * map.zoom * 4);
    map.max = 50;
    i = -1;
    while (++i < map.zoom)
    {
        j = -1;
        while (++j < map.zoom)
        {
			if (j != 0)
			{
           		c_re = (j - map.zoom / 2.0) * 4.0 / map.zoom;
                c_im = (i - map.zoom / 2.0) * 4.0 / map.zoom;
			}
            x = 0;
            y = 0;
            interation = 0;
            while (x * x + y * y <= 4 && interation < map.max)
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                interation++;
            }
            if (interation < map.max && i > 0 && i < len && j > 0 && j < len)
            {
                *(int*)(map.str + (j + i * len) * 4) = 0xffffff;
            }
            else if (i > 0 && i < len && j > 0 && j < len)
            {
                *(int*)(map.str + (j + i * len) * 4) = 0x670000;
            }
        }
    }
    mlx_put_image_to_window(map.ptr, map.win, map.img, 0, 0);
    mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.ptr);
	return (0);
}

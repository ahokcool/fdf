/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:31:40 by astein            #+#    #+#             */
/*   Updated: 2023/05/17 23:24:23 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftf.h"

void	put_point(t_win *win, t_point *point, int color)
{
	mlx_pixel_put(win->mlx, win->win, point->x, point->y, color);
}

void	put_line(t_win *win, t_point *pnt_a, t_point *pnt_b, int color)
{
	t_point	*curr_point;
	t_point	*delta;
	t_point	*sign;
	int		err;
	int		e2;
curr_point= malloc(sizeof(t_point));
	delta = malloc(sizeof(t_point));
	sign = malloc(sizeof(t_point));
	curr_point->x = pnt_a->x;
	curr_point->y = pnt_a->y;
	delta->x = abs(pnt_b->x - curr_point->x);
	delta->y = -abs(pnt_b->y - curr_point->y);
	if (curr_point->x < pnt_b->x)
		sign->x = 1;
	else
		sign->x = -1;
	if (curr_point->y < pnt_b->y)
		sign->y = 1;
	else
		sign->y = -1;
	err = delta->x + delta->y;
	while (1)
	{
		put_point(win, curr_point, 0x00FFFF);
		if (curr_point->x == pnt_b->x && curr_point->y == pnt_b->y)
			break ;
		e2 = 2 * err;
		if (e2 > delta->y)
		{
			err += delta->y;
			curr_point->x += sign->x;
		}
		if (e2 < delta->x)
		{
			err += delta->x;
			curr_point->y += sign->y;
		}
	}
}

int	deal_key(int key, void *param)
{
	ft_printf("Key pressed: %c (%i)\n", key, key);
	// ft_putstr_fd("Key pressed: ", 1);
	// ft_putchar_fd(key, 1);
	if (key == 'q')
		exit(0);
	if (key == K_ARROW_DOWN)
	{
		// tparam->y =param->y +1;
	}
	return (0);
}

void	*ini_win(int width, int heigth, char *title)
{
	t_win	*new_window;

	new_window = malloc(sizeof(t_win));
	if (!new_window)
		return (NULL);
	new_window->mlx = mlx_init();
	new_window->win = mlx_new_window(new_window->mlx, width, heigth, title);
	return (new_window);
}

int	main(void)
{
	t_win	*window;
	t_point	*curr_point;
	t_point	*curr_point2;
	t_point	*curr_point3;
	t_point	*curr_point4;

	// void	*mlx_ptr;
	// void	*win_ptr;
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Hello World");
	ft_putstr_fd("Lets go!\n\n", 1);
	window = ini_win(800, 800, "Hi");
	curr_point = malloc(sizeof(t_point));
	curr_point2 = malloc(sizeof(t_point));
	curr_point3 = malloc(sizeof(t_point));
	curr_point4 = malloc(sizeof(t_point));
	curr_point->x = 10;
	curr_point->y = 10;
	curr_point2->x = 500;
	curr_point2->y = 500;
	curr_point3->x = 500;
	curr_point3->y = 10;
	curr_point4->x = 400;
	curr_point4->y = 678;
	put_point(window, curr_point, 0x00FFFF);
	put_point(window, curr_point2, 0x00FFFF);
	put_point(window, curr_point3, 0x00FFFF);
	put_point(window, curr_point4, 0x00FFFF);
	put_line(window, curr_point, curr_point2, 0x00FFFF);
	put_line(window, curr_point2, curr_point3, 0x00FFFF);
	put_line(window, curr_point3, curr_point4, 0x00FFFF);
	put_line(window, curr_point4, curr_point, 0x00FFFF);
	mlx_key_hook(window->win, deal_key, curr_point);
	mlx_loop(window->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:02:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 17:42:29 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_mlx.h"
#include <stdio.h>

// <Controls>
// MB1 & Drag: Rotate
// MB2 & MB3 & Drag: Translate
// Scroll: Zoom in/out
// Key X/Y/Z: Rotate around x/y/z
// key I/P: Isometric/Parallel
// Key +/-: Flatten

static void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_X)
		fdf->camera->alpha += 0.03;
	else if (key == KEY_Y)
		fdf->camera->beta += 0.03;
	else if (key == KEY_Z)
		fdf->camera->gamma += 0.03;
	draw_fdf(fdf->map, fdf);
}

static void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISOMETRIC;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	draw_fdf(fdf->map, fdf);
}

static void	flatten(int key, t_fdf *fdf)
{
	if (key == KEY_EQUAL)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_MINUS)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 7)
		fdf->camera->z_divisor = 7;
	draw_fdf(fdf->map, fdf);
}

int	key_press(int key, t_fdf *fdf)
{
	if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		rotate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_EQUAL || key == KEY_MINUS)
		flatten(key, fdf);
	else if (key == KEY_ESCAPE)
	{
		free(fdf->map->arr_clr);
		free(fdf->map->arr_z);
		free(fdf->camera);
		free(fdf->mouse);
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		exit(0);
	}
	return (0);
}

int	quit(int key, t_fdf *fdf)
{
	if (key == KEY_ESCAPE)
	{
		free(fdf->map->arr_clr);
		free(fdf->map->arr_z);
		free(fdf->camera);
		free(fdf->mouse);
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		exit(0);
	}
	exit(0);
}

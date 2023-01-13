/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:28:48 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 16:48:11 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_draw_fct(t_point *s, t_point *f)
{
	free(s);
	s = NULL;
	free(f);
	f = NULL;
}

/*void	print_status_2(t_fdf *fdf)
{
	int		y;
	char	*buf = NULL;

	buf = malloc(sizeof(char *) * 10);
	y = 200;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "y_offset: ");
	mlx_string_put(fdf->mlx, fdf->win, 115, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->zoom);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "zoom: ");
	mlx_string_put(fdf->mlx, fdf->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->z_divisor);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "z_divisor: ");
	mlx_string_put(fdf->mlx, fdf->win, 125, y += 0, CLR_TEXT, buf);
}*/

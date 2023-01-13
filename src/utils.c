/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:02:50 by cormiere          #+#    #+#             */
/*   Updated: 2023/01/13 16:47:59 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	terminate(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror(str);
	exit(1);
}

void	push_node(t_node **stack, t_node *new_node)
{
	if (stack)
	{
		if (new_node)
			new_node->nxt = *stack;
		*stack = new_node;
	}
}

t_node	*pop_node(t_node **stack)
{
	t_node	*top;

	top = NULL;
	if (stack && *stack)
	{
		top = *stack;
		*stack = (*stack)->nxt;
	}
	return (top);
}

void	print_controls(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 20, CLR_TEXT, \
					"<Controls>");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"MB1 & Drag: Rotate");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"MB2 & MB3 & Drag: Translate");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Scroll: Zoom in/out");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Key X/Y/Z: Rotate around x/y/z");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"key I/P: Isometric/Parallel");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, \
					"Key +/-: Flatten");
}

/*void	print_status(t_fdf *fdf)
{
	int		y;
	char	buf[10];

	y = 200;
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 60, CLR_TEXT, "<Status>");
	sprintf(buf, "%f", fdf->camera->alpha);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "alpha: ");
	mlx_string_put(fdf->mlx, fdf->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->beta);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "beta: ");
	mlx_string_put(fdf->mlx, fdf->win, 75, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%f", fdf->camera->gamma);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "gamma: ");
	mlx_string_put(fdf->mlx, fdf->win, 85, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->x_offset);
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, CLR_TEXT, "x_offset: ");
	mlx_string_put(fdf->mlx, fdf->win, 115, y += 0, CLR_TEXT, buf);
	sprintf(buf, "%d", fdf->camera->y_offset);
	print_status_2(fdf);
}*/

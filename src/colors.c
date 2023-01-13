/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:01:51 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/15 15:20:10 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

int	get_default_clr(int z, t_map *map)
{
	double	ratio;

	ratio = get_ratio(map->z_min, map->z_max, z);
	if (ratio < 0.2)
		return (CLR_DISCO);
	else if (ratio < 0.4)
		return (CLR_BRICK_RED);
	else if (ratio < 0.6)
		return (CLR_FLAMINGO);
	else if (ratio < 0.8)
		return (CLR_JAFFA);
	else
		return (CLR_SAFFRON);
}

static int	do_lerp(int s, int f, double ratio)
{
	return ((int)((ratio) * s + (1 - ratio) * f));
}

int	get_clr(t_point cur, t_point *s, t_point *f, t_point delta)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (cur.clr == f->clr)
		return (cur.clr);
	if (delta.x > delta.y)
		ratio = get_ratio(s->x, f->x, cur.x);
	else
		ratio = get_ratio(s->y, f->y, cur.y);
	red = do_lerp((f->clr >> 16) & 0xFF, (s->clr >> 16) & 0xFF, ratio);
	green = do_lerp((f->clr >> 8) & 0xFF, (s->clr >> 8) & 0xFF, ratio);
	blue = do_lerp(f->clr & 0xFF, s->clr & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

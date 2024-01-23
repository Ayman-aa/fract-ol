/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:29:07 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/23 19:39:45 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract.h"

int mandelbrot(double a, double b)
{
    double r;
    double i;
    double t;
    int n;

    n = 0;
    i = 0;
    r = 0;

    while (n < ITERATION && mag(r, i) <= 2.0)
    {
        t = r;
        r = r * r - i * i + a;
        i = 2 * t * i + b;
        n++;
    }

    return n;
}
void    ft_mandelbrot(fractCfg *cfg)
{
    int i;
    int j;
    int iterate;

    i = 0;
    j = 0;
    while (j < HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            iterate = (mandelbrot((i - WIDTH / 2) / cfg->zoom, \
                    (j - HEIGHT / 2) / cfg->zoom) / ITERATION) * 255;
            draw_pixel(cfg, i, j, ft_trgb(0, iterate, iterate, iterate));
            i++;
        }
        j++;
    }
}
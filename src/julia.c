/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:51:52 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/24 18:35:35 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

int julia(double a, double b, fractCfg *cfg)
{
    double r;
    double i;
    double t;
    int n;

    n = 0;
    r = a;
    i = b;

    while (n < ITERATION && magnitude(r, i) <= 2.0)
    {
        t = r;
        r = r * r - i * i + cfg->julia_x;
        i = 2 * t * i + cfg->julia_y;
        n++;
    }

    return n;
}

void    ft_julia(fractCfg *cfg)
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
            iterate = (julia((cfg->zoom_x + i - WIDTH / 2) / cfg->zoom,
                            (cfg->zoom_y + j - HEIGHT / 2) / cfg->zoom,
                            cfg) / ITERATION) * 255;
            draw_pixel(cfg, i, j, ft_trgb(0, iterate, iterate, iterate));
            i++;
        }
        j++;
    }
}
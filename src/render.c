/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:26:13 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/23 19:39:53 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract.h"

void    render_set(fractCfg *cfg)
{
    cfg->img = mlx_new_image(cfg->mlx_ptr, WIDTH, HEIGHT);
    cfg->addr = mlx_get_data_addr(cfg->img, &cfg->bits_per_pixel,
            &cfg->line_length, &cfg->endian);
    mlx_clear_window(cfg->mlx_ptr, cfg->win_ptr);
    if (cfg->set == 1)
        ft_mandelbrot(cfg);
    else if (cfg->set == 2)
        ft_julia(cfg);
    mlx_put_image_to_window(cfg->mlx_ptr, cfg->win_ptr, cfg->img, 0, 0);
}

void    draw_pixel(fractCfg *cfg, int x, int y, int color)
{
    char *dst;

    dst = cfg->addr + (y * cfg->line_length + x * (cfg->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

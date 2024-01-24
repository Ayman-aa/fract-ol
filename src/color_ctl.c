/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ctl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:04:52 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/24 18:33:43 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

int color_comb1(double i)
{
    int              color;
    unsigned char    rgb;

    color = 0;
    rgb = 255 - i / ITERATION * 255.0;
    color = rgb;
    color = (color << 8) | rgb;
    color = (color << 8) | rgb;
    return (color);
}

int color_comb2(double i)
{
    int clr;
    double	ratio;

    clr = 0;
    ratio = i / ITERATION;
    clr = (unsigned char)(9 * (1 - ratio) * pow(ratio, 3) * 255);
    clr = (clr << 8) | (unsigned char)(15 * pow((1 - ratio), 2) * 255);
    clr = (clr << 8) | (unsigned char)(8.5 * pow((1 - ratio), 3) * ratio * 255);
    return (clr);
}

int pick_color(double i, int comb)
{
    if (comb == 0)
        return (color_comb1(i));
    else if (comb == 2)
        return (color_comb2(i));
    return (0);
}

void    color_shift(fractCfg *cfg)
{
    cfg->color_num = ++cfg->color_num % 2;
    render_set_bonus(cfg);
}
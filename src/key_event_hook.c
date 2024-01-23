/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:08:23 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/23 23:08:23 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract.h"

int ft_close(fractCfg *cfg)
{
    (void)cfg;
    exit(0);
}

int key_handler(int keycode, void *param)
{
    if (keycode == 53)
        ft_close(param);
    return (0);
}

int mouse_handler(int x, int y, fractCfg *cfg)
{
    if (cfg->set != 2)
        return (0);
    cfg->julia_x = (x - WIDTH / 2.0) / (WIDTH / 4.0);
    cfg->julia_y = (y - HEIGHT / 2.0) / (HEIGHT / 4.0);
    render_set(cfg);
    return (0);
}

int zoom_handler(int button, int x, int y, fractCfg *cfg)
{
    x = 0;
    y = 0;
    if (button == 4)
        cfg->zoom *= ZOOM_FACTOR;
    else if (button == 5)
        cfg->zoom /= ZOOM_FACTOR;
    render_set(cfg);
    return (y);
}

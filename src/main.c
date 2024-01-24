/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:09:05 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/24 18:31:21 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract.h"

void parsing(fractCfg *cfg, int ac, char **av)
{
    if (ac < 2)
	{
		write(1, "No parameters provided, use :julia, mandelbrot\n", 47);
		exit(1);
	}
	if (ac != 2 || (ft_strcmp("mandelbrot", av[1]) != 0 && \
						ft_strcmp("julia", av[1]) != 0))
	{
		write(1, "Invalid parameters, use : julia, mandelbrot\n", 44);
		exit(1);					
	}
	else if (ft_strcmp("mandelbrot", av[1]) == 0)
		cfg->set = 1;
	else if (ft_strcmp("julia", av[1]) == 0)
		cfg->set = 2;
}
int	main(int ac, char **av)
{
	fractCfg	cfg;

	parsing(&cfg, ac, av);
	cfg.zoom = ((HEIGHT + WIDTH) / 8.0);
	cfg.mlx_ptr = mlx_init();
	cfg.win_ptr = mlx_new_window(cfg.mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	render_set(&cfg);
	mlx_hook(cfg.win_ptr, 6, 0, mouse_handler, &cfg);
	mlx_hook(cfg.win_ptr, 17, 0, ft_close, &cfg);
	mlx_hook(cfg.win_ptr, 2, 0, key_handler, &cfg);
	mlx_mouse_hook(cfg.win_ptr, zoom_handler, &cfg);
	mlx_loop(cfg.mlx_ptr);
	return (0);
}
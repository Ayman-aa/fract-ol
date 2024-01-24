/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:21:04 by hbenazza          #+#    #+#             */
/*   Updated: 2024/01/24 19:16:52 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int c, char **v)
{
	t_data	data;

	if (c > 2)
	{
		write(1, "takes no args!!\n", 16);
		exit(0);
	}
	fract(&data, v);
	burning(&data);
	mlx_loop(data.mlx);
	return (0);
}

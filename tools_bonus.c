/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:16:00 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/24 19:16:03 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int	ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' || s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_fd(int n)
{
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -(n);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else
		ft_putchar_fd(n +48);
}

int	k_color(int key, t_data *mlx)
{
	if (key == XK_a)
		return (mlx->r_value += 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_s)
		return (mlx->g_value += 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_d)
		return (mlx->b_value += 15, ft_render(mlx->fractal, mlx), 0);
	if (key == XK_q)
		return (mlx->r_value -= 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_w)
		return (mlx->g_value -= 15, ft_render(mlx->fractal, mlx), 0);
	else if (key == XK_e)
		return (mlx->b_value -= 15, ft_render(mlx->fractal, mlx), 0);
	return (0);
}

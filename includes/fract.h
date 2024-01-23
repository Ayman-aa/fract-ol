/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:09:08 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/23 19:21:49 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define ITERATION 40.0
# define ZOOM_FACTOR 1.1

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct fractconfig
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		it;
	int		i;
	int		j;

	int		set;

	double	julia_x;
	double	julia_y;

	double	zoom;
	double	zoom_x;
	double	zoom_y;

	int		color_num;
}			fractCfg;

#endif
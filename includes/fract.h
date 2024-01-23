#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define ITERATION 40.0
# define ZOOM_FACTOR 1.1

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

	int		atr;

	double	julia_x;
	double	julia_y;

	double	zoom;
	double	zoom_x;
	double	zoom_y;

	int		color_num;
}			fractCfg;

#endif
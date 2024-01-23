#include "includes/fract.h"

void parsing(fractCfg *cfg, int ac, char **av)
{
    if (ac < 2)
	{
		write(1, "No parameters provided use :julia, mandelbrot\n", 48);
		exit(1);
	}
}
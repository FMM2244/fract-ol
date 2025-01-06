#include "src/fractol.h"

int render(t_info *data)
{
	int	x; 
	int	y;
	int center_x; 
	int center_y;
	int temp;

	center_x = data->width; 
	center_y = data->height;
	x = center_x - 30;
	y = center_y; 
	while (y)
	{
		while (x)
		{

		}
		
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info		data;
	t_fractal	*frctl;

	data.height = 1024;
	data.width = 728;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
		data.height, data.width, "fract-ol");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr,
		data.width, data.height);
	data.img.buffer = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.endian);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, &ft_close, &data);
	mlx_key_hook(data.win_ptr, &key_handler, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

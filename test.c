
#include "src/fractol.h"
#include <stdio.h>

int	ft_close(t_info *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	key_handler(int key, t_info *data)
{
	if (key == XK_Escape)
		ft_close(data);
	return (0);
}

void	ppti(t_info *data, int x, int y, int color)
{
	data->img.buffer[(data->img.size_line / 4) * y + x] = color;
}

int	render(t_info *data)
{
	int	x; 
	int	y;
	int center_x; 
	int center_y;

	center_x = data->width / 2;
	center_y = data->height / 2;
	y = 0;
	x = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= 90000)
				ppti(data, x, y, 0x5CD8C8);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (1);
}

int	main()
{
	t_info		data;

	data.height = 728;
	data.width = 1024;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
		data.width, data.height, "fract-ol");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr,
		data.width, data.height);
	data.img.buffer = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.size_line, &data.img.endian);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, &ft_close, &data);
	mlx_key_hook(data.win_ptr, &key_handler, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

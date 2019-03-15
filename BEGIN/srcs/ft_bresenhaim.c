#include <mlx.h>
#include <stdlib.h>

void	Dxbigger(void *mlx_ptr, void *win_ptr, int couleur, int x, int y, int Dx, int Dy, int xincr, int yincr)
{
	int erreur;
	int i;

	erreur = Dx/2;
	for(i=0;i<Dx;i++)
	{
		x += xincr;
		erreur += Dy;
		if(erreur>Dx)
		{
			erreur -= Dx;
			y += yincr;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, couleur);
	}
}

void	Dxsmaller(void *mlx_ptr, void *win_ptr, int couleur, int x, int y, int Dx, int Dy, int xincr, int yincr)
{
	int erreur;
	int i;

	erreur = Dy/2;
	for(i=0;i<Dy;i++)
	{
		y += yincr;
		erreur += Dx;
		if(erreur>Dy)
		{
			erreur -= Dy;
			x += xincr;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, couleur);
	}
}

void Line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int couleur)
{
	int x;
	int y;
	int Dx;
	int Dy;
	int xincr;
	int yincr;

	Dx = abs(x2-x1);
	Dy = abs(y2-y1);
	if(x1<x2)
		xincr = 1;
	else
		xincr = -1;
	if(y1<y2)
		yincr = 1;
	else
		yincr = -1;

	x = x1;
	y = y1;
	if (Dx>Dy)
		Dxbigger(mlx_ptr, win_ptr, couleur, x, y, Dx, Dy, xincr, yincr);
	else
		Dxsmaller(mlx_ptr, win_ptr, couleur,  x, y, Dx, Dy, xincr, yincr);
	mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, couleur);
	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, couleur);
}

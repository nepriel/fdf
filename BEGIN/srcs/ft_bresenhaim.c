#include "fdf.h"

/*void	Dxbigger(void *mlx_ptr, void *win_ptr, int couleur, int x, int y, int Dx, int Dy, int xincr, int yincr)
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
}*/

void	Dxsmaller(t_mlx *mlx, int couleur, t_ptbrese *pt_brese)
{
	int erreur;
	int i;

	erreur = pt_brese->Dy/2;
	for(i=0;i<pt_brese->Dy;i++)
	{
		pt_brese->y += pt_brese->yincr;
		erreur += pt_brese->Dx;
		if(erreur>pt_brese->Dy)
		{
			erreur -= pt_brese->Dy;
			pt_brese->x += pt_brese->xincr;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, pt_brese->x, pt_brese->y, couleur);
	}
}

void	Dxbigger(t_mlx *mlx, int couleur, t_ptbrese *pt_brese)
{
	int erreur;
	int i;

	erreur = pt_brese->Dx/2;
	for(i=0;i<pt_brese->Dx;i++)
	{
		pt_brese->x += pt_brese->xincr;
		erreur += pt_brese->Dy;
		if(erreur>pt_brese->Dx)
		{
			erreur -= pt_brese->Dx;
			pt_brese->y += pt_brese->yincr;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, pt_brese->x, pt_brese->y, couleur);
	}
}

void Line(t_mlx *mlx, int x1, int y1, int x2, int y2, int couleur)
{
	t_ptbrese	pt_brese;
	
	pt_brese.x1 = x1;
	pt_brese.x2 = x2;
	pt_brese.y1 = y1;
	pt_brese.y2 = y2;
	pt_brese.Dx = abs(pt_brese.x2-pt_brese.x1);
	pt_brese.Dy = abs(pt_brese.y2-pt_brese.y1);
	if(pt_brese.x1<pt_brese.x2)
		pt_brese.xincr = 1;
	else
		pt_brese.xincr = -1;
	if(pt_brese.y1<pt_brese.y2)
		pt_brese.yincr = 1;
	else
		pt_brese.yincr = -1;

	pt_brese.x = pt_brese.x1;
	pt_brese.y = pt_brese.y1;
	if (pt_brese.Dx>pt_brese.Dy)
		Dxbigger(mlx, couleur, &pt_brese);
	else
		Dxsmaller(mlx, couleur, &pt_brese);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, pt_brese.x1, pt_brese.y1, couleur);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, pt_brese.x2, pt_brese.y2, couleur);
}

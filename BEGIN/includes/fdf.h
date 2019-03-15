/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:59:55 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 19:43:08 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARGEUR 500
# define HAUTEUR 500

#include "../libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>


typedef	struct		s_check
{
	int				line;
	int				col;
	int				check;

}					t_check;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				line;
	int				col;
	int				Largeur;
	int				Hauteur;
	int				**board;
}					t_mlx;

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
}					t_point;

typedef struct		s_ptbres
{
	int				x;
	int				y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				Dx;
	int				Dy;
	int				xincr;
	int				yincr;
}					t_ptbrese;

int					**creat_tab(int count_lines);
int					*put_eachvalue_intab(char **eachvalue, t_check *check);
int					countcol(char **eachvalue);
int					ft_count_lines(int fd, char **argv);
int					**parsing(int fd, char **argv, t_check *check);
int					end_by_fdftest(char *s);
int					basic_check(int argc, char **argv);
//void				Dxbigger(void *mlx_ptr, void *win_ptr, int couleur, int x, int y, int Dx, int Dy, int xincr, int yincr);
//void				Dxsmaller(void *mlx_ptr, void *win_ptr, int x, int y, int Dx, int Dy, int xincr, int yincr);
//void				Line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int couleur);
void				Dxsmaller(t_mlx *mlx, int couleur, t_ptbrese *pt_brese);
void				Dxbigger(t_mlx *mlx, int couleur, t_ptbrese *pt_brese);
void				Line(t_mlx *mlx, int x1, int y1, int x2, int y2, int couleur);

#endif

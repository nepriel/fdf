/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:59:55 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/15 17:04:52 by vlhomme          ###   ########.fr       */
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
	int				x;
	int				y;
	int				z;
	int				z1;
	int				x1;
	struct s_point	*next;
}					t_check;

int					**creat_tab(int count_lines);
int					*put_eachvalue_intab(char **eachvalue, int *col, int *check);
int					countcol(char **eachvalue);
int					**creat_tab(int count_lines);
int					*put_eachvalue_intab(char **eachvalue, int *col, int *check);
int					ft_count_lines(int fd, char **argv);
int					**parsing(int fd, char **argv, int *countlines, int *col, int *check);
int					end_by_fdftest(char *s);
int					basic_check(int argc, char **argv);
void				Dxbigger(void *mlx_ptr, void *win_ptr, int couleur, int x, int y, int Dx, int Dy, int xincr, int yincr);
void				Dxsmaller(void *mlx_ptr, void *win_ptr, int x, int y, int Dx, int Dy, int xincr, int yincr);
void				Line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int couleur);

#endif

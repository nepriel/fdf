/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 07:04:07 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 23:13:44 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "struct.h"
# include "mlx.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

int		ft_count_lines(int fd, t_check *check);
void	print_board_content(int **board, t_check *check);
int		**parsing(int fd, char **argv, t_check *check);

int		**creat_tab(t_check *check);

int		end_by_fdftest(char *s);
int		basic_check(int argc, char **argv);

void	print_line(t_mlx *mlx, t_point *point);
void	print_lineyello(t_mlx *mlx, t_point *point);
void	fdf(t_mlx *mlx);

void	dxsmaller(t_mlx *mlx, int couleur, t_ptbrese *pt_brese);
void	dxbigger(t_mlx *mlx, int couleur, t_ptbrese *pt_brese);
void	line(t_mlx *mlx, t_point *point, int couleur);

int		ft_key_hook(int keycode, t_mlx *mlx);

void	iso(int *x, int *y, int z);
void	get_x_y(t_mlx *mlx, t_point *point, t_truc *coefij);
void	get_nextx(t_mlx *mlx, t_point *point, t_truc *coefij);
void	get_nexty(t_mlx *mlx, t_point *point, t_truc *coefij);

void	proj2(int *x, int *y, int z);
void	get_x_y2(t_mlx *mlx, t_point *point, t_truc *coefij);
void	get_nextx2(t_mlx *mlx, t_point *point, t_truc *coefij);
void	get_nexty2(t_mlx *mlx, t_point *point, t_truc *coefij);

#endif

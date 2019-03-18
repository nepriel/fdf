/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 06:58:14 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/18 07:01:32 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_truc
{
	int				coef1;
	int				coef2;
	int				i;
	int				j;
}					t_truc;

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
	int				largeur;
	int				hauteur;
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
	int				dx;
	int				dy;
	int				xincr;
	int				yincr;
}					t_ptbrese;

#endif

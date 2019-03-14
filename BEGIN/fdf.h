/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:59:55 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/13 10:57:56 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				z1;
	int				x1;
	struct s_point	*next;
}					t_point;

int		end_by_fdftest(char *s);
int		basic_check(int argc, char **argv);

#endif

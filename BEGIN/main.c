#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>


//WARNING NOT SURE ABOUT THE +1 --> IT CAN BREAK SHIT
int		**creat_tab(int count_lines)
{
	int		**board;

	if (!(board = (int **)ft_memalloc(sizeof(int) * (count_lines /*+ 1*/))))
		return (NULL);
	return (board);
}

//WARNING NOT SURE ABOUT THE +1 --> IT CAN BREAK SHIT
int		*put_eachvalue_intab(char **eachvalue)
{
	int *tab;
	int i;

	i = 0;
	while (eachvalue[i])
		i++;
	if (!(tab = (int *)ft_memalloc(sizeof(int) * (i/*+ 1*/))))
		return (NULL);
	i = 0;
	while (eachvalue[i])
	{
		tab[i] = atoi(eachvalue[i]);
//		printf("%d, ", atoi(eachvalue[i]));
		i++;
	}
	return (tab);
}

int		ft_count_lines(int fd, char **argv)
{
	int i;
	char *line;

	i = 0;
	while(get_next_line(fd, &line) == 1)
	{
	//	printf("%s\n", line);
		i++;
		free(line);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	return (i);
}

int		parsing(int fd, char **argv)
{
	char	*line;
	char	**eachvalue;
	int		j;
	int		count_lines;
	int		**board;

	line = NULL;
	count_lines = ft_count_lines(fd, argv);
	board = creat_tab(count_lines);
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		eachvalue = ft_strsplit(line, ' ');
		board[j] = put_eachvalue_intab(eachvalue);
		free(line);
		j++;
	}
	/*int k = 0, l = 0;
	while (k <= 9)
	{
		l = 0;
		while (l <= 10)
		{
			printf("%02d, ", board[k][l]);
			l++;
		}
		printf("\n");
		k++;
	}*/
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;

	if (basic_check(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	parsing(fd, argv);
	close(fd);
}

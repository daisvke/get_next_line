#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	ft_print_line(int fd, int *ret, int i)
{
	int		curr_ret;
	char	*line;

	curr_ret = 0;
	printf("----------------------------------------------\n\n");
	curr_ret = get_next_line(fd, &line);
	*ret += curr_ret;
	printf("t%d_%d  curr_ret:  %d  ret: %d\n", fd, i, curr_ret, *ret);
	printf("line:\t\t|%s|\n", line);
	free(line);
}

int	main(void)
{
	int	i;
	int	ret;
	int	fd;
	int	fd2;
	int	fd3;
	int	fd5;
	int	fd7;
	int	fd8;
	int	fd9;
	int	fd10;

	fd = open("t", O_RDONLY);
	fd2 = open("t2", O_RDONLY);
	fd3 = open("t3", O_RDONLY);
	fd5 = open("t5", O_RDONLY);
	fd7 = open("t7", O_RDONLY);
	fd8 = open("t8", O_RDONLY);
	fd9 = open("t9", O_RDONLY);
	fd10 = open("t10", O_RDONLY);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = 0;
		ft_print_line(fd, &ret, i);
		ft_print_line(fd2, &ret, i);
		ft_print_line(fd3, &ret, i);
		ft_print_line(fd5, &ret, i);
		ft_print_line(fd7, &ret, i);
		ft_print_line(fd8, &ret, i);
		ft_print_line(fd9, &ret, i);
		ft_print_line(fd10, &ret, i);
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		++i;
	}
	close(fd);
	close(fd2);
	close(fd3);
	close(fd5);
	close(fd7);
}

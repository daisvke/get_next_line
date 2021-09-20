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
	if (curr_ret > 0)
		free(line);
}

int	main()
{
	int	i;
	int	ret;
	int	fd;
	int	fd2;
	int	fd3;
	int	fd5;
	int	fd7;

	fd = open("t", O_RDONLY);
	fd2 = open("t2", O_RDONLY);
	fd3 = open("t3", O_RDONLY);
	fd5 = open("t5", O_RDONLY);
	fd7 = open("t7", O_RDONLY);


/* For mandatory part
 *
	fd = open("t", O_RDONLY);
	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("t_1ret: %d\n", ret);
	printf("t_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd, &line);
	printf("t7_1ret: %d\n", ret);
	printf("t7_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd, &line);
	printf("t7_2ret: %d\n", ret);
	printf("t7_2line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd, &line);
	printf("t2_1ret: %d\n", ret);
	printf("t2_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd, &line);
	p
	intf("t7_3ret: %d\n", ret);
	printf("t7_3line: %s\n", line);
	printf("----------------------------\n\n");
	close(fd);
	free(line);
*/

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
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		++i;
	}
	close(fd);
	close(fd2);
	close(fd3);
	close(fd5);
	close(fd7);
}


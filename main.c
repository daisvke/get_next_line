#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line_bonus.h"

int	main()
{
	int	fd;
	int	fd2;
	int	fd7;
	char	*line;
	int	ret;

	fd = open("t", O_RDONLY);
	fd2 = open("t2", O_RDONLY);
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
	printf("t7_3ret: %d\n", ret);
	printf("t7_3line: %s\n", line);
	printf("----------------------------\n\n");
	close(fd);
	free(line);
*/


	printf("----------------------------\n\n");
	ret = get_next_line(fd, &line);
	printf("t_1ret: %d\n", ret);
	printf("t_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_1ret: %d\n", ret);
	printf("t7_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_2ret: %d\n", ret);
	printf("t7_2line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd2, &line);
	printf("t2_1ret: %d\n", ret);
	printf("t2_1line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_3ret: %d\n", ret);
	printf("t7_3line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_4ret: %d\n", ret);
	printf("t7_4line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_5ret: %d\n", ret);
	printf("t7_5line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd7, &line);
	printf("t7_6ret: %d\n", ret);
	printf("t7_6line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(fd, &line);
	printf("t_4ret: %d\n", ret);
	printf("t_4line: %s\n", line);
	printf("----------------------------\n\n");
	free(line);
	ret = get_next_line(5, NULL);
	printf("t_5ret: %d\n", ret);
	printf("t_5line: %s\n", line);
	printf("----------------------------\n\n");
	if (line)
		free(line);
	close(fd);
	close(fd2);
	close(fd7);
}


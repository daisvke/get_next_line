/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:30:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/03/27 01:47:20 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(int fd, char **line)
{
	size_t	len;
	size_t	pos;
	int		r;
	char	buf[BUFFER_SIZE];
	char	tmp[BUFFER_SIZE];

	if (!buf)
		return(-1);//if size=0
	ft_strinit(buf);
	ft_strinit(tmp);
	while (true)
	{
		if ((r = read(fd, buf, sizeof(buf))) < 0)
		{
			line = ft_strdup(ft_strjoin(tmp, buf));
			return (-1);
		}
		if ((pos = ft_endlinepos(buf)) && r != 0) //ret pos || 0 if no line / no eof
		{
			tmp = ft_strcat(tmp, buf);
			return (1);
		}
		else// noline or pos=0
		{
			if (!ft_strlen(buf) && r == 0) //noline with EOF
				if (*tmp)
					line = strdup();
				else
					
				return (0);
			if (r == 1)//not end of line
			{
				before = 
			}
		}
	}
}

/*
if \n || EOF(= read = 0) in buf
	return before symb
else if read < 0
	return -1

else 
	cpy buf in allocated (return -1 if fails) char *exbuf
	read new bufsize
	if \n || EOF
		if \n only
			return empty string
		concat exbuf + buf into line
		return 1 (\n) || 0 (EOF)

	(bufsize can store max = one line (until EOF)
	so if exbuf allocation len is buf len = ok)
*/

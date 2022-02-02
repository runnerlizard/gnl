#include "get_next_line.h"

int	ft_duplicate(char **dst, char *src)
{
	char	*leaks;

	leaks = NULL;
	if (src == NULL)
		return (-1);
	leaks = *dst;
	*dst = ft_strdup(src);
	if (leaks != NULL)
		free(leaks);
	if (*dst == NULL)
		return (-1);
	return (1);
}

int	ft_join(char **dst, char *src)
{
	char	*leaks;

	leaks = NULL;
	if (src == NULL)
		return (-1);
	leaks = *dst;
	*dst = ft_strjoin(*dst, src);
	if (leaks != NULL)
		free(leaks);
	if (*dst == NULL)
		return (-1);
	return (1);
}

int	ft_check_rem(t_list *my_list, char **line)
{
	char	*nl;

	if (my_list->ost == NULL)
		return (0);
	nl = ft_strchr(my_list->ost, '\n');
	if (nl != NULL)
	{
		*nl = '\0';
		if (ft_duplicate(line, my_list->ost) == -1)
			return (ft_clear_list(&my_list));
		if (ft_duplicate(&my_list->ost, nl + 1) == -1)
			return (ft_clear_list(&my_list));
	}
	if (nl == NULL)
	{
		if (ft_duplicate(line, my_list->ost) == -1)
			return (ft_clear_list(&my_list));
		if (ft_duplicate(&my_list->ost, "") == -1)
			return (ft_clear_list(&my_list));
		return (0);
	}
	return (1);
}

int	ft_read(int fd, char **line, t_list *tmp_list)
{
	int		r_check;
	char	*buff;
	char	*r_end;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*buff = '\0';
	r_check = read(fd, buff, BUFFER_SIZE);
	while (r_check > 0)
	{
		buff[r_check] = '\0';
		r_end = ft_strchr(buff, '\n');
		if (r_end != NULL)
		{
			*r_end = '\0';
			if (ft_duplicate(&tmp_list->ost, r_end + 1) == -1)
				return (ft_clear_list(&tmp_list));
		}
		if (ft_join(line, &buff[0]) == -1)
			return (ft_clear_list(&tmp_list));
		if (r_end != NULL)
			break ;
		r_check = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (r_check);
}

int 	get_next_line(int fd, char **line)
{
	static t_list	*my_list;
	int				check_rem;
	int				check_read;

	if ((BUFFER_SIZE < 1) || (line == NULL) || (read(fd, 0, 0) != 0))
		return (-1);
	if (my_list == NULL)
		my_list = ft_create_new_list(fd);
	*line = ft_strdup("");
	check_rem = ft_check_rem(my_list, line);
	if (check_rem == 1)
		return (1);
	check_read = ft_read(fd, line, my_list);
	if ((check_rem == -1) || (check_read < 0))
		return (ft_clear_list(&my_list));
	if ((check_read == 0) && (check_rem == 0))
	{
		ft_clear_list(&my_list);
		return (0);
	}
	return (1);
}

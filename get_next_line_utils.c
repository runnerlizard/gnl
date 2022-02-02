#include "get_next_line.h"

t_list	*ft_create_new_list(int fd)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->fd = fd;
	new_list->ost = NULL;
	return (new_list);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_clear_list (t_list **main_list)
{
	t_list	*tmp_list;

	tmp_list = *main_list;
	if (tmp_list->ost != NULL)
		free(tmp_list->ost);
	free(*main_list);
	*main_list = NULL;
	return (-1);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (str[i] != 0)
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	i = 0;
	j = 0;
	if (s1 != NULL)
		while (s1[i])
			i++;
	while (s2[j])
		j++;
	res = malloc(sizeof(char) * (i + j + 1));
	if (res == NULL)
		return (NULL);
	res[i + j] = '\0';
	while (j-- > 0)
		res[i + j] = s2[j];
	while (i-- > 0)
		res[i] = s1[i];
	return (res);
}

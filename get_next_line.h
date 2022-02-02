#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*ost;

}					t_list;

int		get_next_line (int fd, char **line);
int		ft_check_ostatok(t_list *work_list, char **line);
t_list	*ft_create_new_list (int fd);
char	*ft_strchr (const char *str, int c);
int		ft_clear_list (t_list **main_list);
char	*ft_strdup (const char *s1);
char	*ft_strjoin (char const *s1, char const *s2);
int		ft_join (char **dst, char *src);
int		ft_duplicate (char **dst, char *src);
int		ft_read (int fd, char **line, t_list *tmp_list);
#endif

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>


// MANDATORY

extern size_t	ft_strlen(const char *s);
extern char		*ft_strcpy(char *dst, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strdup(const char *s);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);


// BONUS

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

extern int		ft_atoi_base(const char *str, const char *base);
extern void		ft_list_push_front(t_list **list, void *data);
extern int		ft_list_size(t_list *list);
extern void		ft_list_sort(t_list **list, int (*cmp)());
extern void		ft_list_remove_if(t_list **list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:31:40 by mrambelo          #+#    #+#             */
/*   Updated: 2024/04/26 14:07:11 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    void            *content;
    struct  s_list  *next;
}   t_list;

int		ft_toupper(int c);
int		ft_isalnum(char c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int     ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_tolower(int character);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int searchChar);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *str, int searchChar);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memchr(const void *mem_block, int search_value, size_t size);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstiter(t_list *lst, void (*f)(void *));
void    ft_lstdelone(t_list *lst, void (*del)(void*));
t_list  *ft_lstnew(void *content);


#endif

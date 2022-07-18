/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:14:34 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/18 10:27:14 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *s);
int		ft_isspace(int c);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_strtrim(char *s1, char *set);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, int n);
void	*ft_memset(void *s, int c, int n);
void	*ft_calloc(int count, int size);

#endif
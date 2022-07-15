/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:31:30 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:32:28 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strs_count(char *str, char c)
{
	int	i;
	int	num;

	if (!c)
		return (1);
	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			num++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (num);
}

static int	next_slen(char *str, char c)
{
	static int	i;
	int		len;

	len = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

static char	**generate(char *s, char **res, char c)
{
	int	i;
	int	arr;

	arr = 0;
	if (!c)
	{
		ft_memmove(res[0], s, ft_strlen(s));
		res[1] = NULL;
		return (res);
	}
	while (*s)
	{
		i = 0;
		while (*s && *s != c)
			res[arr][i++] = *(s++);
		while (*s == c)
			s++;
		arr++;
	}
	res[arr] = NULL;
	return (res);
}

static int	allocate_res(char	**res, char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	if (!res)
		return (0);
	while (i < strs_count(s, c))
	{
		len = next_slen((char *)s, c);
		res[i++] = ft_calloc(len + 1, sizeof(char));
		if (!(res + i))
		{
			while (i-- > 0)
				free(res[i]);
			return (0);
		}
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	if (!*s)
	{
		res = (char **)malloc(sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc(sizeof(char *) * (strs_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (!allocate_res(res, s, c))
		free(res);
	return (generate(s, res, c));
}
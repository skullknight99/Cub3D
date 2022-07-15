/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:52:28 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:53:36 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	located_in(char *set, char c)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

static void	length_c(char *s1, char *set, int *fst, int *lst)
{
	char	*str;

	str = (char *)s1;
	*fst = 0;
	while (located_in(set, *(s1++)))
		*fst += 1;
	*lst = 0;
	s1 = str + ft_strlen(str) - 1;
	while (located_in(set, *(s1--)) && s1 != str)
		*lst += 1;
}

char	*ft_strtrim(char *s1, char *set)
{
	int			first;
	int			last;
	int			len;
	char		*t_arr;

	if (!s1)
		return (NULL);
	length_c(s1, set, &first, &last);
	len = ft_strlen(s1) - last - first;
	if (first + last < ft_strlen(s1))
	{
		t_arr = ft_calloc((len + 1), sizeof(char));
		if (!t_arr)
			return (NULL);
		ft_memmove(t_arr, s1 + first, len);
		return (t_arr);
	}
	t_arr = ft_calloc(1, sizeof(char));
	if (!t_arr)
		return (NULL);
	return (t_arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:28:57 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:29:00 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	char	*t;

	t = (char *)malloc(size * count);
	if (!t)
		return (NULL);
	ft_bzero(t, size * count);
	return (t);
}

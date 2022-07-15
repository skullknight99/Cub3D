/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:51:16 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:51:31 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*dst;
	unsigned char	*srx;
	int				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = dest;
	srx = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = srx[i];
		i++;
	}
	return (dest);
}

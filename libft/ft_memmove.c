/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:50:33 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:50:49 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	char	*srx;
	char	*dst;
	int		i;

	dst = (char *)dest;
	srx = (char *)src;
	if (srx == dst || n == 0)
		return (dest);
	if (dst > srx)
	{
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = srx[i];
			i--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

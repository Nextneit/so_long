/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:56:31 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:15 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*dest;
	char		*srce;

	if (!src && !dst)
		return (0);
	count = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (count < n)
	{
		dest[count] = (char)srce[count];
		count++;
	}
	return (dst);
}

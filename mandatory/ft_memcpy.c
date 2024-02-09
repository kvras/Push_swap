/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:48:27 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:51:29 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)dst;
	while (i < len)
	{
		*ptr = *((unsigned char *)src);
		i++;
		src++;
		ptr++;
	}
	return (dst);
}

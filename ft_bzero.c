/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:32:29 by amasol            #+#    #+#             */
/*   Updated: 2017/11/06 16:32:32 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

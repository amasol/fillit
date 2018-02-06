/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:40:21 by amasol            #+#    #+#             */
/*   Updated: 2017/12/25 16:41:13 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <fcntl.h>

/*typedef struct s_list
{
}*/

void	ft_check_symbols(char const *i);
void	ft_termin(char **str);
void	ft_putstr(char const *str);
void	ft_putchar(char c);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);

#	endif

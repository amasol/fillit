/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:31:32 by amasol            #+#    #+#             */
/*   Updated: 2017/12/25 17:39:53 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("There must be one parameter!\n");
		exit(1);
	}
	ft_termin(argv);
	return (0);
}

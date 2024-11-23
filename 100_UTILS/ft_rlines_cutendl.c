/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlines_cutendl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:30:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 19:30:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

void	ft_rlines_cutendl(char ***rlines)
{
	t_ints	ints;

	if (!rlines || !(*rlines))
		return ;
	ints.i = -1;
	while ((*rlines)[++(ints.i)])
	{
		ints.len = gnlxio_ft_strlen((*rlines)[ints.i]);
		if (ints.len == 0)
			;
		else if ((*rlines)[ints.i][ints.len - 1] == '\n')
			(*rlines)[ints.i][ints.len - 1] = '\0';
	}
}

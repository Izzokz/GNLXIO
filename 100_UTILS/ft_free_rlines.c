/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_rlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:16:43 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/16 10:16:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

void	ft_free_rlines(t_rlines *rlines)
{
	int	i;

	if (!rlines || !(*rlines))
		return ;
	i = -1;
	while ((*rlines)[++i])
	{
		free((*rlines)[i]);
		(*rlines)[i] = NULL;
	}
	free(*rlines);
	*rlines = NULL;
}

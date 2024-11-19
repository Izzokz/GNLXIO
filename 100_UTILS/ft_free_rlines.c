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

void	ft_free_rlines(char ***lines)
{
	int	i;

	if (!lines || !(*lines))
		return ;
	i = -1;
	while ((*lines)[++i])
	{
		free((*lines)[i]);
		(*lines)[i] = NULL;
	}
	free(*lines);
	*lines = NULL;
}

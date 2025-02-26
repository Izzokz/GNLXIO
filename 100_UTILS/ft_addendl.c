/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:34:22 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/02/26 13:34:23 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	ft_rline_addendl(char **rline)
{
	int	len;

	len = -1;
	while ((*rline)[++len])
		;
	if (len == 0 || (*rline)[len - 1] != '\n')
	{
		if (gnlxio_ft_realloc(rline, 1) == -1)
			return (-1);
		(*rline)[len] = '\n';
		return (1);
	}
	return (0);
}

int	ft_rlines_addendl(t_rlines *rlines)
{
	t_ints	ints;

	if (!rlines || !(*rlines))
		return (-1);
	ints = (t_ints){.i = -1, .count = 0};
	while ((*rlines)[++(ints.i)])
	{
		ints.tmp = ft_rline_addendl(&((*rlines)[ints.i]));
		if (ints.tmp == -1)
			return (-1);
		ints.count += ints.tmp;
	}
	return (ints.count);
}

int	ft_slines_addendl(t_slines *slines)
{
	t_ints	ints;

	if (!slines || !(*slines))
		return (-1);
	ints = (t_ints){.i = -1, .count = 0};
	while ((*slines)[++(ints.i)])
	{
		ints.tmp = ft_rlines_addendl(&((*slines)[ints.i]));
		if (ints.tmp == -1)
			return (-1);
		ints.count += ints.tmp;
	}
	return (ints.count);
}

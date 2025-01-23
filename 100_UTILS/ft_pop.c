/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:46 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/22 10:00:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static void	ft_fix_index(int *index, int *max)
{
	if (*index == 0)
		return ;
	if (*index > 0)
		(*index)++;
	ft_fix_lineno(index, *max);
	(*index)--;
}

char	*ft_rlines_pop(t_rlines *rlines, int index)
{
	t_ints		i;
	char		*pop_line;
	t_rlines	tmp;

	i.len = ft_rlines_len(*rlines);
	ft_fix_index(&index, &i.len);
	tmp = gnlxio_ft_calloc(1, sizeof(char *));
	if (!tmp)
		return (NULL);
	i.i = -1;
	pop_line = NULL;
	while (++(i.i) < i.len)
	{
		if (i.i == index)
		{
			pop_line = gnlxio_ft_strdup((*rlines)[i.i]);
			free((*rlines)[i.i]);
		}
		else if (ft_rlines_add(&tmp, (*rlines)[i.i], -1) == -1)
			return (ft_free_rlines(&tmp));
	}
	free(*rlines);
	*rlines = tmp;
	return (pop_line);
}

int	ft_rlines_delete(t_rlines *rlines, int index)
{
	char	*tmp;

	tmp = ft_rlines_pop(rlines, index);
	if (!tmp)
		return (-1);
	free(tmp);
	return (0);
}

t_rlines	ft_slines_pop(t_slines *slines, int index)
{
	t_ints		i;
	t_rlines	pop_rlines;
	t_slines	tmp;

	i.len = ft_slines_rlen(*slines);
	ft_fix_index(&index, &i.len);
	tmp = gnlxio_ft_calloc(1, sizeof(t_rlines));
	if (!tmp)
		return (NULL);
	i.i = -1;
	pop_rlines = NULL;
	while (++(i.i) < i.len)
	{
		if (i.i == index)
		{
			pop_rlines = ft_rlines_dup((*slines)[i.i]);
			ft_free_rlines(&((*slines)[i.i]));
		}
		else if (ft_slines_add(&tmp, (*slines)[i.i], -1) == -1)
			return (ft_free_slines(&tmp));
	}
	free(*slines);
	*slines = tmp;
	return (pop_rlines);
}

int	ft_slines_delete(t_slines *slines, int index)
{
	t_rlines	tmp;

	tmp = ft_slines_pop(slines, index);
	if (!tmp)
		return (-1);
	ft_free_rlines(&tmp);
	return (0);
}

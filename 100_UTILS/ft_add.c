/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:37:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/21 13:41:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static void	fix_index(int *index, int *max)
{
	if (*index == 0)
		return ;
	if (*index > 0)
		(*index)++;
	ft_fix_lineno(index, *max);
	(*max)++;
	(*index)--;
}

static void	ft_swap_lines(char **line1, char **line2)
{
	char	*tmp;

	tmp = *line1;
	*line1 = *line2;
	*line2 = tmp;
}

int	ft_rlines_add(t_rlines *rlines, char *line, int index)
{
	t_ints	i;
	char	*tmp_line;

	i.len = ft_rlines_len(*rlines);
	fix_index(&index, &i.len);
	ft_realloc_rlines(rlines, 1);
	if (!rlines || !(*rlines))
		return (-1);
	i.count = 0;
	i.i = -1;
	while (++(i.i) < i.len)
	{
		if (i.i == index || i.count)
		{
			if (!i.count)
			{
				tmp_line = (*rlines)[i.i];
				(*rlines)[i.i] = line;
			}
			else
				ft_swap_lines(&((*rlines)[i.i]), &tmp_line);
			i.count = 1;
		}
	}
	return (0);
}

static void	ft_swap_rlines(t_rlines *rlines1, t_rlines *rlines2)
{
	t_rlines	tmp;

	tmp = *rlines1;
	*rlines1 = *rlines2;
	*rlines2 = tmp;
}

int	ft_slines_add(t_slines *slines, t_rlines rlines, int index)
{
	t_ints		i;
	t_rlines	tmp_rlines;

	i.len = ft_slines_rlen(*slines);
	fix_index(&index, &i.len);
	ft_realloc_slines(slines, 1);
	if (!slines || !(*slines))
		return (-1);
	i.count = 0;
	i.i = -1;
	while (++(i.i) < i.len)
	{
		if (i.i == index || i.count)
		{
			if (!i.count)
			{
				tmp_rlines = (*slines)[i.i];
				(*slines)[i.i] = rlines;
			}
			else
				ft_swap_rlines(&((*slines)[i.i]), &tmp_rlines);
			i.count = 1;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_rlines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:12:07 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 14:16:30 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
It it fails, it continues to free everything
*/
static void	ft_chainshift(char **dest, char **src)
{
	int	i;
	int	fail;

	if (!dest || !src)
		return ;
	i = -1;
	fail = 0;
	while (src[++i])
	{
		dest[i] = NULL;
		if (!fail)
			dest[i] = gnlxio_ft_strdup(src[i]);
		if (!dest[i])
			fail = 1;
		free(src[i]);
		src[i] = NULL;
	}
	free(src);
	src = NULL;
}

void	ft_realloc_rlines(char ***chain, int nmemb)
{
	int		i;
	int		len;
	char	**temp;

	if (!chain || !(*chain) || nmemb < 0)
		return ;
	i = -1;
	while ((*chain)[++i])
		;
	len = i;
	temp = gnlxio_ft_calloc(len + 1, sizeof(char *));
	if (!temp)
		return ;
	ft_chainshift(temp, *chain);
	*chain = gnlxio_ft_calloc(len + nmemb + 1, sizeof(char *));
	if (!(*chain))
	{
		ft_free_rlines(&temp);
		return ;
	}
	ft_chainshift(*chain, temp);
}

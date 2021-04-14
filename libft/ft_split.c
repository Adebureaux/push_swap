/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:13:00 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/21 18:38:45 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_split(char **dst, int *char_nbr)
{
	int i;

	i = 0;
	if (char_nbr)
		free(char_nbr);
	if (dst)
	{
		while (dst[i])
			free(dst[i++]);
		free(dst);
	}
	return (NULL);
}

static int	ft_split_strs(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static int	*ft_split_chars(const char *str, char c, int str_nbr)
{
	int		*char_nbr;
	int		count;
	int		i;

	i = 0;
	if (!(char_nbr = (int*)malloc(sizeof(int) * str_nbr)))
		return (NULL);
	while (str_nbr--)
	{
		count = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		char_nbr[i++] = count;
	}
	return (char_nbr);
}

static char	**ft_spliter(const char *str, char c, int *char_nbr, int str_nbr)
{
	char	**dst;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(dst = (char**)ft_calloc(1, sizeof(char*) * (str_nbr + 1))))
		return (NULL);
	while (++i < str_nbr)
	{
		while (str[j] == c)
			j++;
		while (str[j] && str[j] != c)
		{
			if (!(dst[i] = ft_substr(str, j, char_nbr[i])))
				return (ft_free_split(dst, char_nbr));
			j += char_nbr[i];
		}
	}
	dst[i] = 0;
	return (dst);
}

char		**ft_split(const char *s, char c)
{
	char	**dst;
	int		*char_nbr;
	int		str_nbr;

	if (!s)
		return (NULL);
	str_nbr = ft_split_strs(s, c);
	if (!(char_nbr = ft_split_chars(s, c, str_nbr)))
		return (NULL);
	if (!(dst = ft_spliter(s, c, char_nbr, str_nbr)))
		return (NULL);
	free(char_nbr);
	return (dst);
}

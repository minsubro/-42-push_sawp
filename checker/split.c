/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:01:55 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/14 01:13:57 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_cnt(char const *s, char c)
{
	int		flag;
	int		i;
	int		cnt;

	flag = 1;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

static char	*ft_strcpy(char *save, char const *s, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		save[i] = s[start];
		i++;
		start++;
	}
	save[i] = 0;
	return (save);
}

char	**ft_free(char **save, int cnt)
{
	int		i;

	i = 0;
	while (i < cnt)
	{
		free(save[i]);
		i++;
	}
	free(save);
	return (NULL);
}

static char	**ft_putstr(char **save, char const *s, char c, int cnt)
{
	int	start;
	int	end;
	int	idx;

	start = 0;
	idx = 0;
	while (idx < cnt)
	{
		while (s[start] == c)
			start++;
		end = start;
		if (s[start] == 0)
			break ;
		while (s[end] != c && s[end] != 0)
			end++;
		save[idx] = (char *)malloc(end - start + 1);
		if (!save[idx])
			return (ft_free(save, idx));
		save[idx] = ft_strcpy(save[idx], s, start, end);
		idx++;
		start = end;
	}
	save[idx] = 0;
	return (save);
}

char	**ft_split(char const *s, char c, int *acnt)
{
	char	**str;
	int		cnt;

	if (s == NULL)
		return (NULL);
	cnt = ft_cnt(s, c);
	*acnt = cnt;
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	return (ft_putstr(str, s, c, cnt));
}
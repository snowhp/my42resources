/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:16:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/07 16:17:30 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isquotes(char *str)
{
	if (str[0] == '\"' && str[1] == '\'')
	{
		if (str[2] == '\0')
			return (0);
		return (2);
	}
	else if (str[0] == '\"' && str[1] == '\'')
	{
		if (str[2] == '\0')
			return (0);
		return (2);
	}
	else if (str[0] == '\"' || str[0] == '\'')
	{
		if (str[1] == '\0')
			return (0);
		return (1);
	}	
	else
		return (0);
}

/* Count numbers of words separated by 'c'.*/
void	ft_wcount(char *str, char c, int *wcount)
{
	int	i;
	int	ctrl;
	int	ctrl1;

	ctrl = 0;
	ctrl1 = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ctrl1 && ft_isquotes(str + i))
		{
			ctrl1 = 1;
			(*wcount)++;
		}
		else if (ctrl1 && ft_isquotes(str + i))
			ctrl1 = 0;
		if (!ctrl && !ctrl1 && !ft_isquotes(str + i))
		{
			ctrl = 1;
			(*wcount)++;
		}
		else if (ctrl && str[i] == c)
			ctrl = 0;
		i += ft_isquotes(str + i) + 1;
	}
}

int	ft_checkchar(const char *str, char c)
{
	int		ctrl;
	int		l;

	l = 0;
	ctrl = 0;
	while (str[l] != '\0' && str[l] != c)
	{
		if (str[l] == 39 && !ctrl)
		{
			ctrl = 1;
			c = '\'';
		}
		l++;
	}
	if (c == '\'')
		l++;
	return (l);
}

static char	*ft_word(const char *str, char c)
{
	int		l;
	int		i;
	char	*res;

	l = ft_checkchar(str, c);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	i = 0;
	while (i < l)
		res[i++] = *str++;
	return (res);
}
#include <stdio.h>

/* This function will split a string by give char c, but joining whats inside 
cj, if its a even number otherwise return 0*/
char	**ft_joinsplit(char *s, char c, char cj)
{
	int		wcount;
	int		i;
	char	**result;

	wcount = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	ft_wcount(s, c, &wcount);
	printf("WC: %i\n", wcount);
	if ((ft_countchar(s, cj) % 2) != 0)
		return (0);
	result = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		if (*s == cj)
			result[i] = ft_word(s, c);
		else
			result[i] = ft_word(s, c);
		s += ft_strlen(result[i++]);
	}
	return (result);
}

int	main()
{
	char	c;
	char	cj;

	char *s3 = "awk \'{count++} END {print count}\'";
	c = ' ';
	cj = 39;

	char **arr = ft_joinsplit(s3, c, cj);
	int i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	char *s1 = "awk \"{count++} END {print count}\"";
	char *s2 = "awk \'\"{count++} END {print count}\"\'";
	char *s = "awk \"\'{count++} END {print count}'\"";
	arr = ft_joinsplit(s1, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	arr = ft_joinsplit(s2, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	arr = ft_joinsplit(s, c, cj);
	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}

	return (0);
}

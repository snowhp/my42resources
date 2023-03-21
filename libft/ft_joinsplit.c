/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:16:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/20 10:14:19 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Count numbers of words separated by 'c'.*/
static int	ft_wcount(const char *str, char c, char cj)
{
	int	i;
	int	ctrl;
	int	ctrl1;
	int	wcount;

	wcount = 0;
	ctrl = 0;
	ctrl1 = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (!ctrl1 && str[i] == cj)
		{
			ctrl1 = 1;
			wcount++;
		}
		else if (ctrl1 && str[i] == cj)
			ctrl1 = 0;
		if (!ctrl && !ctrl1 && str[i] != c && str[i] != cj)
		{
			ctrl = 1;
			wcount++;
		}
		else if (ctrl && str[i] == c)
			ctrl = 0;
		i++;
	}
	return (wcount);
}

static char	*ft_word(const char *str, char c)
{
	int		l;
	int		i;
	char	*res;

	l = 0;
	while (str[l] != '\0' && str[l] != c)
		l++;
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	res[l] = '\0';
	i = 0;
	while (i < l)
		res[i++] = *str++;
	return (res);
}

/* This function will behave like ft_split taking c as a separator but
will join the what appears inside 2 cj char's.*/
char	**ft_joinsplit(char const *s, char c, char cj)
{
	int		wcount;
	int		i;
	char	**result;

	wcount = ft_wcount(s, c, NULL);
	result = (char **)malloc((wcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[i] = ft_word(s, c);
		s += ft_strlen(result[i++]);
	}
	result[i] = NULL;
	return (result);
}

#include <stdio.h>
int	main()
{
	char	*s;

	s = "teste string 'asda asd asd asd s' ola 'asda asd asd asd s' oasd ";
	printf("%i", ft_wcount(s, ' ', 39));
	/* char	*s;
	char	c;
	char	cj;

	s = "teste string 'asda s' ola";
	c = ' ';
	cj = 39;

	char **arr = ft_joinsplit(s, c, cj);
	int i = 0;
	while (arr[i] != 0)
	{
		printf("[%s]\n", arr[i]);      
		i++;
	}
	return (0); */
}

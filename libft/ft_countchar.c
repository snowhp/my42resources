/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:34:59 by tde-sous          #+#    #+#             */
/*   Updated: 2023/03/27 12:36:00 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_countchars(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			count++;
		i++;
	}
	return(count);
}

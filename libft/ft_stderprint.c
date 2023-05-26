/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stderprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:47:38 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 08:47:48 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stderprint(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(2, "(null)", 6));
	while (str[i] != '\0')
		write(2, &str[i++], 1);
	return (i);
}

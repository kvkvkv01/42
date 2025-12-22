/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:17:18 by caualves          #+#    #+#             */
/*   Updated: 2025/12/22 16:17:18 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

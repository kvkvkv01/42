/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:41:03 by caualves          #+#    #+#             */
/*   Updated: 2026/01/05 19:41:03 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}

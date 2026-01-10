/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:40:13 by caualves          #+#    #+#             */
/*   Updated: 2026/01/05 19:40:13 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long long)base_len)
	{
		count = ft_putnbr_base(n / base_len, base, base_len);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(base[n % base_len]) == -1)
		return (-1);
	return (count + 1);
}

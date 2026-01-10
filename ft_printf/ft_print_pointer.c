/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:16:33 by caualves          #+#    #+#             */
/*   Updated: 2025/12/22 16:40:13 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long long	address;
	int					count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long long)ptr;
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	count += ft_putnbr_base(address, "0123456789abcdef", 16);
	return (count);
}

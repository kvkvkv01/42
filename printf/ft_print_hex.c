/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:16:23 by caualves          #+#    #+#             */
/*   Updated: 2025/12/22 16:16:23 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789abcdef", 16));
}

int	ft_print_hex_upper(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789ABCDEF", 16));
}

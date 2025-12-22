/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:15:53 by caualves          #+#    #+#             */
/*   Updated: 2025/12/22 16:15:53 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	sign = 1;
	if (n < 0)
		sign = -1;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

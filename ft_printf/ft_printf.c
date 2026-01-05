/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:17:02 by caualves          #+#    #+#             */
/*   Updated: 2025/12/22 16:41:34 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unknown_specifier(char specifier)
{
	if (ft_putchar('%') == -1)
		return (-1);
	if (ft_putchar(specifier) == -1)
		return (-1);
	return (2);
}

static int	ft_process_conversion(const char *format, int *i, va_list args)
{
	int	result;

	(*i)++;
	result = ft_handle_conversion(format[*i], args);
	if (result == -1)
		return (-1);
	if (result == -2)
		result = ft_handle_unknown_specifier(format[*i]);
	return (result);
}

static int	ft_print_normal_char(char c)
{
	if (ft_putchar(c) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse_format(format, args);
	va_end(args);
	return (count);
}

int	ft_parse_format(const char *format, va_list args)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			result = ft_process_conversion(format, &i, args);
		else
			result = ft_print_normal_char(format[i]);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	return (count);
}

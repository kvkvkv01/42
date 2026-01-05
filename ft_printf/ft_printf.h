/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:40:27 by caualves          #+#    #+#             */
/*   Updated: 2026/01/05 19:40:28 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list args);
int		ft_handle_conversion(char specifier, va_list args);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_pointer(void *ptr);
int		ft_print_decimal(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex_lower(unsigned int n);
int		ft_print_hex_upper(unsigned int n);
int		ft_print_percent(void);
int		ft_putnbr_base(unsigned long long n, char *base, int base_len);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

#endif

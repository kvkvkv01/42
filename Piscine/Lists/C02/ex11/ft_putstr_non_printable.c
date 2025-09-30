/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:46:24 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:46:24 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_putchar(char c)
{
        HANDLE h_StdOut;
        DWORD bytesWritten;

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        WriteFile(h_StdOut, &c, 1, &bytesWritten, NULL);
}

void    ft_putstr_non_printable(char *str)
{
        int     i;
        char    *hex;

        hex = "0123456789abcdef";
        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < 32 || str[i] == 127)
                {
                        ft_putchar('\\');
                        ft_putchar(hex[(unsigned char)str[i] / 16]);
                        ft_putchar(hex[(unsigned char)str[i] % 16]);
                }
                else
                        ft_putchar(str[i]);
                i++;
        }
}

/*#include <stdio.h>

int     main(void)
{
        ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/
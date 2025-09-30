/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:01 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:02:01 by caualves         ###   ########.fr       */
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

/*int     main(void)
{
        ft_putchar('A');
        ft_putchar('\n');
        return (0);
}*/
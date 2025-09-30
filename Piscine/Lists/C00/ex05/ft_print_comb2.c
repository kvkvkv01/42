/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:58:06 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 15:58:06 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Windows.h>

void ft_print_comb(void)
{
        HANDLE  h_StdOut;
        DWORD   bytesWritten;
        char    x;
        char    y;
        char    z;

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        x = '0';
        y = '1';
        z = '2';
        while (x <= '7')
        {
                y = x + 1;
                while (y <= '8')
                {
                        z = y + 1;
                        while (z <= '9')
                        {
                                WriteFile(h_StdOut, &x, 1, &bytesWritten, NULL);
                                WriteFile(h_StdOut, &y, 1, &bytesWritten, NULL);
                                WriteFile(h_StdOut, &z, 1, &bytesWritten, NULL);
                                if (!(x == '7' && y == '8' && z == '9'))
                                {
                                        WriteFile(h_StdOut, ", ", 2, &bytesWritten, NULL);
                                }
                                z++;
                        }
                        y++;
                }
                x++;

        }
}

/*int     main(void)
{
        ft_print_comb();
}*/
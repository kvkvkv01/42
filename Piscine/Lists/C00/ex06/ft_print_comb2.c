/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:45 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:20:45 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Windows.h>

void ft_print_comb2(void)
{
        HANDLE  h_StdOut;
        DWORD   bytesWritten;
        int     first;
        int     second;
        char    output[5];

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        first = 0;
        while (first <= 98)
        {
                second = first + 1;
                while (second <= 99)
                {
                        output[0] = (first / 10) + '0';
                        output[1] = (first % 10) + '0';
                        output[2] = ' ';
                        output[3] = (second / 10) + '0';
                        output[4] = (second % 10) + '0';
                        WriteFile(h_StdOut, output, 5, &bytesWritten, NULL);
                        if (!(first == 98 && second == 99))
                                WriteFile(h_StdOut, ", ", 2, &bytesWritten, NULL);
                        second++;
                }
                first++;
        }
}

/*int     main(void)
{
        ft_print_comb2();
}*/
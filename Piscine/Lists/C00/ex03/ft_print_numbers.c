/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:37:10 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 15:37:10 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_print_numbers(void)
{
        HANDLE  h_StdOut;
        DWORD   bytesWritten;
        char    c;

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        c = '0';
        while (c <= '9')
        {
                WriteFile(h_StdOut, &c, 1, &bytesWritten, NULL);
                c++;
        }
}

/*int     main(void)
{
        ft_print_numbers();
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:22:23 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 15:22:23 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_print_alphabet(void)
{
        HANDLE  h_StdOut;
        DWORD   bytesWritten;
        char    c;

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        c = 'a';
        while (c <= 'z')
        {
                WriteFile(h_StdOut, &c, 1, &bytesWritten, NULL);
                c++;
        }
}

/*int     main(void)
{
        ft_print_alphabet();
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:44:25 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 15:44:25 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_is_negative(int n)
{
        HANDLE  h_StdOut;
        DWORD   bytesWritten;
        char    negative;
        char    positive;

        h_StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        positive = 'P';
        negative = 'N';
        if (n < 0)
        {
                WriteFile(h_StdOut, &negative, 1, &bytesWritten, NULL);
        }
        else
        {
                WriteFile(h_StdOut, &positive, 1, &bytesWritten, NULL);
        }
}

/*int     main(void)
{
        ft_is_negative(-1);
        ft_is_negative(0);
        ft_is_negative(1);
}*/
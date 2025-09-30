/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:26:46 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:26:46 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_putnbr(int nb)
{
        char    c;

        if (nb < 0)
        {
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "-", 1, NULL, NULL);
                nb = -nb;
        }
        if (nb == -2147483648)
        {
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "2147483648", 10, NULL, NULL);
                return ;
        }
        if (nb >= 10)
        {
                ft_putnbr(nb / 10);
        }
        c = (nb % 10) + '0';
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &c, 1, NULL, NULL);
}

/*int     main(void)
{
        ft_putnbr(-2147483648);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        ft_putnbr(2147483647);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        ft_putnbr(0);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        ft_putnbr(-42);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        ft_putnbr(42);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        return (0);
}*/
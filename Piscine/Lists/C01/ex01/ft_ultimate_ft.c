/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:48:02 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:48:02 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <windows.h>

void    ft_ultimate_ft(int *********nbr)
{
        *********nbr = 42;
}

/*void    ft_putnbr(int nb)
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

int     main(void)
{
        int    a;
        int    *p1;
        int    **p2;
        int    ***p3;
        int    ****p4;
        int    *****p5;
        int    ******p6;
        int    *******p7;
        int    ********p8;
        int    *********p9;
        a = 0;
        p1 = &a;
        p2 = &p1;
        p3 = &p2;
        p4 = &p3;
        p5 = &p4;
        p6 = &p5;
        p7 = &p6;
        p8 = &p7;
        p9 = &p8;
        ft_ultimate_ft(p9);
        ft_putnbr(a);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        return (0);
}*/
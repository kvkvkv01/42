/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:52:32 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:52:32 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
        int div;
        int mod;

        div = *a / *b;
        mod = *a % *b;
        *a = div;
        *b = mod;
}

/*int     main(void)
{
        int a;
        int b;

        a = 10;
        b = 3;
        ft_ultimate_div_mod(&a, &b);
        ft_putnbr(a);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        ft_putnbr(b);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
        return (0);
}*/
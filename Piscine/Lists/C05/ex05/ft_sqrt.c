/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:12:56 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:12:56 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_sqrt(int nb)
{
        int     i;

        if (nb < 0)
                return (0);
        if (nb == 0 || nb == 1)
                return (nb);
        i = 1;
        while (i * i <= nb)
        {
                if (i * i == nb)
                        return (i);
                i++;
        }
        return (0);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_sqrt(0)); // 0
        printf("%d\n", ft_sqrt(1)); // 1
        printf("%d\n", ft_sqrt(4)); // 2
        printf("%d\n", ft_sqrt(9)); // 3
        printf("%d\n", ft_sqrt(16)); // 4
        printf("%d\n", ft_sqrt(25)); // 5
        printf("%d\n", ft_sqrt(26)); // 0
        printf("%d\n", ft_sqrt(-4)); // 0
        printf("%d\n", ft_sqrt(2147395600)); // 46340
        printf("%d\n", ft_sqrt(1024)); // 32
        return (0);
}
*/
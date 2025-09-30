/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:14:24 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:14:24 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_is_prime(int nb)
{
        int     i;

        if (nb <= 1)
                return (0);
        i = 2;
        while (i * i <= nb)
        {
                if (nb % i == 0)
                        return (0);
                i++;
        }
        return (1);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_is_prime(0)); // 0
        printf("%d\n", ft_is_prime(1)); // 0
        printf("%d\n", ft_is_prime(2)); // 1
        printf("%d\n", ft_is_prime(3)); // 1
        printf("%d\n", ft_is_prime(4)); // 0
        printf("%d\n", ft_is_prime(5)); // 1
        printf("%d\n", ft_is_prime(16)); // 0
        printf("%d\n", ft_is_prime(17)); // 1
        printf("%d\n", ft_is_prime(18)); // 0
        printf("%d\n", ft_is_prime(19)); // 1
        printf("%d\n", ft_is_prime(20)); // 0
        printf("%d\n", ft_is_prime(97)); // 1
        printf("%d\n", ft_is_prime(100)); // 0
        return (0);
}
*/
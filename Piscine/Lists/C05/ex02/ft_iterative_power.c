/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:09:21 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:09:21 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_iterative_power(int nb, int power)
{
        int     result;

        if (power < 0)
                return (0);
        if (power == 0)
                return (1);
        result = 1;
        while (power > 0)
        {
                result *= nb;
                power--;
        }
        return (result);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_iterative_power(2, 3)); // 8
        printf("%d\n", ft_iterative_power(5, 0)); // 1
        printf("%d\n", ft_iterative_power(3, -2)); // 0
        printf("%d\n", ft_iterative_power(4, 2)); // 16
        printf("%d\n", ft_iterative_power(1, 100)); // 1
        printf("%d\n", ft_iterative_power(0, 5)); // 0
        return (0);
}
*/
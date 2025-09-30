/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:19 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:08:19 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_iterative_factorial(int nb)
{
        int     result;

        if (nb < 0)
                return (0);
        if (nb == 0)
                return (1);
        result = 1;
        while (nb > 1)
        {
                result *= nb;
                nb--;
        }
        return (result);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_iterative_factorial(5)); // 120
        printf("%d\n", ft_iterative_factorial(0)); // 1
        printf("%d\n", ft_iterative_factorial(-3)); // 0
        printf("%d\n", ft_iterative_factorial(1)); // 1
        printf("%d\n", ft_iterative_factorial(10)); // 3628800
        return (0);
}
*/
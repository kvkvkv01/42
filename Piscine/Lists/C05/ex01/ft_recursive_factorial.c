/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:52 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:08:52 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_recursive_factorial(int nb)
{
        if (nb < 0)
                return (0);
        if (nb == 0)
                return (1);
        return (nb * ft_recursive_factorial(nb - 1));
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_recursive_factorial(5)); // 120
        printf("%d\n", ft_recursive_factorial(0)); // 1
        printf("%d\n", ft_recursive_factorial(-3)); // 0
        printf("%d\n", ft_recursive_factorial(1)); // 1
        printf("%d\n", ft_recursive_factorial(10)); // 3628800
        return (0);
}
*/
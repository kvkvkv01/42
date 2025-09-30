/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:11:37 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:11:37 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_recursive_power(int nb, int power)
{
        if (power < 0)
                return (0);
        if (power == 0)
                return (1);
        return (nb * ft_recursive_power(nb, power - 1));
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_recursive_power(2, 3)); // 8
        printf("%d\n", ft_recursive_power(5, 0)); // 1
        printf("%d\n", ft_recursive_power(3, -2)); // 0
        printf("%d\n", ft_recursive_power(4, 2)); // 16
        printf("%d\n", ft_recursive_power(1, 100)); // 1
        printf("%d\n", ft_recursive_power(0, 5)); // 0
        return (0);
}
*/
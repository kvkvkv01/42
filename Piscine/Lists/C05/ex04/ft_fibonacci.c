/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:12:04 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:12:04 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_fibonacci(int index)
{
        if (index < 0)
                return (-1);
        if (index == 0)
                return (0);
        if (index == 1)
                return (1);
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_fibonacci(0)); // 0
        printf("%d\n", ft_fibonacci(1)); // 1
        printf("%d\n", ft_fibonacci(2)); // 1
        printf("%d\n", ft_fibonacci(3)); // 2
        printf("%d\n", ft_fibonacci(4)); // 3
        printf("%d\n", ft_fibonacci(5)); // 5
        printf("%d\n", ft_fibonacci(6)); // 8
        printf("%d\n", ft_fibonacci(7)); // 13
        printf("%d\n", ft_fibonacci(8)); // 21
        printf("%d\n", ft_fibonacci(9)); // 34
        printf("%d\n", ft_fibonacci(10)); // 55
        printf("%d\n", ft_fibonacci(-5)); // -1
        return (0);
}
*/
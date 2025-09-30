/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:02:29 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:02:29 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_atoi(char *str)
{
        int     i;
        int     sign;
        int     result;

        i = 0;
        sign = 1;
        result = 0;
        while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign = -1;
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + (str[i] - '0');
                i++;
        }
        return (result * sign);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_atoi("   -1234abc"));
        printf("%d\n", ft_atoi("   +5678xyz"));
        printf("%d\n", ft_atoi("42 is the answer"));
        printf("%d\n", ft_atoi("   -0"));
        printf("%d\n", ft_atoi("   +0"));
        printf("%d\n", ft_atoi("   00001234"));
        printf("%d\n", ft_atoi("   -00001234"));
        printf("%d\n", ft_atoi("no digits here"));
        printf("%d\n", ft_atoi(""));
        return (0);
}
*/
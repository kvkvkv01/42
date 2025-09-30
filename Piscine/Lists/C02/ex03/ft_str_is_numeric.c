/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:28:57 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:28:57 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_str_is_numeric(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < '0' || str[i] > '9')
                        return (0);
                i++;
        }
        return (1);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "12345";
        char str2[] = "12a45";
        char str3[] = "abcde";
        char str4[] = "";

        printf("str1: %d\n", ft_str_is_numeric(str1));
        printf("str2: %d\n", ft_str_is_numeric(str2));
        printf("str3: %d\n", ft_str_is_numeric(str3));
        printf("str4: %d\n", ft_str_is_numeric(str4));
}*/
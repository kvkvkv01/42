/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:37:42 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:37:42 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int    ft_str_is_uppercase(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < 'a' || str[i] > 'z')
                        return (0);
                i++;
        }
        return (1);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "ABCDE";
        char str2[] = "ABcDE";
        char str3[] = "12345";
        char str4[] = "";

        printf("str1: %d\n", ft_str_is_uppercase(str1));
        printf("str2: %d\n", ft_str_is_uppercase(str2));
        printf("str3: %d\n", ft_str_is_uppercase(str3));
        printf("str4: %d\n", ft_str_is_uppercase(str4));
}*/
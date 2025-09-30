/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:37:07 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:37:07 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_str_is_lowercase(char *str)
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
        char str1[] = "abcde";
        char str2[] = "abCde";
        char str3[] = "12345";
        char str4[] = "";

        printf("str1: %d\n", ft_str_is_lowercase(str1));
        printf("str2: %d\n", ft_str_is_lowercase(str2));
        printf("str3: %d\n", ft_str_is_lowercase(str3));
        printf("str4: %d\n", ft_str_is_lowercase(str4));
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:41:31 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:41:31 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcapitalize(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (i == 0 || !(str[i - 1] >= 'a' && str[i - 1] <= 'z') &&
                    !(str[i - 1] >= 'A' && str[i - 1] <= 'Z') &&
                    !(str[i - 1] >= '0' && str[i - 1] <= '9'))
                {
                        if (str[i] >= 'a' && str[i] <= 'z')
                                str[i] = str[i] - 32;
                }
                else
                {
                        if (str[i] >= 'A' && str[i] <= 'Z')
                                str[i] = str[i] + 32;
                }
                i++;
        }
        return (str);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "hello world! 42foo bar";
        char str2[] = "42foo bar! hello world";
        char str3[] = "heLLo WoRLD! 42FOO BAR";
        char str4[] = "";

        printf("str1: %s\n", ft_strcapitalize(str1));
        printf("str2: %s\n", ft_strcapitalize(str2));
        printf("str3: %s\n", ft_strcapitalize(str3));
        printf("str4: %s\n", ft_strcapitalize(str4));
}*/
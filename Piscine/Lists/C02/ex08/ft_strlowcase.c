/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:40:58 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:40:58 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strlowcase(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] = str[i] + 32;
                i++;
        }
        return (str);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "ABCDE";
        char str2[] = "ABcDE";
        char str3[] = "12345";
        char str4[] = "";

        printf("str1: %s\n", ft_strlowcase(str1));
        printf("str2: %s\n", ft_strlowcase(str2));
        printf("str3: %s\n", ft_strlowcase(str3));
        printf("str4: %s\n", ft_strlowcase(str4));
}*/
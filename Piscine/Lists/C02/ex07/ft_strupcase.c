/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:40:29 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:40:29 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strupcase(char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] >= 'a' && str[i] <= 'z')
                        str[i] = str[i] - 32;
                i++;
        }
        return (str);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "abcde";
        char str2[] = "abCde";
        char str3[] = "12345";
        char str4[] = "";

        printf("str1: %s\n", ft_strupcase(str1));
        printf("str2: %s\n", ft_strupcase(str2));
        printf("str3: %s\n", ft_strupcase(str3));
        printf("str4: %s\n", ft_strupcase(str4));
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:44 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:44:44 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_str_is_printable(char *str)
{
        unsigned int    i;

        i = 0;
        while (str[i] != '\0')
        {
                if (str[i] < 32 || str[i] > 126)
                        return (0);
                i++;
        }
        return (1);
}

/*#include <stdio.h>
int     main(void)
{
        char str1[] = "Hello, World!";
        char str2[] = "Hello\tWorld!";
        char str3[] = "Hello\nWorld!";
        char str4[] = "";

        printf("str1: %d\n", ft_str_is_printable(str1));
        printf("str2: %d\n", ft_str_is_printable(str2));
        printf("str3: %d\n", ft_str_is_printable(str3));
        printf("str4: %d\n", ft_str_is_printable(str4));
}*/
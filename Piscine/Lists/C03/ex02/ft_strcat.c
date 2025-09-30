/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:57:19 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:57:19 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcat(char *dest, const char *src)
{
        int i;
        int j;

        i = 0;
        j = 0;
        while (dest[i] != '\0')
                i++;
        while (src[j] != '\0')
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        dest[i] = '\0';
        return (dest);
}

/*#include <stdio.h>
int     main(void)
{
        char dest[50] = "Hello, ";
        char src[] = "World!";

        printf("%s\n", ft_strcat(dest, src));
}*/
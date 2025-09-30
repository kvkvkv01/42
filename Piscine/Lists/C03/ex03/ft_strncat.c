/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:57:42 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:57:42 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strncat(char *dest, const char *src, unsigned int nb)
{
        unsigned int    i;
        unsigned int    j;

        i = 0;
        j = 0;
        while (dest[i] != '\0')
                i++;
        while (src[j] != '\0' && j < nb)
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

        printf("%s\n", ft_strncat(dest, src, 3));
}*/
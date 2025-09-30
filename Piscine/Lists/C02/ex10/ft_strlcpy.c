/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:43:17 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:43:17 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
        unsigned int    i;

        i = 0;
        if (size == 0)
        {
                while (src[i] != '\0')
                        i++;
                return (i);
        }
        while (i < size - 1 && src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        while (src[i] != '\0')
                i++;
        return (i);
}

/*#include <stdio.h>
int     main(void)
{
        char src[] = "42";
        char dest[50];

        printf("Length: %u\n", ft_strlcpy(dest, src, 1));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcpy(dest, src, 2));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcpy(dest, src, 3));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcpy(dest, src, 0));
        printf("Dest: %s\n", dest);
}*/
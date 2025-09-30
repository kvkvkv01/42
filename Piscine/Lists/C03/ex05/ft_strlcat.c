/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:58:58 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:58:58 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_strlcat(char *dest, const char *src, unsigned int size)
{
        unsigned int    i;
        unsigned int    j;
        unsigned int    dest_len;
        unsigned int    src_len;

        dest_len = 0;
        while (dest[dest_len] != '\0')
                dest_len++;
        src_len = 0;
        while (src[src_len] != '\0')
                src_len++;
        if (size <= dest_len)
                return (size + src_len);
        i = dest_len;
        j = 0;
        while (src[j] != '\0' && i < size - 1)
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        dest[i] = '\0';
        return (dest_len + src_len);
}

/*#include <stdio.h>
int     main(void)
{
        char dest[20] = "Hello, ";
        char src[] = "World!";

        printf("Length: %u\n", ft_strlcat(dest, src, 5));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcat(dest, src, 10));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcat(dest, src, 15));
        printf("Dest: %s\n", dest);
        printf("Length: %u\n", ft_strlcat(dest, src, 20));
        printf("Dest: %s\n", dest);
}*/
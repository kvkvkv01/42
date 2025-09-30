/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:58:11 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:58:11 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strstr(const char *haystack, const char *needle)
{
        int i;
        int j;

        if (needle[0] == '\0')
                return ((char *)haystack);
        i = 0;
        while (haystack[i] != '\0')
        {
                j = 0;
                while (haystack[i + j] == needle[j] && needle[j] != '\0')
                {
                        j++;
                        if (needle[j] == '\0')
                                return ((char *)&haystack[i]);
                }
                i++;
        }
        return (0);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%s\n", ft_strstr("Hello, World!", "World"));
        printf("%s\n", ft_strstr("Hello, World!", "42"));
        printf("%s\n", ft_strstr("Hello, World!", ""));
        printf("%s\n", ft_strstr("", "42"));
        printf("%s\n", ft_strstr("", ""));
}*/
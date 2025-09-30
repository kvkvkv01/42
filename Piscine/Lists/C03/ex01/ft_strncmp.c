/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:56:56 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:56:56 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
        unsigned int    i;

        i = 0;
        while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
        {
                if (s1[i] != s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}

/*#include <stdio.h>
int     main(void)
{
        printf("%d\n", ft_strncmp("abc", "abc", 3));
        printf("%d\n", ft_strncmp("abc", "abd", 3));
        printf("%d\n", ft_strncmp("abd", "abc", 3));
        printf("%d\n", ft_strncmp("abc", "ab", 3));
        printf("%d\n", ft_strncmp("ab", "abc", 3));
        printf("%d\n", ft_strncmp("", "", 3));
        printf("%d\n", ft_strncmp("a", "", 3));
        printf("%d\n", ft_strncmp("", "a", 3));
        printf("%d\n", ft_strncmp("abc", "abd", 2));
        printf("%d\n", ft_strncmp("abc", "abd", 0));
}*/
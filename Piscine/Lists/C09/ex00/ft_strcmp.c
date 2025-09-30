/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:56:30 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 17:56:30 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strcmp(char *s1, char *s2)
{
        int i;

        i = 0;
        while (s1[i] != '\0' || s2[i] != '\0')
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
        printf("%d\n", ft_strcmp("abc", "abc"));
        printf("%d\n", ft_strcmp("abc", "abd"));
        printf("%d\n", ft_strcmp("abd", "abc"));
        printf("%d\n", ft_strcmp("abc", "ab"));
        printf("%d\n", ft_strcmp("ab", "abc"));
        printf("%d\n", ft_strcmp("", ""));
        printf("%d\n", ft_strcmp("a", ""));
        printf("%d\n", ft_strcmp("", "a"));
}*/
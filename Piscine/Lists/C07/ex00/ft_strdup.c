/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:34:02 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:34:02 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

char    *ft_strdup(char *src)
{
        char    *dup;
        int     i;

        i = 0;
        while (src[i] != '\0')
                i++;
        dup = (char *)malloc((i + 1) * sizeof(char));
        if (dup == NULL)
                return (NULL);
        i = 0;
        while (src[i] != '\0')
        {
                dup[i] = src[i];
                i++;
        }
        dup[i] = '\0';
        return (dup);
}

/*int     main(void)
{
        char    *original;
        char    *copy;

        original = "Hello, World!";
        copy = ft_strdup(original);
        if (copy != NULL)
        {
                int     i;

                i = 0;
                while (copy[i] != '\0')
                {
                        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &copy[i], 1, 0, 0);
                        i++;
                }
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, 0, 0);
                free(copy);
        }
        return (0);
}*/
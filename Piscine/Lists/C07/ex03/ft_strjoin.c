/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:38:15 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:38:15 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_strjoin(int size, char **strs, char *sep)
{
        int     i;
        int     j;
        int     k;
        int     total_length;
        char    *joined_str;

        if (size <= 0)
        {
                joined_str = (char *)malloc(1 * sizeof(char));
                if (joined_str == NULL)
                        return (NULL);
                joined_str[0] = '\0';
                return (joined_str);
        }
        total_length = 0;
        for (i = 0; i < size; i++)
        {
                j = 0;
                while (strs[i][j] != '\0')
                {
                        total_length++;
                        j++;
                }
        }
        j = 0;
        while (sep[j] != '\0')
        {
                total_length++;
                j++;
        }
        total_length *= (size - 1);
        total_length += 1;
        joined_str = (char *)malloc(total_length * sizeof(char));
        if (joined_str == NULL)
                return (NULL);
        k = 0;
        while (k < total_length - 1)
        {
                while (strs[i][j] != '\0')
                {
                        joined_str[k] = strs[i][j];
                        k++;
                        j++;
                }
                if (i < size - 1)
                {
                        j = 0;
                        while (sep[j] != '\0')
                        {
                                joined_str[k] = sep[j];
                                k++;
                                j++;
                        }
                }
        }
        joined_str[k] = '\0';
        return (joined_str);
}

/*int     main(void)
{
        char    *strs[] = {"Hello", "world", "this", "is", "42"};
        char    *sep = " ";
        char    *result;
        int     size = 5;

        result = ft_strjoin(size, strs, sep);
        if (result != NULL)
        {
                printf("%s\n", result);
                free(result);
        }
        return (0);
}*/
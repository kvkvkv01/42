/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:37:18 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:37:18 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int     ft_ultimate_range(int **range, int min, int max)
{
        int     *arr;
        int     i;

        if (min >= max)
        {
                *range = 0;
                return (0);
        }
        arr = (int *)malloc((max - min) * sizeof(int));
        if (arr == NULL)
        {
                *range = NULL;
                return (-1);
        }
        i = 0;
        while (min < max)
        {
                arr[i] = min;
                i++;
                min++;
        }
        *range = arr;
        return (i);
}

/*
int     main(void)
{
        int     min;
        int     max;
        int     *range;
        int     size;
        int     i;

        min = 3;
        max = 10;
        size = ft_ultimate_range(&range, min, max);
        if (size != -1 && range != NULL)
        {
                i = 0;
                while (i < size)
                {
                        printf("%d ", range[i]);
                        i++;
                }
                printf("\n");
                free(range);
        }
        else if (size == -1)
                printf("Memory allocation failed\n");
        else
                printf("Invalid range\n");
        return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:36:02 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:36:02 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int min, int max)
{
        int     *range;
        int     i;

        if (min >= max)
                return (0);
        range = (int *)malloc((max - min) * sizeof(int));
        if (range == NULL)
                return (NULL);
        i = 0;
        while (min < max)
        {
                range[i] = min;
                i++;
                min++;
        }
        return (range);
}

/*#include <stdio.h>
int     main(void)
{
        int     min;
        int     max;
        int     *range;
        int     i;

        min = 3;
        max = 10;
        range = ft_range(min, max);
        if (range != NULL)
        {
                i = 0;
                while (i < max - min)
                {
                        printf("%d ", range[i]);
                        i++;
                }
                printf("\n");
                free(range);
        }
        return (0);
}
*/
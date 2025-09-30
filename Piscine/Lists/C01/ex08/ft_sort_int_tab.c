/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:04:25 by caualves          #+#    #+#             */
/*   Updated: 2025/09/17 00:04:25 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
        int	i;
        int	j;
        int	temp;

        i = 0;
        while (i < size - 1)
        {
                j = 0;
                while (j < size - 1 - i)
                {
                        if (tab[j] > tab[j + 1])
                        {
                                temp = tab[j];
                                tab[j] = tab[j + 1];
                                tab[j + 1] = temp;
                        }
                        j++;
                }
                i++;
        }
}

int     main(void)
{
        int tab[4] = {4, 3, 2, 1};
        ft_sort_int_tab(tab, 4);
        printf("%d %d %d %d\n", tab[0], tab[1], tab[2], tab[3]);
}
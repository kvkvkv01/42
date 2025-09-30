/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:57:06 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:57:06 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}

/*int     main(void)
{
        printf("%i\n", ft_strlen("Teste"));
        printf("%i\n", ft_strlen("Teste\n"));
}*/
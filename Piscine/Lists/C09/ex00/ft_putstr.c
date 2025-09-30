/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:53:01 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 16:53:01 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &str[i], 1, 0, 0);
                i++;
        }
}

/*int     main(void)
{
        ft_putstr("Bou & Kanon");
}*/
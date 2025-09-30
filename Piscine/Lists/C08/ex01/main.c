/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:22:35 by caualves          #+#    #+#             */
/*   Updated: 2025/09/30 13:22:35 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remember to delete

#include "ft_boolean.h"

void    ft_putstr(char *str)
{
    while (*str)
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), str++, 1, 0, 0);
}

int    ft_is_even(int nbr)
{
        return ((EVEN(nbr)) ? TRUE : FALSE);
}

int    main(int argc, char **argv)
{
        (void)argv;
        if (ft_is_even(argc - 1) == TRUE)
                ft_putstr(EVEN_MSG);
        else
                ft_putstr(ODD_MSG);
        return (SUCCESS);
}
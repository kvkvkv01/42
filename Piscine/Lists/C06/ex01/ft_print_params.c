/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:22:06 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:22:06 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

int     main(int argc, char **argv)
{
        int     i;

        i = 1;
        if (argc < 2)
                return (0);
        while (i < argc)
        {
                int     j;

                j = 0;
                while (argv[i][j] != '\0')
                {
                        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &argv[i][j], 1, 0, 0);
                        j++;
                }
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, 0, 0);
                i++;
        }
        return (0);
}
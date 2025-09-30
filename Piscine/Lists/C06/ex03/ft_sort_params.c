/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:31:43 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:31:43 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

int     main(int argc, char **argv)
{
        int     i;
        int     j;
        char    *temp;

        if (argc < 2)
                return (0);
        i = 1;
        while (i < argc - 1)
        {
                j = i + 1;
                while (j < argc)
                {
                        int     k;

                        k = 0;
                        while (argv[i][k] != '\0' && argv[j][k] != '\0' && argv[i][k] == argv[j][k])
                                k++;
                        if (argv[i][k] > argv[j][k])
                        {
                                temp = argv[i];
                                argv[i] = argv[j];
                                argv[j] = temp;
                        }
                        j++;
                }
                i++;
        }
        i = 1;
        while (i < argc)
        {
                int     k;

                k = 0;
                while (argv[i][k] != '\0')
                {
                        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &argv[i][k], 1, 0, 0);
                        k++;
                }
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, 0, 0);
                i++;
        }
        return (0);
}
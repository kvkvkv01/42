/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:06:03 by caualves          #+#    #+#             */
/*   Updated: 2025/09/30 14:06:03 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

int     main(int argc, char **argv)
{
        char    ascii[256] = {0};
        if (argc != 3)
        {
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, 0, 0);
                return (0);
        }
        while (*argv[2])
                ascii[(unsigned char)*argv[1]++] = 1;
        while (*argv[1])
        {
                if (ascii[(unsigned char)*argv[1]] == 1)
                {
                        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), argv[1], 1, 0, 0);
                        ascii[(unsigned char)*argv[1]] = 0;
                }
                argv[2]++;
        }
    return (0);
}
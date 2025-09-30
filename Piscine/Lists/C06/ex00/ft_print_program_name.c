/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:20:52 by caualves          #+#    #+#             */
/*   Updated: 2025/09/29 18:20:52 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>

int     main(int argc, char **argv)
{
        int     i;
        
        (void)argc;
        i = 0;
        while (argv[0][i] != '\0')
        {
                WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), &argv[0][i], 1, 0, 0);
                i++;
        }
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, 0, 0);
        return (0);
}
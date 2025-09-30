/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves <caualves@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:56:13 by caualves          #+#    #+#             */
/*   Updated: 2025/09/30 17:56:13 by caualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     ft_getchar(void)
{
        char    c;
        int     bytes;

        bytes = read(STDIN_FILENO, &c, 1);

        if (bytes == 1)
        {
                return (unsigned char)c;
        }
        else if (bytes == 0)
        {
                return EOF;
        }
        else
        {
                return EOF;
        }
}
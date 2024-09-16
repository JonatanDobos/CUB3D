/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nstrlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:25 by jdobos        #+#    #+#                 */
/*   Updated: 2024/09/16 16:03:20 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nstrlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

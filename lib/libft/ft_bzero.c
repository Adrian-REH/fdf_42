/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:42:08 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:22:26 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)

{
	if (n == 0)
		return ;
	while (n--)
		*(unsigned char *)s++ = 0;
}
/* 
int main()
{
	ft_bzero("as", 2);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:12 by root              #+#    #+#             */
/*   Updated: 2025/01/26 12:09:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void eck_args(int argc, char **argv)
{
    if(argc != 5)
    {
        printf("Argument error");
        exit(1);
    }
    if(strlen(argv[2]) == 0)
    {
        printf("command 1 is empty");
        exit(1);
    }
    if(strlen(argv[4]) == 0)
    {
        printf("command 2 is empty");
        exit(1);
    }
}
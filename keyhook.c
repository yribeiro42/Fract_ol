/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:05:13 by yribeiro          #+#    #+#             */
/*   Updated: 2017/06/13 18:03:49 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_hook(int key, t_env *env)
{
	//printf("%d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

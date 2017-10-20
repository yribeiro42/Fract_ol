/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:05:13 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/20 13:14:47 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_hook(int key, t_env *env)
{
	printf("%d\n", key);
	if (key == ESC)
	{
		free(env);
		exit(0);
	}
	if (key == 49)
		env->
	redraw(env);
	return (0);
}

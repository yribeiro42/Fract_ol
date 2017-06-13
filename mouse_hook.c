/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:30:15 by yribeiro          #+#    #+#             */
/*   Updated: 2017/06/13 17:52:34 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_env *env)
{
	//printf("%f\n", (float)(x - WIDTH / 2) / WIDTH * 2);
	env->p_r = (float)(x - WIDTH / 2) / WIDTH * 2;
	env->p_i = (float)(y - HEIGHT / 2) / HEIGHT * 2;
	redraw(env);
	return (0);
}

int		mouse_button_hook(int button, int x, int y, t_env *env)
{
	printf("%d\n", button);
	if (button == 1)
		env->iteration += 10;
	else if (button == 2 && env->iteration > 10)
		env->iteration -= 10;
	if (button == 4)
	{
		env->zoom = (env->zoom + 0.1) * 1.1;
	}
	else if (button == 5)
	{
		env->zoom = (env->zoom + 0.1) / 1.1;
	}
	redraw(env);
	return (0);
}
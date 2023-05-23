/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:11:27 by astein            #+#    #+#             */
/*   Updated: 2023/05/20 22:30:06 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_debug(t_model *model, int curr_stack_depth)
{
	model->dbg = malloc(sizeof(t_dbg));
	model->dbg->count_stack_depth = curr_stack_depth;
}

static void	print_tab_level(t_model *model, t_dbg_flag dbg_flg)
{
	int	tabs;
	int	tab_width;

	tabs = 0;
	tab_width = 5;
	if (dbg_flg == end_block)
		model->dbg->count_stack_depth--;
	while (tabs < (model->dbg->count_stack_depth) * tab_width)
	{
		write(1, " ", 1);
		tabs++;
	}
	if (dbg_flg == start_block)
		model->dbg->count_stack_depth++;
	if (dbg_flg == start_block)
		ft_putstr_fd(WRITE_COLOR_ORANGE "  [START] >", 1);
	else if (dbg_flg == end_block)
		ft_putstr_fd(WRITE_COLOR_GREEN "  [DONE] >>", 1);
	else if (dbg_flg == error_block)
		ft_putstr_fd(WRITE_COLOR_RED "[ERROR] ", 1);
	ft_putstr_fd(WRITE_COLOR_DEFAULT, 1);
}

void	dbg_printf(t_model *model, t_dbg_flag dbg_flg, char *str, ...)
{
	va_list	args;
	int		len;

	if (DEBUG == 1 || dbg_flg == error_block)
	{
		print_tab_level(model, dbg_flg);
		va_start(args, str);
		len = 0;
		while (*str)
		{
			if (*str == '%')
			{
				str++;
				len += print_whatever(args, (char *)str);
			}
			else
				print_char(*str, &len);
			str++;
		}
		va_end(args);
		ft_putstr_fd("\n", 1);
		if (dbg_flg == error_block)
			exit(0);
	}
}
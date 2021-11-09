/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:47:46 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:47:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	swap(t_data *this, t_data *other)
{
	void	*tmp;

	tmp = this->data;
	this->data = other->data;
	other->data = tmp;
}

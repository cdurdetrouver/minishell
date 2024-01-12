/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:40:47 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:52:31 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int	check_sign(const char *str)
{
	if (*str == '-')
		return (-1.0);
	return (1);
}

int	convert_integer_part(const char *str, const char **endptr)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	*endptr = str;
	return (result);
}

double	convert_fractional_part(const char *str)
{
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 0.1;
	while (*str >= '0' && *str <= '9')
	{
		result += decimal * (*str++ - '0');
		decimal *= 0.1;
	}
	return (result);
}

/**
 * @brief convert a string to a double.
 *
 * @param str (const char *) string to convert
 * @return (double) converted string
 */
double	ft_atodbl(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	str = skip_spaces(str);
	sign = check_sign(str);
	if (*str == '-' || *str == '+')
		str++;
	result = convert_integer_part(str, &str);
	if (*str == '.')
		str++;
	result += convert_fractional_part(str);
	return (result * sign);
}

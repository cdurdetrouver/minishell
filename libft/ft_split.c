/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:09:23 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/08 18:11:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_next_sep(int i, const char *str, char charset)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (charset == str[i])
			return (count);
		count++;
		i++;
	}
	if (str[i] == '\0')
		return (count);
	return (0);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (c != str[i])
			word = 1;
		if (c == str[i] && word)
		{
			word = 0;
			count++;
		}
		if (c == str[i])
			word = 0;
		i++;
	}
	if (word)
		count++;
	return (count);
}

char	*str_copy(int i, int len, const char *str)
{
	char	*dest;
	int		j;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < len)
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	*clean(char **dest, int stop)
{
	int	k;

	k = 0;
	while (k < stop)
	{
		free(dest[k]);
		k++;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(const char *str, char charset)
{
	char	**dest;
	int		i;
	int		k;
	int		len;
	int		word_count;

	word_count = count_words(str, charset);
	dest = malloc((word_count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	k = 0;
	while (k < word_count)
	{
		while (str[i] == charset)
			i++;
		len = ft_next_sep(i, str, charset);
		dest[k] = str_copy(i, len, str);
		if (!dest[k])
			return (clean(dest, k));
		i += len;
		k++;
	}
	dest[k] = NULL;
	return (dest);
}

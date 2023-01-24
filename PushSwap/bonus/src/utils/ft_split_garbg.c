/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_garbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:55:09 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/24 04:22:18 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	word_count(char *s, char c);
// i change it ;p
char	**ft_split_garbg(char const *s, char c, t_list **garbg)
{
	char	**splited;
	int		wc;
	int	tmp_count;

	if (!s)
		return (NULL);
	wc = word_count((char *)s, c);
	splited = ft_malloc(malloc((wc + 1) * sizeof(char *)), garbg);
	while (wc--)
	{
		tmp_count = 0;
		while (*s == c)
			s++;
		while (*(s + tmp_count) != c && *(s + tmp_count))
			tmp_count++;
		if (!tmp_count)
			break ;
		*splited = ft_malloc(ft_substr(s, 0, tmp_count), garbg);
		s += tmp_count;
		splited++;
	}
	*splited = NULL;
	return (splited);
}

static int	word_count(char *s, char c)
{
	int	i;

	i = 0;
	while (*(s++))
		if (*(s - 1) != c && (*s == c || !*s))
			i++;
	return (i);
}

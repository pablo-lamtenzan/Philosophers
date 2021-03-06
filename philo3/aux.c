/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:18:58 by pablo             #+#    #+#             */
/*   Updated: 2020/12/18 19:02:53 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo3.h"

int							ft_atoi(const char *str)
{
	int						i;
	unsigned long int		nb;
	int						sing;
	char					*s;

	sing = 1;
	nb = 0;
	i = 0;
	s = (char *)str;
	if (s[i] == '-')
	{
		if (s[i] == '-')
			sing = -sing;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		nb = nb * 10 + s[i++] - '0';
	if ((sing > 0 && nb <= 9223372036854775807L) ||
			(sing < 0 && nb <= 9223372036854775808UL))
		return (sing * nb);
	return (sing < 0 ? 0 : -1);
}

uint64_t					get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((time_t)tv.tv_sec * (time_t)1000 + \
		((suseconds_t)tv.tv_usec / (suseconds_t)1000));
}

void						ft_putnbr_fd(uint64_t n, int fd)
{
	char					str[13];
	int						length;

	if (n == 0u)
		str[0] = '0';
	length = 0;
	while (n != 0u)
	{
		str[length++] = '0' + (n % 10u);
		n = (n / 10u);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], sizeof(str[length]));
}

size_t						ft_strlen(const char *str)
{
	char					*addr;

	addr = (char*)str;
	while (*addr)
		addr++;
	return (addr - str);
}

size_t						ft_strlcpy(char *dst, const char *src,
		size_t dstsize)
{
	size_t		count;
	size_t		size;

	count = 0;
	size = 0;
	if (!dst)
		return (0);
	while (src[size])
		size++;
	if (!dstsize)
		return (size);
	while (src[count] && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (size);
}

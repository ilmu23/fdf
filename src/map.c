/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:18:10 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/19 18:50:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	getmapsize(int fd, t_map *map);
static int	*parseline(int fd, size_t n);

t_map	*parsemap(char *fname)
{
	size_t	i;
	t_map	*out;
	int		fd;

	out = ft_push(ft_alloc(sizeof(t_map)));
	if (!getmapsize(open(fname, O_RDONLY), out))
		return (NULL);
	out->map = ft_push(ft_alloc((out->height + 1) * sizeof(int *)));
	if (!out->map)
		return (NULL);
	i = 0;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < out->height)
	{
		out->map[i] = parseline(fd, out->width);
		if (!out->map[i++])
			return (NULL);
	}
	return (out);
}

static int	*parseline(int fd, size_t n)
{
	size_t	i;
	char	*line;
	int		*out;

	out = ft_push(ft_alloc(n * sizeof(int)));
	line = get_next_line(fd);
	if (!out || !line)
		return (NULL);
	i = 0;
	while (i < n)
	{
		out[i++] = ft_atoi(line);
		line = ft_nextword(line);
	}
	return (out);
}

static int	getmapsize(int fd, t_map *map)
{
	size_t	i;
	char	*line;

	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	map->width = ft_wordcount(line);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	map->height = i;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmedin <angmedin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:11:39 by angmedin          #+#    #+#             */
/*   Updated: 2023/03/31 17:02:29 by angmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*str;

	a = (char) c;
	str = (char *) s;
	while (*str != a && *str != '\0')
	{
		str++;
	}
	if (*str == a)
		return (str);
	return (0);
}*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*call;
	size_t			i;

	if (count > SIZE_MAX / size)
		return (NULL);
	call = (unsigned char *) malloc (count * size);
	i = 0;
	if (!call)
		return (0);
	while (i < count * size)
	{
		call[i] = 0;
		i++;
	}
	return (call);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((int)len == -1 || ((int)len > ((int)ft_strlen(s) - (int)start)))
		str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		str = (char *) malloc((len + 1) * sizeof(char));
	i = (size_t) start;
	j = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	while (j < len && s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}*/

char	*ft_strjoin(char *s1, char s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *) malloc((ft_strlen(s1) + 2) * (sizeof(char)));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	if (s2 != '\0')
	{
		str[j] = s2;
	}
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int 		i;
	int			read_bytes;
	char		*arr;
	static char	*b2 = NULL;

	arr = "";
	buffer = NULL;
	read_bytes = 1;
	i = 0;
	
	/*while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
		while ((ft_strchr(buffer, '\n')) == 0)
			arr = ft_strjoin(arr, buffer);

		while ((ft_strchr(buffer, '\n')) != 0)
		{
			if (buffer[len_buffer - 1] == '\n')
				arr = ft_strjoin(arr, buffer);
			if else (buffer[0] == '\n')
				b2 = buffer + 1;
			else
			{
				i = 0;
				while (buffer[i] != '\n')
				{
					arr = ft_strjoin(arr, buffer);
					i++;
				}
				if (!b2)
				if (b2 == 0)
				if (b2 == NULL)
					b2 = ft_calloc...
				b2 = buffer + i + 1;
			}
		}
	}*/

	// OTRO PLANTEAMIENTO
	
	while (buffer[i] != '\n' && i < BUFFER_SIZE && read_bytes != 0)
	{	
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		arr = ft_strjoin(arr, buffer[i]); // si no me vale ft_strjoin me hago otra
		i++;
	}
	arr[i] = '\0';	
	while (i < BUFFER_SIZE && read_bytes != 0)
	{
		b2 = ft_strjoin(b2, buffer[i + 1]);
		i++;
	}
	return(arr);
}

int	main(void)
{
	int fd = open ("archivo.txt", O_RDONLY);
	char	*line;
	int		i;

	i = 0;
	if (fd == -1)
		return (0);
	/*while (i++ < 20)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}*/
	line = get_next_line(fd);
	close (fd);
	return (0);
}

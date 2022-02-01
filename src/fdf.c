#include "fdf.h"

int	ft_error(const char *str)
{
	perror(str);
	return (-1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", STDERR_FILENO);
		return (-1);
	}
	i = 0;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (ft_error("Error"));
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	free(line);
	return (0);
}

/*
** main.c for main in /home/peau_c/rendu/CPE/CPE_2015_BSQ/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Wed Dec  9 12:31:08 2015
** Last update Sun Dec 20 21:04:09 2015 
*/

#include <stdio.h>
#include <string.h>
#include "../include/my.h"
#include "../include/utils.h"

void	im_free(t_data *data)
{
	int		i;
	
	i = -1;
	while (data->map[++i] != NULL)
	{
		free(data->int_tab[i]);
		free(data->map[i]);
	}
	free(data->map);
	free(data->int_tab);
}

int		prepare(t_data *data, const char * const filename)
{
	char	c;
	char	*number_of_lines = malloc(10);

	number_of_lines[0] = 0;
	bzero(data, sizeof(t_data));

	//Open the file and verify it went correcly
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
	{
		dprintf(2, "Could not open the file %s\n", filename);
		return (1);
	}

	// We read the first line to get the number of lines and their width
	while (read(data->fd, &c, 1) > 0)
	{
		if (c == '\n') {
			data->width = atoi(number_of_lines);
			// Break when we find the end of the first line
			break;
		}
		size_t last_char_index = strlen(number_of_lines);
		number_of_lines[last_char_index] = c;
		number_of_lines[last_char_index + 1] = 0;
	}
	printf("Finished preparing\n There is %lu lines\n", data->width);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 2)
	{
		dprintf(2, "Usage: ./bsq file");
		return (1);
	}
	if (prepare(&data, av[1]))
		return (1);
	if (reading(&data))
		return (1);
	parsing(&data);
	//TODO Print solution
	print_array(data.map);
	im_free(&data);
	return (0);
}

//
// Created by Clément Péau on 2019-03-02.
//

#include <unistd.h>
#include <stdlib.h>
#include <printf.h>

void print_array(char **array)
{
	for (int i = 0; array[i]; i++)
		printf("%s\n", array[i]);
}

void	**create_map(size_t array_size, size_t line_size, size_t type_size)
{
	void **tab;
	
	//Don't forget the null :)
	if (((tab = malloc(sizeof(void *) * (array_size + 1)))) == NULL)
		return (NULL);
	
	for (size_t i = 0; i < array_size; i++)
	{
		if ((tab[i] = malloc(type_size * line_size)) == NULL)
			return (NULL);
	}
	tab[array_size] = NULL;
	return (tab);
}


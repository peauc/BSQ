/*
** reading.c for read in /home/peau_c/rendu/CPE/CPE_2015_BSQ
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Fri Dec 11 10:53:54 2015
** Last update Sat Dec 19 22:22:18 2015 
*/

#include "../include/my.h"

int	tabing(t_data *data)
{
  int	i;

  i = 0;
  if (((data->str = malloc(sizeof(char *) * (data->lenght + 1)))) == NULL)
    return (-1);
  if ((data->int_tab = malloc(sizeof(int *) * data->lenght)) == NULL)
    return (-1);
  while (i != data->lenght)
    {
      if ((data->str[i] = malloc(sizeof(char) * data->width + 2)) == NULL)
	return (-1);
      i++;
    }
  data->str[data->lenght] = NULL;
  i = 0;
  while (i != data->lenght)
    {
      if ((data->int_tab[i] = malloc(sizeof(int) * data->width)) == NULL)
	return (-1);
      i++;
    }
  return (1);
}

int	reading(t_data *data)
{
  int	i;
  char	ch;

  if (tabing(data) == -1)
    return (-1);
  i = 0;
  ch = 0;
  if ((data->fd = open(data->filename, O_RDONLY)) == -1)
    return (-1);
  while (ch != '\n' && (data->size -= 1))
    read(data->fd, &ch, 1);
  while (data->str[i] != NULL  &&
	 read(data->fd, data->str[i], data->width + 1) > 0)
    data->str[i++][data->width + 1] = 0;
  return (1);
}

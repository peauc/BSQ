/*
** main.c for main in /home/peau_c/rendu/CPE/CPE_2015_BSQ/src
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Wed Dec  9 12:31:08 2015
** Last update Sun Dec 20 21:04:09 2015 
*/

#include "../include/my.h"

void		im_free(t_data *data)
{
  int		i;

  i = -1;
  while (data->str[++i] != NULL)
    {
      free(data->int_tab[i]);
      free(data->str[i]);
    }
  free(data->str);
  free(data->int_tab);
}

void		prepare(t_data *data)
{
  char		c;
  int		tmp;

  tmp = 0;
  data->width = 0;
  data->lenght = -1;
  data->size = 0;
  data->max.size = 0;
   while (read(data->fd, &c, 1) > 0)
    {
      data->size++;
      if (c != '\n')
	tmp++;
      if (c == '\n')
	{
	  data->lenght += 1;
	  data->width = (tmp > 0 ? tmp : data->width);
	  tmp = 0;
	}
    }
}

int		main(int ac, char **av)
{
  t_data	data;
  int		i;

  i = -1;
  if (ac < 2)
    {
      write(2, "Usage : ./bsq \"filename\"\n",
	    my_strlen("Usage : ./bsq \"filename\"\n"));
      return (-1);
    }
  else
    data.filename = av[1];
  if ((data.fd = open(data.filename, O_RDONLY)) == -1)
    return (-1);
  prepare(&data);
  data.fd = 0;
  if (reading(&data) == -1)
    return (-1);
  parsing(&data);
  while (data.str[++i] != NULL)
    my_putstr(data.str[i]);
  im_free(&data);
  return (1);
}

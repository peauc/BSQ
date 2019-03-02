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
#include "../include/utils.h"

int	reading(t_data *data)
{
  if ((data->map = (char**)create_map(data->width, data->width, sizeof(char))) == NULL)
      return (1);
  if ((data->int_tab = (int**)create_map(data->width, data->width, sizeof(int))) == NULL)
      return (1);
  
  //We get all the lines and remove the newline
  for (size_t i = 0; data->map[i] != NULL; i++)
  {
         read(data->fd, data->map[i], data->width + 1);
         data->map[i][data->width] = 0;
  }
  return (0);
}

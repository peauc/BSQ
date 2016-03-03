/*
** getinfo.c for  in /home/peau_c/rendu/CPE/CPE_2015_BSQ
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 15 14:39:29 2015
** Last update Sat Dec 19 22:20:41 2015 
*/

#include "../include/my.h"

void	getinfo(t_data *data)
{
  data->width = 0;
  data->lenght = 0;
  while (data->str[0][data->width++] != '\n');
  data->lenght = data->size / data->width - 1;
}

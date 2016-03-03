/*
** my_putstr.c for pustr in /home/peau_c/rendu/CPE/BSQ/CPE_2015_BSQ
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sat Dec 19 12:23:32 2015
** Last update Sat Dec 19 16:43:19 2015 
*/

#include "../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    {
      my_putchar(str[i]);
    }
}

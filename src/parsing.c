/*
** parsing.c for lol in /home/peau_c/rendu/CPE/CPE_2015_BSQ
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 15 11:48:37 2015
** Last update Sun Dec 20 13:45:04 2015 
*/

#include "../include/my.h"

void		finish_it(t_data *data)
{
  int		i;
  int		j;

  i = data->max.y - data->max.size;
  j = data->max.x - data->max.size;
  while (i != data->max.y)
    {
      while (j != data->max.x)
  	{
  	  data->str[i + 1][j + 1] = 'x';
  	  j++;
  	}
      j = data->max.x - data->max.size;
      i++;
    }
}

void		put_max(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i != data->lenght)
    {
      while (j != data->width)
	{
	  if (data->int_tab[i][j] > data->max.size)
	    {
	      data->max.size = data->int_tab[i][j];
	      data->max.x = j;
	      data->max.y = i;
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  finish_it(data);
}
void		bsq_calc(t_data *data)
{
  int		i;
  int		j;
  int		tmp;

  tmp = 0;
  i = 1;
  j = 1;
  while (i != data->lenght)
    {
      while (j != data->width)
	{
	  tmp = data->int_tab[i][j - 1];
	  tmp = (data->int_tab[i-1][j] > tmp ? tmp : data->int_tab[i - 1][j]);
	  tmp = (data->int_tab[i - 1][j - 1] > tmp ? tmp :
		 data->int_tab[i - 1][j - 1]);
	  data->int_tab[i][j] = (data->str[i][j] == 'o' ? 0 : tmp + 1);
	  j++;
	}
      tmp = 0;
      j = 1;
      i++;
    }
  put_max(data);

}

void		parsing(t_data *data)
{
  int		i;
  int		b;

  i = 0;
  b = 0;
  while (b < data->width)
    {
      data->int_tab[i][b] = (data->str[i][b] == 'o' ? 0 : 1);
      b++;
    }
  b = 0;
  i = 0;
  while (i++ < data->lenght - 1)
      data->int_tab[i][b] = (data->str[i][b] == 'o' ? 0 : 1);
  bsq_calc(data);
}

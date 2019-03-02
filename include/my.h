/*
** my.h for .h in /home/peau_c/rendu/CPE/CPE_2015_BSQ/include
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Wed Dec  9 12:28:51 2015
** Last update Sun Dec 20 21:47:18 2015 
*/

#ifndef _MY_H_
# define _MY_H_

#include <unistd.h>

typedef struct s_max
{
  int		size;
  int		y;
  int		x;
}		t_size;

typedef struct	s_data
{
  int		**int_tab;
  int		fd;
  int		size;
  char		**map;
  size_t		width;
  t_size       	max;
}		t_data;

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void parsing(t_data *);
int reading(t_data*);
#endif	/* _MY_H_ */

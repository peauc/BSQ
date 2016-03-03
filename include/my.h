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

typedef struct s_max
{
  int		size;
  int		y;
  int		x;
}		t_size;

typedef struct	s_data
{
  int		**int_tab;
  char		*filename;
  int		fd;
  int		size;
  int		lenght;
  char		**str;
  int		width;
  t_size       	max;
}		t_data;

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void my_putstr(char *);
void show_tab(t_data *);
void parsing(t_data *);
int my_strlen(char *);
void my_strncpy(char *, char *, int);
char *my_realloc(char *, int, int);
int reading(t_data*);
void my_strcpy(char *, char *);
int tabing(t_data *);
void getinfo(t_data *);
#endif	/* _MY_H_ */

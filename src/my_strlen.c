/*
** my_strlen.c for my_strlen in /home/peau_c/rendu/CPE/CPE_2015_BSQ
** 
** Made by 
** Login   <peau_c@epitech.net>
** 
** Started on  Fri Dec 11 16:30:33 2015 
** Last update Fri Dec 11 16:31:22 2015 
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != 0);
  return (i);
}

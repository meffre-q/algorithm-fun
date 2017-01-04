#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct s_list
{
  int id;
  struct s_list *nxt;
  struct s_list *prv;
};

static unsigned short init(struct s_list *list)
{
  void *first_node = list;
  void *tmp;
  unsigned short min = 0;
  unsigned short max;
  unsigned short return_value;

  srand(time(NULL));
  max = rand() % 1000;
  list->id = min;
  list->prv = NULL;
  list->nxt = malloc(sizeof(struct s_list));
  if (!list->nxt)
    {
      printf("ERROR: Malloc failed.\n");
      exit(EXIT_FAILURE);
    }
  min++;
  while (min <= max)
    {
      tmp = list;
      list = list->nxt;
      list->id = min;
      list->prv = tmp;
      list->nxt = malloc(sizeof(struct s_list));
      if (!list->nxt)
	{
	  printf("ERROR: Malloc failed.\n");
	  exit(EXIT_FAILURE);
	}
      min++;
    }
  list->nxt = NULL;
  return_value = list->id;
  list = first_node;
  return return_value;
}

static void display(struct s_list *list)
{
  void *first_node = list;

  while (list)
    {
      printf("id: %i\n", list->id);
      list = list->nxt;
    }
  list = first_node;
}

static unsigned short get_third_from_last(struct s_list *list)
{
  struct s_list *one = list;
  struct s_list *two = list;
  unsigned int i = 0;

  while (two)
    {
      while (i < 6)
	{
	  if (two->nxt)
	    two = two->nxt;
	  else
	    {
	      two = NULL;
	      break;
	    }
	  i++;
	}
      if (i == 6)
	{
	  while (i)
	    {
	      one = one->nxt;
	      i--;
	    }
	}
      else if (i == 3)
	return one->id;
      else if (i > 3)
	{
	  while ((i%3))
	    {
	      one = one->nxt;
	      i--;
	    }
	  return one->id;
	}
      else
	{
	  while (i)
	    {
	      one = one->prv;
	      i--;
	    }
	  return one->id;
	}
    }
}

int main(void)
{
  struct s_list *list;
  unsigned short size;

  list = malloc(sizeof(struct s_list));
  if (!list)
    {
      printf("ERROR: Malloc failed.\n");
      return 1;
    }
  size = init(list);
  printf("Size = %u\nthird from last = %u\n", size, get_third_from_last(list));
  return 0;
}

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

static unsigned short get_middle(struct s_list *list)
{
  void *first_node = list;
  unsigned short return_value = 0;

  while (list)
    {
      if (list->nxt)
	list = list->nxt;
      if (list->nxt)
	list = list->nxt;
      else
	list = NULL;
      return_value++;
    }
  list = first_node;
  return return_value - 1;
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
  printf("Size = %u\nmiddle = %u\n", size, get_middle(list));
  return 0;
}

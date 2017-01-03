#include <stdlib.h>
#include <stdio.h>

struct s_list
{
  int id;
  struct s_list *nxt;
  struct s_list *prv;
};

static void init(struct s_list *list)
{
  void *first_node = list;
  void *tmp;
  unsigned short i = 0;

  list->id = i;
  list->nxt = malloc(sizeof(struct s_list));
  if (!list->nxt)
    {
      printf("ERROR: Malloc failed.\n");
      exit(EXIT_FAILURE);
    }
  i++;
  while (i <= 10)
    {
      tmp = list;
      list = list->nxt;
      list->id = i;
      list->prv = tmp;
      list->nxt = malloc(sizeof(struct s_list));
      if (!list->nxt)
	{
	  printf("ERROR: Malloc failed.\n");
	  exit(EXIT_FAILURE);
	}
      i++;
    }
  list->nxt = first_node;
  tmp = list;
  list = list->nxt;
  list->prv = tmp;
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

static unsigned char check_loop(struct s_list *list)
{
  void *first_node = list;

  while (list)
    {
      if (list == first_node)
	return 0;
      list = list->nxt;
    }
  list = first_node;
  return 0;
}

int main(void)
{
  struct s_list *list;

  list = malloc(sizeof(struct s_list));
  if (!list)
    {
      printf("ERROR: Malloc failed.\n");
      return 1;
    }
  init(list);
  if (check_loop)
    printf("Linked list is circular\n");
  else
    printf("Linked list isn't circular\n");
  return 0;
}

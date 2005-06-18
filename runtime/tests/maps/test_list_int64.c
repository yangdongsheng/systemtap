#include "runtime.h"

/* test of list with value of STRING */
#define NEED_INT64_VALS
#define KEY1_TYPE INT64
#include "map-keys.c"

#include "list.c"

int main ()
{
  int i;

  MAP map = _stp_list_new (10, INT64);

  for (i = 0; i < 10; i++)
    _stp_list_add_int64 (map, (int64_t)i);


  _stp_map_print(map, "list[%1d] = %d");
  printf ("size is %d\n\n", _stp_list_size(map));

  /* we set a limit of 10 elements so these */
  /* won't be added to the list */
  for (i = 50; i < 55; i++)
    _stp_list_add_int64 (map, i);
  _stp_map_print(map, "list[%1d] = %d");


  _stp_list_clear (map);
  _stp_map_print(map, "list[%1d] = %d");

  for (i = 50; i < 55; i++)
    _stp_list_add_int64 (map, i);

  _stp_map_print(map, "newlist[%1d] = %d");

  _stp_map_del (map);

  return 0;
}

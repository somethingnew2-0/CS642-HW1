#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char *arg)
{
  char buf[400];
  //char* mystring = "%32u%n%220u%n%03u%n%192u%n";
  //snprintf(buf, sizeof buf, "%32u%n%220u%n%03u%n%192u%n", 1, (void *)(0xbffffe3c), 1, (void *)
  //	(0xbiffffe3d), 1, (void*)(0xbffffe3e), 1, (void*)(0xbffffe3f) );
  snprintf(buf, sizeof buf, arg);
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf(stderr, "target5: argc != 2\n");
      exit(EXIT_FAILURE);
    }
  foo(argv[1]);

  return 0;
}

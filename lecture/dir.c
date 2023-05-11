#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>

#define oops(msg, errn) { perror(msg); exit(errn); }

int main(int argc, char *argv[])
{
   DIR *dir;
   struct dirent *dir_entry;
   
    long largestFile = 0;

   if ((dir = opendir(".")) == NULL)
      oops("Cannot open the directory.", 1);

   printf("DIRECTORY LISTING:\n");
   while ((dir_entry = readdir(dir)) != NULL)
   {
      struct stat fileInfo;
      stat(dir_entry->d_name, &fileInfo);
      if(largestFile < fileInfo.st_size) {
        largestFile = fileInfo.st_size;
        printf("New largest file found: %s\n", dir_entry->d_name);
      }
   }
   
   closedir(dir);
}
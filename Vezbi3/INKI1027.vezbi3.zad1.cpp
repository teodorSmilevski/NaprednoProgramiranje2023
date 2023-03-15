// Teodor Smilevski INKI1027
#include <stdio.h>      
#include <time.h>     

int main ()
{
  time_t now;
  struct tm newyear;
  double seconds;

  time(&now);  

  newyear = *localtime(&now);

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;

  seconds = difftime(now,mktime(&newyear));

  printf ("%.f seconds since new year in the current timezone.\n", seconds);
  return 0;
}
/* so ovaa programa se presmetuva izminatoto vreme od novata godina do sega vo sekundi  */

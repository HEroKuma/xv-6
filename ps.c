#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char *argv[])
{
  int p;
  if(argc > 2){
    return -1;
  }
  struct pstat* infotable = (struct pstat*)malloc(sizeof(struct pstat));
  if(argc == 1){
    getpinfo(infotable);
    printf(1, "PID tickets ticks\n");
    for(p = 0; p < NPROC; p++){
      if(infotable->inuse[p])
        printf(1, "%d %d %d\n", infotable->pid[p], infotable->tickets[p], infotable->ticks[p]);
    }
  }
  if(argc == 2 && strcmp(argv[1], "-r") == 0){
    while(1){
      getpinfo(infotable);
      printf(1, "PID tickets ticks\n");
      for(p = 0; p < NPROC; p++){
        if(infotable->inuse[p])
          printf(1, "%d %d %d\n", infotable->pid[p], infotable->tickets[p], infotable->ticks[p]);
      }
      sleep(50);
    }
  }
  return 0;
}

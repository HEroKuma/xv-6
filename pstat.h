#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
  int inuse[NPROC];      // slot of process table is in use(0 || 1)
  int tickets[NPROC];    // number of tickets this process has
  int pid[NPROC];        // PID of each process
  int ticks[NPROC];      // total number of ticks this process has been scheduled for
};

#endif // if _PSTAT_H_

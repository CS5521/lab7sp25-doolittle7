#include "param.h"

#ifndef _PSTAT_H_
#define _PSTAT_H_

typedef struct {
    int inuse;
    int tickets;
    int pid;
    int ticks;
    char name[16];
    char state;
} pstat_t;

typedef pstat_t pstatTable[NPROC];

void getpinfo(pstatTable *);

#endif // _PSTAT_H_
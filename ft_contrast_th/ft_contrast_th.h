#ifndef FT_CONTRAST_TH_H
# define FT_CONTRAST_TH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

/* Threads`s possible statuses; */
#define EMPTY		0
#define RUNNING		1
#define RUNNABLE	2

#define STACK_SIZE  8192 /* ulimit -s */
#define MAX_THREAD  4

typedef struct thread thread_t, *thread_p;

struct		thread
{
  int		*sp;                /* curent stack pointer */
  char		stack[STACK_SIZE];       /* the thread's stack */
  int		status;
};

static thread_t all_thread[MAX_THREAD];
thread_p  current_thread;
thread_p  next_thread;

#endif

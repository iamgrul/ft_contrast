#include "ft_contrast_th.h"

void  thread_init(void)
{
  current_thread = &all_thread[0];
  current_thread->status = RUNNING;
}

static void thread_queue(void)
{
  thread_p t;

  /* Look for other runnable threads */
  t = all_thread;
  while (t < all_thread + MAX_THREAD)
  {
    if (t->status == RUNNABLE && t != current_thread)
    {
      next_thread = t;
        break;
    }
    t++;
  }
  if (t >= all_thread + MAX_THREAD && current_thread->status == RUNNABLE) 
    next_thread = current_thread;
  if (next_thread == 0) 
  {
    write(2, "thread_queue: no runnable threads; deadlock\n", 48);
    exit(0);
  }
  if (current_thread != next_thread) 
    next_thread->status = RUNNING;
  else
    next_thread = 0;
}

int   thread_create(void (*func)())
{
  thread_p t;

  t = all_thread;
  while (t < all_thread + MAX_THREAD)
  {
    if (t->status == EMPTY)
      break ;
    t++;
  }
  t->sp = (int *) (t->stack + STACK_SIZE);   // set sp to the top of the stack
  *(int *)(t->sp) = (int)func;           // push return address on stack
  t->status = RUNNABLE;
  return ((int)func);
}

static void	mythread1(void)
{
  int i;

  ft_putstr("thread running\n");
  i = 0;
  while (i++ < 10)
  {
    printf("thread 1: %x\n", (int)current_thread);
    current_thread->status = RUNNABLE;
    thread_queue();
  }
  ft_putstr("thread 1: exit\n");
  current_thread->status = EMPTY;
  thread_queue();
}

static void	mythread2(void)
{
  int i;

  ft_putstr("thread running\n");
  i = 0;
  while (i++ < 10)
  {
    printf("thread 2: %x\n", (int)current_thread);
    current_thread->status = RUNNABLE;
    thread_queue();
  }
  ft_putstr("thread 2: exit\n");
  current_thread->status = EMPTY;
  thread_queue();
}

static void	mythread3(void)
{
  int i;

  ft_putstr("thread running\n");
  i = 0;
  while (i++ < 10)
  {
    printf("thread 3: %x\n", (int)current_thread);
    current_thread->status = RUNNABLE;
    thread_queue();
  }
  ft_putstr("thread 3: exit\n");
  current_thread->status = EMPTY;
  thread_queue();
}

int		main(void) 
{

  thread_init();
  thread_create(mythread1);
  mythread1();
  thread_queue();
  thread_create(mythread2);
  mythread2();
  thread_create(mythread3);
  mythread3();
  thread_queue();
  return (0);
}

#include "ft_contrast_th.h"
#include "./libft/libft.h"

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

static void	mythread(void)
{
  int i;

  ft_putstr("thread running\n");
  i = 0;
  while (i++ < 100)
  {
    printf("thread: %x\n", (int)current_thread);
    current_thread->status = RUNNABLE;
    thread_queue();
  }
  ft_putstr("thread: exit\n");
  current_thread->status = EMPTY;
  thread_queue();
}

int		main(void) 
{
  thread_init();
  thread_create(mythread);
  mythread ();
  thread_create(mythread);
  mythread ();
  thread_queue();
  return (0);
}

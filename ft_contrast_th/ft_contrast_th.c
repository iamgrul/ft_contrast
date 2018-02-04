#include "ft_contrast_th.h"
#include <pthread.h>
#include <signal.h>

typedef struct s_job
{
  size_t       id;
  void    (*task)(void *arg);
  void    *arg;
  struct s_job   *next;

} t_job;


// typedef struct s_thread
// {
//   size_t       id;
//   pthread_t   thread;
// } t_thread;

typedef struct s_tp_thread
{
  size_t      threads_max;
  size_t      threads_working;
  size_t      jobs_amount;
  pthread_t    *threads;
  t_job       *jobs;

	// struct thpool_* thpool_p;            /* access to thpool          */

} t_tp_thread;



t_job *j_create(void    (*_job)(void *arg),void *_arg, int _id)
{
  t_job *job;

  job = NULL;
  if (!(job = malloc(sizeof(t_job))))
  {
    ft_putendl("Failed malloc while creating a job");
    return NULL;
  }
  job->id = _id;
  job->arg = _arg;
  job->task = _job;
  job->next = NULL;
  return (job);
}

//TODO: start LOOP waiting for some jobs
t_tp_thread *tp_create(size_t num)
{
  t_tp_thread *pool;

  pool = NULL;
  if (!(pool= malloc(sizeof(t_tp_thread))))
  {
    ft_putendl("Failed malloc while creating a thread pool");
    return NULL;
  }
  if (!(pool->threads = malloc(sizeof(pthread_t))))
  {
    free(pool);
    ft_putendl("Failed malloc while creating a thread pool");
    return NULL;
  }
  pool->threads_max = num;
  pool->jobs = NULL;
  pool->threads_working = 0;
  pool->jobs_amount = 0;
  return (pool);
}
void tp_queue_added(t_tp_thread *tp)
{
  t_job *job;

  pthread_create(tp->threads, NULL, tp->jobs->task, tp->jobs->arg);
  job = tp->jobs;
  tp->jobs = tp->jobs->next;
  job->next = NULL;
  free(job);
}
//TODO: send signal to LOOP that is wating
void tp_add_task(t_tp_thread *tp,void (*fun)(void *arg),void *arg)
{
  t_job *job;

  if (!tp || !fun)
    return ;
  job = tp->jobs;
  if (tp->jobs)
  {
    while (tp->jobs->next)
      tp->jobs = tp->jobs->next;
     if (!(tp->jobs->next = j_create(fun, arg, tp->jobs_amount++)))
      return ;
    tp->jobs = job;
  }
  else
    tp->jobs = j_create(fun, arg, tp->jobs_amount++);
  tp_queue_added(tp);
}
void fun(void *c)
{
  ft_putstr((char*)c);
}
int main(void)
{
t_tp_thread *pool;
pool = tp_create(1);
while (1)
{
  tp_add_task(pool, &fun, (void*)"111111111111");
  tp_add_task(pool, &fun, (void*)"222222222222");
  tp_add_task(pool, &fun, (void*)"333333333333");
   tp_add_task(pool, &fun, (void*)"111111111111");
  tp_add_task(pool, &fun, (void*)"222222222222");
  tp_add_task(pool, &fun, (void*)"333333333333");
}


sleep(1000);
  return 0;
}
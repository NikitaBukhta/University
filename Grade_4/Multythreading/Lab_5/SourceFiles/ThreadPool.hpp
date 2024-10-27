#ifndef __LAB_5_MULTYTHREADING_THREADPOOL_HPP
#define __LAB_5_MULTYTHREADING_THREADPOOL_HPP

#include <functional>
#include <future>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
public:
  ThreadPool(std::size_t threads);
  ~ThreadPool();

  template <class F> void enqueue(F &&f);

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;

  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;

  void worker_thread();
};

#endif // __LAB_5_MULTYTHREADING_THREADPOOL_HPP
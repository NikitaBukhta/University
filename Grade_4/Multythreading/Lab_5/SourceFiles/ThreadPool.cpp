#include "ThreadPool.hpp"

ThreadPool::ThreadPool(std::size_t threads) : stop(false) {
  for (std::size_t i = 0; i < threads; ++i) {
    workers.emplace_back(&ThreadPool::worker_thread, this);
  }
}

ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    stop = true;
  }
  condition.notify_all();
  for (std::thread &worker : workers) {
    worker.join();
  }
}

void ThreadPool::worker_thread() {
  while (true) {
    std::function<void()> task;

    {
      std::unique_lock<std::mutex> lock(queue_mutex);
      condition.wait(lock, [this] { return stop || !tasks.empty(); });
      if (stop && tasks.empty())
        return;
      task = std::move(tasks.front());
      tasks.pop();
    }

    task();
  }
}

template <class F> void ThreadPool::enqueue(F &&f) {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    tasks.emplace(std::forward<F>(f));
  }
  condition.notify_one();
}
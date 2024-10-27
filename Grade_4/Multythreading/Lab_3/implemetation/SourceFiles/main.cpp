#include "Student.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <random>
#include <thread>

template <typename Arr> void parallelSorting(Arr &array) {
  auto threadsCount = std::thread::hardware_concurrency();
  auto arrSize = array.size();
  auto chunkSize = arrSize / threadsCount;
  auto arrBegin = std::begin(array);

  std::queue<std::thread> threads;

  for (std::int32_t i{0}; i < threadsCount; ++i) {
    auto start = i * chunkSize;
    auto end = i == threadsCount - 1 ? arrSize : start + chunkSize;

    threads.emplace(std::thread([&arrBegin, start, end]() {
      std::sort(arrBegin + start, arrBegin + end);
    }));
  }

  // std::sort(arrBegin, arrBegin + arrSize);

  for (std::int32_t i{0}; i < threadsCount; ++i) {
    threads.front().join();
    threads.pop();
  }

  std::int32_t step = chunkSize;
  while (step < arrSize) {
    for (std::int32_t i = 0; i < arrSize - step; i += 2 * step) {
      std::int32_t left = i;
      std::int32_t mid = i + step;
      std::int32_t right = std::min<std::int32_t>(i + 2 * step, arrSize);

      std::inplace_merge(array.begin() + left, array.begin() + mid,
                         array.begin() + right);
    }
    step *= 2;
  }
}

template <typename Arr> void commonSorting(Arr &array) {
  std::sort(std::begin(array), std::end(array));
}

template <typename Arr, typename SortFunction>
void sortTest(Arr &array, SortFunction sortMethod) {
  auto start = std::chrono::steady_clock::now();
  sortMethod(array);
  auto end = std::chrono::steady_clock::now();

  std::cout << "Время выполнения: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << " миллисекунд" << std::endl;

  if (std::is_sorted(std::begin(array), std::end(array)))
    std::cout << "Массив отсортирован";
  else
    std::cout << "Не отсортирован массив";
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  for (size_t i = 1; i <= 10; ++i) {
    size_t sizeVector = i * (size_t)1e7;
    std::vector<Student> arr(sizeVector);
    std::for_each(std::begin(arr), std::end(arr),
                  [i = 0.01](Student &elem) mutable {
                    elem.setAvarageGrade(i);
                    i += 0.01;
                  });

    std::mt19937_64 urng{121216};
    std::shuffle(arr.begin(), arr.end(), urng);

    std::cout << "Количество элементов: " << sizeVector << std::endl;

    std::cout << "Сортировка с параллельными вычислениями:" << std::endl;
    sortTest(arr, parallelSorting<std::vector<Student>>);

    std::shuffle(arr.begin(), arr.end(), urng);
    std::cout << "Сортировка в одном потоке:" << std::endl;
    sortTest(arr, commonSorting<std::vector<Student>>);

    std::cout << std::endl;
  }

  return 0;
}

#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

// Оператор A: A = Σ(α * x_i)
double operationA(double x, double alpha) { return alpha * x; }

// Оператор B: B = (x_i / α)
double operationB(double x, double alpha) { return x / alpha; }

double parallelReduce(std::vector<double> &startPoints,
                      std::function<double(double, double)> combine) {
  auto actualResListSize = startPoints.size();
  while (actualResListSize > 1) {
    std::vector<std::future<double>> tmpResList;

    for (std::int32_t i = 0; i < actualResListSize; i += 2) {
      tmpResList.emplace_back(std::async(
          std::launch::async,
          [&startPoints, i, actualResListSize, &combine]() -> double {
            return i + 1 == actualResListSize
                       ? startPoints[i]
                       : combine(startPoints[i], startPoints[i + 1]);
          }));
    }

    startPoints.clear();
    for (auto &res : tmpResList) {
      startPoints.emplace_back(res.get());
    }

    actualResListSize = startPoints.size();
  }

  return startPoints.empty() ? 0 : startPoints[0];
}

double computeOperation(std::vector<double> &startPoints, double alpha,
                        std::function<double(double, double)> combine,
                        std::function<double(double, double)> operation) {
  std::vector<double> actualResList;
  actualResList.reserve(startPoints.size());
  for (auto x : startPoints) {
    actualResList.emplace_back(operation(x, alpha));
  }

  return parallelReduce(actualResList, combine);
}

void paracomputerProccess() {
  double alpha = 2.0;
  std::vector<double> x = {1.0, 2.0, 3.0, 4.0};

  auto resultA = computeOperation(x, alpha, std::plus<>(), operationA);
  auto resultB = computeOperation(x, alpha, std::multiplies<>(), operationB);
  auto finalResult = resultA - resultB;

  std::cout << "Result of A: " << resultA << std::endl;
  std::cout << "Result of B: " << resultB << std::endl;
  std::cout << "Result of A - B: " << finalResult << std::endl;
}

int main() {
  paracomputerProccess();

  return 0;
}

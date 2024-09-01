#include "Task4.hpp"

#include <QDebug>
#include <QElapsedTimer>
#include <QVector>
#include <QThreadPool>
#include <QMutex>
#include <QMutexLocker>

namespace Tasks {

QMutex mutex;  // Глобальный мьютекс для синхронизации доступа к матрице C

void Task4::run() {
    qDebug() << __PRETTY_FUNCTION__ << "called";

    int size = 1000;
    int num_threads = 4;

    QVector<QVector<int>> A(size, QVector<int>(size, 1));  // Матрица A
    QVector<QVector<int>> B(size, QVector<int>(size, 2));  // Матрица B
    Result C(size, size);

    QElapsedTimer timer;
    timer.start();

    auto multiply_block = [&A, &B, &C, size](int start_row, int end_row) {
        qDebug() << "Thread started for rows" << start_row << "to" << end_row;
        for (int i = start_row; i < end_row; ++i) {
            for (int j = 0; j < size; ++j) {
                int sum = 0;
                for (int k = 0; k < size; ++k) {
                    sum += A[i][k] * B[k][j];
                }
                // Использование мьютекса для защиты доступа к матрице C
                QMutexLocker locker(&mutex);
                C.set_value(i, j, sum);
            }
        }
        qDebug() << "Thread finished for rows" << start_row << "to" << end_row;
    };

    int rows_per_thread = size / num_threads;
    QThreadPool pool;
    pool.setMaxThreadCount(num_threads);

    for (int t = 0; t < num_threads; ++t) {
        int start_row = t * rows_per_thread;
        int end_row = (t == num_threads - 1) ? size : start_row + rows_per_thread;
        pool.start([&multiply_block, start_row, end_row](){ multiply_block(start_row, end_row); });
    }

    pool.waitForDone();

    qint64 elapsed = timer.elapsed();
    qDebug() << "Time elapsed with" << num_threads << "threads:" << elapsed << "ms";
}

Result::Result(int rows, int cols) {
    _matrix.resize(rows);
    for (auto& row : _matrix) {
        row.resize(cols, 0);
    }
}
Result::~Result() {
    _matrix.clear();
}

void Result::set_value(int row, int col, int value) {
    _matrix[row][col] = value;
}

int Result::get_value(int row, int col) const {
    return _matrix[row][col];
}

} // namespace Tasks

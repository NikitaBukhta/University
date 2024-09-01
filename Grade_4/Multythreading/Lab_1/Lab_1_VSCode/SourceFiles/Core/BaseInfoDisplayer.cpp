#include "BaseInfoDisplayer.hpp"

#include <QDebug>
#include <QThread>

#include <iostream>

namespace Core {

BaseInfoDisplayer::BaseInfoDisplayer()
: _msg{"Лабораторна робота №1\nЗ дисципліни Технології Розподілених Систем та Паралельних Обчислень\nСтудента групи ІПЗ-4.04\nБухти Микити"}
{

}

void BaseInfoDisplayer::run() {
    for (qint64 i{0}; i < _msg.size(); ++i) {
        std::wcout << static_cast<wchar_t>(_msg[i].unicode()) << std::flush;
        QThread::msleep(50);
    }
    std::wcout << std::endl;
}

} // Core
#include "Task1.hpp"

#include <QDebug>
#include <QThread>

#include <string>
#include <iostream>

namespace Tasks {

void Task1::run() {
    qDebug() << __PRETTY_FUNCTION__ << "called";
    std::wstringstream str{L"We have the Java learning course!"};
    std::wstring word;

    while(std::getline(str, word, L' ')) {
        std::wcout << word << L' ' << std::flush;
        QThread::msleep(1000);
    }
    std::wcout << std::endl;
}

} // Tasks

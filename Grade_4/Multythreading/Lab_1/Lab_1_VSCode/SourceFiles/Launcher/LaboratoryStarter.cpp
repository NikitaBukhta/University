#include "LaboratoryStarter.hpp"

#include "Core/BaseInfoDisplayer.hpp"

#include "Tasks/Task1.hpp"
#include "Tasks/Task2.hpp"
#include "Tasks/Task3.hpp"
#include "Tasks/Task4.hpp"

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

namespace Launcher {

Starter::Starter(int argc, char *argv[], QObject* parent) 
: Core::Starter(argc, argv, parent) {
    _pool = QThreadPool::globalInstance();
    _pool->setMaxThreadCount(1);
}

int Starter::executeApp() {
    _pool->start(new Core::BaseInfoDisplayer());
    _pool->start(new Tasks::Task1);
    _pool->start(new Tasks::Task2);
    _pool->start(new Tasks::Task3);
    _pool->start(new Tasks::Task4);

    _pool->waitForDone();

    QTimer::singleShot(10, [this]() {
        emit this->finish();
    });

    return Core::Starter::executeApp();
}

} // Launcher
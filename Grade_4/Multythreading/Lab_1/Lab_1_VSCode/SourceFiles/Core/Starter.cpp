#include "Starter.hpp"
#include "Launcher/LaboratoryStarter.hpp"

namespace Core {

QSharedPointer<Starter> Starter::create(int argc, char *argv[], QObject* parent) {
    static QSharedPointer<Starter> instance(new Launcher::Starter(argc, argv, parent));

    return instance;
}

int Starter::main() {
    int ret = executeApp();

    return ret;
}

int Starter::executeApp() {    
    return _qt_app.exec();
}

Starter::Starter(int argc, char *argv[], QObject* parent)
: QObject{parent}
, _argc{argc}
, _argv{argv}
, _qt_app{argc, argv} {
    init_connections();
}

void Starter::init_connections() {
    connect(this, &Starter::finish, &_qt_app, &QCoreApplication::quit);
}

} // namespace Core
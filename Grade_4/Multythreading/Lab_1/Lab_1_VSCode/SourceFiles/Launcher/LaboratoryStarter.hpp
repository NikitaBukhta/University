#ifndef __LAB1_LAUNCHER_LABORATORYSTARTER_HPP__
#define __LAB1_LAUNCHER_LABORATORYSTARTER_HPP__

#include "Core/Starter.hpp"

#include <QThreadPool>

namespace Launcher {

class Starter final : public Core::Starter {
public:
    Starter(int argc, char *argv[], QObject* parent = nullptr);
    Q_DISABLE_COPY(Starter);

private:
    int executeApp() override;

private:
    QThreadPool* _pool;
};

} // Launcher

#endif // __LAB1_LAUNCHER_LABORATORYSTARTER_HPP__
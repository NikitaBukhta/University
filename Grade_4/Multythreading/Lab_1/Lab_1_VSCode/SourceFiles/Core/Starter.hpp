#ifndef __LAB1_SOURCEFILES_CORE_STARTER_HPP__
#define __LAB1_SOURCEFILES_CORE_STARTER_HPP__

#include <QObject>
#include <QSharedPointer>
#include <QAtomicPointer>
#include <QCoreApplication>

namespace Core {
    
class Starter : public QObject {
    Q_OBJECT

public:
    static QSharedPointer<Starter> create(int argc, char *argv[], QObject* parent = nullptr);

    int main();

protected:
    virtual int executeApp();

protected:
    Starter() = delete;
    Starter(int argc, char *argv[], QObject* parent = nullptr);
    Q_DISABLE_COPY(Starter);

    void init_connections();

protected:
    QCoreApplication _qt_app;

signals:
    void finish();

private:
    int _argc;
    char ** _argv;
};

} // namespace Core

#endif // __LAB1_SOURCEFILES_CORE_STARTER_HPP__
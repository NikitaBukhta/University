#ifndef __LAB1_SOURCEFILES_CORE_BASEINFODISPLAYER_HPP__
#define __LAB1_SOURCEFILES_CORE_BASEINFODISPLAYER_HPP__

#include <QRunnable>
#include <QString>

namespace Core {

class BaseInfoDisplayer : public QRunnable {
public:
    BaseInfoDisplayer(void);

    void run() override;

private:
    QString _msg;
};

} // Core

#endif // __LAB1_SOURCEFILES_CORE_BASEINFODISPLAYER_HPP__
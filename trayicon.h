#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QFont>

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    static TrayIcon *factory();
private:
    static TrayIcon *tray;
    explicit TrayIcon(QObject *parent = 0);
    QFont font;

signals:
    void quit();
public slots:
    void onActivation(QSystemTrayIcon::ActivationReason reason);

};

#endif // TRAYICON_H

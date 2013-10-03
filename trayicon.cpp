#include "trayicon.h"
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QPen>

TrayIcon *TrayIcon::tray = 0;
TrayIcon * TrayIcon::factory()
{
    if (!tray){
        tray = new TrayIcon();
        tray->connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),tray,SLOT(onActivation(QSystemTrayIcon::ActivationReason)));
    }
    return tray;
}

void TrayIcon::onActivation(QSystemTrayIcon::ActivationReason reason)
{
    emit quit();
}

TrayIcon::TrayIcon(QObject *parent) :
    QSystemTrayIcon(parent), font("",20)
{
    if (QSystemTrayIcon::isSystemTrayAvailable()){
        QPixmap pixmap(64,64);
        pixmap.fill(Qt::darkGreen);
        QPainter painter(&pixmap);
        QString string = "SOG";
        painter.setFont(font);
        painter.setPen(QPen(Qt::red));
        painter.drawText(pixmap.rect(),Qt::AlignHCenter | Qt::AlignVCenter, string);
        setIcon(pixmap);
        show();
    }
}

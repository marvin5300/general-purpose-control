
#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <ui_measurementdevice.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>
#include <CSynchcommConsumer.h>

int main(int argc, char *argv[])
{
    // thread
    QThread consumer;
    QThread producer;

    // application
    QApplication a(argc, argv);

    // translator
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "MeasurementControl_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // create and show mainwindow
    MainWindow w(&consumer, &producer);

    w.show();

    return a.exec();

}

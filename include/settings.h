#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Settings;
}

/**
* Dialog to change settings like output file and port name filter.
*/
class Settings : public QDialog
{
    Q_OBJECT

signals:
    // only emit signals if save or apply button is clicked
    void setOutputFileName(QString fileName);
    void setSerialMask(QStringList masks);

public:
    explicit Settings(QWidget *parent = nullptr, QString filePath = "", QStringList masks = {},
                      Qt::WindowFlags flags = Qt::WindowCloseButtonHint | Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
    ~Settings();

private slots:
    void applySettings();
    void enableApplyButton();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H

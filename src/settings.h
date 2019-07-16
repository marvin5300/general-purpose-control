#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

signals:
    // only emit signals if save or apply button is clicked
    void setOutputFileName(QString fileName);

public:
    explicit Settings(QWidget *parent = nullptr, QString filePath = "",
                      Qt::WindowFlags flags = Qt::WindowCloseButtonHint | Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
    ~Settings();

private slots:
    void applySettings();
    void enableApplyButton();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H

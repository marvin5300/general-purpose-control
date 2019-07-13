#ifndef SETVALUE_H
#define SETVALUE_H

#include <QFrame>

namespace Ui {
class SetValue;
}

class SetValue : public QFrame
{
    Q_OBJECT

public:
    explicit SetValue(QWidget *parent = nullptr);
    ~SetValue();

private:
    Ui::SetValue *ui;
};

#endif // SETVALUE_H

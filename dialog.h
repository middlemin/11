#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

class Dialog : public QMainWindow
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // DIALOG_H
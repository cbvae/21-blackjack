#ifndef TABLE_H
#define TABLE_H

#include <QLabel>
#include <QSpinBox>
#include "deck.h"

class QWidget;

class Table:public QWidget
{
    Q_OBJECT
public:
    Table(QWidget *parent = 0);

    QSpinBox *num;
    QSpinBox *p;
    QSpinBox *d;

    void setbei();
    int getNum();

    QLabel *last;

    QLabel *labelD1;
    QLabel *labelD2;
    QLabel *labelD3;
    QLabel *labelD4;
    QLabel *labelD5;

    QLabel *labelP1;
    QLabel *labelP2;
    QLabel *labelP3;
    QLabel *labelP4;
    QLabel *labelP5;

private:
    QLabel *cl;
    QLabel *labelD;
    QLabel *labelP;
};

#endif // TABLE_H

#include <QtGui>
#include <QPixmap>
#include "table.h"
#include "deck.h"

Table::Table(QWidget* parent)
    : QWidget(parent)
{
    num=new QSpinBox;
    num->setEnabled(false);
    num->setRange(0, 52);
    num->setAlignment(Qt::AlignHCenter);

    p=new QSpinBox;
    p->setEnabled(false);

    d=new QSpinBox;
    d->setEnabled(false);

    QFont fc;
    fc.setPointSize(15);

    QFont ft;
    ft.setPointSize(20);

    cl = new QLabel("Cards left:");
    cl->setAlignment(Qt::AlignHCenter);
    cl->setFont(fc);

    last = new QLabel("Points:     0  :  0");
    last->setAlignment(Qt::AlignHCenter);
    last->setFont(fc);

    labelD = new QLabel("Dealer:");
    labelD->setAlignment(Qt::AlignHCenter);
    labelD->setFont(ft);

    labelP = new QLabel("Player:");
    labelP->setAlignment(Qt::AlignHCenter);
    labelP->setFont(ft);


    labelD1 = new QLabel;
    labelD1->setAlignment(Qt::AlignHCenter);

    labelD2 = new QLabel;
    labelD2->setAlignment(Qt::AlignHCenter);

    labelD3 = new QLabel;
    labelD4 = new QLabel;
    labelD5 = new QLabel;

    labelP1 = new QLabel;
    labelP1->setPixmap(QPixmap(":/images/bei.png"));
    labelP1->setAlignment(Qt::AlignHCenter);

    labelP2 = new QLabel;
    labelP2->setPixmap(QPixmap(":/images/bei.png"));
    labelP2->setAlignment(Qt::AlignHCenter);

    labelP3 = new QLabel;
    labelP4 = new QLabel;
    labelP5 = new QLabel;

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addStretch();
    topLayout->addWidget(cl);
    topLayout->addWidget(num);
    topLayout->addStretch();
    topLayout->addWidget(last);
    topLayout->addStretch();

    QHBoxLayout *lefttopLayout = new QHBoxLayout;
    lefttopLayout->addWidget(labelD);
    lefttopLayout->addWidget(d);
    lefttopLayout->addStretch();


    QHBoxLayout *leftMiddleLayout = new QHBoxLayout;
    leftMiddleLayout->addWidget(labelD1);
    leftMiddleLayout->addWidget(labelD2);

    QHBoxLayout *leftbottomLayout = new QHBoxLayout;
    leftbottomLayout->addWidget(labelD3);
    leftbottomLayout->addWidget(labelD4);
    leftbottomLayout->addWidget(labelD5);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(lefttopLayout);
    leftLayout->addLayout(leftMiddleLayout);
    leftLayout->addLayout(leftbottomLayout);

    QHBoxLayout *righttopLayout = new QHBoxLayout;
    righttopLayout->addWidget(labelP);
    righttopLayout->addWidget(p);
    righttopLayout->addStretch();

    QHBoxLayout *rightMiddleLayout = new QHBoxLayout;
    rightMiddleLayout->addWidget(labelP1);
    rightMiddleLayout->addWidget(labelP2);

    QHBoxLayout *rightbottomLayout = new QHBoxLayout;
    rightbottomLayout->addWidget(labelP3);
    rightbottomLayout->addWidget(labelP4);
    rightbottomLayout->addWidget(labelP5);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addLayout(righttopLayout);
    rightLayout->addLayout(rightMiddleLayout);labelD2->setPixmap(QPixmap(":/images/bei.png"));
    rightLayout->addLayout(rightbottomLayout);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addLayout(leftLayout);
    bottomLayout->addLayout(rightLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);    
}

void Table::setbei()
{
    labelD1->setPixmap(QPixmap(QString(":/images/%1.png").arg(QString("bei"))));
    labelD2->setPixmap(QPixmap(":/images/bei.png"));
    labelD3->setPixmap(QPixmap(":/images/bei.png"));
    labelD4->setPixmap(QPixmap(":/images/bei.png"));
    labelD5->setPixmap(QPixmap(":/images/bei.png"));
    labelP3->setPixmap(QPixmap(":/images/bei.png"));
    labelP4->setPixmap(QPixmap(":/images/bei.png"));
    labelP5->setPixmap(QPixmap(":/images/bei.png"));
}





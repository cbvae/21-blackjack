#include <QtGui>
#include "mainwindow.h"
#include "table.h"
#include "deck.h"

MainWindow::MainWindow()
{
    setWindowTitle("Welcome To BlackJack");

    table = new Table;
    table->num->setValue(52);
    table->setbei();

    setCentralWidget(table);
    createActions();
    createMenus();
    createToolBars();
    setFixedSize(QWidget::sizeHint());

//    sleep(3);
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New Game"), this);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newGame()));

    dealHandAction = new QAction(tr("&Deal Hand"), this);
    dealHandAction->setEnabled(false);
    connect(dealHandAction, SIGNAL(triggered()), this, SLOT(dealHand()));

    shuffleDeckAction = new QAction(tr("&Shuffle Deck"), this);
    shuffleDeckAction->setEnabled(false);
    connect(shuffleDeckAction, SIGNAL(triggered()), this, SLOT(shuffleDeck()));

    hitAction = new QAction(tr("&Hit"), this);
    hitAction->setEnabled(false);
    connect(hitAction, SIGNAL(triggered()), this, SLOT(hit()));

    stayAction = new QAction(tr("&Stand"), this);
    stayAction->setEnabled(false);
    connect(stayAction, SIGNAL(triggered()), this, SLOT(stay()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    aboutAction = new QAction(tr("&About"),this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(newAction);
    gameMenu->addAction(quitAction);

    controlMenu = menuBar()->addMenu(tr("&Control"));
    controlMenu->addAction(dealHandAction);
    controlMenu->addAction(shuffleDeckAction);
    controlMenu->addAction(hitAction);
    controlMenu->addAction(stayAction);

    aboutMenu = menuBar()->addMenu(tr("About"));
    aboutMenu->addAction(aboutAction);
}

void MainWindow::createToolBars()
{
    control = new QToolBar("&Play", this);
    control->addAction(newAction);
    control->addAction(dealHandAction);
    control->addAction(shuffleDeckAction);
    control->addAction(hitAction);
    control->addAction(stayAction);
    control->addAction(quitAction);

    QMainWindow::addToolBar(Qt::RightToolBarArea, control);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinue()){
        event->accept();
    }else{
        event->ignore();
    }
}

bool MainWindow::okToContinue()
{
    int r = QMessageBox::warning(this, tr("Black Jack"),
                                 tr("The current game will be closed.\n"
                                    "Do you want to continue:"),
                                 QMessageBox::No | QMessageBox::Yes);
    if(r == QMessageBox::Yes){
        return true;
    } else{
        return false;
    }
}

void MainWindow::newGame()
{
    if(okToContinue())
    {
        deck = new Deck;
        table = new Table;
//        deck->pl[0] = QString::fromStdString(deck->getTop());
        table->setbei();
        repoke();
        table->num->setValue(48);;
        setCentralWidget(table);

        pwin=dwin=player=dealer=0;
        dnum=pnum=3;
//        table->last->setText(QString("Points:   %1  :  %2").arg(QString::number(dealerPlay()))
//                             .arg(QString::number(calculatePoint())));

        hitAction->setEnabled(true);
        shuffleDeckAction->setEnabled(true);
        stayAction->setEnabled(true);
    }
}

void MainWindow::dealHand()
{
    dealHandAction->setEnabled(false);
    shuffleDeckAction->setEnabled(true);
    hitAction->setEnabled(true);
    stayAction->setEnabled(true);

    deck=new Deck;
    table->setbei();
    repoke();
}

void MainWindow::shuffleDeck()
{
    int m;
    m=deck->updateImage();
    deck->shuffle(m);

    shuffleDeckAction->setEnabled(false);
}

void MainWindow::hit()
{
    shuffleDeckAction->setEnabled(true);

//    if(deck->stk.empty())
//        shuffleDeck();
    string str =deck->getTop();
    deck->pl[pnum-1]=QString::fromStdString(str);
    deck->stk.pop();
    table->num->setValue(deck->calculateStack());
    switch (pnum) {
    case 3:
        table->labelP3->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->pl[2])+".png"));        
        pnum++;
        break;
    case 4:
        table->labelP4->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->pl[3])+".png"));       
        pnum++;
        break;
    case 5:
        table->labelP5->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->pl[4])+".png"));        
        pnum++;
        break;
    }
//    table->last->setText(QString("Points:   %1  :  %2").arg(QString::number(pnum))
//                         .arg(QString::number(calculatePoint())));
    if(calculatePoint()>21)
        playerLose();
}

void MainWindow::stay()
{
    stayAction->setEnabled(false);

    player=calculatePoint();
    dealer=dealerPlay();
    if(dealer<=21 && dealer>player){
        playerLose();
    }else{
        playerWin();
    }
}

void MainWindow::repoke()
{
    deck->reDeliver();
    table->num->setValue(deck->calculateStack());
    table->labelP1->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->pl[0])+".png"));
//    table->labelP1->setText(deck->pl[0]);
    table->labelP2->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->pl[1])+".png"));
//    table->getPics();
}

int MainWindow::dealerPlay()
{
    while(calculateDealer()<=18)
    {
        string str =deck->getTop();
        deck->dl[dnum-1]=QString::fromStdString(str);
        deck->stk.pop();
        table->num->setValue(deck->calculateStack());
        switch (dnum) {
        case 3:
            table->labelD3->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->dl[2])+".png"));
            dnum++;
            break;
        case 4:
            table->labelD4->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->dl[3])+".png"));
            dnum++;
            break;
        case 5:
            table->labelD5->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->dl[4])+".png"));
            dnum++;
            break;
        }
    }
    table->labelD1->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->dl[0])+".png"));
    table->labelD2->setPixmap(QPixmap(":/images/"+QString("%1").arg(deck->dl[1])+".png"));

    return calculateDealer();
}

int MainWindow::calculatePoint()
{
    int mark=0;
    int cal=0;
    for(int p=0; p<pnum-1; p++)
    {
        char ch = deck->pl[p][1].unicode();
        if(ch=='1')
        {
            mark++;
        }else{
            cal=cal+getValue(ch);
        }
    }
    if (mark>0)
    {
        if((cal+10+mark)<=21){
            return cal+10+mark;
        }else{
            return cal+mark;
        }
    }else{
        return cal;
    }
}

int MainWindow::calculateDealer()
{
    int mark=0;
    int cal=0;
    for(int p=0; p<dnum-1; p++)
    {
        char ch = deck->dl[p][1].unicode();
        if(ch=='1')
        {
            mark++;
        }else{
            cal=cal+getValue(ch);
        }
    }
    if (mark>0)
    {
        if((cal+10+mark)<=21 || (cal+10+mark)>18){
            return cal+10+mark;
        }else{
            return cal+mark;
        }
    }else{
        return cal;
    }
}

int MainWindow::getValue(char a)
{
    switch (a) {
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 10;
    }
}

void MainWindow::playerWin()
{
    dealHandAction->setEnabled(true);
    shuffleDeckAction->setEnabled(false);
    hitAction->setEnabled(false);
    stayAction->setEnabled(false);

    pwin++;
    table->p->setValue(pwin);
    if(pnum<6){
        if(dealer>21){
            table->last->setText(QString("Points:   Bust!  :  %1")
                         .arg(QString::number(calculatePoint())));
        }else{
            table->last->setText(QString("Points:   %1  :  %2").arg(QString::number(dealerPlay()))
                                     .arg(QString::number(calculatePoint())));
        }
    }
    if(pnum==6 || player==21){
    table->last->setText(QString("Points:   Perfectly win!!!"));
    }

    pnum=3;
    dnum=3;
    QMessageBox::warning(this, tr("Win"),
                         tr("You beat the dealer!!"),
                         QMessageBox::Ok);
}

void MainWindow::playerLose()
{
    dealHandAction->setEnabled(true);
    shuffleDeckAction->setEnabled(false);
    hitAction->setEnabled(false);
    stayAction->setEnabled(false);

    dwin++;
    table->d->setValue(dwin);
    if(calculatePoint()>21){
        table->last->setText(QString("Points:   Bust!!!"));
    }else{
        table->last->setText(QString("Points:   %1  :  %2").arg(QString::number(dealerPlay()))
                                 .arg(QString::number(calculatePoint())));
    }

    pnum=3;
    dnum=3;
    QMessageBox::warning(this, tr("Lose"),
                         tr("You Lose!!"),
                         QMessageBox::Ok);
}

void MainWindow::about()
{
    QMessageBox message(QMessageBox::NoIcon, "About", "Blackjack--ChenBo");
    message.setIconPixmap(QPixmap(":/images/splash.png"));
    message.exec();
}

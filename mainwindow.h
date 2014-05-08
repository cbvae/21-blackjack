#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table.h"
#include "deck.h"

class QAction;
class QLabel;
class Table;
class Deck;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

    QString hitme;
    QString ex;

protected:
void closeEvent(QCloseEvent *);

private slots:
void newGame();
void dealHand();
void shuffleDeck();
void hit();
void stay();
void about();

void repoke();

private:
void createActions();
void createMenus();
void createToolBars();
bool okToContinue();

int calculatePoint();
int calculateDealer();
int dealerPlay();
int getValue(char a);
void playerWin();
void playerLose();

int dealer;
int player;

int pnum;
int dnum;
int pwin;
int dwin;

Table *table;
Deck *deck;

QMenu *gameMenu;
QMenu *controlMenu;
QMenu *aboutMenu;

QToolBar *control;

QAction *newAction;
QAction *dealHandAction;
QAction *shuffleDeckAction;
QAction *hitAction;
QAction *stayAction;
QAction *quitAction;
QAction *aboutAction;

};

#endif // MAINWINDOW_H

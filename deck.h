#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <QStringList>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Deck : public QObject
{

public:
    Deck(QObject* parent=0);

    int calculateStack();

    void del(int p, int q);
    void delStack();
    void reDeliver();
    string getTop();

    void shuffle(int n);
    int updateImage();

    int _num;
    QString image[52];
    QString dl[5];
    QString pl[5];

    string poke[52];
    stack<string> stk;

private:
    QString values;
    QString suits;
    QString card;


};



#endif // DECK_H

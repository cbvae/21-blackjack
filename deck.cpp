#include "deck.h"
#include <QStringList>
#include <string>
#include <ctime>
#include <stdlib.h>

Deck::Deck(QObject* parent) :QObject(parent)
 {
    values="123456789tjqk";
    suits="htmf";
    int i=0;

    foreach(QChar suit, suits){
        foreach(QChar value, values){
            QString card = QString("%1%2").arg(suit).arg(value);
            image[i] = card;
            i++;
        }
    }

    if(!stk.empty())
        delStack();

    shuffle(52);

}

int Deck::calculateStack()
{
    return stk.size();
}

void Deck::delStack()
{
    while(1)
    {
        if(!stk.empty()){
                stk.pop();
        }else{
            break;
        }
    }
}

void Deck::shuffle(int n)
{
    for(int m=n-1; m>-1; m--)
    {
        if(m>0)
        {
            int ran;
            srand(unsigned(time(0)));

            ran= rand()%(m+1);
            stk.push(image[ran].toStdString());
            del(ran, m);
        }else{
            stk.push(image[0].toStdString());
            image[0]="";
        }
    }
}

int Deck::updateImage()
{
    int m=0;
    while(!stk.empty())
    {
        image[m] = QString::fromStdString(Deck::getTop());
        stk.pop();
        m++;
    }
    return m;
}

string Deck::getTop()
{
    return stk.top();
}

void Deck::reDeliver()
{
    dl[0] = QString::fromStdString(Deck::getTop());
    stk.pop();
    dl[1] = QString::fromStdString(Deck::getTop());
    stk.pop();
    pl[0] = QString::fromStdString(Deck::getTop());
    stk.pop();
    pl[1] = QString::fromStdString(Deck::getTop());
    stk.pop();
}


void Deck::del(int p, int q)
{
    for(int j=p; j<q; j++)
    {
        image[j]=image[j+1];
    }
    image[q]="";
}

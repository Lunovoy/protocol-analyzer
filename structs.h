
#include <iostream>
#include <QString>
#include <QFile>
#ifndef STRUCTS_H
#define STRUCTS_H


struct Fname {

    QString name;
    FILE *capfile;
};


extern struct Fname *cap;



#endif // STRUCTS_H




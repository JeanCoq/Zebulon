/* 
 * File:   ClassPeriod.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:30
 */

#ifndef CLASSPERIOD_H
#define	CLASSPERIOD_H
#include <string>
#include "Group.h"
#include <list>

using namespace std;

class ClassPeriod {
public:
    ClassPeriod();
    ClassPeriod(const ClassPeriod& orig);
    virtual ~ClassPeriod();
private:
    string teacher;
    list<Group> groupList;
};

#endif	/* CLASSPERIOD_H */


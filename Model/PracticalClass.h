/* 
 * File:   PracticalClass.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef PRACTICALCLASS_H
#define	PRACTICALCLASS_H
#include "ClassPeriod.h"

class PracticalClass : public ClassPeriod {
public:
    PracticalClass(string teacher, int duration, Module* mod);
    PracticalClass(const ClassPeriod* orig);
    virtual ~PracticalClass();
private:
};

#endif	/* PRACTICALCLASS_H */


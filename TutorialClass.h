/* 
 * File:   TutorialClass.h
 * Author: E110091P
 *
 * Created on 7 février 2012, 15:31
 */

#ifndef TUTORIALCLASS_H
#define	TUTORIALCLASS_H
#include "ClassPeriod.h"
class TutorialClass  : public ClassPeriod{
public:
    TutorialClass();
    TutorialClass(const TutorialClass& orig);
    virtual ~TutorialClass();
private:

};

#endif	/* TUTORIALCLASS_H */


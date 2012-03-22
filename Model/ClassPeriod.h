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
#include "Module.h"
#include <list>

using namespace std;
class Module;
class ClassPeriod {
public:
    ClassPeriod(int id, string teacher, int duration, Module* mod);
    ClassPeriod(const ClassPeriod& orig);
    virtual ~ClassPeriod();

    int GetDuration() const {
        return duration;
    }

    void SetDuration(int duration) {
        this->duration = duration;
    }

    list<Group*>* GetGroupList() const {
        return groupList;
    }

    void SetGroupList(list<Group*>* groupList) {
        this->groupList = groupList;
    }

    int GetId() const {
        return id;
    }

    void SetId(int id) {
        this->id = id;
    }

    string GetTeacher() const {
        return teacher;
    }

    void SetTeacher(string teacher) {
        this->teacher = teacher;
    }

    Module* GetMomo() const {
        return momo;
    }

    void SetMomo(Module* momo) {
        this->momo = momo;
    }



private:
    int id;
    string teacher;
    int duration;
    list<Group*> *groupList;
    Module *momo;
};

#endif	/* CLASSPERIOD_H */


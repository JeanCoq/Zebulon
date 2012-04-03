/*
 * File:   WindowAdministrator.cpp
 * Author: E110091P
 *
 * Created on 29 mars 2012, 12:32
 */

#include "WindowAdministrator.h"

WindowAdministrator::WindowAdministrator(Controller* ctrl, MainWindow* mainwindow) {
    load = false;
    groupClassPeriodModified = false;
    widget.setupUi(this);
    this->ctrl = ctrl;
    this->m = mainwindow;
    this->setModal(true);
    this->setWindowIcon(QIcon("./zebulon.png"));
    
    this->widget.tableWidgetModules->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetModules->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassPeriod->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetClassrooms->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetClassrooms->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ; 
    this->widget.tableWidgetStudents->horizontalHeader()->setVisible(true);
    this->widget.tableWidgetStudents->horizontalHeader()->setResizeMode ( QHeaderView::Stretch) ;
    
    oldIdSelectedModule = "";
    refreshModule(1);
    refreshClassroom(1);
    currentModule = NULL;
    
    QObject::connect(widget.buttonAddModule, SIGNAL(clicked()), this, SLOT(addModule()));
    QObject::connect(widget.buttonEditModule, SIGNAL(clicked()), this, SLOT(editModule()));
    QObject::connect(widget.buttonDeleteModule, SIGNAL(clicked()), this, SLOT(deleteModule()));
    QObject::connect(widget.buttonOkEditModule, SIGNAL(clicked()), this, SLOT(okEditModule()));
    QObject::connect(widget.buttonCancelEditModule, SIGNAL(clicked()), this, SLOT(cancelEditModule()));
    QObject::connect(widget.tableWidgetModules, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(moduleClicked()));
    QObject::connect(widget.tableWidgetClassPeriod, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(classperiodClicked()));
    QObject::connect(widget.buttonAddClassPeriod, SIGNAL(clicked()), this, SLOT(addClassPeriod()));
    QObject::connect(widget.buttonEditClassPeriod, SIGNAL(clicked()), this, SLOT(editClassPeriod()));
    QObject::connect(widget.buttonDeleteClassPeriod, SIGNAL(clicked()), this, SLOT(deleteClassPeriod()));
    QObject::connect(widget.buttonOkEditClassPeriod, SIGNAL(clicked()), this, SLOT(okEditClassPeriod()));
    QObject::connect(widget.buttonCancelEditClassPeriod, SIGNAL(clicked()), this, SLOT(cancelEditClassPeriod()));
    QObject::connect(widget.buttonAddGroupClassPeriod, SIGNAL(clicked()), this, SLOT(addGroupClassPeriod()));
    QObject::connect(widget.buttonDeleteGroupClassPeriod, SIGNAL(clicked()), this, SLOT(deleteGroupClassPeriod()));
    QObject::connect(widget.listWidgetGroups, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayStudents()));
    QObject::connect(widget.comboBoxGroupClassPeriod, SIGNAL(currentIndexChanged (int)), this, SLOT(comboBoxGroupsClassPeriodChanged(int)));
    QObject::connect(widget.listWidgetGroupClassPeriod, SIGNAL(currentRowChanged (int)), this, SLOT(listGroupClassPeriodClicked()));
    QObject::connect(widget.buttonClose, SIGNAL(clicked()), this, SLOT(close()));  
}

void WindowAdministrator::moduleClicked(){
    refreshModule(2);
}

void WindowAdministrator::classperiodClicked() {
    currentClassPeriod = NULL;
    refreshModule(3);
}

void WindowAdministrator::comboBoxGroupsClassPeriodChanged(int index){
    if(!load){
        if(moduleState == 51){
            refreshModule(511);
        }else if(moduleState == 52){
            refreshModule(521);
        }else if(moduleState == 522){
            refreshModule(523);
        }else if(moduleState == 512){
            refreshModule(513);
        }
    }
}

void WindowAdministrator::listGroupClassPeriodClicked(){
    if(!load){
    cout<<"current row avant refresh "<<widget.listWidgetGroupClassPeriod->currentRow()<<endl;
        if(moduleState == 52){
            refreshModule(522);
        }else if(moduleState == 521){
            refreshModule(523);
        }else if(moduleState == 51){
            refreshModule(512);
        }else if(moduleState == 511){
            refreshModule(513);
        }
    cout<<"Fin current row après refresh "<<widget.listWidgetGroupClassPeriod->currentRow()<<endl;
    }
}

void WindowAdministrator::setCurrentModule(){
    QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
    list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator itM = lm->begin();
    list<Module*>::const_iterator itMMax = lm->end();
    for(; itM!=itMMax; itM++){
        if((*itM)->GetId() == (*itModule)->text().toStdString()) {
            break;
        }
    }

    currentModule = (*itM);
}

void WindowAdministrator::setCurrentClassPeriod(){
    if(widget.tableWidgetClassPeriod->currentRow() != -1 && currentClassPeriod == NULL){
        QList<QTableWidgetItem*>::iterator itClassPeriod = widget.tableWidgetClassPeriod->selectedItems().begin();
        list<ClassPeriod*>::iterator itCP = currentModule->GetClassPeriodList()->begin();
        list<ClassPeriod*>::const_iterator itCPMax = currentModule->GetClassPeriodList()->end();
        for(; itCP!=itCPMax; itCP++){
            if((*itCP)->GetId() == (*itClassPeriod)->text().toInt()) {
                break;
            }
        }
        currentClassPeriod = (*itCP);
    }
}

void WindowAdministrator::loadGroupsClassPeriod(){
    widget.comboBoxGroupClassPeriod->clear();
    list<Group*>* l = this->ctrl->getSchedule()->GetGroupList();
    list<Group*>::iterator it = l->begin();
    list<Group*>::const_iterator MaxList = l->end();
    int count =  tempGroupListClassPeriod.count();
    for(;it != MaxList; it++){
        bool test = false;
        if(currentClassPeriod != NULL){
            list<Group*>::iterator itG = currentClassPeriod->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = currentClassPeriod->GetGroupList()->end();
            for(; itG!= itGMax; itG++) {
                if((*itG)->GetId() == (*it)->GetId()){
                    if(!groupClassPeriodModified && count == 0){
                        tempGroupListClassPeriod.push_back(QString::fromStdString((*itG)->GetId()));
                        test = true;
                    }
                    break;
                }
            }
        }
        
        
        if(!test && tempGroupListClassPeriod.indexOf(QString::fromStdString((*it)->GetId())) == -1){
            widget.comboBoxGroupClassPeriod->addItem((*it)->GetId().c_str());
        }
        
    }
    int indexRowGroupCP = widget.listWidgetGroupClassPeriod->currentRow();
    widget.listWidgetGroupClassPeriod->clear();
    widget.listWidgetGroupClassPeriod->addItems(tempGroupListClassPeriod);
    widget.listWidgetGroupClassPeriod->setCurrentRow(indexRowGroupCP);
    widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
}

void WindowAdministrator::setCurrentClassroom(){
    QList<QTableWidgetItem*>::iterator itClassroom = widget.tableWidgetModules->selectedItems().begin();
    
    list<Classroom*> *lc = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator itC = lc->begin();
    list<Classroom*>::const_iterator itCMax = lc->end();
    for(;itC != itCMax ; itC++){
        if((*itC)->GetId() == (*itClassroom)->text().toStdString())
            break;
    }
    
    currentClassroom = (*itC);
}

void WindowAdministrator::displaySpecificityClassroom() {
    widget.labelNumberComputers->setVisible(false);
    widget.lineEditNumberComputers->setVisible(false);
    widget.checkBoxSpecificity->setVisible(false);
    if(widget.comboBoxClassRoom->currentText() == "Practical Classroom") {
        widget.labelNumberComputers->setVisible(true);
        widget.lineEditNumberComputers->setVisible(true);
    }
    else if(widget.comboBoxClassRoom->currentText() == "Tutorial Classroom") {
        widget.checkBoxSpecificity->setVisible(true);
    }
    else if(widget.comboBoxClassRoom->currentText() == "Lecture Hall") {
        widget.checkBoxSpecificity->setVisible(true);
    }
}

void WindowAdministrator::refreshClassroom(int newState){
    this->classroomState = newState;
    switch(newState){
        case 1 :
            currentClassroom = NULL;
            widget.tableWidgetClassrooms->setEnabled(true);
            widget.frameClassroom->setVisible(false);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(false);
            widget.buttonDeleteClassroom->setEnabled(false); 
            displayClassroom();
            break;
        case 2 :
            setCurrentClassroom();
            widget.tableWidgetClassrooms->setEnabled(true);
            widget.frameClassroom->setVisible(false);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(true);
            widget.buttonDeleteClassroom->setEnabled(true);
            displayClassroom();
            break;
        case 31 :
            widget.tableWidgetClassrooms->setEnabled(false);
            widget.frameClassroom->setVisible(true);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(true);
            widget.buttonDeleteClassroom->setEnabled(true);
            widget.lineEditIdClassroom->setText("");
            widget.lineEditCapacityClassroom->setText("");
            widget.comboBoxClassRoom->setCurrentIndex(-1); 
            displaySpecificityClassroom();
            break;
        case 32 :
            widget.tableWidgetClassrooms->setEnabled(false);
            widget.frameClassroom->setVisible(true);
            widget.buttonAddClassroom->setEnabled(true);
            widget.buttonEditClassroom->setEnabled(true);
            widget.buttonDeleteClassroom->setEnabled(true);
            widget.lineEditIdClassroom->setText(currentClassroom->GetId().c_str());
            widget.lineEditCapacityClassroom->setText(QString::number(currentClassroom->GetCapacity()));
            if(dynamic_cast<TutorialClassroom*>(currentClassroom) != NULL) 
                widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Tutorial Classroom"));
            else if(dynamic_cast<PracticalClassroom*>(currentClassroom) != NULL)
                widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Practical Classroom"));
            else if(dynamic_cast<LectureHall*>(currentClassroom) != NULL)
                widget.comboBoxClassRoom->setCurrentIndex(widget.comboBoxClassRoom->findText("Lecture Hall"));
            else
                widget.comboBoxClassRoom->setCurrentIndex(-1);
            displaySpecificityClassroom();   
            break;
    }
}

void WindowAdministrator::refreshModule(int newState) {
    this->moduleState = newState;
    cout<<"Etat "<<moduleState<<endl;
    load = true;
    switch(this->moduleState){
        case 1 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            displayModule();
            currentModule = NULL;
            displayClassPeriod();
            break;
        case 2 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(true);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(true);
            widget.buttonDeleteModule->setEnabled(true);
            widget.buttonAddClassPeriod->setEnabled(true);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            widget.lineEditModule->setText("");
            widget.comboBoxTypeClassPeriod->setCurrentIndex(-1);
            widget.lineEditTeacherClassPeriod->setText("");
            widget.lineEditDurationClassPeriod->setText("");
            widget.listWidgetGroupClassPeriod->clear();
            if(oldIdSelectedModule == "")
                oldIdSelectedModule = (*(widget.tableWidgetModules->selectedItems().begin()))->text().toStdString();
            
            currentClassPeriod = NULL;
            displayModule();
            displayClassPeriod();
            setCurrentModule();
            break;
        case 3 :
            widget.tableWidgetModules->setEnabled(true);
            widget.tableWidgetClassPeriod->setEnabled(true);
            widget.buttonAddModule->setEnabled(true);
            widget.buttonEditModule->setEnabled(true);
            widget.buttonDeleteModule->setEnabled(true);
            widget.buttonAddClassPeriod->setEnabled(true);
            widget.buttonEditClassPeriod->setEnabled(true);
            widget.buttonDeleteClassPeriod->setEnabled(true);
            widget.frameEditModule->setVisible(false);
            widget.frameEditClassPeriod->setVisible(false);
            widget.lineEditIdModule->setText("");
            widget.lineEditNameModule->setText("");
            widget.lineEditTheHeadModule->setText("");
            widget.lineEditModule->setText("");
            widget.comboBoxTypeClassPeriod->setCurrentIndex(-1);
            widget.lineEditTeacherClassPeriod->setText("");
            widget.lineEditDurationClassPeriod->setText("");
            widget.listWidgetGroupClassPeriod->clear();
            
            setCurrentModule();
            setCurrentClassPeriod();
            displayClassPeriod();
            
            
            break;
        case 41 :
            widget.tableWidgetModules->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false);
            break;
        case 42 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);  
            if(currentModule != NULL){
                widget.lineEditIdModule->setText(currentModule->GetId().c_str());
                widget.lineEditNameModule->setText(currentModule->GetName().c_str());
                widget.lineEditTheHeadModule->setText(currentModule->GetTheHead().c_str()); 
            }
            break;
        case 43 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditModule->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);  
            if(currentModule != NULL){
                widget.lineEditIdModule->setText(currentModule->GetId().c_str());
                widget.lineEditNameModule->setText(currentModule->GetName().c_str());
                widget.lineEditTheHeadModule->setText(currentModule->GetTheHead().c_str()); 
            }
            break;
        case 51 :
            widget.tableWidgetModules->setEnabled(false);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);            
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            widget.frameEditClassPeriod->setVisible(true);
            widget.lineEditModule->setText(currentModule->GetId().c_str());
            
            loadGroupsClassPeriod();
            
            break;
        case 511 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            break;
        case 512 :
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);      
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            break;
        case 513 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);
            break;
        case 52 :
            widget.tableWidgetModules->setEnabled(false);
            widget.tableWidgetClassPeriod->setEnabled(false);
            widget.frameEditClassPeriod->setVisible(true);
            widget.buttonAddModule->setEnabled(false); 
            widget.buttonEditModule->setEnabled(false);
            widget.buttonDeleteModule->setEnabled(false);
            widget.buttonAddClassPeriod->setEnabled(false);
            widget.buttonEditClassPeriod->setEnabled(false);
            widget.buttonDeleteClassPeriod->setEnabled(false);  
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);
            widget.lineEditModule->setText(currentModule->GetId().c_str());
            if(currentClassPeriod != NULL){
                 widget.lineEditDurationClassPeriod->setText(QString::number(currentClassPeriod->GetDuration()));
                widget.lineEditTeacherClassPeriod->setText(currentClassPeriod->GetTeacher().c_str()); 
                widget.lineEditModule->setText(currentModule->GetId().c_str()); 

                int indexCP;
                if(dynamic_cast<TutorialClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Tutorial");
                else if(dynamic_cast<PracticalClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Practical");
                else if(dynamic_cast<MagistralClass*>(currentClassPeriod) != NULL) indexCP = widget.comboBoxTypeClassPeriod->findText("Magistral");
                else indexCP = -1;

                widget.comboBoxTypeClassPeriod->setCurrentIndex(indexCP);
            }
            loadGroupsClassPeriod();
            break;
        case 521 :
            widget.buttonAddGroupClassPeriod->setEnabled(true); 
            widget.listWidgetGroupClassPeriod->setCurrentRow(-1);
            widget.buttonDeleteGroupClassPeriod->setEnabled(false);          
            break;
        case 522 :
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);      
            widget.buttonAddGroupClassPeriod->setEnabled(false);
            widget.comboBoxGroupClassPeriod->setCurrentIndex(-1);
            loadGroupsClassPeriod();
            break;
        case 523 :
            widget.buttonAddGroupClassPeriod->setEnabled(true);
            widget.buttonDeleteGroupClassPeriod->setEnabled(true);
            break;
    }
    load = false;
    cout<<"Etat Fin "<<moduleState<<endl;
}

void WindowAdministrator::displayClassroom(){
    widget.tableWidgetClassrooms->clear();
    list<Classroom*> *lc = this->ctrl->getSchedule()->GetClassroomList();
    list<Classroom*>::iterator itC = lc->begin();
    list<Classroom*>::const_iterator itCMax = lc->end();
    QTableWidget *twc = this->widget.tableWidgetClassrooms;
    for(;itC != itCMax ; itC++){
        int nbrow = twc->rowCount();
        twc->insertRow(nbrow);
        twc->setItem(nbrow, 0, new QTableWidgetItem((*itC)->GetId().c_str()));
        twc->setItem(nbrow, 1, new QTableWidgetItem(QString::number((*itC)->GetCapacity())));
        string specificity = "", type = ""; 
        if(dynamic_cast<TutorialClassroom*>(*itC) != NULL) {
            type = "Tutorial Classroom";
            if(((TutorialClassroom*)(*itC))->IsVideoprojector())
                specificity = "projector available";
            else specificity = "no projector";
        }
        else if(dynamic_cast<PracticalClassroom*>(*itC) != NULL){
            type = "Practical Classroom";
        }
        else if(dynamic_cast<LectureHall*>(*itC) != NULL){
            type = "Lecture Hall";
            if(((LectureHall*)(*itC))->IsVideoconferencing()){
                specificity = "video conferencing is possible";
            } else{
                specificity = "";
            }
        }
        twc->setItem(nbrow, 2, new QTableWidgetItem(type.c_str()));
        QTableWidgetItem *item = new QTableWidgetItem(specificity.c_str());
        twc->setItem(nbrow, 3, item);
        if(currentClassroom != NULL){
            if((*itC)->GetId() == currentClassroom->GetId()){
                twc->setCurrentItem(item);
            }
        }
    }
}

void WindowAdministrator::addModule() {
    currentModule = NULL;
    if(moduleState == 1) {
        refreshModule(41);
    }else if(moduleState == 2){
        refreshModule(42);
    }else{
        refreshModule(43);
    }
    
}
void WindowAdministrator::editModule() { 
    if(moduleState == 2){
        refreshModule(42);
    }else{
        refreshModule(43);
    }
    

//    widget.frameEditModule->setVisible(true);
    
}

void WindowAdministrator::okEditModule() {
    if(currentModule != NULL){
        ctrl->setModule(currentModule, widget.lineEditIdModule->text().toStdString(), widget.lineEditNameModule->text().toStdString(), widget.lineEditTheHeadModule->text().toStdString());
    }
    else{
        Module* mod = new Module(widget.lineEditIdModule->text().toStdString(), widget.lineEditNameModule->text().toStdString(), widget.lineEditTheHeadModule->text().toStdString());
        ctrl->addModule(mod);

    }
    oldIdSelectedModule = widget.lineEditIdModule->text().toStdString();

    if(moduleState == 41 || moduleState == 42){
        refreshModule(2);
    }else{
        refreshModule(3);
    }
    
//    m->addModuleToComboBox();
}
void WindowAdministrator::cancelEditModule() {
//    widget.frameEditModule->setVisible(false);
//    widget.lineEditIdModule->setText("");
//    widget.lineEditNameModule->setText("");
//    widget.lineEditTheHeadModule->setText("");
    
    if(moduleState == 41){
        refreshModule(1);
    } else if (moduleState == 42){
        refreshModule(2);
    } else{
        refreshModule(3);
    }
}
void WindowAdministrator::deleteModule() {
    ctrl->delModule(currentModule);
//    m->addModuleToComboBox();
    refreshModule(1);

}
void WindowAdministrator::displayModule() {
    QTableWidget *table = widget.tableWidgetModules;    
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    QTableWidgetItem *item;
    
    list<Module*>* l = this->ctrl->getSchedule()->GetModuleList();
    list<Module*>::iterator it = l->begin();
    list<Module*>::const_iterator MaxList = l->end();
    for(;it != MaxList; it++){
        item = new QTableWidgetItem((*it)->GetId().c_str());
        int nbRow = table->rowCount();
        table->insertRow(nbRow);
        table->setItem(nbRow, 0, item);
        item = new QTableWidgetItem((*it)->GetName().c_str());
        table->setItem(nbRow, 1, item);
        item = new QTableWidgetItem((*it)->GetTheHead().c_str());
        table->setItem(nbRow, 2, item);
        
        if((*it)->GetId() == oldIdSelectedModule) {
            table->setCurrentItem(item);
            oldIdSelectedModule = "";
            currentModule = (*it);
        }
    }
}

void WindowAdministrator::displayStudents(){
    cout<<"groupe clique"<<endl;
//    QList<QListWidgetItem*>::iterator  itGroup = lwibegin();
    QList<QListWidgetItem*>::iterator itGroup = this->widget.listWidgetGroups->selectedItems().begin();
    list<Group*> *lg = this->ctrl->getSchedule()->GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();
    for(; itG != itGMax ; itG++ ){
        if((*itG)->GetId() == (*itGroup)->text().toStdString()){
            break;
        }
    }
    list<Student*> *ls = (*itG)->GetStudentList();
    list<Student*>::iterator itS = ls->begin();
    list<Student*>::const_iterator itSMax = ls->end();
    QTableWidget* tw = this->widget.tableWidgetStudents;
    while(tw->rowCount() != 0) {
        tw->removeRow(tw->rowCount()-1);
    }
    for(; itS != itSMax ; itS++){
        int nbRow = tw->rowCount();
        tw->insertRow(nbRow);
        tw->setItem(nbRow, 0, new QTableWidgetItem((*itS)->GetId().c_str()));
        tw->setItem(nbRow, 1, new QTableWidgetItem((*itS)->GetLastname().c_str()));
        tw->setItem(nbRow, 2, new QTableWidgetItem((*itS)->GetFirstname().c_str()));
        tw->setItem(nbRow, 3, new QTableWidgetItem((*itS)->GetAddr().c_str()));
        tw->setItem(nbRow, 4, new QTableWidgetItem((*itS)->GetEmail().c_str()));
    }
}
void WindowAdministrator::displayClassPeriod() {
    QTableWidget *table = widget.tableWidgetClassPeriod;
    while(table->rowCount() != 0) {
        table->removeRow(table->rowCount()-1);
    }
    
    if(widget.tableWidgetModules->currentRow() != -1) {
//        QList<QTableWidgetItem*>::iterator itModule = widget.tableWidgetModules->selectedItems().begin();
//
//        list<Module*> *lm = this->ctrl->getSchedule()->GetModuleList();
//        list<Module*>::iterator itM = lm->begin();
//        list<Module*>::const_iterator itMMax = lm->end();
//        for(; itM!=itMMax; itM++){
//            if((*itM)->GetId() == (*itModule)->text().toStdString()) {
//                break;
//            }
//        }
//
//        currentModule = (*itM);

        string type, groups = "";
        QTableWidgetItem *item;

        list<ClassPeriod*>* lcp = currentModule->GetClassPeriodList();
        list<ClassPeriod*>::iterator itCp = lcp->begin();
        list<ClassPeriod*>::const_iterator MaxListCp = lcp->end();
        for(;itCp != MaxListCp; itCp++){
            if(dynamic_cast<TutorialClass*>(*itCp) != NULL) type = "Tutorial";
            else if(dynamic_cast<PracticalClass*>(*itCp) != NULL) type = "Practical";
            else if(dynamic_cast<MagistralClass*>(*itCp) != NULL) type = "Magistral";
            else type = "";

            item = new QTableWidgetItem(QString::number((*itCp)->GetId()));
            int nbRow = table->rowCount();
            table->insertRow(nbRow);
            table->setItem(nbRow, 0, item);

            item = new QTableWidgetItem(type.c_str());
            table->setItem(nbRow, 1, item);

            item = new QTableWidgetItem((*itCp)->GetTeacher().c_str());
            table->setItem(nbRow, 2, item);

            item = new QTableWidgetItem(QString::number((*itCp)->GetDuration()));
            table->setItem(nbRow, 3, item);

            groups = "";
            list<Group*>::iterator itG = (*itCp)->GetGroupList()->begin();
            list<Group*>::const_iterator itGMax = (*itCp)->GetGroupList()->end();
            for(; itG!= itGMax; itG++) {
                groups.append((*itG)->GetId());
                groups.append(";");
            }

            item = new QTableWidgetItem(groups.c_str());
            table->setItem(nbRow, 4, item);
            
            if(currentClassPeriod != NULL){
                
                if((*itCp)->GetId() == currentClassPeriod->GetId()) {
                    table->setCurrentItem(item);
                }
                //widget.tableWidgetClassPeriod->setCurrentItem(*(widget.tableWidgetClassPeriod->findItems(QString::number(currentClassPeriod->GetId()), Qt::MatchCaseSensitive).begin()));
       
            }

        }
    }
}
void WindowAdministrator::addClassPeriod() {
    currentClassPeriod = NULL;
    if(moduleState == 2)
        refreshModule(51);
    else
        refreshModule(52);
}
void WindowAdministrator::editClassPeriod() {
    refreshModule(52);
    
    
    
    
   
}
void WindowAdministrator::deleteClassPeriod() {
    QList<QTableWidgetItem*>::iterator itClassPeriod = widget.tableWidgetClassPeriod->selectedItems().begin();
    list<ClassPeriod*>::iterator itCP = currentModule->GetClassPeriodList()->begin();
    list<ClassPeriod*>::const_iterator itCPMax = currentModule->GetClassPeriodList()->end();
    for(; itCP!=itCPMax; itCP++){
        if((*itCP)->GetId() == (*itClassPeriod)->text().toInt()) {
            break;
        }
    }
    ctrl->delClassPeriod((*itCP), currentModule);
    
    currentClassPeriod = NULL;
    refreshModule(2);
}
void WindowAdministrator::addGroupClassPeriod() {
    groupClassPeriodModified = true;
    tempGroupListClassPeriod.push_back(widget.comboBoxGroupClassPeriod->currentText());
    
    if(moduleState == 521){
        refreshModule(52);
    }else if(moduleState == 523){
        refreshModule(52);
    }else if(moduleState == 511){
        refreshModule(51);
    }else if(moduleState == 513){
        refreshModule(51);
    }

    
}
void WindowAdministrator::deleteGroupClassPeriod() {
    groupClassPeriodModified = true;
    tempGroupListClassPeriod.removeOne(widget.listWidgetGroupClassPeriod->currentItem()->text());
    if(moduleState == 522){
        refreshModule(52);
    }else if(moduleState == 523){
        refreshModule(521);
    }else if(moduleState == 512){
        refreshModule(51);
    }else if(moduleState == 513){
        refreshModule(511);
    }
}
void WindowAdministrator::okEditClassPeriod() {
    cout<<"1"<<endl;
    groupClassPeriodModified = false;
    list<Group*>* lGNew = new list<Group*>();
    list<Group*> *lg = this->ctrl->getSchedule()->GetGroupList();
    list<Group*>::iterator itG = lg->begin();
    list<Group*>::const_iterator itGMax = lg->end();
    for( ; itG != itGMax ; itG++){
        if(widget.listWidgetGroupClassPeriod->findItems(QString::fromStdString((*itG)->GetId()), Qt::MatchCaseSensitive).size() != 0 ){
            lGNew->push_back((*itG));
        }
    }
    cout<<"3"<<endl;
    tempGroupListClassPeriod.clear();
    if(currentClassPeriod != NULL){
        ctrl->setClassPeriod(currentModule, currentClassPeriod, widget.comboBoxTypeClassPeriod->currentText().toStdString(), widget.lineEditTeacherClassPeriod->text().toStdString(), widget.lineEditDurationClassPeriod->text().toInt(), lGNew);
    }
    else{
        cout<<"5"<<endl;
        ClassPeriod *cp;
        string type = widget.comboBoxTypeClassPeriod->currentText().toStdString();
        if(type == "Magistral")
            cp = new MagistralClass(widget.lineEditTeacherClassPeriod->text().toStdString(), widget.lineEditDurationClassPeriod->text().toInt(), currentModule);
        else if(type == "Practical")
            cp = new PracticalClass(widget.lineEditTeacherClassPeriod->text().toStdString(), widget.lineEditDurationClassPeriod->text().toInt(), currentModule);
        else
            cp = new TutorialClass(widget.lineEditTeacherClassPeriod->text().toStdString(), widget.lineEditDurationClassPeriod->text().toInt(), currentModule);
        cout<<"6"<<endl;
        cp->SetGroupList(lGNew);
        
        ctrl->addClassPeriod(cp, currentModule);
        currentClassPeriod = cp;
    }
    cout<<"2"<<endl;
//    oldIdSelectedModule = widget.lineEditIdModule->text().toStdString();
    refreshModule(3);
}
void WindowAdministrator::cancelEditClassPeriod() {
    groupClassPeriodModified = false;
    tempGroupListClassPeriod.clear();
    if(moduleState == 51){
        refreshModule(2);
    }else{
        refreshModule(3);
    }
}
WindowAdministrator::~WindowAdministrator() {

}


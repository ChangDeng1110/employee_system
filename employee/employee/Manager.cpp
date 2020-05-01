//
//  Manager.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include "Manager.h"

using namespace std;

Manager::Manager(int Id, string m_name, int dId)
{
    this->m_id = Id;
    this->m_name = m_name;
    this->m_DeptId = dId;
    
}

void Manager::showInfo()
{
    cout << "Manager_id : " << this->m_id << "|"
         << "\tManager_name : " << this->m_name << "|"
         << "\tJob_title : " << this->getDeptName() << "|"
         << "\tJob_duty : " << this->getDeptDuty() << endl;
}

string Manager::getDeptName()
{
    return "Manager";
}

string Manager::getDeptDuty()
{
    return "write PPT";
}

//
//  employee.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include <stdio.h>
#include "employee.h"


Employee::Employee(int Id, string m_name, int dId)
{
    this->m_id = Id;
    this->m_name = m_name;
    this->m_DeptId = dId;
    
}

void Employee::showInfo()
{
    cout << "Employee_id : " << this->m_id << "|"
         << "\tEmployee_name : " << this->m_name << "|"
         << "\tJob_title : " << this->getDeptName() << "|"
         << "\tJob_duty : " << this->getDeptDuty() << endl;
}

string Employee::getDeptName()
{
    return "programmer";
}

string Employee::getDeptDuty()
{
    return "code the world";
}


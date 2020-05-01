//
//  Boss.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//
#include "Boss.h"

using namespace std;

Boss::Boss(int Id, string m_name, int dId)
{
    this->m_id = Id;
    this->m_name = m_name;
    this->m_DeptId = dId;
    
}

void Boss::showInfo()
{
    cout << "Boss_id : " << this->m_id << "|"
         << "\tBoss_name : " << this->m_name << "|"
         << "\tJob_title : " << this->getDeptName() << "|"
         << "\tJob_duty : " << this->getDeptDuty() << endl;
}

string Boss::getDeptName()
{
    return "Boss";
}

string Boss::getDeptDuty()
{
    return "Drink Tea";
}

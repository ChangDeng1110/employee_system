//
//  employee.h
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#ifndef employee_h
#define employee_h

#pragma once
#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

class Employee : public Worker
{
    
public:
    Employee(int Id, string m_name, int dId);
    
    virtual void showInfo();
    virtual string getDeptName();
    virtual string getDeptDuty();
    
};

#endif /* employee_h */

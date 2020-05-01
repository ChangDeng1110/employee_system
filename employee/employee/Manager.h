//
//  Manager.h
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#ifndef Manager_h
#define Manager_h

#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

class Manager : public Worker
{
public:
    Manager(int Id, string m_name, int dId);
    virtual void showInfo();
    virtual string getDeptName();
    virtual string getDeptDuty();
};

#endif /* Manager_h */

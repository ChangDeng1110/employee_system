//
//  Boss.h
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#ifndef Boss_h
#define Boss_h

#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
public:
    Boss(int Id, string m_name, int dId);
    virtual void showInfo();
    virtual string getDeptName();
    virtual string getDeptDuty();
};

#endif /* Boss_h */

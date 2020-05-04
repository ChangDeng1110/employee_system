//
//  worker.h
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#ifndef worker_h
#define worker_h

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker
{
public:
    int m_id;
    string m_name;
    int m_DeptId;
    
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    virtual string getDeptDuty() = 0;
};

#endif /* worker_h */

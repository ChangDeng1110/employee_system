//
//  WokerManager.hpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#ifndef WokerManager_hpp
#define WokerManager_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"
#include <fstream>

#define FILENAME "/Users/changdeng/Documents/c++/employee_system/employee/employee/empFile.txt"

using namespace std;

class WorkerManager
{
public:
    WorkerManager();
    void Show_Menu();
    void exitSystem();
    int m_EmpNum;
    Worker ** m_EmpArray;
    void Add_Emp();
    void save();
    bool m_fileIsEmpty;
    int get_EmpNum();
    ~WorkerManager();

};

#endif /* WokerManager_hpp */

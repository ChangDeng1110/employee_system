//
//  WokerManager.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include "WokerManager.hpp"

WorkerManager::WorkerManager()
{
    
}

void WorkerManager::Show_Menu()
{
    cout << "=============================" << endl;
    cout << "0. exist system" << endl;
    cout << "1. add employee" << endl;
    cout << "2. show employee information" << endl;
    cout << "3. delete employee" << endl;
    cout << "4. edit employee" << endl;
    cout << "5. search employee" << endl;
    cout << "6. sort employee number" << endl;
    cout << "7. clear all employee" << endl;
    cout << "=============================" << endl;
    
}

void WorkerManager::exitSystem()
{
    cout << "welcome to use the system next time!" << endl;
    exit(0);
}

WorkerManager::~WorkerManager()
{
    
}

//
//  main.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include <iostream>
#include "WokerManager.hpp"
#include "worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;


int main()
{
//    Worker *worker = NULL;
//    worker = new Employee(1,"tom",1);
//    worker->showInfo();
//
//    Manager *manager = NULL;
//    manager = new Manager(2,"neo",2);
//    manager->showInfo();
//
//    Boss *boss = NULL;
//    boss = new Boss(2,"neo",2);
//    boss->showInfo();
    
    WorkerManager wm;
    int choice = 0;

    while(true)
    {
        wm.Show_Menu();
        cout << "please input your choose number: ";
        cin >> choice;
        switch (choice) {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.Add_Emp();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;

            default:
                break;
        }
    }
    
    return 0;
}

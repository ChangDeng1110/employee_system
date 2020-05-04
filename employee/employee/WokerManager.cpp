//
//  WokerManager.cpp
//  employee
//
//  Created by Chang Deng on 2020/5/1.
//  Copyright © 2020 Chang Deng. All rights reserved.
//

#include "WokerManager.hpp"

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    
    int num = 0;
    
    int id;
    string name;
    int dId;
    
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num;
}

void WorkerManager::Del_Emp()
{
    if(this->m_fileIsEmpty)
    {
        cout << "No file" << endl;
    }
    else
    {
        cout << "input the id number for deleting: ";
        int id;
        cin >> id;
        int index = this->IsExist(id);
        if(index != -1)
        {
            for(int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum --;
            this->save();
            cout << "delete sucessful!" << endl;
        }
        else
        {
            cout << "can not find this people!" << endl;
        }
    }
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for(int i = 0; i < this->m_EmpNum; i++)
    {
        if(this->m_EmpArray[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    
    return index;
}


void WorkerManager::Mod_Emp()
{
    if(this->m_fileIsEmpty)
    {
        cout << "No file" << endl;
    }
    else
    {
        cout << "input modify ID: ";
        int id;
        cin >> id;
        
        int ret = this->IsExist(id);
        
        if(ret != -1)
        {
            delete this->m_EmpArray[ret];
            
            int newId = 0;
            string newName = "";
            int newDep = 0;
            
            cout << "find id " << id << ", please input new ID : ";
            cin >> newId;
            cout << "please input new name : ";
            cin >> newName;
            cout << "please input new department id : ";
            cout << "1. programmer, 2. manager, 3. boss" << endl;
            cin >> newDep;
            
            Worker * worker = NULL;
            switch (newDep) {
                case 1:
                    worker = new Employee(newId,newName,newDep);
                    break;
                case 2:
                    worker = new Manager(newId,newName,newDep);
                    break;
                case 3:
                    worker = new Boss(newId,newName,newDep);
                    break;
                    
                default:
                    break;
            }
            
            this->m_EmpArray[ret] = worker;
            cout << "modify sucessful!" << endl;
            this->save();
            
        }
        else
        {
            cout << "can not find this people!" << endl;
        }
    }
    
}

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open())
    {
        cout << "no named file!" << endl;
        this -> m_fileIsEmpty = true;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "empty file!" << endl;
        this -> m_fileIsEmpty = true;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    
    int num = this->get_EmpNum();
    cout << "emplpoyee number is: " << num << endl;
    this->m_EmpNum = num;
    
    this ->m_EmpArray = new Worker * [this->m_EmpNum];
    this -> init_Emp();
//    for(int i = 0; i < this->m_EmpNum; i++)
//    {
//        cout << this->m_EmpArray[i]->m_id << this->m_EmpArray[i]->m_name << this->m_EmpArray[i]->m_DeptId << endl;
//    }
}

void WorkerManager::show_Emp()
{
    if(this->m_fileIsEmpty)
    {
        cout << "no file or empty file!";
    }
    else
    {
        for(int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
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

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_id<< " "
        << this->m_EmpArray[i]->m_name<< " "
        << this->m_EmpArray[i]->m_DeptId<< endl;
    }
    ofs.close();
}


void WorkerManager::Add_Emp()
{
    cout << "Please input the number you want to add: ";
    int addNum = 0;
    cin >> addNum;
    
    if (addNum > 0)
    {
        int newSize = this->m_EmpNum + addNum;
        Worker** newSpace = new Worker*[newSize];
        
        if(this->m_EmpArray != 0)
        {
            for(int i = 0; i < this->m_EmpNum; i ++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        
        for(int i = 0; i < addNum; i++)
        {
            int id;
            int dSelect;
            string name;
            
            cout << "input " << i+1 << " new employee id: ";
            cin >> id;
            
            cout << "input " << i+1 << " new employee name: ";
            cin >> name;
            
            cout << "please input the role of new employee: " << endl;
            cout << "1. programmer" << endl;
            cout << "2. manager" << endl;
            cout << "3. boss" << endl;
            
            cin >> dSelect;
            
            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(id,name,dSelect);
                    break;
                case 2:
                    worker = new Manager(id,name,dSelect);
                    break;
                case 3:
                    worker = new Boss(id,name,dSelect);
                    break;
                    
                default:
                    break;
            }
            
            newSpace[this->m_EmpNum+i] = worker;
        }
        
        delete [] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        
        cout << "succesful add " << addNum << " employees" << endl;
        this->m_fileIsEmpty = false;
        this->save();
    }
    else
    {
        cout << "invalid input!" << endl;
    }
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    
    int id;
    string name;
    int dId;
    
    int index = 0;
    
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        if(dId == 1)
        {
            worker = new Employee(id,name,dId);
        }
        else if(dId == 2)
        {
            worker = new Manager(id,name,dId);
        }
        else
        {
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index] = worker;
        index ++;
    }
    
    ifs.close();
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
    }
}

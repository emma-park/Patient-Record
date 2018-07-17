// Anushka Birla 20723833 and Emma Park 20725926

#ifndef records_manager_h
#define records_manager_h
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "patient_record.hpp"



class RecordsManager{
    PatientRecord** record;
    int size;
    int capacity;
    
public:
    RecordsManager ();
    RecordsManager (int nCap);
    void insert (RecordsManager* value);
    int getSize();
    int getCapacity();
    friend class RecordsManagerTest;
    void print();
    bool insertRecord (uint newCatID, uint newPatID, string newName, string newAddress, string newDOB);
    bool removeRecord (uint categoryID, uint patientID);
};








#endif /* records_manager_h */

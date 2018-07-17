//
//  Header.h
//  mte140-as2
//
//  Created by Anushka Birla on 2018-05-24.
//  Copyright © 2018 Anushka Birla. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */

class PatientRecord{
    
    uint categoryID;
    uint patientID;
    string fullName;
    string address;
    string birthdate;
    
public:
    PatientRecord ();
    PatientRecord (uint newCatID, uint newPatID, string newName, string newAddress, string newDOB);
    uint getCatID ();
    uint getPatID ();
    
};

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



#ifndef patient_record_h
#define patient_record_h
#include "main.cpp"

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
    string getName();
    string getAddress();
    string getDOB();
};




#endif /* patient_record_h */


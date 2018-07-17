// Anushka Birla 20723833 and Emma Park 20725926

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "patient_record.hpp"


using namespace std;

PatientRecord::PatientRecord (){
    categoryID = 0;
    patientID = 0;
    fullName = " ";
    address = " ";
    birthdate = " ";
}

PatientRecord::PatientRecord (uint newCatID, uint newPatID, string newName, string newAddress, string newDOB){
    categoryID = newCatID;
    patientID = newPatID;
    fullName = newName;
    address = newAddress;
    birthdate = newDOB;
}

uint PatientRecord::getCatID(){
    return categoryID;
}

uint PatientRecord::getPatID(){
    return patientID;
}

string PatientRecord::getName() {
    return fullName;
}

string PatientRecord::getAddress() {
    return address;
}

string PatientRecord::getDOB() {
    return birthdate;
}

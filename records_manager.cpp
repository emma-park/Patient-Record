// Anushka Birla 20723833 and Emma Park 20725926

// NOTE: Occasionally, our code doesn't compile properly and gives us the error "EXC_BAD_ACCESS". We think it has something to do with Line 121 in this file, but we talked with Igor about that line. Normally when we run it, we have no problems, hope that's okay!


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "records_manager.hpp"

using namespace std;

const int defaultRMSize = 10;

RecordsManager::RecordsManager (){
    capacity = defaultRMSize;
    record = new PatientRecord* [capacity];
    size = 0;
}

RecordsManager::RecordsManager (int nCap){
    size = 0;
    if (nCap < 128) {
        capacity = defaultRMSize;
        record = new PatientRecord* [capacity];
    }
    else {
        capacity = nCap;
        record = new PatientRecord* [nCap];
    }
}

int RecordsManager::getSize(){
    return size;
}

int RecordsManager::getCapacity(){
    return capacity;
}

void RecordsManager::print() {
    if (size == 0){
        cout << "Empty! There are currently no patient records stored" << endl;
    }
    
    for (int i=0; i<size; i++){
        cout << "Category ID: " << record[i]->getCatID() << endl
        << "Patient ID: " << record[i]->getPatID() << endl
        << "Full Name: " << record[i]->getName() << endl
        << "Address: " << record[i]->getAddress() << endl
        << "Date of birth (dd/mm/yy): " << record[i]->getDOB() << endl;
    }
}



bool RecordsManager::insertRecord (uint newCatID, uint newPatID, string newName, string newAddress, string newDOB){
    if (size == capacity){
        capacity*=2;
        PatientRecord ** arr = new PatientRecord*[capacity];
        for (int i = 0; i<size; i++)
            arr[i] = record[i];
        delete [] record;
        record = arr;
    }
    
    if (size ==0){
        size ++;
        record[0] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);
        return 1;
    }
    for (int i = 0; i<size; i ++){
        if (newCatID == record[i]->getCatID()){
            if (newPatID == record[i]->getPatID())
                return 0;
            else{
                while (newCatID == record[i]->getCatID() && newPatID > record[i]->getPatID() && i < size-1) // iterate through until newPatID < Patient ID or it has iterated through all members with the same CatID
                    i++;
                if(newCatID == record[i]->getCatID() && newPatID > record[i]->getPatID()){ // greater than final record, insert at the end of the list
                    record[i+1] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);
                    size++;
                }
                else { // newPatID is less than final, insert before
                    size ++; //increase size and insert
                    for (int j=size; j>i; j--)
                        record[j] = record[j-1];
                    record[i] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);
                }
                return 1;
            }
        }
        else {
            if (newCatID < record[i]->getCatID()){
                size ++;
                for (int j=size; j>i; j--)
                    record[j] = record[j-1];
                record[i] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);
                return 1;
            }
            else if (newCatID > record[i]->getCatID() && i==size-1) {
                record[i+1] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);
                size ++;
                return 1;
            }
        }
    }
    return 0;
}

bool RecordsManager::removeRecord (uint categoryID, uint patientID){
    
    for (int i = 0; i<size; i ++){
        while(categoryID == record[i]->getCatID()){
            for(int j=i; j<size; j++){
                if (patientID == record[j]->getPatID()){
                    for (int k = j; k < size; k++)
                        record[k] = record[k+1];
                    size--;
                    delete record [size]; // throwing errors
                    record[size] = NULL;
                    if (size < capacity/4 && capacity/4 > 10){
                        capacity/=2;
                        PatientRecord ** arr = new PatientRecord*[capacity];
                        for (int i = 0; i<size; i++)
                            arr[i] = record[i];
                        delete [] record;
                        record = arr;
                    }
                    return 1;
                }
            }
            return 0;
        }
        if (i == size-1 && categoryID != record[i]->getCatID())
            return 0;
    }
    return 0;
}

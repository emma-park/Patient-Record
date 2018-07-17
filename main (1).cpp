// Anushka Birla 20723833 and Emma Park 20725926

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "records_manager.hpp"
#include "patient_record.hpp"
#include "records_manager_test.hpp"


using namespace std;


int main() {
    RecordsManagerTest testRecord;
    cout << (testRecord.test1() ? "TEST 1 PASSED" : " TEST 1 FAILED") << endl << endl;
    cout << (testRecord.test2() ? "TEST 2 PASSED" : " TEST 2 FAILED") << endl << endl;
    cout << (testRecord.test3() ? "TEST 3 PASSED" : " TEST 3 FAILED") << endl << endl;
}












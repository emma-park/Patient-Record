// Anushka Birla 20723833 and Emma Park 20725926

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "records_manager_test.hpp"
#include "records_manager.hpp"

using namespace std;


bool RecordsManagerTest::test1(){
    RecordsManager testRecord;
    
    testRecord.insertRecord(3, 44, "Amy Kim", "123 university", "12/12/80");
    testRecord.insertRecord(7, 10, "Joe Brown", "400 king street", "18/11/83");
    testRecord.insertRecord(9, 4, "Emily Mann", "783 erb street", "18/08/86");
    testRecord.insertRecord(1, 23, "Selena Gomez", "238 Town Street", "16/10/89");
    testRecord.insertRecord(7, 22, "Aladdin John", "554 queen", "01/06/97");
    testRecord.insertRecord(3, 75, "Taylor Dechair", "113 college", "10/01/99");
    
    testRecord.print();
    cout << endl;
    
    testRecord.removeRecord(7, 22);
    testRecord.removeRecord(7, 10);
    testRecord.removeRecord(3, 75);
    testRecord.removeRecord(3, 44);
    testRecord.removeRecord(9, 4);
    testRecord.removeRecord(1, 23);
    
    testRecord.print();
    cout << endl;
    return 1;
}


bool RecordsManagerTest::test2(){
    RecordsManager testRecord;
    
    cout << "Original size is: " << testRecord.size << endl;
    cout << "Original capacity is: " << testRecord.capacity << endl;
    
    for (int i = 0; i< 15; i++){ // inserts 15 records
        testRecord.insertRecord(i, 44, "Amy Kim", "123 university", "12/12/80");
    }
    
    cout << "Size is: " << testRecord.size << endl;
    cout << "Capacity is: " << testRecord.capacity << endl;
    
    for (int i = 15; i<45; i++){ // inserts 20 more records
        testRecord.insertRecord(i, 22, "Aladdin John", "554 queen", "01/06/97");
    }
    cout << "Size is: " << testRecord.size << endl;
    cout << "Capacity is: " << testRecord.capacity << endl;
    
    for (int i = 0; i < 90; i++){
        testRecord.removeRecord(i, 44);
        testRecord.removeRecord(i, 22);
    }
    
    cout << "Final size is: " << testRecord.size << endl;
    cout << "Final capacity is: " << testRecord.capacity << endl;
    
    return 1;
}


bool RecordsManagerTest::test3(){
    RecordsManager testRecord;
    
    cout << (!testRecord.removeRecord(3, 44) ? "Remove Test 1 Passed" : "Remove Test 1 Failed") << endl << endl; // tries to remove a record from an empty list
    
    testRecord.print();
    cout << endl;
    
    testRecord.insertRecord(3, 44, "Amy Kim", "123 university", "12/12/80");
    testRecord.insertRecord(9, 4, "Emily Mann", "783 erb street", "18/08/86");
    testRecord.insertRecord(3, 44, "Amy Kim", "123 university", "12/12/80"); // tries to insert a duplicate record
    testRecord.insertRecord(7, 10, "Joe Brown", "400 king street", "18/11/83");
    
    testRecord.print();
    cout << endl;
    
    cout << (!testRecord.removeRecord(2, 19) ? "Remove Test 2 Passed" : "Remove Test 2 Failed") << endl << endl; // tries to remove a record that isn't there
    testRecord.print();
    cout << endl;
    
    return 1;
}

/*
Constraints:
    1. The numbers assigned to employees are 5 digit each and initially the company can assign
       the numbers to a maximum of 1000 employees.
    2. The number assigned to each employee can be reassigned to some other employee in future
       if the earlier one leaves the company and some new employee joins.

    Using Hash Data Structure write the algorithm/pseudo-code and implementation as well, for
    this set-up. Each record should have these three fields: - ID, Name, Ph_No. Initialize all 1000
    numbers first starting from 11111, 11112 and so on.
    The program should have following features:
        1. Adding a record for new employee based on ID.
        2. Display all the records at any moment of time
        3. Deleting the employee based on ID, but retain the number assigned to it as is.
        4. Searching a particular employee either by phone_no or ID.


Approach:
    1.Initialize the table sixe T_S.
    2. Create a Hash Table.
    3. Declare a key K and Value V;
    4.Create a constructor to create a table
    5.Create a hasfunction() to return the key
    6.Create a functions to insert, remove, search data.
    7.Create a drop list to take input for operations.
    8.Take input and print the result.
    9. END
*/
#include<iostream>      // Used for manipulating input/output streams
#include<cstdlib>       //used for data type conversion, pseudo-random number generation, memory allocation, searching, sorting, mathematics, and dealing with wide or multibyte characters
#include<string>        //required for string functions
#include<cstdio>        //used to print the strings, integer, character etc on the output screen
using namespace std;
const int T_S = 200;        //Initializing constant amount of hash lists
class HashTableEntry {       
public:
    int k;
    int v;
    HashTableEntry(int k, int v) {
        this->k = k;
        this->v = v;
    }
};
class HashMapTable {            //Declaration of class HashMapTable
private:
    HashTableEntry** t;
public:
    HashMapTable() {                                
        t = new HashTableEntry * [T_S];
        for (int i = 0; i < T_S; i++) {  //We traverse to every hash group and confirm if its empty
            t[i] = NULL;            //To make sure the data structure is empty
        }
    }
    int HashFunc(int k) {
        return k % T_S;             //Since we only have a table of size T_S so we need to return a value between 0 and T_S
                                    //Hence we can return the moofulus of the key with the table size. (For eg. Key= 32, then it will return us the value 32)
                                    //(i.e. The value 32 will be the 33 list in this table as the table is an array that is 0 based)
    }
    void Insert(int k, int v) {                       //Fucntion Insert()-> to insert employee data
        int h = HashFunc(k);                    //The key will be hashed so we need a value that corresponds to the key
                                                //So whatever the result of this hash will signify which lists the key-value pair needs to go into
        while (t[h] != NULL && t[h]->k != k) {   //First we need to make sure that the key exists and replace the value of the key that we need as an input
            h = HashFunc(h + 1);        //Since the value of the table was NULL as default we increment it by one so as to add the record into the table
        }
        if (t[h] != NULL)       //if the value of any list is not NULL by default we delete any previous entry present 
            delete t[h];
        t[h] = new HashTableEntry(k, v);    
    }
    int SearchKey(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)           //If no data is found at the entered key return -1
            return -1;
        else                        //If data is found at the key then return the value V stored at the key
            return t[h]->v;
    }
    void Remove(int k) {
        int h = HashFunc(k);        //Similar as before to remove a record stored in a list, we find the key and remove the key-value pair
                                    // and whatever the iterator is pointing to
        while (t[h] != NULL) {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {                 //If the there is no key found, return the value of the key k  ;
            cout << "No Element found at key " << k << endl;
            return;         
        }
        else {                          //If the record is found at the key delete the record;
            delete t[h];
        }
        cout << "Element Deleted" << endl;
    }
    ~HashMapTable() {                           //Destructor to destroy the object created by the constructor
        for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
};
int main() {
    HashMapTable hash;
    int k, v;
    int c;
    while (1) {                 //Print the output of the operation once executed
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c) {                //Creating a drop list to choose desired operation
        case 1:
            cout << "Enter element to be inserted: ";
            cin >> v;
            cout << "Enter key at which element to be inserted: ";
            cin >> k;
            hash.Insert(k, v);              //Passing value to Insert()
            break;
        case 2:
            cout << "Enter key of the element to be searched: ";
            cin >> k;
            if (hash.SearchKey(k) == -1) {        
                cout << "No element found at key " << k << endl;
                continue;
            }
            else {
                cout << "Element at key " << k << " : ";
                cout << hash.SearchKey(k) << endl;      
            }
            break;
        case 3:
            cout << "Enter key of the element to be deleted: ";
            cin >> k;
            hash.Remove(k);             //Passing value of key to Remove()->To delete or remove entry
            break;
        case 4:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
    return 0;
}

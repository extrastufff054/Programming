#include<iostream>
#include<list>
#include<cstring>
using namespace std;

//Hash table to implement employee information

class HashTable
{
    private:
        static const int hashGroups=10000;
        list<pair<int,string>> table[hashGroups];     //List1,Index 0, list 1, List 2, index 2, list 2...
        
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void InsertItem(int key,string value);
        void RemoveItem(int key);
        string SearchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const
{  
    int sum;
    for (int i{};i<hashGroups;i++)
    {
        sum += table[i].size();

    }
    if(!sum)
    {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key)
{
    return key%hashGroups;
}

void HashTable::InsertItem(int key, string value)
{
    int hashValue=hashFunction(key);
    auto& cell=table[hashValue];
    auto bItr=begin(cell);
    bool keyExists=false;
    for(; bItr !=end(cell); bItr++)
    {
        if(bItr->first==key)
        {
            keyExists=true;
            bItr->second=value;
            cout<<"[Warning] Key exists. Value replaced"<<endl;
            break;
        }
    }
    if(!keyExists)
    {
        cell.emplace_back(key,value);
    }
    return;
}

void HashTable::RemoveItem(int key)
{
    int hashValue = hashFunction(key);
    auto& cell=table[hashValue];
    auto bItr=begin(cell);
    bool keyExists=false;
    for(;bItr!=end(cell);bItr++)

    if(bItr->first==key)
    {
        keyExists=true;
        bItr=cell.erase(bItr);
        cout<<"[Information]Item removed and replaced"<<endl;
        break;

    }
    if(!keyExists)
    {
        cout<<"[Warning] KEy not found. Pair not removed"<<endl;

    }
}

void HashTable::printTable()
{
    for (int i{};i<hashGroups; i++)
    {
        if(table[i].size()==0)  continue;

        auto bItr=table[i].begin();
        for(;bItr!=table[i].end();bItr++)
        {
            cout<<"[Information] Key:"<<bItr->first<<"Value: "<<bItr->second<<endl;
        }
    }
    return;

}

int main()
{
    HashTable HT;

    if(HT.isEmpty())
    {
        cout<<"Correct answer. Good job";

    }

    else
    {
        cout<<"Oh ..Oh..We need to check out code!!"<<endl;
    }

   

    HT.InsertItem(323,"timmy");
    HT.InsertItem(323,"jimmy");
    HT.InsertItem(376,"mummy");
    HT.InsertItem(343,"tufammy");
    HT.InsertItem(321,"samy");
    HT.printTable();

    HT.RemoveItem(376);
    HT.RemoveItem(311);
    

    if(HT.isEmpty())
    {
        cout<<"oh .oh We need to check out code!!"<<endl;
    }
    else
    {
        cout<<"correct answer! good job"<<endl;
    }

    return 0;
}

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;

    cout<<"Enter the value of n=";
    cin>>n;

    int originaln=n;
    int sum=0;

    while(n>0)
    {
        int lastdigit=n%10;
        sum+=pow(lastdigit,3);
        n=n/10;
    }

    if(sum==originaln)
    {
        cout<<"The entered number is Armstrong number";
    }
    else{
        cout<<"The number is not Armstrong";
    }
}
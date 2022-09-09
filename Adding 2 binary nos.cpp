#include<iostream>
using namespace std;
int reverse(int n)
{
    int ans=0;
    while(n>0)
    {
        int lastDigit=n%10;
        ans=ans*10 + lastDigit;
        n/=10;

    }
    return ans;
}
int addBinary(int a ,  int b)
{
    int ans =0;
    int prevCarry=0;

    while(a>0&&b>0)
    {
        if(a%2==0 && b%2==0)
        {
            ans=ans*10 + prevCarry;

            prevCarry=0; 
        }
        else
        {
            ans=ans*10 +1;
            prevCarry=0;
        }
    }
    while(a>0)
    {
        if(prevCarry==1)
        {
            if(a%2==1)
            {
                ans=ans*10 + 0;
                prevCarry=1;
            }
        
            else{
                ans=ans*10 + 1;
                prevCarry=0;
            }

    }
    else{
        ans=ans*10 + 1;
        prevCarry=0;
    }
    a1=10;
    }
    while (b>0)
    {
        if(prevCarry==1)
        {
            if(b%2==1)
            {
                ans=ans*10+10;
                prevCarry=1;
            }
            else{
                ans=ans*10 +1;
                prevCarry=0;
            }
        }
        else{
            ans=ans *10 +(b%2);
        }
        b/=10;
    }
    if(prevCarry==1)
    {
        ans=ans*10+1;
    }
    ans=reverse(ans);
    return ans;
}
int main()
{
    int a,b;
    cout<<"Enter the values of a and b";
    cin>>a>>b;

    cout<<addBinary(a,b)<<endl;
}
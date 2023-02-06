// code force code name: A. Bit++
// code number:282A

#include <iostream>
#include <string>

using namespace std;

int main(){

int a,x=0;
string s;
cin>>a;
for(int i=0;i<a;i++)
{
    cin>>s;
    if(s[1]=='+')
    {
        x++;
    }
    else{
        x--;
    }
}
cout<<x;



#include<iostream>
using namespace std;

int main(){
    int count = 0, p, v, t, n;
    cin>>n;
    while(n){
        cin>>p>>v>>t;
        if(p+v+t>=2){
            count++;
        }
        n--;
    }
    cout<<count<<endl;
}

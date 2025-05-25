#include <iostream>
#include <vector>

using namespace std;

bool isugly(int n) {
    if(n<=0)
        return false;
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    while(n%5==0)
        n/=5;
    if(n==1)
        return true;
    else
        return false;
}

int main(){
    long long n;
    cout << "Enter value of 'n': ";
    cin >> n;
    long long temp=n;
    long long result;
    long long num=1;
    while(n>0){
        if(isugly(num)){
            n--;
            result=num;
        }
        num++;
    }
    cout << temp << "th ugly number: " << result;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int num ; 
int pow(int i,int j){if(j==0) return 1; if(j==1) return i; 
    if(j%2==0){int tmp=pow(i,j/2); return tmp*tmp;} else return i*pow(i,j-1);}
vector<bool> isprime(1e5+2,true);vector<int> primes;
void sieve(){isprime[1]=false;
    for(int i=2;i<1e5;i++){primes.push_back(i);for(int j=2*i;j<1e5;j+=i)isprime[j]=false;}}
void oup(int ans){cout<<"Phi of "<< num <<" is "<<ans<<"\n";}
int main() {
    int tmp;cout << "Enter the number \n"; cin >> num;tmp=num;
    sieve();
    if(isprime[num]){oup(num-1); return 0;} else{
        vector<pair<int,int>> coprimes; int i{0};while(num>1){if(num%primes[i]==0){int cnt=0;
        while(num%primes[i]==0)cnt++,num/=primes[i];coprimes.push_back({primes[i],cnt});}i++;}
        int ans = 1; 
        for(auto it: coprimes){ans*=(pow(it.first,it.second)-pow(it.first,it.second-1));}  num=tmp; oup(ans); 
    }
}

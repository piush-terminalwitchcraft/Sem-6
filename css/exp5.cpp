#include <iostream>

using namespace std;
// d === e-1mod pn 
// q r1 r2 r t1 t2 t
int findModInv(int n, int m){
    int q, r1 = m, r2 = n, r, t1 = 0, t2 = 1, t;
    while(r2 != 0){r = r1%r2; q = r1/r2;t = t1-q*t2;r1 = r2; r2 = r; t1 = t2; t2 = t; }
    return (t1+m)%m;
}
int ModPow(int n, int m, int MOD){
    if(m==0) return 1; 
    if(m==1) return n%MOD; 
    if(m%2==0) {
        int f = ModPow(n,m/2,MOD);
        return ((f%MOD)*(f%MOD))%MOD;
    }
    else return (n*ModPow(n,m-1,MOD))%MOD;
}
int main(){
    int p = 3, q = 11;
    int n = p*q, pn = (p-1)*(q-1);
    int e; cout << "Enter the public key, should be between 2 and less than "<< pn << "\n"; cin >> e; 
    int d = findModInv(e,pn);
    cout << "value of d is " << d << "\n";
    int M ; cout << "Enter the data to be send \n"; cin >> M; 
    int C = ModPow(M,e,n);
    cout << "Encryption is " << C << "\n"; 
    int D = ModPow(C,d,n); 
    cout << "Decryption is " << D << "\n";
    return 0;
}

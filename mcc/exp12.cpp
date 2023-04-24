#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int getBit(string s, int idx){
    int sm{0};
    for(int i = idx; i<idx+8; i++) sm+=s[i]-'0';
    return (sm<=3?0:1);
}
int32_t main() {
    cout << "Enter the data to be transmitted (2 bits)\n";
    string data ; cin >> data; 
    cout << "Enter the chipping sequence (16 bits)\n";
    string chipseq; cin >> chipseq;
    string encData = chipseq;
    cout << "Step 1 => Xoring chip sequence with data \n";
    for(int i = 0; i < 16; i++){
        encData[i] = '0'+ ((chipseq[i]-'0')^(data[i/8]-'0'));
    }
    cout << "Encoded data is - " << encData << "\n";
    cout << "Step 2 => Decoding data with same chip sequence \n";
    string decData = encData;
    for(int i = 0; i < 16; i++){
        decData[i] = '0'+ ((chipseq[i]-'0')^(encData[i]-'0'));
    }
    cout << "Decoded data is - " << decData << "\n";
    for(int i = 0; i < 16; i+=8){
        cout<<getBit(decData,i);
    }
    cout<<endl;


}

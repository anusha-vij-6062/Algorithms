#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carryOut=0;
        int sum=0;
        string result="";
        int i=a.size()-1,j=b.size()-1;

        while(i>=0||j>=0||carryOut==1){
            sum+=carryOut;
            sum+=(i>=0?a[i]-'0':0);
            sum+=(j>=0?b[j]-'0':0);
            carryOut=sum/2;
            sum=sum%2;
            result=to_string(sum)+result;
            sum=0;
            --i;--j;
        }
        return result;
    }
};

int main(){
Solution s;
cout<<s.addBinary("1100","1011");
}

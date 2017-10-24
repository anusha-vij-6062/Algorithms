class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carryIn=0;
        int sum=0;
        string s;
        
        while(i>-1||j>-1||carryIn){
            sum+=(i>=0?num1[i]-'0':0);
            sum+=(j>=0?num2[j]-'0':0);
            sum+=carryIn;
            carryIn=0;
            if(sum>9)
                carryIn=1;
            sum=sum%10;
            s=char(sum+'0')+s;
            i--;
            j--;
            sum=0;
        }
        return s;
    }
};

int main(){
Solution s;
s.addStrings("1764446489469","948654280294745428208465");
}

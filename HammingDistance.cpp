#define BITSIZE 32
class Solution {
public:
    
    string intToBinary(int x){
        string s;
        char rem;
        while(x>0){
            rem=x%2;
            cout<<rem;
            s = to_string(rem) + s;
            x=x/2;
        }
        return s;
    }
    
    string padding(string x){
        for(int i=x.size();i<BITSIZE;i++)
            x='0'+x;
        return x;
    }
    
    
    int hammingDistance(int x, int y) {
        int count=0;
        string sx=intToBinary(x);
        string sy=intToBinary(y);

        sx=padding(sx);
        sy=padding(sy);
    
        
        for(int i=0;i<BITSIZE;i++){
            if(sx.at(i)!=sy.at(i))
                count++;
        }
        return count;
        
    }
};

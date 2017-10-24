class Solution {
    char sum;
    char carry;
public:
    
    void getSum(char a,char b, char carryIn){
        switch(carryIn){
            case '0':
                if(a=='0'&& b=='0'){
                    this->sum='0';
                    this->carry='0';
                }
                else if(a=='0'&& b=='1'){
                    this->sum='1';
                    this->carry='0';
                }
                   else if(a=='1'&& b=='0'){
                    this->sum='1';
                    this->carry='0';
                }
                else{
                    this->sum='0';
                    this->carry='1';
                }
                break;
            case '1':
                if(a=='0'&& b=='0'){
                    this->sum='1';
                    this->carry='0';
                }
                else if(a=='0'&& b=='1'){
                    this->sum='0';
                    this->carry='1';
                }
                   else if(a=='1'&& b=='0'){
                    this->sum='0';
                    this->carry='1';
                }
                else{
                    this->sum='1';
                    this->carry='1';
                }
                break;
        }
    }
    
    
    
    
    string addBinary(string a, string b) {
        string ans;
        this->carry='0';
        int sizea=a.size()-1;
        int sizeb=b.size()-1;
        char carryIn='0';
        
        while(sizea>-1 || sizeb>-1){
            if(sizea>=0 && sizeb>=0){
            getSum(a.at(sizea),b.at(sizeb),carryIn);
            carryIn=this->carry;
            sizea--;
            sizeb--;
            ans=this->sum+ans;   
                cout<<"\n sum:"<<this->sum <<" \t carry"<<this->carry;
            }
            else if(sizea>=0 && sizeb<0){
            getSum(a.at(sizea),'0',carryIn);
            carryIn=this->carry;
            sizea--;
                ans=this->sum+ans; 
                cout<<"\n sum:"<<this->sum <<" \t carry"<<this->carry;
            }
            else{
            getSum('0',b.at(sizeb),carryIn);
            carryIn=this->carry;;
            sizeb--; 
            ans=this->sum+ans; 
                cout<<"\n sum:"<<this->sum <<" \t carry"<<this->carry;
            }
        }
        if(this->carry=='1')
        return this->carry+ans;
        else return ans;
    }
};

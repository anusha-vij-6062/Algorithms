class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>num;
        vector<int> index(2);
        int sum=target;
        vector<int>::iterator it=nums.begin();
        for(int i=0;it!=nums.end();it++){
            sum-=*it;
            if(num.find(sum)!=num.end()){
                index[0]=num.find(sum)->second;
                index[1]=i;
                return index;
            }
            num.insert(pair<int,int>(*it,i));
            i++;
            sum+=*it;
        }
        return index;  
    }
};

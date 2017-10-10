//#####Longest Substring Without Repeating Characters###

#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int maxLength=0;
        int tmp=0;
        int start=0;
        int end=1;
        int isUnique;
        if(s.size()==1)
            return 1;
        
        while(start!=s.size() && s.size()!=0){
            string substring=s.substr(start,end);
            isUnique=allUnique(substring);
            if(isUnique>=0){
                start+=1;
                end=1;
            }
            else{
                tmp=substring.size();
                if(tmp>maxLength)
                    maxLength=tmp;
                end++;
                if(start+end>s.size()){
                    break;
                }
            }
        }
        return maxLength;
    }
    
    int allUnique(string s){
        map <char, int> arr;
        for (int i=0;i<s.size();i++){
            char c=s.at(i);
            if(arr[c]==0){
                arr[c]=1;
                cout<<"\n No duplicates found! :)";
            }
            else{
                cout<<"\nFound duplicate at!" <<i;
                return i;
            }
        }
        return -1;
    }
};


class Test{
public:
    string testString;
    int expectedOutput;
    
    Test(string str,int length){
        testString=str;
        expectedOutput=length;
        
        
    }
    
};

int main(){
    Test t("abcabuyr",6);
    Solution s;
    if(t.expectedOutput==s.lengthOfLongestSubstring(t.testString))
        cout<<"Test Passed!";
    else{
        cout<<"Test Failed";
        cout<<"\n Expected Output is:"<<t.expectedOutput;
        cout<<"\n Got:"<<s.lengthOfLongestSubstring(t.testString);
    }
    
}




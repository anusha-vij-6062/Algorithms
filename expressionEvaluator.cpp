#include <iostream>
#include <queue>
#include<sstream>
#include <stdlib.h>
using namespace std;


int evaluate(string expression){
    queue<int> q1;
    queue<char>e1;
    bool first=true;
    int ans=0;
    int num1,num2;
    int startIndex=0;
    int currentIndex=0;

    while(currentIndex<expression.size()){
    if(expression.at(currentIndex)=='+' || expression.at(currentIndex)=='-'){
        char sign=expression.at(currentIndex);
        e1.push(sign);
        string substring=expression.substr(startIndex,currentIndex);
        int x;
        istringstream (substring) >> x;
        q1.push(x);
        startIndex=currentIndex+1;
    }
        ++currentIndex;
    }
    string substring=expression.substr(startIndex,currentIndex-1);
    int x;
    istringstream (substring) >> x;
    q1.push(x);

//   // case for + and -
//   // get the expression 

    while(!q1.empty()){
        char sign=e1.front();
        e1.pop();
        if(first){
            num1=q1.front();
            if(sign=='+')
                ans+=num1;
            else
                ans-=num1;
            q1.pop();
        }
        switch(sign){
            case '+':
                num2=q1.front();
                ans+=num2;
                q1.pop();
                break;
            case '-':
                num2=q1.front();
                ans-=num2;
                q1.pop();
                break;
        }
   }
    return ans;
}



// To execute C++, please define "int main()"
int main() {
    string expression = "6+90";
    cout<<evaluate(expression);


    return 0;
}


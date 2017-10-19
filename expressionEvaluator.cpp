// # You are building an educational website and want to create a simple calculator for students to use. For now, the calculator will only allow addition and subtraction of positive integers.

// # Given an expression string using the "+" and "-" operators like "5+16-2", write a function to parse the string and evaluate the result.

// # Sample input/output:
// # "6+9-12" => 3
// # "1+2-3+4-5+6-7" => -2

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
    int num;
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
    ans=q1.front();
    q1.pop();

    while(!q1.empty()){
        char sign=e1.front();
        e1.pop();
        switch(sign){
            case '+':
                num=q1.front();
                ans+=num;
                q1.pop();
                break;
            case '-':
                num=q1.front();
                ans-=num;
                q1.pop();
                break;
        }
   }
    return ans;
}
// To execute C++, please define "int main()"
int main() {
    string expression = "6+90-9+10+3";
    cout<<evaluate(expression);
    return 0;
}


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int* updateStep(char direction,int currPath[]){
    switch(direction){
        case 'N':
            currPath[1]++;
            break;
        case 'S':
            currPath[1]--;
            break;
        case 'E':
            currPath[0]++;
            break;
        case 'W':
            currPath[0]--;
            break;
    }
    return currPath;
}

char getNewDirection(char currentDir,char manuver){
    switch(currentDir){
        case 'N':
            if(manuver=='L')
                return 'W';
            else return 'E';
        case 'S':
            if(manuver=='L')
                return 'E';
            else return 'W';
        case 'E':
            if(manuver=='L')
                return 'N';
            else
                return 'S';
        case 'W':
            if(manuver=='L')
                return 'S';
            else
                return 'N';
    }
    cout<<"Didnt match anything!";
    return currentDir;
}
string isACircle(string command) {
    vector<vector<int>> path;
    int currentPath[2];
    currentPath[0] = 0;
    currentPath[1] = 0;
    vector<int> temp;
    temp.push_back(currentPath[0]);
    temp.push_back(currentPath[1]);

    int *cPath = currentPath;
    char currentDir = 'N';
    cout << "\n---------------------------------------------------";
    cout << "\nCommand:" << command << endl;
    cout << "Starting point is:(0,0) North";
    for (int i = 0; i < command.size(); i++) {
        switch (command.at(i)) {
            case 'G':
                cout << "\nCurrent Direction: " << currentDir;
                cPath = updateStep(currentDir, currentPath);
                cout << "\nUpdated step: (" << cPath[0] <<","<< cPath[1]<<")";
                temp[0] = cPath[0];
                temp[1] = cPath[1];
                path.push_back(temp);
                break;
            case 'R':
                currentDir = getNewDirection(currentDir, 'R');
                cout << "\nNew Direction: " << currentDir;
                break;
            case 'L':
                currentDir = getNewDirection(currentDir, 'L');
                cout << "\nNew Direction: " << currentDir;
                break;
        }
    }
    bool flag = false;
    bool goIn = true;
    if (path.size() == 0) {
        return "YES";
    }

    if (currentDir == 'N' && (((temp[0] - 0) * (temp[0] - 0)) + ((temp[1] - 0) * (temp[1] - 0))) > 0)
        return "NO";
    else
        return "YES";
}

vector <string> doesCircleExist(vector <string> commands) {
    vector <string> answer;
    string s;
    for(int i=0;i<commands.size();i++){
        answer.push_back(isACircle(commands[i]));
    }
    return answer;
}

int main()
{
    ifstream fout("/Users/Anushavijay/CLionProjects/practice/input.txt");
    vector <string> res;
    int commands_size = 0;
    string x;
    string commands_item;
    vector<string> commands;

    if(fout.is_open()) {
        getline(fout, x);
        commands_size = stoi(x);
        for(int i = 0; i < commands_size; i++) {
            getline(fout, commands_item);
            commands.push_back(commands_item);

        }

    }

    res = doesCircleExist(commands);
    cout<<"\n--------------------Final Answer--------------------------\n";
    for(int res_i = 0; res_i < res.size(); res_i++) {
        cout <<commands[res_i]<<" :"<< res[res_i] << endl;;
    }

    fout.close();
    return 0;
}



#include <iostream>
#include <vector>
#include <string>
using namespace std;
void paginate(vector<string>,int);

/*
 * Index 0: HostID
 * Index 1: ListingID
 * Index 2: Property Rating
 * Index 3: Location
 */

class Test{
    vector<string> results;
    int resultsPerPage;

public:Test(vector<string> results,int rpp){
        this->results=results;
        this->resultsPerPage=rpp;
    }

bool existsInList(int* arr,int val){
    for(int i=0;i<this->resultsPerPage;i++)
        if(arr[i]==val)
            return true;
    return false;

}

    void paginate(){
        vector<string> output;
        int* uniqueHosts;
        int uniqueHostsize=0;
        char delimiter = ',';
        string hostId;

        int i=0;
        cout<<"\nOrizinal size of results:"<<results.size();
        while(results.size()) {
            int* uniqueHosts=new int[5];
            uniqueHostsize=0;
            i=0;
            vector<string>::iterator it = results.begin();
            for (; it != results.end();) {
                cout << "\n i:" <<i;
                cout<<"\nCurrently:"<<*it;
                hostId = results[i].substr(0, results[i].find(delimiter));
                cout << "\nHostID:" << hostId;
                cout<<"\nExists in the list?"<<existsInList(uniqueHosts,stoi(hostId));
                if (uniqueHostsize < 5) {
                    if(!existsInList(uniqueHosts, stoi(hostId))){
                    uniqueHosts[uniqueHostsize] = stoi(hostId);
                    cout << "\nAdded:" << uniqueHosts[uniqueHostsize] << "at Position" << uniqueHostsize;
                    output.push_back(results[i]);
                    results.erase(it);
                    it--; i--;
                    uniqueHostsize++;
                    if (uniqueHostsize == 5) {
                        output.push_back("\"\"");
                        cout << "\nNew Size of results are:" << results.size();
                        cout<<"\nDeleteing space";
                        delete(uniqueHosts);
                        break;
                    }
                    }

                    else{
                        if(results.size()<5) {
                            int j=0;
                            vector<string>::iterator jt=results.begin();
                            uniqueHosts[uniqueHostsize] = stoi(results[j].substr(0, results[j].find(delimiter)));
                            cout << "\nAdded:" << uniqueHosts[uniqueHostsize] << "at Position" << uniqueHostsize;
                            output.push_back(results[j]);
                            results.erase(jt);
                            uniqueHostsize++;
                            cout << "\n Next up:" << *jt;
                            if (uniqueHostsize == 5) {
                                output.push_back("\"\"");
                                cout << "\nNew Size of results are:" << results.size();
                                cout << "\nDeleteing space";
                                delete (uniqueHosts);
                                break;
                            }
                            it--;
                            i--;
                        }
                    }
                }
                it++;
                i++;
            }
        }

        cout<<"\nFinal list!\n";
        for(int i=0;i<output.size();i++){
            cout<<"\n"<<output[i];
        }
    }

};

int main() {
    vector <string> results;
    //HostID,ListingID,Rating,Place
    results.push_back("2,29,300.7,SF"); //1
    results.push_back("5,5,209.2,SF");  //1
    results.push_back("21,7,203.5,Oak);      //1
    results.push_back("7,8,202.8,SF");   //1
    results.push_back("7,11,199.9,SF"); //2
    results.push_back("2,16,190.6,SF"); //2
    results.push_back("7,29,185.4,SF");
    results.push_back("8,22,180.0,Oak");       //1
    results.push_back("7,21,162.4,SF");
    results.push_back("3,18,161.7,SJ"); //2
    results.push_back("3,30,149.8,SJ");
    results.push_back("4,76,146.8,SF"); //2
    results.push_back("3,14,141.9,SF");
    int resultsPerPage=5;
    Test t(results,resultsPerPage);
    t.paginate();
    return 0;
}

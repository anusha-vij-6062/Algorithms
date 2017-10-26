/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<int> v;
        int importance=0;
        
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id==id){
                v.insert(v.end(),employees[i]->subordinates.begin(),employees[i]->subordinates.end());
                importance+=employees[i]->importance;
            }
        }
        
        for(int j=0;j<v.size();j++){
            int Id=v[j];
            cout<<"\nID->"<<Id;
            for(int i=0;i<employees.size();i++){
                if(employees[i]->id==Id){
                    v.insert(v.end(),employees[i]->subordinates.begin(),employees[i]->subordinates.end());
                    importance+=employees[i]->importance;
                    break;
            }
        }
            
        }
        
        return importance;
    }
};

using namespace std;
#include <map>
#include <vector>
#include <string>
#include <set>

class Record {
public:
    string name;
    string type;
    string value;
    string operation;
};

class Node {
public:
    Node* parent;
    vector<Node*> children;
    Record nodeName;
};


void setValues(int idx, map<int, int>& res, vector<vector<int>> adjacency_matrix) {
    if (res.count(idx) > 0) return;
    int val = 0;
    vector<int> children = adjacency_matrix[idx];
    for (int i = 0; i < children.size(); i++){
        if (children[i] != 1) continue; // no connection
        if (res.count(i) == 0){ // we don't have the child's value yet
            setValues(i, res, adjacency_matrix); // O(v) time since look up time is constant.
        }
        val += res[i];
    }
    res[idx] = val;
}

void print_res(map<string, int>& m){
     for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}
map<string, int> calcMeas(vector<Record> records) {
    map<int, int> res;
    // Construct name to index and index to name mapping
    map<string, int> nameToidx;
    map<int, string> idxToName;

    int idx = 0;
    for (int i = 0; i < records.size(); i++) {
        string name = records[i].name;
        if (nameToidx.count(name) > 0) continue;
        nameToidx[name] = idx;
        idxToName[idx] = name;
        idx += 1;
    }

    //Implement Adjacent Matrix Graph
    int n = nameToidx.size();
    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < records.size(); i++) {
        Record r = records[i];
        if (r.type == "M"){
            res[nameToidx[r.name]] = stoi(r.value);
            continue;
        }
        // type is combination
        int idxChild = nameToidx[r.value];
        int idxParent =nameToidx[r.name];
        adjacency_matrix[idxParent][idxChild] = 1;
    }

    for (int i = 0; i < n; i++){
        setValues(i, res, adjacency_matrix); // set all values of index and its children
    }

    //Takes the int to int map and converts it to the string to int map
    map<string, int> str_res;
    for (const auto& [key, value] : res) {
        str_res[idxToName[key]] = value;
    }
    return str_res;
}

int main() {
    // The following is the test case you gave me during the interview.
    // Note that the operations field is assumed to always be "+".
    Record m1;
    m1.name = "m1";
    m1.type = "M";
    m1.value = "1";
    m1.operation = "+";
    Record m2;
    m2.name = "m2";
    m2.type = "C";
    m2.value = "m1";
    m2.operation = "+";
    Record m22;
    m22.name = "m2";
    m22.type = "C";
    m22.value = "m3";
    m22.operation = "+";
    Record m222;
    m222.name = "m2";
    m222.type = "C";
    m222.value = "m4";
    m222.operation = "+";
    Record m3;
    m3.name = "m3";
    m3.type = "M";
    m3.value = "4";
    m3.operation = "+";
    Record m4;
    m4.name = "m4";
    m4.type = "C";
    m4.value = "m1";
    m4.operation = "+";

    vector<Record> r = {m1, m2, m22, m3, m222, m4};

    map<string, int> m = calcMeas(r);
    print_res(m);
}

// if in dic, constant time
// if not in dic, v^2 max

// The maximum amount of time for any verticies, is O(V)
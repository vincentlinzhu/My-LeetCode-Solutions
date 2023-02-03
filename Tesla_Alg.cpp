#include <iostream>
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

int getVal(Node n, map<string, int>& m) {
    int val = 0;
    for (Node* child : n.children) {
        if (child->nodeName.type == "M") { // if n's children are all M types
            val += stoi(child->nodeName.value);
        } else {
            int cTypeVal = 0;
            cTypeVal = getVal(*child, m);
            m.insert(pair<string, int>(child->nodeName.name, cTypeVal));
            val += cTypeVal;
        }
    }
    return val;
}

map<string, int> calcMeas(vector<Record> records) {
    //Implement Adjacent Matrix Graph
    set<string> recordNames;
    for (int i = 0; i < records.size(); i++) {
        recordNames.insert(records[i].name);
    }
    
    map<string, int> vertices;
    int indexCounter = 0;
    for (set<string>::iterator it = recordNames.begin(); it != recordNames.end(); it++) {
        vertices.insert(pair<string, int>(record.name, indexCounter));
        indexCounter++;
    }

    vector<vector<int>> measureGraph(recordNames.size(), vector<int>(recordNames.size(), 0)) ;
    for (int i = 0; i < records.size(); i++) {
        if (records[i].type == "C") {
            measureGraph[vertices.find(records[i].name)->second][vertices.find(records[i].value)->second] = 1;
        }
    }
    
//    map<string, Record> m;
//    for (int i = 0; i < records.size(); i++) {
//        m.insert(pair<string, Record>(records[i].name, records[i]));
//    }
//
//    map<string, Node> graph;
//    for (auto& record : records) {
//        Node* recordNode = new Node;
//        recordNode->nodeName = record;
//        map<string, Node>::iterator it = graph.find(record.name);
//        if (it != graph.end()) {
//            Node* childRecordNode = new Node;
//            childRecordNode->nodeName = m.find(recordNode->nodeName.value)->second;
//            it->second.children.push_back(childRecordNode);
//        } else {
//            Node* childRecordNode = new Node;
//            childRecordNode->nodeName = m.find(recordNode->nodeName.value)->second;
//            if (recordNode->nodeName.type == "C") {
//                recordNode->children.push_back(childRecordNode);
//            }
//            graph.insert(pair<string, Node>(record.name, *recordNode));
//        }
//    }

    map<string, int> res;
    // Populate Map with M type measurments: O(v) time where v is the number of measurements
    for (int i = 0; i < records.size(); i++) {
        if (records[i].type == "M") {
            res.insert(pair<string, int>(records[i].name, stoi(records[i].value)));
        }
    }
    
    map<int, string> m;
    for (int i = 0; i < measureGraph.size(); i++) {
        res.insert(pair<int, int>(i, getVal(it->second, res)));
    }

//    for (map<string, Node>::iterator it = graph.begin(); it != graph.end(); it++) {
//        if (res.find(it->first) == res.end()) {
//            res.insert(pair<string, int>(it->first, getVal(it->second, res)));
//        }
//    }

    return res;
}

int main() {
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
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

// if in dic, constant time
// if not in dic, v^2 max

// The maximum amount of time for any verticies, is O(V)

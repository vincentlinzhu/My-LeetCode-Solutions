#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <cmath>

int romanToInt(string s) {
    int result=0;
    map<int,string> m;
    m.insert(pair<int,string>(1,"I"));
    m.insert(pair<int,string>(4,"IV"));
    m.insert(pair<int,string>(5,"V"));
    m.insert(pair<int,string>(9,"IX"));
    m.insert(pair<int,string>(10,"X"));
    m.insert(pair<int,string>(40,"XL"));
    m.insert(pair<int,string>(50,"L"));
    m.insert(pair<int,string>(90,"XC"));
    m.insert(pair<int,string>(100,"C"));
    m.insert(pair<int,string>(400,"CD"));
    m.insert(pair<int,string>(500,"D"));
    m.insert(pair<int,string>(900,"CM"));
    m.insert(pair<int,string>(1000,"M"));

    map<int,string>::iterator it;
    for (int i=0;i<s.length();i++){
        if (((s.substr(i,1).compare("I")==0)&&(s.substr(i+1,1).compare("V")==0)) || ((s.substr(i,1).compare("I")==0)&&(s.substr(i+1,1).compare("X")==0))){
            for(it=m.begin(); it!=m.end(); it++){
                string s1=s.substr(i,2);
                string s3=it->second;
                int comp=s1.compare(s3);
                if (comp==0){
                    result+=it->first;
                }
            }
            i++;
        }
        else if (((s.substr(i,1).compare("X")==0)&&(s.substr(i+1,1).compare("L")==0)) || ((s.substr(i,1).compare("X")==0)&&(s.substr(i+1,1).compare("C")==0))){
            for(it=m.begin(); it!=m.end(); it++){
                string s1=s.substr(i,2);
                string s3=it->second;
                int comp=s1.compare(s3);
                if (comp==0){
                    result+=it->first;
                }
            }
            i++;
        }
        else if (((s.substr(i,1).compare("C")==0)&&(s.substr(i+1,1).compare("D")==0)) || ((s.substr(i,1).compare("C")==0)&&(s.substr(i+1,1).compare("M")==0))){
            for(it=m.begin(); it!=m.end(); it++){
                string s1=s.substr(i,2);
                string s3=it->second;
                int comp=s1.compare(s3);
                if (comp==0){
                    result+=it->first;
                }
            }
            i++;
        }
        else{
            for(it=m.begin(); it!=m.end(); it++){
                string s2=s.substr(i,1);
                if (s2.compare(it->second)==0){
                    result+=it->first;
                }
            }
        }
    }
    return result;
}

int main(){
    
    return 0;
}

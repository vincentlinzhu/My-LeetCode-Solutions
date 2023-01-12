string convert(string s, int numRows) {
    if (numRows <= 1) {
        return s;
    }

    int row = 0;
    bool down = true;
    vector<string> v(numRows);
    
    for(int i = 0; i < numRows; i++){
        v.at(i) = "";
    }

    
    for(int i = 0; i < s.size(); i++){
        v.at(row) += s[i];
        if(row == 0){
            down = true;
        }
        if(row == numRows - 1){
            down = false;
        }
        down ? row++ : row--;
    }

    string answer = "";
    for(int i = 0; i < numRows; i++){
        answer += v.at(i);
    }
    return answer;
}
void print(vector<int> v){
    vector<int>::iterator iter;
    if (v.size() == 0) return;
    for(iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    return;
}
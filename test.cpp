#include<bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
{
    return (a.second < b.second);
}

string extractString(string str){
    int pos = str.find(':');
    return str.substr(0,pos+1);
}
int extractIntegerWords(string str)
{
    stringstream ss;
    ss << str;
    string temp,name;
    int found;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found)
            return found;
        else

        temp = "";
    }
    return -1;
}

int main(){
    string ipfilename("ip3.txt");
    string opfilename("ip3_op.txt");
    vector<pair<string,int>> values;
    string line;

    ifstream input_file(ipfilename);
    ofstream outdata(opfilename);
    getline(input_file, line);
    int no_of_emp=extractIntegerWords(line);

    getline(input_file, line);
    getline(input_file, line);
    getline(input_file, line);
    while (getline(input_file, line)){

        int val=extractIntegerWords(line);
        string name=extractString(line);
        values.push_back(make_pair(name,val));
    }

    sort(values.begin(), values.end(), sortbysec);

    int min_diff = values[values.size()-1].second;
    int min_index = 0;
    for(int i=0;i<values.size()-no_of_emp+1;i++){
            int diff = values[no_of_emp+i-1].second-values[i].second;
            if(diff<=min_diff){
                    min_diff = diff;
                    min_index = i;
            }
    }

    outdata<<"The goodies selected for distribution are:"<<endl<<endl;
    for(int i=min_index;i<min_index+no_of_emp;i++){
        outdata<<values[i].first<<" "<<values[i].second<<endl;
    }
    outdata<<endl<<"And the difference between the chosen goodie with highest price and the lowest price is "<<min_diff<<endl;

    outdata.close();
    input_file.close();

    return 0;
}

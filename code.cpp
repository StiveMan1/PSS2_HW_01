#include <bits/stdc++.h>

using namespace std;
string line;
int a;
bool isInWord(char arc){
    return arc != '.' && arc != ',' && arc != ' ';
}
bool isDot(char arc){
    return arc == '.';
}
char toLower(char arc){
    if(arc >= 'A' && arc <= 'Z'){
        return char(int(arc) - int('A') + int('a'));
    }
    return arc;
}
char toUpper(char arc){
    if(arc >= 'a' && arc <= 'z'){
        return char(int(arc) - int('a') + int('A'));
    }
    return arc;
}
vector<string> Text;
map<string,vector<int>> M;
int main() {
    getline(cin,line);
    a = line.size();
    string sentence = "";
    int s_count = 0;
    for(int i=0;i<a;i++){
        string arc = "";
        while(i < a && isInWord(line[i])){
            sentence += line[i];
            arc += toLower(line[i]);
            i++;
        }
        if(arc.size() >0){
            if(M[arc].size() == 0 || M[arc][M[arc].size()-1] != s_count){
                M[arc].push_back(s_count);
            }
        }
        sentence += line[i];
        if(i < a && isDot(line[i])){
            Text.push_back(sentence);
            // cout<<sentence<<endl;
            sentence="";
            i++;
            s_count++;
        }

    }
    cin>>a;
    while(a--){

        cin>>sentence;
        line = "";
        for(int i=0;i<sentence.size();i++){
            line += toLower(sentence[i]);
        }
        cout<<M[line].size()<<endl;
        for(auto arc : M[line]){
            string lol = Text[arc];
            for(int i=0;i<lol.size();i++){
                string arc = "" , lower = "" , upper = "";
                while(i < lol.size() && isInWord(lol[i])){
                    arc += lol[i];
                    lower += toLower(lol[i]);
                    upper += toUpper(lol[i]);
                    i++;
                }
                if(arc.size() >0 && lower == line){
                    cout<<upper;
                }else{
                    cout<<arc;
                }
                if(i < lol.size())
                    cout<<lol[i];
            }
            cout<<endl;
        }
    }
}

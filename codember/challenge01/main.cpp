#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    string line;
    ifstream myfile ("data.txt");
    map<string, string> user;
    string last_user = "";
    int valid_users = 0;
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            if (line != "") {
                char *token_line = strtok((char *)line.c_str(), " ");
                while (token_line != NULL) {
                    size_t found = ((string) token_line).find(":");
                    string key = ((string) token_line).substr(0,found);
                    string val = ((string) token_line).substr(found+1);
                    // insert in map
                    user.insert({key,val});
                    token_line = strtok(NULL, " ");
                }                
            }
            else {
                if (user.count("usr") + user.count("eme") + user.count("psw") + user.count("age") + user.count("loc") + user.count("fll") == 6) {
                    last_user = user["usr"];
                    valid_users++;
                }
                user.clear();
            }
        }
        myfile.close();
        cout << valid_users << last_user  << endl;
    }
    else cout << "Unable to open file" << endl;
}
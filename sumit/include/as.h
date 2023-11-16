#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
class papa{
    public:
    void subku(){
    
    ifstream inputFile("/Users/sumit/Desktop/sumit/data/trainerallotment.csv"); // Replace with your CSV file name.

    if (!inputFile.is_open()) {
        cerr << "Failed to open the CSV file." << endl;
        return;
    }

    string idToSearch;
    cout << "Enter the Batch ID you want to search: ";
    cin >> idToSearch;

    string line;
    bool found = false;
    while (getline(inputFile, line)) {
        vector<string> fields = split(line, ' '); // Assuming space as the delimiter in your CSV.

        if (fields.size() >= 9) { // Make sure there are enough fields to avoid access violations.
            string id = fields[0];

            if (id == idToSearch) {
                found = true;
                string language = fields[1];
                string startDate = fields[2];
                string endDate = fields[3];
                string duration = fields[4];
                string location = fields[5];
                string day = fields[6];
                string month = fields[7];
                string name = fields[8];

               cout << "\n=======================================" << endl;
                cout << "ID: " << id << endl;
                cout << "Language: " << language << endl;
                cout << "Start Date: " << startDate << endl;
                cout << "End Date: " << endDate << endl;
                cout << "Duration: " << duration << " days" << endl;
                cout << "Location: " << location << endl;
                cout << "Starting Date: " << day << " " << month << endl;
                cout << "Faculty Name: " << name << "Sir"<<endl;
                cout << "\n===================================" << endl;
                // No need to continue searching after finding the record.
                cout<<"1.Search for another Batch                    2.You Want to Exit  "<<endl;
                int a;
                cin>>a;
                if(a==1){
                    subku();
                    break;
                }
                else{
                    cout<<"See You Again"<<endl;
                }
            }
        }
    }

    if (!found) {
        cout << "ID not found in the CSV file." << endl;
           cout<<"1.Search for another Batch                    2.You Want to Exit  "<<endl;
                int a;
                cin>>a;
                if(a==1){
                    subku();
                }
                else{
                    cout<<"See You Again"<<endl;
                }
    }

    inputFile.close();

    return ;
}
};
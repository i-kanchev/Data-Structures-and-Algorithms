// https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/challenge-3770

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N;
    cin >> N;

    map<string, vector<string>> directories;

    directories.insert({ "/", {} });

    string currDir = "/";

    for (size_t i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if (command == "ls")
        {
            for (string dir : directories.at(currDir))
                cout << dir << ' ';
            cout << '\n';
        }
        else if (command == "pwd")
        {
            cout << currDir << '\n';
        }
        else if (command == "mkdir")
        {
            string dirName;
            cin >> dirName;

            string dirPath = currDir + dirName + "/";

            if (directories.count(dirPath))
                cout << "Directory already exists\n";

            else
            {
                directories.insert({ dirPath, {} });

                directories.at(currDir).push_back(dirName);
                sort(directories.at(currDir).begin(), directories.at(currDir).end());
            }
        }

        else if (command == "cd")
        {
            string dirName;
            cin >> dirName;

            if (dirName == "..")
            {
                if (currDir == "/")
                    cout << "No such directory\n";
                else
                {
                    unsigned pos = currDir.find_last_of('/', currDir.length() - 2);
                    
                    currDir = currDir.substr(0, pos + 1);
                }
            }
            else
            {
                string dirPath = currDir + dirName + "/";
                
                if (!directories.count(dirPath))
                    cout << "No such directory\n";

                else
                    currDir = dirPath;
            }
        }
    }

    return 0;
}
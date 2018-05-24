#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include <vector>

using namespace std;

void lowerCase(string &input)
{
    for (string::iterator it = input.begin(); it != input.end(); ++ it)
        *it = tolower((unsigned char)*it);

}


map <string,int> pathNr;

map <string,string> pathUpper;

vector<string> exclude;

int main()

{
    ifstream git("gitignore.in");
    ifstream previous("previous.in");
    ifstream current("current.in");
    ofstream added("added.out");
    ofstream modified("modified.out");
    ofstream deleted("deleted.out");

    string temp;

    while(git >> temp)
    {
        lowerCase(temp);
        exclude.push_back(temp);

    }

    while(previous >> temp)

    {

        int nr;
        previous >> nr;
        string convert = temp;
        lowerCase(convert);

        int ok = 0;

        for(auto it = exclude.begin(); it != exclude.end(); it++)
        {
            if(convert.find(*it) != string::npos)
            {
                ok = 1;
            }

        }
        if(ok == 0)
        {
            pathNr[convert] = nr;
            pathUpper[convert] = temp;
        }



    }

    while(current >> temp)

    {
        int nr;

        current >> nr;
        string convert = temp;
        lowerCase(convert);

        int ok = 0;

        for(auto it = exclude.begin(); it != exclude.end(); it++)
        {
            if(convert.find(*it)!= string::npos)
            {
                ok = 1;
            }

        }

        if(ok == 0)
        {



            if(pathNr.find(convert) != pathNr.end())
            {
                if( pathNr[convert] != nr)
                {
                    modified << temp<<endl;
                }
                pathNr.erase(convert);
            }
            else
                added << temp<<endl;

        }
    }

    while(!pathNr.empty())
    {
        auto it = pathNr.begin()->first;
        deleted << pathUpper[it]<<endl;
        pathNr.erase(pathNr.begin());
    }

    return 0;

}

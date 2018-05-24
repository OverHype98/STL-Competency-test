#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;

void lowerCase(string &input)
{
    for (string::iterator it = input.begin(); it != input.end(); ++ it)
        *it = tolower((unsigned char)*it);

}


map <string,int> pathNr;

map <string,string> pathUpper;

int main()

{

    ifstream previous("previous.in");
    ifstream current("current.in");
    ofstream added("added.out");
    ofstream modified("modified.out");
    ofstream deleted("deleted.out");

    string temp;

    while(previous >> temp)

    {

        int nr;
        previous >> nr;
        string convert = temp;
        lowerCase(convert);
        pathNr[convert] = nr;
        pathUpper[convert] = temp;

    }



    while(current >> temp)

    {
        int nr;

        current >> nr;
        string convert = temp;
        lowerCase(convert);
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

    while(!pathNr.empty())
    {
        auto it = pathNr.begin()->first;
        deleted << pathUpper[it]<<endl;
        pathNr.erase(pathNr.begin());
    }

    return 0;

}

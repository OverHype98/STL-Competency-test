#include<bits/stdc++.h>

using namespace std;


map<string,vector<int>> TaskDuration;
map<string,int> LoadedTasks;
map<string,int> TaskFinalDuration;
map<string,int> nrTasks;



int main()
{
    ifstream read("input.txt");
    int n,temp;
    string task,task1;

    read>>n;

    for(int i = 0; i < n; i++)
    {
        read>>temp;
        read>>task;
        read>>temp;
        TaskDuration[task].push_back(temp);
    }



    read>>n;

    for(int i = 0; i < n; i++)
    {
        read>>temp;
        read>>task;
        LoadedTasks[task]++;
    }



    for(auto it = TaskDuration.begin(); it != TaskDuration.end(); it++)
    {
        double count = 0,sum = 0;
        for(auto j = it->second.begin(); j != it->second.end(); j++)
        {
            count++;
            sum+=*j;
        }
        sum/=count;
        TaskFinalDuration[it->first] = sum;
    }

    while(read>>task)
    {
        nrTasks[task]++;
    }


    int output = 0;

    for(auto it : LoadedTasks)
    {
        double nr = 0;

        nr =  1.0*it.second/nrTasks[it.first];
        nr =ceil(nr);
        output+=nr*TaskFinalDuration[it.first];


    }

    cout<<output;



    return 0;
}

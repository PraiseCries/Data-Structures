//Ahmad Zeyad Badwan, U18102159

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

//Asks the user for number of Processes.
int Npross;
cout << "Enter number of Processes (less than 10) : ";
cin >> Npross;
cout << endl;

//Creates a 2D array and asks the user to fill each process with a burst time and priority.
int prioList[Npross][2];
cout << "Enter Burst time and Priority:" << endl;
cout << endl;

for (int i = 0; i<Npross; i++)
{
    cout << "P[" << i+1 << "]" << endl;

    cout << "Burst time:";
    cin >> prioList[i][0];

    cout << "Priority:";
    cin >> prioList[i][1];

    cout << endl;
}

cout << "Process" <<setw(13)<< "Burst Time" << setw(23) << "Waiting Time" << setw(23) << "Turnaround Time" << endl;

//Organizes the array of processes in ascending order according to their priority number
//to help calculate the waiting time and the turnaround time.
int temp;
for (int k = 0; k<Npross; k++)
{
    for (int q = k+1; q < Npross; q++)
    {
        if(prioList[k][1] > prioList[q][1])
        {
            temp = prioList[k][0];
            prioList[k][0] = prioList[q][0];
            prioList[q][0] = temp;

            temp = prioList[k][1];
            prioList[k][1] = prioList[q][1];
            prioList[q][1] = temp;
        }
    }
}

//Prints all processes in order according to their priority number while calculating both their
//waiting time and turnaround time.
int time = 0;
int tTime = prioList[0][0];
for (int i = 0; i<Npross; i++)
{

    cout << "P[" << i+1 << "]" << setw(13) << prioList[i][0] << setw(19) << time << setw(24) << tTime << endl;

    time += prioList[i][0];
    tTime += prioList[i+1][0];
}

return 0;
}



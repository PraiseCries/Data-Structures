//Ahmad Zeyad Badwan, U18102159

#include <iostream>

using namespace std;

int main(){

//Here I defined the given reference string into an array, number of frames, number of faults and hits.
//The variables count and test help me out with the FIFO algorithm later in the code.
int refString[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
int frames, hit;
int faults = 0;
int count = 0;
bool test;

//Show the user the reference string
cout << "The reference string is: [ ";
for(int i=0; i<12; i++)
{
    cout << refString[i] << " ";
}
cout << "]" << endl;

//Ask the user for the number of frames and put it into an array called ladder
cout << "Enter Total Number of Frames:  ";
cin >> frames;

int ladder[frames];

//initialize the ladder array with the number -1
for(int j=0; j<frames; j++)
{
    ladder[j] = -1;
}

//The first loop goes through the reference string while the second
for(int i=0; i<12; i++)
{
    //Second loop compares the current number from the string with the 'ladder' array.
    for(int j=0; j<frames; j++)
    {
        //If it finds that the number exists it breaks from the checking loop
        if(refString[i] == ladder[j])
        {
            test = true;
            break;
        }
        //else it continues, in which case if it finds no equal number in the 'ladder'
        else
            test = false;
    }
    //If the current reference string number is already on the 'ladder' nothing happens
    if(test == true)
        hit++;
    //Else it changes one of the 'ladder' numbers with the new number.
    else
    {
        //The function depends on the 'count' variable to determine which number needs to be switched
        //And since its a FIFO algorithm, simply incrementing the 'count' variable till it reaches the max was more than sufficient.
        //Finally, I increment the 'faults' variable to keep count of it for the user.
        ladder[count] = refString[i];
        count++;
        faults++;
        if(count == frames)
            count = 0;
    }
    //Before the main loop above repeats, this loop prints the current 'ladder' in a neat way
    for(int k=0; k<frames; k++)
    {
        cout << "        "<< ladder[k];
    }
    cout << endl;
}

//This simply prints how many faults occurred by the end of the algorithm
cout << endl;
cout << "Total Page Faults:        " << faults;

return 0;
}

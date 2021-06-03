#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    ifstream file("sampledata.txt");

    string data;

    // As array is used to store burst times
    // so to allocate memory to an array
    // maximum size is needed
    // So assuming 1000 is the maximum cpu burst
    // times or io burst times are there in data
    int cpu[1000];
    int io[1000];

    // In order to avoid this assumption
    // vector can be used to store burst times
    // No size is required to declare and use a vector

    // Use a while loop together with the getline() function to read the file line by line
    getline(file,data);
    while (getline (file, data)) {
      // Output the text from the file
        int l = data.length();

        // Indexes for two arrays
        // cpu burst time array and io burst
        // time array
        int cpu_in = 0;
        int io_in = 0;

        // Extracting words one by one from the string
        string word="";


        for(int i=0;i<l;i++)
        {
           // if the space character is found that means a complete word
           // has been extracted from the string
            if(data[i]==' ')
            {
                if(word[0]=='-')
                {
                    // Multiplying by -1 to remove
                    // the negative sign
                    io[io_in] = stoi(word)*-1;
                    io_in++;
                }
                else
                {
                    cpu[cpu_in] = stoi(word);
                    cpu_in++;
                }
                word = "";
            }
           // continue to add characters to the word
            else
            {
                word = word + data[i];
            }
        }

       // Checking for the last word extracted
    //   if starts with '-' then it is an i/o
    // burst time else cpu burst time
        if(word[0]=='-')
        {
            io[io_in] = stoi(word)*-1;
            io_in++;
        }
        else
        {
            cpu[cpu_in] = stoi(word);
            cpu_in++;
        }

        // Print burst times of the process
        cout<<"CPU burst time: ";
        for(int i=0;i<cpu_in;i++)
        cout<<cpu[i]<<" ";

        cout<<"\n";

        cout<<"I/O burst time: ";
        for(int i=0;i<io_in;i++)
        cout<<io[i]<<" ";

        cout<<"\n";
    }

    // Close the file
    file.close();

    return 0;
}

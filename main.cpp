#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    // declare arrays
    string state [1000];
    double cost[1000];
    int count=0;
    
    //read the file
    ifstream fileIn ("packages.txt");
    if (fileIn)
    {
        while (!fileIn.eof())// keep reading as long as not at the end
        {
            fileIn >> state[count];
            fileIn >> cost[count];
            count++;
        }
    }
    // closes out the file
    fileIn.close();
    //save the file
    
    while (true)
    {
        // menu for user to choose from
        cout << "====================================" << endl;
        cout << "Welcome to Fedex in the middle of nowhere. :-)" << endl;
        cout << "This tool will help you keep track of packages" << endl;
        cout << "====================================" << endl;
        cout << "1- Create New Mail" << endl;
        cout << "2- Search Mail (by State)" << endl;
        cout << "3- Search Mail (by Cost)" << endl;
        cout << "4- Grand Report" << endl;
        cout << "0 - Exit" << endl;
        
        
        int choice;
        cout << "What do you want to do?" << endl;
        cin >> choice;
        
        if (choice ==1)
        {
            string st;
            double stc=0.0;
    
            cout << "Destination State <two letter, no space): ";
            cin >> st;
            
            state[count]=st;
            
            cout << "Cost of this delivery? ";
            cin>> stc;
            cost[count]=stc;
            
            count ++;
        }
        else if (choice == 2)
        {
            string st;

            cout << "Enter state you want to see < two letter, no space>: ";
            cin >> st;
            // when youre moving thru the array always start i @ 0
            for (int i=0; i <count; i++)
            {
                if (state[i]== st)
                {
                    cout << "Here are the packages to: " << state[i] << endl ;
                    cout << "Package to " << state[i] << " for " << cost[i] << endl;
                }
            }
        }
        else if (choice ==3)
        {
            double min=0;
            cout << "Enter minimum package price: ";
            cin >> min;
            
            // casting the int as a double here
            // any other data type that is a number
            cout << "Here are the packages that are larger in value than " << min << ":" << endl;
            
            for( int i=0; i<count; i++)
            {
                if (min < cost[i])
                {
                    cout << "Package to " << state[i] << " for $" << cost[i] << endl;
                }
            }
            
        }
        
        else if (choice ==4)
        {
            double total=0;
            cout << "Here are all the packages for today" << endl;
            for (int i=0; i<count; i++)
            {
                cout << "Package to " << state[i] << " for $" << cost[i] << endl;
                total += cost[i];
            }
            
            cout << "Total cost for all packages today so far is $" << total << endl;
        }
        else if (choice == 0)
        {
            break;
        }
    }
    // ofstream should be at the end of the file bc thats when its going to read the data into txt file?
    // thats when u finally have the arrays built
    ofstream fileOut("packages.txt");
    for (int i=0; i<count; i++)
    {
        // go thru each package
        // add endl so that second package goes to the next line
        fileOut <<  state[i] << " "  << cost[i];
        // so that you dont put out an endline at the end of your data
        // if you do that ull have new line at the end of data and the array will read that and you will have garbage values
        if (i < count -1)
        {
            fileOut << endl;
        }
    }
    // closes out the file
    fileOut.close();
    
    system ("PAUSE");
    return 0;
    
}

#include <iostream>
#include <iomanip> //setw; left; right

using namespace std;

const int MAX_ARR_SIZE = 5;

//prototypes
int displayMenu(string[], int[], int);
int getMin(const int[], int );
int getMax(const int[], int );
void displayArray1(const int[], const string[], int); //FOR INT ARRAYS
void calculateTotalCost(const int[], int[], int[], int);
void displayMaxJarsSold(int[], int, int);
void displayMinJarsSold(int[], int, int);


//void displayArray2(string int[], int); FOR STRING ARRAYS

int main()
{
    //Initialize arrays
    string salsaTypes[MAX_ARR_SIZE] = {"MILD","MEDIUM","SWEET","HOT","ZESTY"};
    int jarsSold[MAX_ARR_SIZE] = {0,0,0,0,0};
    int totalCost[MAX_ARR_SIZE] = {0,0,0,0,0};
    const int prices[MAX_ARR_SIZE] = {1,2,5,7,4};

    //initialize variables
    int choice;
    int maxJarsSold;
    int minJarsSold;

    //Begin program
    do
    {
    choice = displayMenu(salsaTypes, jarsSold, MAX_ARR_SIZE);
    switch(choice)
    {
    case 1:
        calculateTotalCost(prices, jarsSold, totalCost, MAX_ARR_SIZE);
        displayArray1(totalCost, salsaTypes, MAX_ARR_SIZE);
        break;
    case 2:
        maxJarsSold = getMax(jarsSold, MAX_ARR_SIZE);
        displayMaxJarsSold(jarsSold, maxJarsSold, MAX_ARR_SIZE);
        break;
    case 3:
        minJarsSold = getMin(jarsSold, MAX_ARR_SIZE);
        displayMinJarsSold(jarsSold, minJarsSold, MAX_ARR_SIZE);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        cout << "Something went wrong. Please consult the manager." << endl;
        cout << "Exiting..." << endl;
        break;
    }
    }while(choice != 7); //continue running until choice is 7: Exit


    //say goodbye
    cout << "Thank you for using Team Tostitos Salsa Program." << endl;
    cout << "Goodbye." << endl;

    return 0;
}

int displayMenu(string arr1[], int arr2[], int arrSize)
{
    //arr1 is for string types
    //arr2 is for integer types

    cout << "Welcome to Team Tostitos Chip and Salsa POS Program" << endl;
    int num = 0;

    int choice = 2;

    do
    {
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Would you like to buy some (more) salsa? (Enter 1 or 2)\n";
        cin >> choice;
    }while(cin.fail() || choice > 2 || choice < 1);

    if (choice == 1) //only ask for salsa if the user wants more
    {
        //asks user for number of jars they want for each
        for (int i = 0; i<arrSize;i++)
        {
            do
            {
                cout << "How many " << arr1[i] << " jars would you like to buy?\n";
                cin.clear();
                cin.sync();
                cin >> num;
                arr2[i] = num;
            }while(cin.fail());

        }
        cout << "\n" << endl;
    }

    //displays jars bought
    for (int i = 0; i< arrSize; i++)
    {
        cout << "# of jars for " << arr1[i] << " Salsa: " << arr2[i] << endl;
    }

    cout << "\n" << endl;

    //Prompt user for a choice
    do //repeat until the conditions are met
    {
        cout << "Please select one of the following: " << endl;
        //Options
        cout << "1. Display all salsa sales" << endl;
        cout << "2. Display the best-selling salsa (in # of Jars sold)" << endl; //MAXIMUM for JarsSold
        cout << "3.displayArray1 Display the worst-selling salsa (in # of Jars sold)" << endl; //MAXIMUM for JarsSold
        cout << "4. Display the most profitable salsa (in $)" << endl; //MAXIMUM for total cost
        cout << "5. Display the least profitable salsa (in $)" << endl; //MINIMUM for total cost
        cout << "6. Collect new salsa data" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter: ";
        cin.clear();
        cin.sync();
        cin >> choice;
    }while(cin.fail() || choice > 7 || choice < 1);

    cout << "Your choice: " << choice << endl;
    return choice;

}
int getMin(const int arr[], int arrSize)
{
    int myMin = arr[0];

    for (int i=1; i< arrSize; i++)
    {
        if (arr[i] < myMin)
            myMin = arr[i];
    }

    return myMin;
}

int getMax(const int arr[], int arrSize)
{
    int myMax = arr[0];

    for (int i=1; i< arrSize; i++)
    {
        if (arr[i] > myMax)
            myMax = arr[i];
    }

    return myMax;
}
void displayArray1(const int arr[], const string arr2[], int arrSize)
{
    //arr[2] = 1000;
    for (int i=0; i<arrSize; i++)
        cout << "Sales for # of " << arr2[i] << " salsa jars sold (in $): " << arr[i] << endl;

    cout << "\n\n" << endl;
}
void calculateTotalCost(const int arr1[], int arr2[], int arr3[], int arrSize)//change the address of values outside of itself; calculates total cost
{
    for(int i = 0; i<arrSize; i++)
    {
        arr3[i] = arr1[i] * static_cast<double>(arr2[i]);
    }
}
void displayMaxJarsSold(int arr[], int maxJars, int arrSize)
{
    if(arr[0] == maxJars)
    {
        cout << "The most amount of jars sold was MILD, which sold "
             << maxJars << " jar(s)."
             << endl;
    }
    else if (arr[1] == maxJars)
    {
        cout << "The most amount of jars sold was MEDIUM, which sold "
             << maxJars << " jar(s)."
             << endl;
    }
    else if (arr[2] == maxJars)
    {
        cout << "The most amount of jars sold was SWEET, which sold "
             << maxJars << " jar(s)."
             << endl;
    }
    else if (arr[3] == maxJars)
    {
        cout << "The most amount of jars sold was HOT, which sold "
             << maxJars << " jar(s)."
             << endl;
    }
    else if (arr[4] == maxJars)
    {
        cout << "The most amount of jars sold was ZESTY, which sold "
             << maxJars << " jar(s)."
             << endl;
    }
    else
    {
        cout << "Something went wrong. Please consult management." << endl;
        cout << "Exiting..." << endl;
    }

}
void displayMinJarsSold(int arr[], int minJars, int arrSize)
{
    if(arr[0] == minJars)
    {
        cout << "The least amount of jars sold was MILD, which sold "
             << minJars << " jar(s)."
             << endl;
    }
    else if (arr[1] == minJars)
    {
        cout << "The least amount of jars sold was MEDIUM, which sold "
             << minJars << " jar(s)."
             << endl;
    }
    else if (arr[2] == minJars)
    {
        cout << "The least amount of jars sold was SWEET, which sold "
             << minJars << " jar(s)."
             << endl;
    }
    else if (arr[3] == minJars)
    {
        cout << "The least amount of jars sold was HOT, which sold "
             << minJars << " jar(s)."
             << endl;
    }
    else if (arr[4] == minJars)
    {
        cout << "The least amount of jars sold was ZESTY, which sold "
             << minJars << " jar(s)."
             << endl;
    }
    else
    {
        cout << "Something went wrong. Please consult management." << endl;
        cout << "Exiting..." << endl;
    }
}

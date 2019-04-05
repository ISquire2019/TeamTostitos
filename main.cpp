/*
Programmers:

Team: Tostitos

Members:
Duke Ellington
Pedro Benegas
Isaiah Sule

Date: 4-1-2019 to 4-5-2019

Description: This program will ask the user if they want to buy our salsa and then allow the user to display the results of their purchase in numerous ways
             such as which salsa was the most profitable, or which salsa didn't have the most sales, or if they even bought any salsa. It will repeat this process until the
             user decides to EXIT the program, to which the sale will end.

             Enjoy our wonderful salsa with Tostitos chips! Thank you.
*/
#include <iostream>
#include <iomanip> //setw; left; right

using namespace std;

const int MAX_ARR_SIZE = 5; //stores maximum array size

//prototypes
int displayMenu(string[], int[], int);
int getMin(const int[], int );
int getMax(const int[], int );
void displayRec(const string[], const int[], const int[], int);
void calculateTotalCost(const int[], int[], int[], int);
void displayMaxJarsSold(int[], int, int);
void displayMinJarsSold(int[], int, int);
void displayMostProfitableSalsa(int[], int, int);
void displayLeastProfitableSalsa(int[], int, int);
void resetArrays(int[], int[], int);


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
    int maxProfitable;
    int minProfitable;

    //Begin program
    do
    {
    choice = displayMenu(salsaTypes, jarsSold, MAX_ARR_SIZE);
    switch(choice)
    {
    case 1: //display record of all arrays
        calculateTotalCost(prices, jarsSold, totalCost, MAX_ARR_SIZE);
        displayRec(salsaTypes, jarsSold, totalCost, MAX_ARR_SIZE);
        break;
    case 2: //determine best-selling salsa (by # of jars)
        maxJarsSold = getMax(jarsSold, MAX_ARR_SIZE);
        displayMaxJarsSold(jarsSold, maxJarsSold, MAX_ARR_SIZE);
        break;
    case 3: //determine least-selling salsa (by # of jars)
        minJarsSold = getMin(jarsSold, MAX_ARR_SIZE);
        displayMinJarsSold(jarsSold, minJarsSold, MAX_ARR_SIZE);
        break;
    case 4: //display the most profitable salsa (in $)
        calculateTotalCost(prices, jarsSold, totalCost, MAX_ARR_SIZE);
        maxProfitable = getMax(totalCost,MAX_ARR_SIZE);
        displayMostProfitableSalsa(totalCost, MAX_ARR_SIZE, maxProfitable);
        break;
    case 5: //display the least profitable salsa (in $)
        calculateTotalCost(prices, jarsSold, totalCost, MAX_ARR_SIZE);
        minProfitable = getMin(totalCost,MAX_ARR_SIZE);
        displayLeastProfitableSalsa(totalCost, MAX_ARR_SIZE, minProfitable);
        break;
    case 6: //clear all data, allowing new data to be inputted; simply reset the array values to zero
        resetArrays(jarsSold, totalCost, MAX_ARR_SIZE);
        break;
    case 7: //does nothing, skips to the end of the loop, since the answer is 7, which is EXIT, break loop
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
void resetArrays(int arr1[], int arr2[], int arrSize)
{
    /*
    Function: resetArrays
    Programmer: Isaiah Sule
    Date: 4/5/19
    Parameters: arr1[], arr2[], arrSize
    Description: It simply resets all values from both jarsSold and totalCost to zero, allowing for new data to be inputted.
    */
    for (int i = 0; i<arrSize; i++)
    {
        arr1[i] = 0;
        arr2[i] = 0;
    }
    cout << "<<<<DATA CLEARED>>>>" << endl;
    cout << "Ready to collect new data." << endl;
    cout << "Continuing program..." << endl;
}
void displayMostProfitableSalsa(int arr[], int arrSize, int maximum)
{
    /*
    Function: displayMostProfitableSalsa
    Programmer: Isaiah Sule
    Date: 4/1/19
    Parameters: arr[], arrSize, maximum
    Description: First, determine if ANY salsa was sold at all and then, if yes, determine which value in arr[] has the maximum stored, which was
                 calculated by getMax();
    */
    int sum = 0;

    for(int i = 0; i<arrSize; i++)
        sum += arr[i];
    if(sum == 0)
        cout << "You sold no salsa today." << endl;
    else
    {
        if(arr[0] == maximum)
            cout << "The most profitable salsa was MILD, which was (in $) " << maximum << endl;
        else if (arr[1] == maximum)
            cout << "The most profitable salsa was MEDIUM, which was (in $) " << maximum << endl;
        else if (arr[2] == maximum)
            cout << "The most profitable salsa was SWEET, which was (in $) " << maximum << endl;
        else if (arr[3] == maximum)
            cout << "The most profitable salsa was HOT, which was (in $) " << maximum << endl;
        else if (arr[4] == maximum)
            cout << "The most profitable salsa was ZESTY, which was (in $) " << maximum << endl;
        else
        {
            cout << "Something went wrong." << endl;
            cout << "Please consult the manager." << endl;
            cout << "Exiting..."<< endl;
        }

    }

}
void displayLeastProfitableSalsa(int arr[], int arrSize, int minimum)
{
    /*
    Function: displayLeastProfitableSalsa
    Programmer: Isaiah Sule
    Date: 4/5/19
    Description: Find out if any salsa was sold, then display the least profitable salsa based on which value in the array, arr[], has the minimum, which was calculated by getMin();
    */
    int sum = 0;

    for(int i = 0; i<arrSize; i++)
        sum += arr[i];
    if (sum == 0)
        cout << "You sold no salsa today." << endl;
    else
    {
        if(arr[0] == minimum)
            cout << "The least profitable salsa was MILD, which was (in $) " << minimum << endl;
        else if (arr[1] == minimum)
            cout << "The least profitable salsa was MEDIUM, which was (in $) " << minimum << endl;
        else if (arr[2] == minimum)
            cout << "The least profitable salsa was SWEET, which was (in $) " << minimum << endl;
        else if (arr[3] == minimum)
            cout << "The least profitable salsa was HOT, which was (in $) " << minimum << endl;
        else if (arr[4] == minimum)
            cout << "The least profitable salsa was ZESTY, which was (in $) " << minimum << endl;
        else
        {
            cout << "Something went wrong." << endl;
            cout << "Please consult the manager." << endl;
            cout << "Exiting..."<< endl;
        }
    }


}
void displayRec(const string salsa[], const int jarsSold[],
                const int price[], int arrSize)
{
    /*
    Function: displayRec
    Programmer: Isaiah Sule
    Date: 4/1/19
    Description: displays all the arrays in a neat chart using #include iomanip's  setw() function to format properly
    */
    cout << left << endl; //start from the furthest left, iomanip feature
    cout << "Salsa" << "     "
         << "Jars Sold" << "     "
         << "Price(in $)"
         << endl;
    cout << "-------------------------------" << endl;
    for (int i=0; i<arrSize; i++)
        cout << setw(10) << salsa[i]
             << setw(10) << jarsSold[i]
             << setw(10) << price[i] << endl;
}
int displayMenu(string arr1[], int arr2[], int arrSize)
{
    /*
    Function: displayMenu
    Programmer: Isaiah Sule
    Date: 4/1/19
    Description: displays option for the user to choose from, then returns the user's inputted answer back to main.
                 Also:
                    -asks the user if they want to buy any salsa (if they haven't already)
                    -displays how many salsa jars have been sold
    Returns: int choice
    */
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
        cout << "3. Display the worst-selling salsa (in # of Jars sold)" << endl; //MAXIMUM for JarsSold
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
    /*
    Function: getMin
    Programmer: Professor Adi Zejnilovic
    Date: 4/1/19/*
    Function: getMin
    Programmer: Professor Adi Zejnilovic
    Date: 4/1/19
    Description: Sets an initial variable, myMin, to a random value in arr[], then replaces that value with a value within arr[] that is less than myMin's intial value,
                 which finds the minimum.

                 NOTE:
                 This is done in a for loop
                 it is then returned to the main function to be used for other functions such as displayMostProfitableSalsa();, or displayMaxJarsSold();
    Returns: int myMin
    */
    Description: Sets an initial variable, myMin, to a random value in arr[], then replaces that value with a value within arr[] that is less than myMin's initial value,
                 which finds the minimum.

                 NOTE:
                 This is done in a for loop
                 it is then returned to the main function to be used for other functions such as displayMostProfitableSalsa();, or displayMaxJarsSold();
    */
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
    /*
    Function: getMax
    Programmer: Professor Adi Zejnilovic
    Date: 4/1/19
    Description: Sets an initial variable, myMax, to a random value in arr[], then replaces that value with a value within arr[] that is more than myMax's initial value,
                 which finds the maximum for us. Returns that value back to the main function to use later.
    Returns: int myMax
    */
    int myMax = arr[0];

    for (int i=1; i< arrSize; i++)
    {
        if (arr[i] > myMax)
            myMax = arr[i];
    }

    return myMax;
}
void calculateTotalCost(const int arr1[], int arr2[], int arr3[], int arrSize)//change the address of values outside of itself; calculates total cost
{
    /*
    Function: calculateTotalCost
    Programmer: Isaiah Sule
    Date: 4/3/19
    Description: This function is responsible for determining the value of the array, totalCost[], by multiplying the jars sold (therefore, we need the jarsSold[] array)
                 times the price of the salsa (which requires the prices[] array).

                 EX:

                 MILD salsa costs $1

                 jarsSold[1,0,2,3,4];
                          ^
                          ^
                          ^
                        {jarsSold[0] (which is 1) * price[0] (which is also 1) } = totalCost[0]; (which would be 1)

                And since we know that each value corresponds to the other, rather than hard code it, we'll use a for loop


                NOTE: arrays don't require references, "&", so rather than returning the results of this function back to the main, we can just replace what's inside the array
                      and it can interacted with outside this function, therefore, the function type is void.
    */
    for(int i = 0; i<arrSize; i++)
    {
        arr3[i] = arr1[i] * static_cast<double>(arr2[i]);
    }
}
void displayMaxJarsSold(int arr[], int maxJars, int arrSize)
{
    /*
    Function: displayMaxJarsSold
    Programmer: Isaiah Sule
    Date: 4/1/19
    Description: displays the maximum amount of jars sold, using the getMax()'s results, inside this function, which we've stored as 'maxJars'
    */
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
    /*
    Function: displayMinJarsSold
    Programmer: Isaiah Sule
    Date: 4/1/2019
    Description: This function is responsible for displaying the minimum amount of jars sold.
                 We do this by borrowing the value from the results of getMin(), and storing it here, as 'minJars'
    */
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

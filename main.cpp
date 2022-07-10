#include <iostream>
#include<bits/stdc++.h>
#include <conio.h>
#include <vector>
using namespace std;

class phoneDirectory
{
private:
    string fName;
    string lName;
    string phoneNum;
public:
    //ctor
    phoneDirectory(){};
    //dtor
    virtual ~phoneDirectory(){};
    //container to first names.
    vector<string>firstNames;
    //container to last names.
    vector<string>lastNames;
    //container to phone numbers.
    vector<string>phoneNumbers;
    //fName setter
    void setFName(string f){fName = f;};
    //lName setter
    void setLName(string l){lName = l;};
    //phone number setter
    void setPhoneNum(string p){phoneNum = p;};
    //fName getter.
    string getFName(){return fName;};
    //lName getter.
    string getLName(){return lName;};
    //phoneNum getter.
    string getPhoneNum(){return phoneNum;};

    void AddDirectory()
{
    //First name from user into container.
    string FirstName ;
    cout << "Enter Directory First Name : ";
    cin >> FirstName;
    setFName(FirstName);
    firstNames.push_back(getFName()); //vector of first names.

    //last name from user into container.
    string LastName ;
    cout << "Enter Directory Last Name : ";
    cin >> LastName;
    setLName(LastName);
    lastNames.push_back(getLName());  //vector of last names.

    //last name from user into container.
    string phoneNumber ;
    cout << "Enter Directory Phone Number : ";
    cin >> phoneNumber;
    setPhoneNum(phoneNumber);
    phoneNumbers.push_back(getPhoneNum());  //vector of phone Numbers.
}
    //Function to print all Directories.
    void printDirectories()
{
    cout << endl<<endl;
    cout << "Your Directories ---> "<<endl;
    for(unsigned int i = 0 ; i < firstNames.size(); i++)
    {
        cout <<i+1<< ") Your Directory First name : "<<firstNames[i]<<endl;
        cout << "Your Directory Last Name : "<<lastNames[i]<<endl;
        cout << "Your Directory Phone Number : "<<phoneNumbers[i]<<endl<<endl;
    }
    cout << endl<<endl;
}
    //Function to search for Directory by (Frist Name).
    void Search_By_FName()
{
    string firstName;
    bool found = false ;
    cout << "Enter the First Name of the directory you searching for : " ;
    cin >> firstName;
    for(unsigned int i = 0 ; i < firstNames.size(); i++)
    {
        if(firstNames[i] == firstName)
        {
            found = true;
            cout << "Your Directory First name : "<<firstNames[i]<<endl;
            cout << "Your Directory Last Name : "<<lastNames[i]<<endl;
            cout << "Your Directory Phone Number : "<<phoneNumbers[i]<<endl;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Directory you searching for doesn't exist !!"<<endl;
    }
}

    //Function to search for Directory by (Frist Name).
    void Search_By_PhoneNum()
{
    string PhNum;
    bool found = false ;
    cout << "Enter the Phone Number of the directory you searching for : " ;
    cin >> PhNum;
    for(unsigned int i = 0 ; i < phoneNumbers.size(); i++)
    {
        if(phoneNumbers[i] == PhNum )
        {
            found = true;
            cout << "Your Directory First name : "<<firstNames[i]<<endl;
            cout << "Your Directory Last Name : "<<lastNames[i]<<endl;
            cout << "Your Directory Phone Number : "<<phoneNumbers[i]<<endl;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Directory you searching for doesn't exist !!"<<endl;
    }
}

    //Function to delete Directory by (Frist Name).
    void Delete_By_FName()
{
    string firstName;
    bool found = false ;
    cout << "Enter the First Name of the directory you want to delete : " ;
    cin >> firstName;
    for(unsigned int i = 0 ; i < firstNames.size(); i++)
    {

        if(firstNames[i] == firstName)
        {
            found = true;
            firstNames.erase(firstNames.begin());
            lastNames.erase(lastNames.begin());
            phoneNumbers.erase(lastNames.begin());
            cout << "Your Directory has been deleted . "<<endl;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Directory you searching for doesn't exist !!"<<endl;
    }
}

void Sort_Directories()
{
    ///Using Insertion Sort.
    for (unsigned int i = 1, j; i < firstNames.size(); i++)
    {
        string tmp_Fname = firstNames [i];
        string tmp_Lname = lastNames [i];
        string tmp_PhNum = phoneNumbers [i];
        for (j = i; j > 0 && tmp_Fname < firstNames [j-1]; j--)
        {
            //Swapping the 2 Directories.
            firstNames[j] = firstNames[j-1];
            lastNames[j] = lastNames[j-1];
            phoneNumbers [j] = phoneNumbers[j -1];
        }
        firstNames [j] = tmp_Fname;
        lastNames [j] = tmp_Lname;
        phoneNumbers [j] = tmp_PhNum;
    }
    cout << endl<<endl;
    cout << "Your Directories After Sorting :"<<endl;
    for(unsigned int i = 0 ; i < firstNames.size(); i++)
    {
            cout <<i+1<< ") Your Directory First name : "<<firstNames[i]<<endl;
            cout << "Your Directory Last Name : "<<lastNames[i]<<endl;
            cout << "Your Directory Phone Number : "<<phoneNumbers[i]<<endl;

        cout << endl;
    }
    cout << endl<<endl;


}
void shellSort()
{
    for (int gap = firstNames.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < firstNames.size(); i += 1)
        {
            string tmp_Fname = firstNames [i];
            string tmp_Lname = lastNames [i];
            string tmp_PhNum = phoneNumbers [i];
             int j;
            for (j = i; j >= gap && firstNames[j - gap] > tmp_Fname; j -= gap)
                firstNames [j] = firstNames [j - gap];

            //  put temp (the original a[i]) in its correct location
            firstNames [j] = tmp_Fname;
            lastNames [j] = tmp_Lname;
            phoneNumbers [j] = tmp_PhNum;
        }
    };




}
;};
int main()
{
 phoneDirectory test;
    while(true)
    {
        cout << "Please enter Your option : \n\n" << "1- Add Directory. \n2- Search Directory by First name. \n3- Search Directory by phone Number."<<
             " \n4- Delete directory by First name. \n5- List Directory in alphabetical order (Ascending)."<<"\nEnter 0 to exit."<<endl;
        int option ;
        cin >> option;
        switch(option)
        {
        case 0 :
            exit(0);
            break;
        case 1:
            test.AddDirectory();
            break;
        case 2:
            test.Search_By_FName();
            break;
        case 3:
            test.Search_By_PhoneNum();
            break;
        case 4:
            test.Delete_By_FName();
            break;
        case 5:
             test.Sort_Directories();
            break;
        default:
            cout << "\nWrong option, please re-choose a number: \n";
            break;
        }
        cout << "\nPress any key to continue... ";
        getch();
        system("cls");



    };
    return 0 ; }


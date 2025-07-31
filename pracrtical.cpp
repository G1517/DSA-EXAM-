#include<iostream>
using namespace std;

int main()
{
    int marks , grade;
    // Input The Marks
    cout << "Enter The Marks : ";
    cin >> marks;

    if(marks > 100 || marks < 0)
    {
        cout << "Please Enter The Valid Marks";
        return 0;
    }

    // Ternary Operator
    (marks >= 90) ? cout << "Your Grade Is A" << endl: 
    (marks >= 80) ? cout << "Your Grade Is B" << endl : 
    (marks >= 70) ? cout << "Your Grade Is C" << endl :
    (marks >= 60) ? cout << "Your Grade Is D" << endl :
    (marks >= 50) ? cout << "Your Grade Is E" << endl : 
    cout << "Fail"; 

    // Aloocating Grade Acording To Marks
    if(marks >= 90)
    {
        grade = 'A';
    }
    else if(marks >= 80)
    {
        grade = 'B';
    }
    else if(marks >= 70)
    {
        grade = 'C';
    }
    else if(marks >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'E';
    }

    //Giving The FeedBack According To Grade
    switch(grade)
    {
        case 'A': 
        {
            cout << "Excellent Work" << endl;
            break;
        }

        case 'B': 
        {
            cout << "Well Done" << endl;
            break;
        }

        case 'C': 
        {
            cout << "Good Job" << endl;
            break;
        } 

        case 'D': 
        {
            cout << "You Pass But You Could Better" << endl;
            break;
        }

        case 'E': 
        {
            cout << "Sorry You Failed" << endl;
            break;
        }

        default:
        {
            cout << "Enter Valid Marks";
        }
    }

    //Cheak The Next Level Aligibility
    if(grade == 'E')
        {
            cout << "Please Try Again Next Time";
        }
    else
        {
            cout << "Congratulations ! You Are Eligible For The Next Level";
        }
   
    return 0;
}




banking system 

#include <iostream>
using namespace std;
class BankAccount
{
protected:
    int accountNumber, balance = 0;
    string accountHolderName;

public:
    void createAccount(int acnumber, string name)
    {
        this->accountNumber = acnumber;
        this->balance = balance;
        this->accountHolderName = name;
        cout << "\nAcount Created Successfully ! ";
    }

    void displayAccountInfo()
    {
        cout << "\n---------Account Details-----------";
        cout << "\nAccount Number : " << this->accountNumber;
        cout << "\nAccount Holder Name : " << this->accountHolderName;
        cout << "\nAccount Balance : " << this->balance;
        cout << "\n-----------------------------------";
    }

    int getAccNumber()
    {
        return this->accountNumber;
    }

    void deposit(int amount)
    {
        this->balance += amount;
        cout << "Amount Added Successfully ! ";
    }
    void withdraw(int amount)
    {
        if (this->balance >= amount)
        {
            this->balance = this->balance - amount;
            cout << "Amount withdrwal Successfully ! ";
        }
        else
        {
            cout << "You have insufficient Balance ! ";
        }
    }
};

class SavingAccount : public BankAccount
{
protected:
    int interestRate;
    string password;

public:
    void setPassword(string password)
    {
        this->password = password;
    }
    string getPassword()
    {
        return this->password;
    }

    void calculateInterest(double interestRate)
    {
        this->balance += (this->balance / 100) * interestRate;
        cout << "Interest Added Successfully ! ";
    }
};
int main()
{
    SavingAccount account[10];
    string password, name;
    int accountNumber, count = 0;

    int choice;

    do
    {
        cout << "\n-----------Laxmi Chit Fund---------";
        cout << "\n1 for create account...";
        cout << "\n2 for view Account Details...";
        cout << "\n3 for deposit...";
        cout << "\n4 for withdraw...";
        cout << "\n5 for calculate Interest...";
        cout << "\n6 for Exit...";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            bool flag = false;
            // Create account
            cout << "Enter Account Number : ";
            cin >> accountNumber;
            cin.ignore();

            for (int i = 0; i < count; i++)
            {
                if (account[i].getAccNumber() == accountNumber)
                {

                    flag = true;
                    break;
                }
            }

            if (flag == false)
            {
                cout << "Enter Name : ";
                getline(cin, name);
                cout << "Set Password : ";
                cin >> password;
                account[count].createAccount(accountNumber, name);
                account[count].setPassword(password);
                count++;
            }
            else
            {
                cout << "Account is already Exists ! ";
            }

            break;
        }
        case 2:
        {
            // View details
            int acnumber;
            string password;
            bool flag = false;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);
            for (int i = 0; i < count; i++)
            {

                if ((account[i].getAccNumber() == acnumber))
                {
                    flag = true;

                    if (((account[i].getPassword() == password)))
                    {

                        account[i].displayAccountInfo();
                        break;
                    }
                    else
                    {
                        cout << "You have Entered Incorrect Password ! ";
                    }
                }
            }

            if (flag == false)
            {
                cout << "Please Enter Valid Account Number ! ";
            }
            break;
        }
        case 3:
        {
            // Deposit
            int acnumber;
            string password;
            bool flag = false;
            bool newflag = false;
            int val;
            int amount;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);

            for (int i = 0; i < count; i++)
            {

                if ((account[i].getAccNumber() == acnumber))
                {
                    flag = true;

                    if ((account[i].getPassword() == password))
                    {
                        newflag = true;
                        val = i;
                        break;
                    }
                }
            }

            if (newflag == false)
            {
                cout << "You have Entered Incorrect Password ! ";
            }
            else
            {
                cout << "Enter Amount : ";
                cin >> amount;
                account[val].deposit(amount);
            }
            if (flag == false)
            {
                cout << "Please Enter Valid Account Number ! ";
            }
            break;
        }
        case 4:
        {
            // Withdraw
            int acnumber;
            bool flag = false;
            bool newflag = false;
            int val;
            string password;
            int amount;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);

            for (int i = 0; i < count; i++)
            {

                if ((account[i].getAccNumber() == acnumber))
                {
                    flag = true;

                    if ((account[i].getPassword() == password))
                    {
                        newflag = true;
                        val = i;
                        break;
                    }
                }
            }
            if (newflag == false)
            {
                cout << "You have Entered Incorrect Password ! ";
            }
            else
            {
                cout << "Enter Amount : ";
                cin >> amount;
                account[val].withdraw(amount);
            }
            if (flag == false)
            {
                cout << "Please Enter Valid Account Number ! ";
            }
            break;
        }
        case 5:
        {
            // Calculate interest
            int acnumber;
            bool flag = false;
            string password;
            int interestRate;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);
            cout << "Enter InterestRate : ";
            cin >> interestRate;
            for (int i = 0; i < count; i++)
            {

                if (account[i].getAccNumber() == acnumber)
                {
                    flag = true;
                    if (account[i].getPassword() == password)
                    {

                        account[i].calculateInterest(interestRate);
                        break;
                    }
                }
            }
            if (flag == false)
            {
                cout << "Please Enter Valid Account Number ! ";
            }
            break;
        }
        case 6:
        {
            // For Exit
            cout << "Thank you for banking with us ! ";
            break;
        }
        }

    } while (choice != 6);

    return 0;
}



Student 

#include<iostream>
#include<vector>
using namespace std;
class School{
    private:
    int studentId;
    string studentName;

    public:

    School(int id, string name){
        this->studentId = id;
        this->studentName = name;
    }

    void seeAllStudent(){
        cout<<"\n-----------xxxxxxx-------------";
        cout<<"\nId : "<<this->studentId;
        cout<<"\nName : "<<this->studentName;
        cout<<"\n-----------xxxxxxx-------------";
    }

    int getId(){
        return this->studentId;
    }

};
int main(){
    vector<School> student;
    int choice;
    do{
        cout<<"\n1 for Add student detail...";
        cout<<"\n2 for remove student...";
        cout<<"\n3 for see All Student...";
        cout<<"\n4 for search student...";
        cout<<"\n5 for Exit...";
        cout<<"\nEnter your choice : ";
        cin>>choice;


        switch(choice){
            case 1:{

                int id; string name;
                cout<<"Enter Id : ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Name : ";
                getline(cin,name);

                student.push_back(School(id, name));
                break;
            }
            case 2:{
                int id;
                bool isFound = false;
                cout<<"Enter Id : ";
                cin>>id;

                for(auto i = student.begin(); i < student.end();i++){
                    if(i->getId() == id){
                        student.erase(i);
                        isFound = true;
                        // break;
                    }
                }

                (isFound == true) ? cout<<"Student Id removed succefully !"<<endl : cout<<"Student Not Found !"<<endl;
                break;
            }
            case 3:{
                for(auto i = student.begin(); i != student.end();i++){
                    i->seeAllStudent();
                    cout<<endl;
                }

                break;
            }
            case 4:{
                    int id;
                    bool isFound = false;
                    cout<<"Enter Id : ";
                    cin>>id;
                    for(auto i = student.begin(); i != student.end();i++){
                        if(i->getId() == id){
                            i->seeAllStudent();
                            isFound = true;
                        }
                }
                 (isFound == true)?cout<<"":cout<<"Student Not Found !";
                break;
            }
            case 5:{
                cout<<"Thank You !";
                break;
            }
            default:
            cout<<"Invalid Choice..."<<endl;
        }
    }while(choice != 5);
return 0;
}

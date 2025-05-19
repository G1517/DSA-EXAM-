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
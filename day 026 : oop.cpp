#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Base Class
class Student
{
protected:
    string name;
    int rollNo;
    string subject;

public:

    virtual void input()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, subject);
    }

    virtual void display()
    {
        cout << left << setw(15) << name;
        cout << setw(10) << rollNo;
        cout << setw(15) << subject;
    }

    int getRollNo()
    {
        return rollNo;
    }

    virtual ~Student()
    {
    }
};


// Derived Class
class StudentMarks : public Student
{
private:
    string subjectCode;
    int internalAssessment;
    int universityExamMarks;

public:

    void input()
    {
        Student::input();

        cout << "Enter Subject Code: ";
        getline(cin, subjectCode);

        cout << "Enter Internal Assessment: ";
        cin >> internalAssessment;

        cout << "Enter University Exam Marks: ";
        cin >> universityExamMarks;
    }

    void display()
    {
        Student::display();

        cout << left << setw(12) << subjectCode;
        cout << setw(12) << internalAssessment;
        cout << setw(12) << universityExamMarks;
        cout << setw(10)
             << internalAssessment + universityExamMarks;

        cout << endl;
    }

    void displayHeader()
    {
        cout << left << setw(15) << "Name";
        cout << setw(10) << "Roll No";
        cout << setw(15) << "Subject";
        cout << setw(12) << "SubCode";
        cout << setw(12) << "Internal";
        cout << setw(12) << "UnivExam";
        cout << setw(10) << "Total";

        cout << endl;
    }
};


// Master Table
class MasterTable
{
private:
    vector<StudentMarks> records;

public:

    // Build Table
    void buildTable()
    {
        int n;

        cout << "How many records? ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "\nRecord " << i + 1 << endl;

            StudentMarks s;
            s.input();

            records.push_back(s);
        }

        cout << "\nTable created successfully!\n";
    }


    // Display Table
    void listTable()
    {
        if(records.empty())
        {
            cout << "\nTable is empty.\n";
            return;
        }

        cout << "\n========== Master Table ==========\n";

        records[0].displayHeader();

        for(int i = 0; i < records.size(); i++)
        {
            records[i].display();
        }
    }


    // Insert
    void insertEntry()
    {
        StudentMarks s;

        cout << "\nEnter New Student Details\n";

        s.input();

        records.push_back(s);

        cout << "Record inserted successfully!\n";
    }


    // Delete
    void deleteEntry()
    {
        int roll;

        cout << "Enter Roll Number to delete: ";
        cin >> roll;

        for(int i = 0; i < records.size(); i++)
        {
            if(records[i].getRollNo() == roll)
            {
                records.erase(records.begin() + i);

                cout << "Record deleted successfully!\n";
                return;
            }
        }

        cout << "Record not found.\n";
    }


    // Edit
    void editEntry()
    {
        int roll;

        cout << "Enter Roll Number to edit: ";
        cin >> roll;

        for(int i = 0; i < records.size(); i++)
        {
            if(records[i].getRollNo() == roll)
            {
                cout << "\nEnter New Details\n";

                records[i].input();

                cout << "Record updated successfully!\n";
                return;
            }
        }

        cout << "Record not found.\n";
    }


    // Search
    void searchRecord()
    {
        int roll;

        cout << "Enter Roll Number to search: ";
        cin >> roll;

        for(int i = 0; i < records.size(); i++)
        {
            if(records[i].getRollNo() == roll)
            {
                cout << "\n===== Record Found =====\n";

                records[i].displayHeader();
                records[i].display();

                return;
            }
        }

        cout << "Record not found.\n";
    }
};


// Main Function
int main()
{
    MasterTable table;

    int choice;

    do
    {
        cout << "\n===== Student Record Management =====\n";

        cout << "1. Build Master Table\n";
        cout << "2. List Table\n";
        cout << "3. Insert New Entry\n";
        cout << "4. Delete Entry\n";
        cout << "5. Edit Entry\n";
        cout << "6. Search Record\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                table.buildTable();
                break;

            case 2:
                table.listTable();
                break;

            case 3:
                table.insertEntry();
                break;

            case 4:
                table.deleteEntry();
                break;

            case 5:
                table.editEntry();
                break;

            case 6:
                table.searchRecord();
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}

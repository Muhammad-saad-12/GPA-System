#include <iostream>
#include <string>

using namespace std;

struct Subject {
    string name;
    int credits;
    float grade;
};

struct GPA {
    Subject subjects[10];
    int count;

    GPA() {
        count = 0;
    }
int menu(){
    int cho;
    cout<<"Menu"<<endl;
    cout<<"1.Enter a new subject data and grade"<<endl;
    cout<<"2.Display subject data nd grades"<<endl;
    cout<<"3.Update subject data"<<endl;
    cout<<"4.Delete subject data"<<endl;
    cout<<"5.Calculate GPA"<<endl;
    cout<<"6.Calculaet CGPA"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"Press any key[1,2,3,4,5,6,7]:";
    cin>>cho;
    return cho;
}
    void addSubject() {
        if (count >= 10) {
            cout << "Maximum number of subjects reached." << endl;
            return;
        }

        Subject subject;

        cout << "Enter subject name: ";
        cin >> subject.name;

        cout << "Enter number of credits: ";
        cin >> subject.credits;

        cout << "Enter grade received: ";
        cin >> subject.grade;

        subjects[count] = subject;
        count++;

        cout << "Subject added successfully." << endl;
    }

    void displayGPA() {
        if (count == 0) {
            cout << "No subjects entered." << endl;
            return;
        }

        float totalGradePoints = 0;
        int totalCredits = 0;

        for (int i = 0; i < count; i++) {
            totalGradePoints += subjects[i].credits * subjects[i].grade;
            totalCredits += subjects[i].credits;
        }

        float gpa = totalGradePoints / totalCredits;

        cout << "GPA: " << gpa << endl;
    }

    void editSubject() {
        if (count == 0) {
            cout << "No subjects entered." << endl;
            return;
        }

        string name;

        cout << "Enter the name of the subject you want to edit: ";
        cin >> name;

        for (int i = 0; i < count; i++) {
            if (subjects[i].name == name) {
                cout << "Enter new number of credits: ";
                cin >> subjects[i].credits;

                cout << "Enter new grade received: ";
                cin >> subjects[i].grade;

                cout << "Subject edited successfully." << endl;

                return;
            }
        }

        cout << "Subject not found." << endl;
    }

    void deleteSubject() {
        if (count == 0) {
            cout << "No subjects entered." << endl;
            return;
        }

        string name;

        cout << "Enter the name of the subject you want to delete: ";
        cin >> name;

        for (int i = 0; i < count; i++) {
            if (subjects[i].name == name) {
                for (int j = i; j < count - 1; j++) {
                    subjects[j] = subjects[j + 1];
                }

                count--;

                cout << "Subject deleted successfully." << endl;

                return;
            }
        }

        cout << "Subject not found." << endl;
    }
};

int main() {
    GPA gpa;
int choice;
    while (true) {
        choice=menu();
        }
}

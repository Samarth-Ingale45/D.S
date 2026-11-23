#include <iostream>
#include <string>
using namespace std;

// Inner Linked List for courses of a single student
class CourseNode
{
public:
    string courseName;
    CourseNode* next;
};

class Student
{
public:
    int rollNo;
    string name;
    string program;
    CourseNode* courseHead; // Head of student's enrolled courses
    Student* next;          // Master Student Linked List pointer
    Student* hashNext;      // Hash Table chaining pointer
};

Student* head = NULL;
const int TABLE_SIZE = 10;
Student* hashTable[TABLE_SIZE] = { NULL };

int hashFunction(int rollNo)
{
    return rollNo % TABLE_SIZE;
}

// Helper function to find a student in O(1) average time via Hash Table
Student* findStudent(int rollNo)
{
    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
            return temp;
        temp = temp->hashNext;
    }
    return NULL;
}

void registerStudent()
{
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;

    if (findStudent(roll) != NULL)
    {
        cout << "Roll Number already registered." << endl;
        return;
    }

    Student* newStu = new Student();
    newStu->rollNo = roll;
    newStu->courseHead = NULL;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, newStu->name);
    cout << "Enter Program (e.g., B.Tech AI-ML): ";
    getline(cin, newStu->program);

    // 1. Add to Master Linked List
    newStu->next = head;
    head = newStu;

    // 2. Add to Hash Table (Chaining)
    int index = hashFunction(roll);
    newStu->hashNext = hashTable[index];
    hashTable[index] = newStu;

    cout << "Student registered successfully." << endl;
}

void updateStudent()
{
    int roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;

    Student* stu = findStudent(roll);
    if (stu == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Updated Name: ";
    getline(cin, stu->name);
    cout << "Enter Updated Program: ";
    getline(cin, stu->program);
    cout << "Student information updated." << endl;
}

void enrollCourse()
{
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;

    Student* stu = findStudent(roll);
    if (stu == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore();
    CourseNode* newCourse = new CourseNode();
    cout << "Enter Course Name/Code to enroll: ";
    getline(cin, newCourse->courseName);

    // Insert course into student's course linked list
    newCourse->next = stu->courseHead;
    stu->courseHead = newCourse;

    cout << "Enrolled in " << newCourse->courseName << " successfully." << endl;
}

void withdrawCourse()
{
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;

    Student* stu = findStudent(roll);
    if (stu == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore();
    string targetCourse;
    cout << "Enter Course Name/Code to withdraw: ";
    getline(cin, targetCourse);

    CourseNode* curr = stu->courseHead;
    CourseNode* prev = NULL;

    while (curr != NULL && curr->courseName != targetCourse)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Course not found in student's enrollments." << endl;
        return;
    }

    if (prev == NULL)
        stu->courseHead = curr->next;
    else
        prev->next = curr->next;

    delete curr;
    cout << "Withdrawn from " << targetCourse << " successfully." << endl;
}

void removeStudent()
{
    int roll;
    cout << "Enter Roll Number to remove: ";
    cin >> roll;

    // 1. Unlink from Hash Table
    int index = hashFunction(roll);
    Student* hCurr = hashTable[index];
    Student* hPrev = NULL;

    while (hCurr != NULL && hCurr->rollNo != roll)
    {
        hPrev = hCurr;
        hCurr = hCurr->hashNext;
    }

    if (hCurr == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    if (hPrev == NULL)
        hashTable[index] = hCurr->hashNext;
    else
        hPrev->hashNext = hCurr->hashNext;

    // 2. Unlink from Master Linked List
    Student* lCurr = head;
    Student* lPrev = NULL;

    while (lCurr != NULL && lCurr != hCurr)
    {
        lPrev = lCurr;
        lCurr = lCurr->next;
    }

    if (lCurr != NULL)
    {
        if (lPrev == NULL)
            head = lCurr->next;
        else
            lPrev->next = lCurr->next;
    }

    // 3. Free all enrolled courses of this student first
    CourseNode* cTemp = hCurr->courseHead;
    while (cTemp != NULL)
    {
        CourseNode* nextCourse = cTemp->next;
        delete cTemp;
        cTemp = nextCourse;
    }

    delete hCurr;
    cout << "Student record removed successfully." << endl;
}

void searchStudent()
{
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    Student* stu = findStudent(roll);
    if (stu == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cout << "\nRoll No: " << stu->rollNo << " | Name: " << stu->name << " | Program: " << stu->program << endl;
    cout << "Enrolled Courses: ";
    CourseNode* cTemp = stu->courseHead;
    if (cTemp == NULL)
        cout << "None";
    while (cTemp != NULL)
    {
        cout << cTemp->courseName << (cTemp->next != NULL ? ", " : "");
        cTemp = cTemp->next;
    }
    cout << endl;
}

void displayAllStudents()
{
    Student* temp = head;
    if (temp == NULL)
    {
        cout << "No student records available." << endl;
        return;
    }

    cout << "\n--- All Registered Students ---" << endl;
    while (temp != NULL)
    {
        cout << "Roll No: " << temp->rollNo << " | Name: " << temp->name << " | Program: " << temp->program << endl;
        cout << "  Courses: ";
        CourseNode* cTemp = temp->courseHead;
        if (cTemp == NULL)
            cout << "None";
        while (cTemp != NULL)
        {
            cout << cTemp->courseName << (cTemp->next != NULL ? ", " : "");
            cTemp = cTemp->next;
        }
        cout << "\n-------------------------------" << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n=== University Registration & Enrollment System ===" << endl;
        cout << "1. Register New Student" << endl;
        cout << "2. Search Student by Roll Number" << endl;
        cout << "3. Update Student Info" << endl;
        cout << "4. Enroll Student in Course" << endl;
        cout << "5. Withdraw Student from Course" << endl;
        cout << "6. Remove Student Record" << endl;
        cout << "7. Display All Students" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: registerStudent(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: enrollCourse(); break;
            case 5: withdrawCourse(); break;
            case 6: removeStudent(); break;
            case 7: displayAllStudents(); break;
            case 8: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 8);

    return 0;
}

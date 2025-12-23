    // This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.
    // The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.
    // The class Student should have two data members: marks, which is an array of size  and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.
    // For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .
    // Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
    // Note: Expand the main function to look at how the input is being handled.
    // Input Format
    // The first line of input contains the number of objects that are being created. If the first line of input for each object is 1 , it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
    // If the first line of input for each object is 2, it means that the object is of the Student class, you will have to input the name, age and the marks of the student in 6  subjects.
    #include <iostream>
    #include <string>
    // #include <numeric>

    using namespace std;

    class Person {
    public:
        string name;
        int age;
        virtual void getdata() {}
        virtual void putdata() {}
    };

    class Professor : public Person {
    public:
        int publications;
        int cur_id;
        static int id;

        Professor() {
            this->cur_id = ++id;
        }

        void getdata() {
            cin >> name >> age >> publications;
        }

        void putdata() {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
    };
    int Professor::id = 0;

    class Student : public Person {
    public:
        int marks[6];
        int cur_id;
        static int id;

        Student() {
            this->cur_id = ++id;
        }

        void getdata() {
            cin >> name >> age;
            for (int i = 0; i < 6; i++) {
                cin >> marks[i];
            }
        }

        void putdata() {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                sum += marks[i];
            }
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
    };
    int Student::id = 0;

    int main() {
        int n, val;
        cin >> n;
        Person *per[n];

        for (int i = 0; i < n; i++) {
            cin >> val;
            if (val == 1) {
                per[i] = new Professor;
            } else {
                per[i] = new Student;
            }
            per[i]->getdata();
        }

        for (int i = 0; i < n; i++) {
            per[i]->putdata();
        }

        return 0;
    }
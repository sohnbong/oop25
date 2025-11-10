#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public :
        Student(int id , char* name)
        {
                stu_id = id;
                stu_name = name;
        }
        ~Student() {}

        static bool comp_student(const Student& a, const Student& b);
        char* getName() { return stu_name; }
        int getID() const { return stu_id; }

private :
        int stu_id;
        char* stu_name;
};

bool Student::comp_student(const Student& a, const Student& b)
{
        return (a.stu_id < b.stu_id);
}

void Display(vector<Student>::iterator start, vector<Student>::iterator end)
{
        for( vector<Student>::iterator p = start; p != end; ++p )
                cout<< p->getID() << " : " << p->getName() << endl ;
}

class MyFunct {
public:
        bool operator()(const Student& a, const Student& b)
        {
                return (a.getID() < b.getID());
        }
};

int main()
{
        vector<Student> stu_vec;

        stu_vec.push_back(Student(4,"Nancy"));
        stu_vec.push_back(Student(1,"Tom"));
        stu_vec.push_back(Student(3,"Mike"));
        stu_vec.push_back(Student(2,"Lisa"));

        Display(stu_vec.begin() , stu_vec.end());
        cout << endl;

        sort(stu_vec.begin() , stu_vec.end(), MyFunct());

        Display(stu_vec.begin() , stu_vec.end());

        return 0;

}

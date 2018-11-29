#include <iostream>

using namespace std;
const int MAX_NAME = 14; // Assume a name contains at most 14 characters
enum Gender { MALE, FEMALE };
struct Date { int year; int month; int day; };

struct Student
{
	int ID;
	char first_name[MAX_NAME + 1];
	char last_name[MAX_NAME + 1];
	Date birth_date;
	Gender gender;
	double GPA;
};

void InputStudent(Student* s);
void OutputStudent(Student* s);
void InputAllStudent(Student *y, int n);
void OutputAllStudent(Student *y, int n);
void SortStudents(Student *y, int n, bool (*LessThan)(Student*,Student*));
bool BirthLess(Student* a, Student* b);
bool GPAGreater(Student* a, Student* b);
bool GPAGreater(Student* a, Student* b);
Student* SearchStudentID(Student *y, int n, int ID);
Student* SearchStudentFirstName(Student *y, int n, char* name);

int main()
{
    int f;
	Student s;
	int id;
	char N;
	int n;  //n is number of student
	cout << "Enter the number of students: ";
	cin >> n;
	cout<<endl;
	Student *y = new Student[n];
	InputAllStudent(y, n);
	do
     {
    cout<<"1) Output all students data."<<endl;
    cout<<"2) Sort students by increasing birth date."<<endl;
    cout<<"3) Sort students by decreasing GPA."<<endl;
    cout<<"4) Search students by ID."<<endl;
    cout<<"5) Search students by first name."<<endl;
    cout<<"6) Exit the program."<<endl;
    cout<<endl;
    cout<<"Enter the number of your choice."<<endl;
    cin>>f;
    cout<<endl;
     if( f == 1)
       {
           OutputAllStudent(y, n);
           cout<<endl;
       }
     else if(f == 2)
       {
           SortStudents(y , n , BirthLess );
           OutputAllStudent(y, n);
           cout<<endl;
       }
     else if( f==3 )
     {
         SortStudents(y , n , GPAGreater );
         OutputAllStudent(y, n);
         cout<<endl;
     }
     else if( f==4)
     {
         Student* p;
         p=SearchStudentID(y, n, id);
         if(p!=NULL)
         {
        cout<<"The student ";
         OutputStudent(p);
         }
         else
            cout<<"The student is not found"<<endl;
            cout<<endl;

     }
     else if( f==5)
     {
         Student* p;
         p=SearchStudentFirstName(y, n, &N);
         if(p!=NULL)
         {
        cout<<"The student ";
         OutputStudent(p);
         }
         else
            cout<<"The student is not found"<<endl;
            cout<<endl;
     }
     else if(f == 6)
        break;
    else
    {
        cout<<"The choice is wrong"<<endl;
        continue;
    }

     }
     while(f!=1 || f!=2 || f!=3 || f!=4 || f!=5);
	return 0;
}

void InputStudent(Student* s)
	{
    int inputG;
	cout << "Enter the ID of student: ";
	cin >> s->ID;
	cout << "Enter the first name of student: ";
	cin >> s->first_name;
	cout << "Enter the last name of student: ";
	cin >> s->last_name;
	cout << "Enter the birth date of student:" << endl <<"-------------------------------"<< endl << "Enter day: ";
	cin >> s->birth_date.day;
	cout << "Enter month: ";
	cin >> s->birth_date.month;
	cout << "Enter year: ";
	cin >> s->birth_date.year;
	cout << "Enter the Gender of student:" << "  (If Male enter 0, Female enter 1) => ";
	cin >> inputG;
	s->gender = static_cast<Gender>(inputG);
	if (s->gender == 0)
	{cout<<"                           < Male >"<<endl;}
	else if(s->gender == 1)
	{cout<<"                           < Female >"<<endl;}
	cout << "Enter the GPA of student: ";
	cin >> s->GPA;
	}
void OutputStudent(Student *s)
{
	cout << "ID: " << s->ID;
	cout << "   Name: " << s->first_name << " " << s->last_name
		 << "   Birth date: " << s->birth_date.day << "/" << s->birth_date.month << "/" << s->birth_date.year<< "   GPA: " << s->GPA;
		if (s->gender == 0)
        {
            cout << "   Gender: Male"<<endl;
        }
        else if (s->gender == 1)
        {
            cout << "   Gender: Female"<<endl;
        }
}
void InputAllStudent(Student* y, int n)
{

	for (int i = 0; i<n; i++)
	{
		cout << "Student " << i + 1 << endl;
		cout << endl;
		InputStudent(y+i);
		cout<<endl;
	}

}
void OutputAllStudent(Student *y, int n)
{
	for (int i = 0; i<n ; i++)
	{
		OutputStudent(y+i);
	}
}

void SortStudents(Student *y, int n, bool (*LessThan)(Student*,Student*))
{
    for(int i=0 ; i<n;i++)
    {
        for(int j=i+1 ;j<n ;j++)
        {
           if(LessThan(y+i,y+j))
           {
             Student temp=y[i];
             y[i]=y[j];
             y[j]=temp;
           }
        }
    }
}

bool BirthLess(Student* a, Student* b)
{
    if((a->birth_date.year) < (b->birth_date.year))
        return true;
    else if((a->birth_date.year) > (b->birth_date.year))
        return false;
    else
    {
        if((a->birth_date.month) < (b->birth_date.month))
            return true;
        else if((a->birth_date.month) > (b->birth_date.month))
            return false;
        else
            {
            if((a->birth_date.day) < (b->birth_date.day))
                 return true;
           else if((a->birth_date.day) > (b->birth_date.day))
            return false;
           else
            return true;
            }
    }
}
bool GPAGreater(Student* a, Student* b)
{
  if( (a->GPA) >= (b->GPA))
        return true;
  else
    return false;
}
Student* SearchStudentID(Student *y, int n, int id)
{
    cout<<"Enter the ID that you want to search :  ";
    cin>>id;
    cout<<endl;
    for(int i=0 ; i<n ; i++)
        {
            if(id == (y[i]).ID)
        {
            return y+i;
        }
        }
            return 0;
    }
Student* SearchStudentFirstName(Student *y, int n, char* name)
{
    cout<<"Enter the Name that you want to search :  ";
    cin>>name;
    cout<<endl;
    for(int i=0 ; i<n ; i++)
    {
        if((string)name == (string)(y+i)->first_name)
        {
            return (y+i);
        }
    }
    return 0;
}


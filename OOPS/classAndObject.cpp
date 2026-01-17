#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int age;
    string name;

    Student(int age,string name){
      this->age = age;
      this->name = name;
    }
    Student(int a){
      age=a;
      name="Unknown";
    }

    int findsq(int k){
      return k*k;
    }
    int squareOfAge(int age){
      return age*age;
    }
    void display(){
      cout<<"Name: "<<name<<",Age:"<<age<<endl;
    }

};


int main(){
  Student s1(21,"Alice");
  Student s2(22,"Bob");
  Student s3(23,"Charlie");
  Student s4(25);
  Student s5(50);



 cout<<s5.squareOfAge(5)<<endl; 

  return 0;
}
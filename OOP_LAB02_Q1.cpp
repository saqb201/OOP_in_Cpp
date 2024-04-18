#include<iostream>
#include <string>
using namespace std;
//here we have made the class
class student {
//	here we have try to maximize our data tobe private so thst it will remain secure
    private:
        string Name;
        int roll_num;
        int semester;
//        here we have made public so that we can access to the data we want to  
    public:
        char section;
//        here we have taken the input through the user so that we can done operations on it as our data isnot accessable by outside of the class
        void setdata(string n,int r,int sem,char sec){
        Name=n;
        roll_num=r;
        semester=sem;
        section=sec;
        }
//        here we have set data to be shown to the public or user
        void getdata(){
        cout << "Name - " <<Name<< endl;
        cout << "Roll Number - "<<roll_num<< endl;
        cout << "Semester - "<<semester<< endl;
        cout << "Section - "<<section<< endl<<endl;
        }    
        
};

int main()
//{	here in main we have just call the funtion we decleared above 
    {
	student s1,s2,s3,s4;
    s1.setdata("Saqib",11,2,'A');
    s2.setdata("Hamza",9,2,'B');
    s3.setdata("Muneeb",21,2,'C');
    s4.setdata("Rayyan",10,2,'D');
    
   // s1.getdata();
   // s2.getdata();
   // s3.getdata();
   // s4.getdata();
    
    cout << "The name of student who are in section A " << endl;
    cout << "----------------------------------------" << endl<<endl;
    student s[]={s1,s2,s3,s4};
//    using condition so that only A section students data is being shown 
    for (int i=0;i<3;i++){
        if (s[i]. section=='A')
       { s[i].getdata();}
    }
    
}
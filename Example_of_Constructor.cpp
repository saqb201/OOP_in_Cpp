// // 
// #include <iostream>
// using namespace std;
// class Wall { // declare a class
// private:
// double *length;
// double *height;
// public:
// // initialize variables with parameterized constructor
// Wall(){
// length=NULL;
// height=NULL;
// }
// Wall(double len, double hgt) {
// length = new double;
// height = new double;
// if (length!=NULL && height !=NULL){
// *length=len;
// *height=hgt;
// }
// else
// exit(1);
// }
// // copy constructor - Deep Copy with a Wall object as parameter
// // copies data of the obj parameter
// Wall(Wall &obj) {
// length=new double;
// height= new double;
// *length = *(obj.length);
// *height = *(obj.height);
// }
// set_values(double len, double hei){
// *length=len;
// *height=hei;
// }
// double calculateArea() {
// return (*length) * (*height);
// }
// ~Wall(){
// delete height;
// delete length;
// }
// };
// int main() {
// // create an object of Wall class
// Wall wall1(10.5, 8.6);
// // copy contents of wall1 to wall2
// Wall wall2 = wall1;
// // print areas of wall1 and wall2
// cout << "Area of Wall 1: "<<wall1.calculateArea()<< endl;
// cout << "Area of Wall 2: " << wall2.calculateArea()<<endl;
// wall2.set_values(2.3,1.5);
// cout<<"after changing values for wall 2"<<endl;
// cout <<"Area of Wall 1: " << wall1.calculateArea()<< endl;
// cout << "Area of Wall 2: " << wall2.calculateArea();
// return 0;
// }

#include <iostream>
using namespace std;
class HelloWorld{
public:
HelloWorld(){
cout<<"Constructor is called"<<endl;
}
~HelloWorld(){
cout<<"Destructor is called"<<endl;
}
void display(){
cout<<"Hello World!"<<endl;
}
};
int main(){
HelloWorld obj;
obj.display();
return 0;
}


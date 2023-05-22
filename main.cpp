//Jose Jimenez
//CECS 282 - 04
//Prog 6 - Luggage
//Due Date: 05 - 05 - 2022
//
//I certify that this program is my own original work. I did not 
//copy any part of this program from any other source. I further certify 
//that I typed each and every line of code in this program.
#include <iostream>
#include<vector>
using namespace std;
#include <iomanip>
#include <stdio.h>

//abstract base class
class luggage{
  protected:
    static double totalVol;
    string type;
    static int lugTotal;
    static int serialNumGen;
    int serialNum;
  public:
    luggage(){
      type = "luggage";
      lugTotal+=1;
      serialNum = serialNumGen++;
      cout << "Creating luggage" << endl;
    }
    
    virtual double getVolume() = 0;
    
    static double getTotalVolume(){
      return totalVol;
    }

    static int getCount(){
      return lugTotal;
    }

    string getType(){
      return type;
    }

    string getSerial(){
      return "SN: " + to_string(serialNum) + ")";
    }

    friend ostream & operator<<(ostream& stream, luggage * lptr){
      stream << setw(10)<<left<<lptr->getType()<<": "<<setw(6)<<right<<setprecision(1)<<fixed<<lptr->getVolume()<<" - "<<lptr->getSerial();
      return stream;
  }
};

int luggage::lugTotal = 0;
int luggage::serialNumGen = 1;
double luggage::totalVol = 0;
class box : public luggage{
private:
double h;
double w;
double l;
static int lugTotal;
static double totalVol;

public:
box(double width, double height, double length){
  h = height;
  w = width;
  l = length;
  type = "Box";
  lugTotal++;
  totalVol += getVolume();
  luggage::totalVol+= getVolume();
  cout << "Created box " << "(Volume: " << getVolume() << " " << getSerial() <<endl;
}
double getVolume(){
  double b = w * h * l;
  return b;
}

static int getCount(){
  return lugTotal;
}

static double getTotalVolume(){
  return totalVol;
}

};//end of box

double box::totalVol = 0;
int box::lugTotal = 0;

class sphere : public luggage{
private:
double r;
static int lugTotal;
static double totalVol;

public:
sphere(double radius){
  r = radius;
  type = "Sphere";
  lugTotal++;
  totalVol += getVolume();
  luggage::totalVol+= getVolume();
  cout << "Created sphere " << "(Volume: " << getVolume() << " " << getSerial() <<endl;
}
double getVolume(){
  double s = (4.0/3.0) * 3.14 * (r*r*r);
  return s;
}

static int getCount(){
  return lugTotal;
}

static double getTotalVolume(){
  return totalVol;
}

};//end of the sphere
double sphere::totalVol = 0;
int sphere::lugTotal = 0;

class cube : public luggage{
private:
double w;
static int lugTotal;
static double totalVol;

public:
cube(double width){
  w = width;
  type = "Cube";
  lugTotal++;
  totalVol += getVolume();
  luggage::totalVol+= getVolume();
  cout << "Created cube " << "(Volume: " << getVolume() << " " << getSerial() <<endl;
}
double getVolume(){
  double wi = w*w*w;
  return wi;
}

static int getCount(){
  return lugTotal;
}

static double getTotalVolume(){
  return totalVol;
}

};//end of the cube
double cube::totalVol = 0;
int cube::lugTotal = 0;

class pyramid : public luggage{
private:
double b;
double h;
static int lugTotal;
static double totalVol;
public:
pyramid(double base ,double height){
      b = base;
      h = height;
      lugTotal+=1;
      type = "Pyramid";
      totalVol += getVolume();
      luggage::totalVol+= getVolume();
      cout << "Created Pyramid " << "(Volume: " << getVolume() << " " << getSerial() <<endl; 
    }

    double getVolume(){
      double p = (1.0/3.0) * (b * b) * h;
      return p;
    }

    static int getCount(){
      return lugTotal;
    }

    static double getTotalVolume(){
      return totalVol;
    }


};//end of pyramid
double pyramid::totalVol = 0;
int pyramid::lugTotal = 0;

class cylinder : public luggage{
private:
double l;
double r;
static int lugTotal;
static double totalVol;
public:
cylinder(double radius,double length){
      l = length;
      r = radius;
      lugTotal+=1;
      type = "Cylinder";
      totalVol += getVolume();
      luggage::totalVol+= getVolume();
      cout << "Created cylinder " << "(Volume: " << getVolume() << " " << getSerial() <<endl; 
    }

    double getVolume(){
      double c = 3.14 * (r * r) * l;
      return c;
    }

    static int getCount(){
      return lugTotal;
    }

    static double getTotalVolume(){
      return totalVol;
    }


};//end of cylinder
double cylinder::totalVol = 0;
int cylinder::lugTotal = 0;


int menu(){
  //menu
  int input = 0;
    cout<<"1) Add luggage to storage container\n";
    cout<<"2) Remove luggage from storage container\n";
    cout<<"3) Show all luggage\n";
    cout<<"4) Show total volumes\n";
    cout<<"5) Quit\n";

    cin >> input;//getting input
  return input;
}


int main() {
  bool running = true;
  int input1;
  int displayCount = 0;
  double w;
  double l;
  double h;
  double b;
  double r;
  int sn;
  vector<luggage*> container{};//vector of that luggage pointers
  while(running != false){
    int input = menu();
    //users choice
    if(input == 1){
      cout << "What type of luggage do you want to add:"<<endl;
      cout <<"1) Box"<<endl;
      cout << "2) Cylinder"<<endl;
      cout << "3) Sphere"<<endl;
      cout << "4) Cube"<<endl;
      cout << "5) Pyramid"<<endl;
      cin >> input1;
      if(input1 == 1){
        cout << "(Box) Enter the width, height and length: \n";
        cin >> w;
        cin >> h;
        cin >> l;
        container.push_back(new box(w, h, l));
        cout << endl;
      }
      else if(input1 == 2){
        cout << "(Cylinder) Enter the radius and length: \n";
        cin >> r;
        cin >> l;
        container.push_back(new cylinder(r, l));
        cout << endl;
      }
      else if(input1 == 3){
        cout << "(Sphere) Enter radius: \n";
        cin >> r;
        container.push_back(new sphere(r));
        cout << endl;
      }
      else if(input1 == 4){
        cout << "(Cube) Enter width: \n";
        cin >> w;
        container.push_back(new cube(w));
        cout << endl;
      }
      else{
        cout << "(Pyramid) Enter base and height: \n";
        cin >> b;
        cin >> h;
        container.push_back(new pyramid(b, h));
        cout << endl;
        
      }
    }//end of first input
    else if(input == 2){
      cout << "Enter the serial number you want to remove:\n";
      int index = 0;
      cin >> sn;
      container.erase(container.begin()+ sn-1);
      for(auto l:container){
        cout << ++displayCount<<") "<< l << endl;
      }
      displayCount = 0; 
      cout << endl;
      //container.erase(container.begin()+ sn-1);
      
    }//end of second input
    else if(input == 3){
      int count = 0;
      for(auto l:container) // container is vector<luggage*>
      cout << ++count<<") "<< l << endl;
      cout << "Total Volume: "<<luggage::getTotalVolume()<<"\n"<<endl;
      cout << "Total Luggage Items: "<<luggage::getCount()<<endl;
      cout << "Total Boxes: "<<box::getCount()<<endl;
      cout << "Total Spheres: "<<sphere::getCount()<<endl;
      cout << "Total Cubes: "<<cube::getCount()<<endl;
      cout << "Total Cylinders: "<<cylinder::getCount()<<endl;
      cout << "Total Pyramid: "<<pyramid::getCount()<<endl;
    }
    else if(input == 4){
      cout<<"Item type    Total Volume"<<endl;
      cout<<"Box    "<<box::getTotalVolume()<<endl;
      cout<<"Sphere    "<<sphere::getTotalVolume()<<endl;
      cout<<"Cube    "<<cube::getTotalVolume()<<endl;
      cout<<"Cylinder    "<<cylinder::getTotalVolume()<<endl;
      cout<<"Pyramid    "<<pyramid::getTotalVolume()<<endl;
      cout<<"Luggage    "<<luggage::getTotalVolume()<<endl;
    }
    else{//(input == 5)
      break;
    }
    
  }//end of the while loop
}//end of the main
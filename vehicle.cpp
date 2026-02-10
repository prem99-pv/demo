#include<iostream>
using namespace std;

class vehicle{
    private:
       int vehicleid;
       string manufacturer;
       string model;
       int year;

public:
    static int totalVehicles;
    vehicle(){
        totalVehicles++;
    }
    void setDetails(int id, string manu, string mod, int yr){
        vehicleid = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }
    int getVehicleID(){
        return vehicleid;
    }
    void getDetails(){
        cout<<"Vehicle ID: "<<vehicleid<<endl;
        cout<<"Manufacturer: "<<manufacturer<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }
};
int vehicle::totalVehicles = 0;

class car : public vehicle{
    private:
        string fueltype;
    public:
        void setCarDetails(int id, string manu, string mod, int yr, string fuel){
            setDetails(id, manu, mod, yr);
            fueltype = fuel;
        }
        void getCarDetails(){
            getDetails();
            cout<<"Fuel Type: "<<fueltype<<endl;
        }
};
class ElectricCar : public car{
    private:
        int batteryCapacity;
    public:
        void setElectricCarDetails(int id, string manu, string mod, int yr, string fuel, int battery){
            setCarDetails(id, manu, mod, yr, fuel);
            batteryCapacity = battery;
        }
        void getElectricCarDetails(){
            getCarDetails();
            cout<<"Battery Capacity: "<<batteryCapacity<<" kWh"<<endl;
        }
};
class Sportscar : public ElectricCar{
    private:
        int topSpeed;
    public:
        void setSportscarDetails(int id, string manu, string mod, int yr, string fuel, int battery, int speed){
            setElectricCarDetails(id, manu, mod, yr, fuel, battery);
            topSpeed = speed;
        }
        void getSportscarDetails(){
            getElectricCarDetails();
            cout<<"Top Speed: "<<topSpeed<<" km/h"<<endl;
        }
};
class aircraft{
    private:
       int flightrange;
       public:
        void setFlightRange(int range){
            flightrange = range;
        }
};
class flyingcar : public car, public aircraft{
    private:
        int wingSpan;
    public:
        void setFlyingCarDetails(int id, string manu, string mod, int yr, string fuel, int range, int wing){
            setCarDetails(id, manu, mod, yr, fuel);
            setFlightRange(range);
            wingSpan = wing;
        }
        void getFlyingCarDetails(){
            getCarDetails();
            cout<<"Wing Span: "<<wingSpan<<" meters"<<endl;
        }
};
class sedan : public car{
    private:
        int trunkCapacity;
    public:
        void setSedanDetails(int id, string manu, string mod, int yr, string fuel, int trunk){
            setCarDetails(id, manu, mod, yr, fuel);
            trunkCapacity = trunk;
        }
        void getSedanDetails(){
            getCarDetails();
            cout<<"Trunk Capacity: "<<trunkCapacity<<" liters"<<endl;
        }
};
class vehicleregistry{
    vehicle* vehicles[100];
    int count;

    public:
        vehicleregistry(){
            count = 0;
        }
        void addVehicle(vehicle* v){
            vehicles[count++] = v;
        }
        void displayAllVehicles(){
            for(int i=0; i<count; i++){
                vehicles[i]->getDetails();
                cout<<endl;
            }
        }
        void searchByVehicleID(int id){
           for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                vehicles[i]->getDetails();
                cout << endl;
                return;
            }
        }
            cout<<"Vehicle with ID "<<id<<" not found."<<endl;
        }
};
int main(){
  vehicleregistry registry;
  int choice ;

  do{
    cout<<"\nVehicle Registry Menu";
    cout<<"\n1. Add Vehicle";
    cout<<"\n2. Add Electric Sports car";
    cout<<"\n3. Add Flying Car";
    cout<<"\n4. View all vehicles";
    cout<<"\n5. Search Vehicle by ID";
    cout<<"\n6. Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;  
    
    if(choice == 1){
        int id, year;
        string manu, mod, fuel;
        cout<<"Enter Vehicle ID: ";
        cin>>id;
        cout<<"Enter Manufacturer: ";
        cin>>manu;
        cout<<"Enter Model: ";
        cin>>mod;
        cout<<"Enter Year: ";
        cin>>year;
        cout<<"Enter Fuel Type: ";
        cin>>fuel;

        car* c = new car();
        c->setCarDetails(id, manu, mod, year, fuel);
        registry.addVehicle(c);
    }
    else if(choice == 2){
        int id, year, battery, speed;
        string manu, mod, fuel;
        cout<<"Enter Vehicle ID: ";
        cin>>id;
        cout<<"Enter Manufacturer: ";
        cin>>manu;
        cout<<"Enter Model: ";
        cin>>mod;
        cout<<"Enter Year: ";
        cin>>year;
        cout<<"Enter Fuel Type: ";
        cin>>fuel;
        cout<<"Enter Battery Capacity (kWh): ";
        cin>>battery;
        cout<<"Enter Top Speed (km/h): ";
        cin>>speed;

        Sportscar* sc = new Sportscar();
        sc->setSportscarDetails(id, manu, mod, year, fuel, battery, speed);
        registry.addVehicle(sc);
    }
    else if(choice == 3){
        int id, year, range, wing;
        string manu, mod, fuel;
        cout<<"Enter Vehicle ID: ";
        cin>>id;
        cout<<"Enter Manufacturer: ";
        cin>>manu;
        cout<<"Enter Model: ";
        cin>>mod;
        cout<<"Enter Year: ";
        cin>>year;
        cout<<"Enter Fuel Type: ";
        cin>>fuel;
        cout<<"Enter Flight Range (km): ";
        cin>>range;
        cout<<"Enter Wing Span (meters): ";
        cin>>wing;

        flyingcar* fc = new flyingcar();
        fc->setFlyingCarDetails(id, manu, mod, year, fuel, range, wing);
        registry.addVehicle(fc);
    }
    else if(choice == 4){
        registry.displayAllVehicles();
    }
    else if(choice == 5){
        int searchID;
        cout<<"Enter Vehicle ID to search: ";
        cin>>searchID;
        registry.searchByVehicleID(searchID);
    }
  }while(choice != 6);
  cout<<"Total Vehicles Registered: "<<vehicle::totalVehicles<<endl;
}

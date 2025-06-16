#include "CarpoolSystem.h"
#include "MyString.h"
#include "Parent.h"
#include "Driver.h"
#include "Child.h"
#include "VehicleInfo.h"
#include <ctime>

int main() {
    CarpoolSystem system;

    // Create Parents
    Parent* p1 = new Parent("Sara", "Ali", "sara@example.com", "111", "Lahore");
    Parent* p2 = new Parent("John", "Doe", "john@example.com", "222", "Karachi");

    // Create Children
    Child* c1 = new Child(7, p1);
    Child* c2 = new Child(8, p2);
    c1->addEmergencyContact("123");
    c2->addEmergencyContact("1122");

    p1->addChild(c1);
    p2->addChild(c2);

    // Create Vehicles and Drivers
    VehicleInfo* car = new Car("Toyota", 4);
    VehicleInfo* bike = new Bike("Honda", 1);
    Driver* d1 = new Driver("Adeel", "Khan", "adeel@example.com", "333", "Lahore", car);
    Driver* d2 = new Driver("Nida", "Zehra", "nida@example.com", "444", "Karachi", bike);

    d1->addAvailability(1);
    d2->addAvailability(2);

    // Add to system
    system.addUser(p1);
    system.addUser(p2);
    system.addUser(d1);
    system.addUser(d2);

    // Create RideOffers
    tm rideTime{};
    rideTime.tm_hour = 8;
    rideTime.tm_min = 30;

    RideOffer* ro1 = new RideOffer("Lahore", "School", rideTime, p1);
    RideOffer* ro2 = new RideOffer("Karachi", "School", rideTime, p2);
    p1->createRideOffer(ro1);
    p2->createRideOffer(ro2);

    system.addRideOffer(ro1);
    system.addRideOffer(ro2);

    // Process offers
    system.processRequests();

    return 0;
}

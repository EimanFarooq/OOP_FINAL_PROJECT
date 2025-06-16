#ifndef CARPOOLSYSTEM_H
#define CARPOOLSYSTEM_H

#include "Parent.h"
#include "Driver.h"
#include "RideOffer.h"
#include "Logger.h"

class CarpoolSystem {
private:
    MyVector<Person*> users;
    MyVector<RideOffer*> activeOffers;

public:
    void addUser(Person* user) {
        users.push_back(user);
        Logger::logEvent("User added to system.");
    }

    void addRideOffer(RideOffer* offer) {
        activeOffers.push_back(offer);
        Logger::logEvent("Ride offer added to system.");
    }

    void processRequests() {
        for (int i = 0; i < activeOffers.size(); ++i) {
            if (!activeOffers[i]->isBooked()) {
                for (int j = 0; j < users.size(); ++j) {
                    if (users[j]->getUserType() == DRIVER) {
                        Driver* d = static_cast<Driver*>(users[j]);
                        Booking* b = new Booking(activeOffers[i], d);
                        d->addBooking(b);
                        activeOffers[i]->setBooking(b);
                        break; 
                    }
                }
            }
        }
    }
};

#endif

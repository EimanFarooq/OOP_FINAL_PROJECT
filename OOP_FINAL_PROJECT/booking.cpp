#include "Booking.h"
#include "Driver.h" 

void Booking::display() const {
    std::cout << "Booking Info:\n";
    if (offer)
        offer->display();
    if (driver)
        driver->displayInfo();
    std::cout << "Rating: " << rating << ", Comment: " << comment << "\n";
}

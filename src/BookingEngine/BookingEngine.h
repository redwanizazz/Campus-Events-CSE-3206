#ifndef BOOKINGENGINE_H
#define BOOKINGENGINE_H
#include <string>
#include "../Notification/IObserver.h"

class BookingEngine {
private:
    IObserver* observer;
public:
    void addObserver(IObserver* obs) { observer = obs; }
    bool bookTicket(int userId, int eventId) {
        if (observer) {
            observer->update("Booking Confirmed: Event " + std::to_string(eventId));
        }
        return true;
    }
};

#endif
#include "findBookingById.h"

Booking* findBookingById(
    vector<Booking>& bookings,
    int bookingId
)
{
    
    for (int i = 0; i < bookings.size(); i++)
    {
        if (bookings[i].bookingId == bookingId)
        {
            return &bookings[i];
        }
    }

    return nullptr;
}
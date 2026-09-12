#include "findBookingById.h"
Booking* findBookingById(
    vector<Booking>& bookingList,
    int bookingId
)
{
    for (auto& booking : bookingList)
    {
        if (booking.bookingId == bookingId)
            return &booking;
    }
    return nullptr;
}

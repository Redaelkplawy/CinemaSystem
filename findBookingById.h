#pragma once

#include "CinemaData.h" 
#include <vector>

Booking* findBookingById(
    vector<Booking>& bookings,
    int bookingId
);

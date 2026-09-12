#pragma once

#include "CinemaData.h" 
#include <vector>

using namespace std;

Booking* findBookingById(
    vector<Booking>& bookings,
    int bookingId
);

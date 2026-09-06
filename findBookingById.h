#pragma once
#include "cinema Data .h"
#include <vector>

using namespace std;

Booking* findBookingById(
    vector<Booking>& bookings,
    int bookingId
);

#include "cancelBooking.h"
#include "findBookingById.h"  
#include "unbookSeat.h"        
#include <iostream>

using namespace std;

void cancelBooking(vector<Booking>& bookingList, vector<Movie>& movieList) {
    if (bookingList.empty()) {
        cout << "No bookings available.\n";
        return;
    }

    int bookingId;
    cout << "Enter booking ID to cancel: ";
    cin >> bookingId;

    // البحث عن الحجز
    Booking* booking = findBookingById(bookingList, bookingId);
    if (booking == nullptr) {
        cout << "Booking not found.\n";
        return;
    }

    if (!booking->isActive) {
        cout << "This booking is already cancelled.\n";
        return;
    }

    // إرجاع المقاعد
    for (auto& movie : movieList) {
        if (movie.movieId == booking->movieId) {
            for (const auto& seat : booking->seats) {
                // استخدام unbookSeat لإرجاع المقعد
                unbookSeat(movie.seats, seat.first, seat.second);
            }
            break;
        }
    }

    booking->isActive = false;
    cout << "Booking cancelled successfully.\n";
}

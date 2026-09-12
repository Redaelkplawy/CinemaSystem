#include "printTicket.h"
#include "CinemaData.h" 

#include <iostream>

using namespace std;

void printTicket(const Booking& booking, const Movie& movie) {
    cout << "\n";
    cout << "==============================\n";
    cout << "         CINEMA TICKET        \n";
    cout << "==============================\n";

    cout << "Booking ID: " << booking.bookingId << "\n";
    cout << "Customer ID: " << booking.customer.customerId << "\n";
    cout << "Customer Name: " << booking.customer.fullName << "\n";
    cout << "Phone: " << booking.customer.phone << "\n";
    cout << "Movie: " << movie.name << "\n";
    cout << "Showtime: " << movie.showtime << "\n";
    cout << "Hall: " << movie.hallId << "\n";

    cout << "Seats: ";
    for (const auto& [row, col] : booking.seats) {    // range-based for
        cout << "(" << (row + 1) << "," << (col + 1) << ") ";
    }
    cout << "\n";

    cout << "Number of Seats: " << booking.seatCount << "\n";
    cout << "Booking Date: " 
         << booking.bookingDate.day << "/" 
         << booking.bookingDate.month << "/" 
         << booking.bookingDate.year << "\n";
    cout << "Original Price: " << booking.originalPrice << "\n";
    cout << "Discount: " << booking.discountAmount << "\n";
    cout << "Total Price: " << booking.totalPrice << "\n";
    cout << "==============================\n";
}

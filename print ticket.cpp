#include "print ticket.h"
#include "cinema Data .h"

#include <iostream>

using namespace std;

void printTicket(
    const Booking& booking,
    const Movie& movie
)
{
    cout << "\n";
    cout << "==============================\n";
    cout << "         CINEMA TICKET        \n";
    cout << "==============================\n";

    cout << "Booking ID: "
        << booking.bookingId
        << endl;

    cout << "Customer ID: "
        << booking.customer.customerId
        << endl;

    cout << "Customer Name: "
        << booking.customer.fullName
        << endl;

    cout << "Phone: "
        << booking.customer.phone
        << endl;

    cout << "Movie: "
        << movie.name
        << endl;

    cout << "Showtime: "
        << movie.showtime
        << endl;

    cout << "Hall: "
        << movie.hallId
        << endl;

    cout << "Seats: ";

    for (int i = 0; i < booking.seats.size(); i++)
    {
        cout << "("
            << booking.seats[i].first + 1
            << ","
            << booking.seats[i].second + 1
            << ") ";
    }

    cout << endl;

    cout << "Number of Seats: "
        << booking.seatCount
        << endl;

    cout << "Booking Date: "
        << booking.bookingDate.day
        << "/"
        << booking.bookingDate.month
        << "/"
        << booking.bookingDate.year
        << endl;

    cout << "Original Price: "
        << booking.originalPrice
        << endl;

    cout << "Discount: "
        << booking.discountAmount
        << endl;

    cout << "Total Price: "
        << booking.totalPrice
        << endl;

    cout << "==============================\n";
    
}
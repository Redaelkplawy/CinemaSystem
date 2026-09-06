#include "cancelBooking.h"
#include <iostream>

using namespace std;

void cancelBooking(
    vector<Booking>& bookings,
    vector<Movie>& movies
)
{
    if (bookings.empty())
    {
        cout << "No bookings available.\n";
        return;
    }

    int bookingId;

    cout << "Enter booking ID to cancel: ";
    cin >> bookingId;

    for (int i = 0; i < bookings.size(); i++)
    {
        if (bookings[i].bookingId == bookingId)
        {
            if (!bookings[i].isActive)
            {
                cout << "This booking is already cancelled.\n";
                return;
            }

            for (int j = 0; j < movies.size(); j++)
            {
                if (movies[j].movieId == bookings[i].movieId)
                {
                    for (int k = 0; k < bookings[i].seats.size(); k++)
                    {
                        int row = bookings[i].seats[k].first;
                        int column = bookings[i].seats[k].second;

                        movies[j].seats[row][column] = 'O';
                    }

                    break;
                }
            }

            bookings[i].isActive = false;

            cout << "Booking cancelled successfully.\n";
            return;
        }
    }

    cout << "Booking not found.\n";
}
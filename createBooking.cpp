#include "createBooking.h"
#include "cinemaData.h"
#include <iostream>
#include <vector>

using namespace std;

void creatBooking(
    vector<Movie>& movies,
    vector<Booking>& bookings
)
{
    // «· √ﬂœ „‰ ÊÃÊœ √›·«„
    if (movies.empty())
    {
        cout << "No movies available.\n";

        return;
    }

    // ⁄‰Ê«‰ ﬁ«∆„… «·√›·«„
    cout << "\n===== Movies =====\n";

    // ⁄—÷ «·√›·«„
    for (int i = 0; i < movies.size(); i++)
    {
        cout << i + 1 << ". "
            << movies[i].name
            << " - "
            << movies[i].price
            << endl;
    }
     // «Œ Ì«— ›Ì·„
    int movieChoice;

    cout << "\nChoose a movie: ";
    cin >> movieChoice;

    while (movieChoice < 1 || movieChoice > movies.size())
    {
        cout << "Invalid choice. Choose again: ";
        cin >> movieChoice;
    }

    Movie& selectedMovie = movies[movieChoice - 1];

    cout << "\nYou selected: "
        << selectedMovie.name
        << endl;
    //⁄—÷ «·„ﬁ«⁄œ
    cout << "\n===== Seats =====\n";

    for (int i = 0; i < selectedMovie.seats.size(); i++)
    {
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < selectedMovie.seats[i].size(); j++)
        {
            cout << selectedMovie.seats[i][j] << " ";
        }

        cout << endl;
        
    }
    
    //«Œ Ì«— „ﬁ⁄œ
    int seatCount;

    cout << "\nHow many seats do you want? ";
    cin >> seatCount;

    while (seatCount <= 0)
    {
        cout << "Invalid number. Enter again: ";
        cin >> seatCount;
    }

    Booking newBooking;

    newBooking.movieId = selectedMovie.movieId;
    newBooking.movieName = selectedMovie.name;
    newBooking.seatCount = seatCount;
    newBooking.pricePerSeat = selectedMovie.price;

    for (int i = 0; i < seatCount; i++)
    {
        int row;
        int column;

        cout << "\nSeat " << i + 1 << endl;

        cout << "Enter row: ";
        cin >> row;

        cout << "Enter column: ";
        cin >> column;

        while (
            row < 1 ||
            row > selectedMovie.seats.size() ||
            column < 1 ||
            column > selectedMovie.seats[row - 1].size()
            )
        {
            cout << "Invalid seat. Try again.\n";

            cout << "Enter row: ";
            cin >> row;

            cout << "Enter column: ";
            cin >> column;
        }

        if (selectedMovie.seats[row - 1][column - 1] == 'X')
        {
            cout << "This seat is already booked.\n";

            i--;
            continue;// loop⁄‘«‰ „ÌŒ—Ã‘ »—Â «· 
        }

        selectedMovie.seats[row - 1][column - 1] = 'X';

        newBooking.seats.push_back(
            { row - 1, column - 1 }
        );

        cout << "Seat booked successfully.\n";
    }
    // Õ”«» ”⁄— «· –ﬂ—Â
    // Calculate original price
    newBooking.originalPrice =
        newBooking.pricePerSeat * newBooking.seatCount;

    // Calculate discount
    if (newBooking.seatCount > 4)
    {
        newBooking.discountAmount =
            newBooking.originalPrice * 0.10;
    }
    else
    {
        newBooking.discountAmount = 0.0;
    }

    // Calculate total price
    newBooking.totalPrice =
        newBooking.originalPrice - newBooking.discountAmount;
    cout << "\nOriginal Price: "
        << newBooking.originalPrice
        << endl;

    cout << "Discount: "
        << newBooking.discountAmount
        << endl;

    cout << "Total Price: "
        << newBooking.totalPrice
        << endl;
    
    cout << "\n===== Customer Information =====\n";

    cout << "Enter customer ID: ";
    cin >> newBooking.customer.customerId;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, newBooking.customer.fullName);

    cout << "Enter phone: ";
    cin >> newBooking.customer.phone;
    //id ticket
    if (bookings.empty())
    {
        newBooking.bookingId = 1001;
    }
    else
    {
        newBooking.bookingId = bookings.back().bookingId + 1;
    }
    //  «—ÌŒ «·ÕÃ“
    cout << "\n===== Booking Date =====\n";

    cout << "Enter day: ";
    cin >> newBooking.bookingDate.day;

    cout << "Enter month: ";
    cin >> newBooking.bookingDate.month;

    cout << "Enter year: ";
    cin >> newBooking.bookingDate.year;
    // Õ›Ÿ «·ÕÃ“ 
    bookings.push_back(newBooking);
    //—”«·… «·‰Ã«Õ
    cout << "\nBooking completed successfully!\n";

    cout << "Booking ID: "
        << newBooking.bookingId
        << endl;

    cout << "Movie: "
        << newBooking.movieName
        << endl;

    cout << "Customer: "
        << newBooking.customer.fullName
        << endl;

    cout << "Number of Seats: "
        << newBooking.seatCount
        << endl;cout << "total price : "
        << newBooking.totalPrice 
        << endl;

   

}
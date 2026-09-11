#include "createBooking.h"
#include "displaySeats.h"          
#include "isSeatAvailable.h"       
#include "bookSeat.h"              
#include "calculateTotalPrice.h"   
#include "getIntInput.h"           
#include "getStringInput.h"       

#include <iostream>
using namespace std;

void createBooking(vector<Movie>& movieList, vector<Booking>& bookingList)
{
    // 1. التحقق من وجود أفلام
    if (movieList.empty()) {
        cout << "No movies available.\n";
        return;
    }

    // 2. عرض قائمة الأفلام
    cout << "\n===== Movies =====\n";
    for (size_t i = 0; i < movieList.size(); i++) {
        cout << (i + 1) << ". "
             << movieList[i].name
             << " - " << movieList[i].price << " EGP\n";
    }

    // 3. اختيار فيلم
    cout << "\nChoose a movie (1-" << movieList.size() << "): ";
    int movieChoice = getIntInput(1, static_cast<int>(movieList.size()));
    Movie& selectedMovie = movieList[movieChoice - 1];

    cout << "\nYou selected: " << selectedMovie.name << "\n";

    // 4. عرض خريطة المقاعد
    displaySeats(selectedMovie.seats);

    // 5. اختيار عدد التذاكر
    cout << "\nHow many seats do you want? ";
    int seatCount = getIntInput(1, 10);

    Booking newBooking;
    newBooking.movieId = selectedMovie.movieId;
    newBooking.movieName = selectedMovie.name;
    newBooking.seatCount = seatCount;
    newBooking.pricePerSeat = selectedMovie.price;

    // 6. اختيار المقاعد (حلقة واحدة مع إعادة المحاولة عند الحجز المزدوج)
    int bookedSeats = 0;
    while (bookedSeats < seatCount) {
        cout << "\n--- Seat " << (bookedSeats + 1) << " of " << seatCount << " ---\n";

        cout << "Enter row (1-" << selectedMovie.seats.size() << "): ";
        int row = getIntInput(1, static_cast<int>(selectedMovie.seats.size())) - 1;

        cout << "Enter column (1-" << selectedMovie.seats[row].size() << "): ";
        int col = getIntInput(1, static_cast<int>(selectedMovie.seats[row].size())) - 1;

        if (!isSeatAvailable(selectedMovie.seats, row, col)) {
            cout << "This seat is already booked. Please choose another.\n";
            continue;  // ✅ بدل i-- (أكثر وضوحاً)
        }

        bookSeat(selectedMovie.seats, row, col);
        newBooking.seats.push_back({row, col});
        bookedSeats++;
        cout << "Seat booked successfully.\n";
    }

    // 7. حساب السعر باستخدام دالة مساعدة
    double discountAmount = 0.0;
    newBooking.originalPrice = newBooking.pricePerSeat * newBooking.seatCount;
    newBooking.totalPrice = calculateTotalPrice(
        newBooking.pricePerSeat,
        newBooking.seatCount,
        discountAmount
    );
    newBooking.discountAmount = discountAmount;

    cout << "\n--- Price Details ---\n";
    cout << "Original Price: " << newBooking.originalPrice << " EGP\n";
    cout << "Discount: " << newBooking.discountAmount << " EGP\n";
    cout << "Total Price: " << newBooking.totalPrice << " EGP\n";

    // 8. بيانات العميل
    cout << "\n===== Customer Information =====\n";
    cout << "Enter customer ID: ";
    newBooking.customer.customerId = getIntInput(1, 999999);

    newBooking.customer.fullName = getStringInput("Enter full name: ");
    newBooking.customer.phone = getStringInput("Enter phone: ");

    // 9. توليد رقم الحجز (من الثابت STARTING_BOOKING_ID)
    if (bookingList.empty()) {
        newBooking.bookingId = STARTING_BOOKING_ID;
    } else {
        newBooking.bookingId = bookingList.back().bookingId + 1;
    }

    // 10. تاريخ الحجز
    cout << "\n===== Booking Date =====\n";
    cout << "Enter day (1-31): ";
    newBooking.bookingDate.day = getIntInput(1, 31);

    cout << "Enter month (1-12): ";
    newBooking.bookingDate.month = getIntInput(1, 12);

    cout << "Enter year (2020-2100): ";
    newBooking.bookingDate.year = getIntInput(2020, 2100);

    // 11. حفظ الحجز
    bookingList.push_back(newBooking);

    // 12. رسالة النجاح
    cout << "\n========================================\n";
    cout << "   Booking completed successfully!\n";
    cout << "========================================\n";
    cout << "Booking ID     : " << newBooking.bookingId << "\n";
    cout << "Movie          : " << newBooking.movieName << "\n";
    cout << "Customer       : " << newBooking.customer.fullName << "\n";
    cout << "Number of Seats: " << newBooking.seatCount << "\n";
    cout << "Total Price    : " << newBooking.totalPrice << " EGP\n";
    cout << "========================================\n";
}

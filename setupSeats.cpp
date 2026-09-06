#include "setupSeats.h"
#include <iostream>

using namespace std;

void setupSeats(
    vector<vector<char>>& seats,
    int rows,
    int cols
)
{
    // ÊåíÁÉ ÇáãŞÇÚÏ
    seats = vector<vector<char>>( rows,vector<char>(cols, 'O')
    );

    // ÚäæÇä ÎÑíØÉ ÇáãŞÇÚÏ
    cout << "\n===== Seat Map =====\n";

    // ÇáãÑæÑ Úáì ÇáÕİæİ
    for (int i = 0; i < seats.size(); i++)
    {
        // ØÈÇÚÉ ÑŞã ÇáÕİ
        cout << "Row " << i + 1 << ": ";

        // ÇáãÑæÑ Úáì ÇáãŞÇÚÏ ÇáãæÌæÏÉ ÏÇÎá ÇáÕİ
        for (int j = 0; j < seats[i].size(); j++)
        {
            // ØÈÇÚÉ ÇáãŞÚÏ
            cout << seats[i][j] << " ";
        }

        // ÇáÇäÊŞÇá ááÓØÑ ÇáÊÇáí
        cout << endl;
    }
}
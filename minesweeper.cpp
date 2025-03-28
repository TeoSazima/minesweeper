#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

void vypispole(char hraciPole[10][10], bool debug, bool hratelnost);


int main()

{

    srand(time(NULL));

    bool debug = false;
    bool hratelnost = true;

    char hraciPole[10][10] = {};

    int miny_X = 0;

    int miny_Y = 0;

    int pocetMinOkolo = 0;


    int vstupY = 0;

    int vstupX = 0;


    for (int i = 0; i < 10; i++)

    {

        for (int j = 0; j < 10; j++)

        {
            hraciPole[i][j] = '#';
        }
    }


    for (int i = 0; i < 25; i++)

    {

        miny_X = rand() % 10;

        miny_Y = rand() % 10;

        if (hraciPole[miny_X][miny_Y] == 'X')

        {

            i--;

            continue;

        }

        else

        {

            hraciPole[miny_X][miny_Y] = 'X';

        }

    }
    
    vypispole(hraciPole, debug, hratelnost);

    while (hratelnost) {


        
        pocetMinOkolo = 0;

        cout << "Zadejte hodnotu X: ";

        cin >> vstupX;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "\nZadejte hodnotu Y: ";

        cin >> vstupY;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (vstupX < 0 || vstupX > 9)

        {

            cout << "zadali jste neplatnou hodnotu X\n";

            continue;

        }

        if (vstupY < 0 || vstupY > 9)

        {

            cout << "zadali jste neplatnou hodnotu Y\n";

            continue;

        }

        if (hraciPole[vstupX][vstupY] == 'X')

        {
            system("cls");
            cout << "Hra skoncila, stoupl jsi na minu.\n";
            cout << "Zadal jsi X: " << vstupX << "; Y: " << vstupY << " Kde se nachazela mina. \n\n";
            hratelnost = false;
            vypispole(hraciPole, debug, hratelnost);
            return(0);


        }

        else

        {


            for (int i = vstupY - 1; i <= vstupY + 1; i++)

            {

                for (int j = vstupX - 1; j <= vstupX + 1; j++)

                {

                    if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
                    {

                        if (hraciPole[j][i] == 'X') {
                        
                            pocetMinOkolo++;

                        }
                    }

                }

            }

            hraciPole[vstupX][vstupY] = pocetMinOkolo + '0';  // Převedení čísla na odpovídající znak ASCII
            system("cls");
            vypispole(hraciPole, debug, hratelnost);

        }

    }

}

void vypispole(char hraciPole[10][10], bool debug, bool hratelnost) {

    cout << "    0 1 2 3 4 5 6 7 8 9 Y\n";
    cout << "  " <<  (char)218 << "--------------------\n";

    for (int i = 0; i < 10; i++)

    {

            cout << i << " | ";
        

            for (int j = 0; j < 10; j++)

            {

                if ( hratelnost == true)
                {
                    if (hraciPole[i][j] == 'X' && debug == true)
                    {

                        cout << hraciPole[i][j] << " ";
                        continue;

                    }

                    if (hraciPole[i][j] == 'X')

                    {

                        cout << "# ";

                    }

                    else

                    {

                        cout << hraciPole[i][j] << " ";

                    }

                }

                else
                {
                    cout << hraciPole[i][j] << " ";
                }


            }
            
            cout << std::endl;
    }

    cout << "X\n\n";
}

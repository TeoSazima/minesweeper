#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

void vypispole();

int main()
{
    srand(time(NULL));


    char hraciPole[10][10] = {};
    int miny_X = 0;
    int miny_Y = 0;
    int pocetMinOkolo = 0;
    bool hratelnost = true;
    
    int vstupY = 0;
    int vstupX = 0;


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            hraciPole[i][j] = '#';
            std::cout << hraciPole[i][j];
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < 10; i++)
    {
        miny_X = rand() % 5;
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

    while (hratelnost) {

        pocetMinOkolo = 0;
        cout << "Zadejte hodnotu X: ";
        cin >> vstupX;
        cout << "\nZadejte hodnotu Y: ";
        cin >> vstupY;

        if (vstupX <= 0 || vstupX >= 11)
        {

            cout << "zadali jste neplatnou hodnotu X";
            continue;

        }
        if (vstupY <= 0 || vstupY >= 11)
        {
            cout << "zadali jste neplatnou hodnotu Y";
            continue;

        }

        if (hraciPole[vstupX][vstupY] == 'X')
        {

            cout << "Hra skoncila, stoupl jsi na minu.";
            return(0);


        }
        else
        {
           

            for (int i = vstupY - 1; i < vstupY + 1; i++)
            {

                for (int j = vstupX - 1; j < vstupX + 1; j++)
                {

                    if (hraciPole[j][i] == 'X')
                    {

                        pocetMinOkolo++;

                    }


                }

            }

            hraciPole[vstupX][vstupY] = pocetMinOkolo + '0';  // Převedení čísla na odpovídající znak ASCII
            vypispole();
        }

    }
}

void vypispole(char hraciPole[10][10]) {

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (hraciPole[i][j] == 'X')
            {
                cout << "#";
            }
            else
            {
                cout << hraciPole[i][j];
            }
        }
        cout << std::endl;
    }

}

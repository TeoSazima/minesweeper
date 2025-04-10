#include <iostream>
#include <ctime>
#include <windows.h> // pro funkci SetConsoleTextAttribute


using std::cout;
using std::cin;

void vypispole(char hraciPole[10][10], bool debug, bool hratelnost);
void uvodniText();
void odhalPole(char hraciPole[10][10], int x, int y);
void KonecHryText();
bool konecHryChecker(char HraciPole[10][10]);

int main()

{

    


    srand(time(NULL));

    bool debug = true;
    bool hratelnost = true;
    bool konecHry = false;

    char hraciPole[10][10] = {};

    int miny_X = 0;
    int miny_Y = 0;
    int pocetMinOkolo = 0;

    std::string vstupKontrolaVlajky = "0";
    bool pozadavekNaOznaceniVlajka = false;
    bool pozadavekNaOdebraniVlajka = false;

    int pocetmin = 25; //Zde se nastavuje pocet min
    int vstupY = 0;
    int vstupX = 0;


    for (int i = 0; i < 10; i++)

    {

        for (int j = 0; j < 10; j++)

        {
            hraciPole[i][j] = '#';
        }
    }


    for (int i = 0; i < pocetmin; i++)  

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
    uvodniText();
    vypispole(hraciPole, debug, hratelnost);

    while (hratelnost) {


        
        pocetMinOkolo = 0;
        pozadavekNaOznaceniVlajka = false;
        pozadavekNaOdebraniVlajka = false;

        cout << "Zadejte hodnotu X: ";

        cin >> vstupKontrolaVlajky;
        if (vstupKontrolaVlajky[0] == 'V' || vstupKontrolaVlajky[0] == 'F')
        {

            pozadavekNaOznaceniVlajka = true;
            vstupX = vstupKontrolaVlajky[1] - '0';

        }
        else
        {
            vstupX = vstupKontrolaVlajky[0] - '0';
        }
        
        //kontrola jestli rac chce odebrat vlajecku
        if (vstupKontrolaVlajky[0] == 'O' || vstupKontrolaVlajky[0] == 'R')
        {

            pozadavekNaOdebraniVlajka = true;
            vstupX = vstupKontrolaVlajky[1]  - '0';

        }
        


        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "\nZadejte hodnotu Y: ";

        cin >> vstupY;
        

        
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (vstupX < 0 || vstupX > 9 || vstupY < 0 || vstupY > 9)

        {

            cout << "zadali jste neplatnou hodnotu\n";
            cout << "X: " << vstupX << " Y: " << vstupY << std::endl;
            pozadavekNaOznaceniVlajka = false;
            pozadavekNaOdebraniVlajka = false;
            continue;

        }

        if (pozadavekNaOdebraniVlajka == true)
        {
            if (hraciPole[vstupX][vstupY] == 'A')
            {

                hraciPole[vstupX][vstupY] = 'X'; // Pokud hrac umistil vlajecku na minu nastavi se pole na minu
                pozadavekNaOdebraniVlajka = false;
                system("cls");
                vypispole(hraciPole, debug, hratelnost);
                
                if (konecHry == true)
                {

                    KonecHryText();
                    return(0);
                }
                
                konecHry = konecHryChecker(hraciPole);

                continue;


            }
           
            if (hraciPole[vstupX][vstupY] == 'B')
            {

                hraciPole[vstupX][vstupY] = '#'; // Pokud hrac umistil vlajecku na minu nastavi se pole na minu
                pozadavekNaOdebraniVlajka = false;
                system("cls");
               
                konecHry = konecHryChecker(hraciPole);
                if (konecHry == true)
                {

                    KonecHryText();
                    return(0);
                }
                
                vypispole(hraciPole, debug, hratelnost);
                
                continue;


            }


        }

        if (pozadavekNaOznaceniVlajka == true) {

            if (hraciPole[vstupX][vstupY] == 'X')
            {

                hraciPole[vstupX][vstupY] = 'A'; // hrac spravne polozil vlajecku


            }
            if (hraciPole[vstupX][vstupY] == '#')
            {

                hraciPole[vstupX][vstupY] = 'B'; //hrac polozil vlajecku na spatne misto



            }
        }
        

        if (hraciPole[vstupX][vstupY] == 'X')

        {
            system("cls");
            cout << "Hra skoncila, stoupl jsi na minu.\n";
            cout << "Zadal jsi X: " << vstupX << "; Y: " << vstupY << " Kde se nachazela mina. \n\n";
            hratelnost = false;
            vypispole(hraciPole, true, false);
            return(0);


        }

        else {

            if (pozadavekNaOznaceniVlajka == false && pozadavekNaOdebraniVlajka == false) {

                for (int i = vstupY - 1; i <= vstupY + 1; i++) {

                

                    for (int j = vstupX - 1; j <= vstupX + 1; j++) {

                    

                        if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
                        

                            if (hraciPole[j][i] == 'X' || hraciPole[j][i] == 'A' ) {

                                pocetMinOkolo++;
                            }

                        }
                    }
                }

                hraciPole[vstupX][vstupY] = pocetMinOkolo + '0';
            }
        }

        if (hraciPole[vstupX][vstupY] == '0')
        {

            odhalPole(hraciPole, vstupX, vstupY);

        }


        konecHry = konecHryChecker(hraciPole);
        if (konecHry == true)
        {

            KonecHryText();
            return(0);
        }


        system("cls");
        vypispole(hraciPole, debug, hratelnost);

        

    }

}


void uvodniText() {

    cout << R"(        _                                            
  _ __ (_)_ _  ___ ____ __ _____ ___ _ __  ___ _ _ 
 | '  \| | ' \/ -_|_-< V  V / -_) -_) '_ \/ -_) '_|
 |_|_|_|_|_||_\___/__/\_/\_/\___\___| .__/\___|_|   
                                    |_|            )" << std::endl;
    cout << "\n---------------------------------------------------\n";

    cout << "Vytejte ve hre minesweeper. Nize najdete pravidla a navod k pouziti:\n\n";

    cout << "Pravidla:\n";
    cout << "1) Cilem hry je najit vsechny miny a na zadnou neslapnout.\n";
    cout << "2) Pokud slapnete na minu tak automaticky prohravate.\n\n";

    cout << "Navod k pouziti:\n";
    cout << "1) Pro zadani pole je potreba zvolitt souradne X, Y; ktere se nachazeji po stranach herniho pole.\n";
    cout << "2) Pokud chcete oznacit pole Vlajkou (Domnivate se ze se pod pole nachazi mina), pridejte pred X souradnici pismeno F nebo V.\n";
    cout << "3) Pokud chcete odebra vlajecku z hraciho pole staci pred X souradnici napsat R nebo O (velke o).";

    cout << "\n---------------------------------------------------\n";
    system("pause");
    system("cls");

}

void KonecHryText() {

    system("cls");
    cout << R"(        _                                            
  _ __ (_)_ _  ___ ____ __ _____ ___ _ __  ___ _ _ 
 | '  \| | ' \/ -_|_-< V  V / -_) -_) '_ \/ -_) '_|
 |_|_|_|_|_||_\___/__/\_/\_/\___\___| .__/\___|_|   
                                    |_|            )" << std::endl;
    cout << "\n---------------------------------------------------\n";

    cout << "Gratuluji dohral jsi moji hru\n";
    cout << "Pokud ti hra prila priliz lehka, muzes si zvisit pocet min na radku: 38\n";
    cout << "Naopak pokud ti hra prisla priliz sozita muzes si pocet min snizit\n";
    
    cout << "\n---------------------------------------------------\n";
    
    
}


bool konecHryChecker(char HraciPole[10][10]) {

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (HraciPole[i][j] == 'B' || HraciPole[i][j] == 'X')
            {
                return false;
                break;
            }
        }
    }

    return true;
}

// Tuto funkci generoval Copilot a slouzi pouze pro zmenu barev

void nastavBarvu(int barva) {
    // Získáme handle pro konzoli
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Nastavíme barvu
    SetConsoleTextAttribute(hConsole, barva);
}

void odhalPole(char hraciPole[10][10], int vstupX, int vstupY) {
   


}


void vypispole(char hraciPole[10][10], bool debug, bool hratelnost) {

    cout << "    0 1 2 3 4 5 6 7 8 9 Y\n";
    cout << "  " <<  (char)218 << "--------------------\n";

    for (int i = 0; i < 10; i++)

    {

            cout << i << " | ";
        

            for (int j = 0; j < 10; j++)

            {

                if (hratelnost == true)
                {
                    if (hraciPole[i][j] == 'A' || hraciPole[i][j] == 'B')
                    {
                        nastavBarvu(12); // Cervena
                        cout << "! ";
                        nastavBarvu(7); // Bila
                        continue;
                    }

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

                        if (hraciPole[i][j] == '0')
                        {
                            nastavBarvu(10); // Svetle zelena
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '1')
                        {
                            nastavBarvu(1); // Modra
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '2')
                        {
                            nastavBarvu(6); // Zelena
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '3')
                        {
                            nastavBarvu(4); // Cervena
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '4')
                        {
                            nastavBarvu(5); // Fialova
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '5')
                        {
                            nastavBarvu(6); // Zluta
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '6')
                        {
                            nastavBarvu(6); // Azurova
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '7')
                        {
                            nastavBarvu(9); // Svetle modra
                            cout << hraciPole[i][j] << " ";
                            nastavBarvu(7); // Bila
                        }
                        else if (hraciPole[i][j] == '8')
                        {
                            nastavBarvu(7); // Bila
                            cout << hraciPole[i][j] << " ";
                            
                        }
                        else
                        {
                            cout << hraciPole[i][j] << " ";
                        }

                        

                    }


                }
                else
                {

                    if (hraciPole[i][j] == '0')
                    {
                        nastavBarvu(10); // Svetle zelena
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '1')
                    {
                        nastavBarvu(1); // Modra
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '2')
                    {
                        nastavBarvu(6); // Zelena
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '3')
                    {
                        nastavBarvu(4); // Cervena
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '4')
                    {
                        nastavBarvu(5); // Fialova
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '5')
                    {
                        nastavBarvu(6); // Zluta
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '6')
                    {
                        nastavBarvu(6); // Azurova
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '7')
                    {
                        nastavBarvu(9); // Svetle modra
                        cout << hraciPole[i][j] << " ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == '8')
                    {
                        nastavBarvu(7); // Bila
                        cout << hraciPole[i][j] << " ";

                    }
                    else if (hraciPole[i][j] == 'A')
                    {
                        nastavBarvu(12); // Cervena
                        cout << "! ";
                        nastavBarvu(7); // Bila
                    }
                    else if (hraciPole[i][j] == 'B')
                    {

                        cout << "# ";
                      
                    }
                    else if (hraciPole[i][j] == 'X')
                    {
                        nastavBarvu(15); // Cervena
                        cout << "X ";
                        nastavBarvu(7); // Bila
                    }
                    else
                    {
                        cout << hraciPole[i][j] << " ";
                    }

                }
            }
            
            cout << std::endl;
    }

    cout << "X\n\n";
} 

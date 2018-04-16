/*tekste isrename visus zodzius ir pateikiame visus zodzius i ekrana*/
/*ND reik panaudot MAP ir suskaiciuoti panaudotu zodziu skaiciu. Taip pat pasalinti
kablelius, kabutes ir t.t.*/

#include <cstdlib>
#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

class ZODYNAS
{
    private:
        set <string> zodis;
        set<string>::iterator iter;
    set<string>::iterator iter_ini;
    set<string>::iterator iter_fin;
    public:
        ZODYNAS();
        void skaityti_faila();
        void show();
};

//==============================================================================
ZODYNAS::ZODYNAS()//konstruktorius
{
   // zodis.erase(0);//nunulinam
}

//==============================================================================
void ZODYNAS::show()
{
    set<string>::iterator iter;
    set<string>::iterator iter_ini;
    set<string>::iterator iter_fin;

    iter_ini = zodis.begin();
    iter_fin = zodis.end();

    for (iter = iter_ini; iter != iter_fin; iter++)
        cout << *iter << endl;
    cout << endl;
}

//==============================================================================
void ZODYNAS::skaityti_faila()
{
    string s1;
    ifstream srautas("TEKSTAS.txt", ios::in | ios::binary);
// "|" zenklius reiskia, kad binary veiksmus vykdys, tik jei in veiksmai bus atlikti teisingai
    if (!srautas)
        {
            cout << "Failo nera" << endl;
            system("PAUSE");
            exit(0);
        }
    darkarta:
        srautas >> s1;
        zodis.insert(s1);
        if(srautas.eof()!=true)
        goto darkarta;
    srautas.close();
}

//==============================================================================
int main(int argc, char *argv[])
{
   ZODYNAS straipsniukstis;
    straipsniukstis.skaityti_faila();
    straipsniukstis.show();

    system("PAUSE");
    return EXIT_SUCCESS;
}

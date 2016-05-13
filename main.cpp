#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    // Tant que nous n'avons pas extrait toutes les lettres du mot
    while (mot.size() != 0)
    {
        // On choisit un num�ro de lettre au hasard dans le mot
        position = rand() % mot.size();
        // On ajoute la lettre dans le mot m�lang�
        melange += mot[position];
        // On retire cette lettre du mot myst�re pour ne pas la prendre une 2e fois
        mot.erase(position, 1);
    }

    // On renvoie le mot m�lang�
    return melange;
}

string recupererMotDictionnaire()
{
    ifstream monFlux("dico.txt");  //Ouverture d'un fichier en lecture
    int position(0);
    string motARetourner;

    if(monFlux)
    {
        int nbrMot = 323577;//Le nombre de mot dans le disctionnaire
        position = rand() % nbrMot;
        for(int i = 0; i < position ; i++)//on r�cup�re les mot jusqu'a arriv� au bon !
        {
            monFlux >> motARetourner;
        }

        monFlux.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return motARetourner;
}

int main()
{
    bool continuer = true;
    string motMystere, motMelange, motUtilisateur;

    // Initialisation des nombres al�atoires
    srand(time(0));
    int nbrEssai = 5;

    do
    {
        nbrEssai = 5;
        // On r�cup�re un mot dans le dictionnaire
        motMystere = recupererMotDictionnaire();

        // On r�cup�re le mot avec les lettre m�lang�es dans motMelange
        motMelange = melangerLettres(motMystere);

        // On demande � l'utilisateur quel est le mot myst�re
        do
        {
            cout << endl << "Quel est ce mot ? " << motMelange << endl;
            cout << endl << "Il vous reste " << nbrEssai << " essais" << endl;
            cin >> motUtilisateur;

            if (motUtilisateur == motMystere)
            {
                cout << "Bravo !" << endl;
            }
            else
            {
                cout << "Ce n'est pas le mot !" << endl;
                nbrEssai--;
                if(nbrEssai == 0) //Si il n'y a plus d'essai c'est perdu
                    cout << "VOUS AVEZ PERDU ! Le mot etait : " << motMystere << endl;
            }
        }while (motUtilisateur != motMystere && nbrEssai > 0); // On recommence tant qu'il n'a pas trouv� et si le nombre d'essai est au dessus de z�ro


        //**************proposition pour rejouer******************
        bool rejouerReponseObtenue = false;
        while(!rejouerReponseObtenue)
        {
            //on r�cup�re la r�ponse si on veux continuer
            cout << "Voulez vous rejouer ? o pour oui ou n pour non" << endl;
            char reponse;
            cin >> reponse;
            switch(reponse)
            {
                case 'o'://oui
                    rejouerReponseObtenue = true;
                    cout << "Super on va rejouer !" << endl;
                break;
                case 'n'://non
                    rejouerReponseObtenue = true;
                    continuer = false;
                    cout << "Snif... d'accord au revoir..." << endl;
                break;
                default://autre r�ponse
                    cout << "Je n'est pas comprie votre reponse !" << endl;
            }
        }

    }while (continuer);//On v�rifie si on rejoue a la partie !

    return 0;
}

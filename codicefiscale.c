#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 16
#define C 50


void fcognome(char *pcognome, char *pcodicefiscale);


void fnome(char *pnome, char *pcodicefiscale);


void fanno(int *pannonascita, char *pcodicefiscale);


void fmese(int *pmesenascita, char *pcodicefiscale);


void fgiornosesso(int *pgiornonascita, char *psesso, char *pcodicefiscale);


void fcomuni(char *pcodicefiscale);


char fcontrollo(char *codice);


int main(){


   char codicefiscale[N];


   /* _____________________________________
      | 1 - 3 cognome                     |
      | 4 - 6 nome                        |
      | 7 - 8 anno di nascita             |
      | 9 mese di nascita                 |
      | 10 - 11 giorno di nascita + sesso |
      | 12 - 15 comuni                    |
      | 16 carattere di controllo         |
      |___________________________________|
                                           
      - CCC --> Cognome
      - NNN --> Nome
      - AA       - M   --> Mese
      - GG  --> Giorno + Sesso
      - CCCC -> Codice Comune
      - X   --> Carattere di Controllo
   */      


   char cognome[C];
   char nome[C];
   int annonascita;
   int mesenascita;
   int giornonascita;
   char sesso;


  do {
        printf("Inserire il proprio cognome: ");
        scanf("%s", cognome);
        fcognome(cognome, codicefiscale);

        printf("Inserire il proprio nome: ");
        scanf("%s", nome);
        fnome(nome, codicefiscale);

        printf("Inserire il proprio anno di nascita: ");
        scanf("%d", &annonascita);
        fanno(&annonascita, codicefiscale);

        printf("Inserire il proprio mese di nascita (1-12): ");
        scanf("%d", &mesenascita);
        fmese(&mesenascita, codicefiscale);

        printf("Inserire il proprio giorno di nascita: ");
        scanf("%d", &giornonascita);
        printf("Inserire il proprio sesso (M/F): ");
        scanf(" %c", &sesso); 
        fgiornosesso(&giornonascita, &sesso, codicefiscale);

        fcomuni(codicefiscale);

        
        char controllo = fcontrollo(codicefiscale);
        codicefiscale[16] = controllo; 

        printf("Codice fiscale generato: %s\n", codicefiscale);

        
        printf("Vuoi reinserire i dati? (s/n): ");
        char risposta;
        scanf(" %c", &risposta);
        if (risposta != 's' && risposta != 'S') {
            break;
        }
    } while (1); 

    return 0;
}




void fcognome(char *pcognome, char *pcodicefiscale) {
   int c = 0;
   char cons_trovate[3] = {0};


   
   for (int i = 0; pcognome[i] != '\0' && c < 3; i++) {
       char carattere = toupper(pcognome[i]);
       if (carattere != 'A' && carattere != 'E' && carattere != 'I' && carattere != 'O' && carattere != 'U') {
           cons_trovate[c] = carattere;
           c++;
       }
   }


   
   if (c < 3) {
       for (int i = 0; pcognome[i] != '\0' && c < 3; i++) {
           char carattere = toupper(pcognome[i]);
           if (carattere == 'A' || carattere == 'E' || carattere == 'I' || carattere == 'O' || carattere == 'U') {
               cons_trovate[c] = carattere;
               c++;
           }
       }
   }


   
   while (c < 3) {
       cons_trovate[c] = 'X';
       c++;
   }


  
   for (int i = 0; i < 3; i++) {
       pcodicefiscale[i] = cons_trovate[i];
   }
}




void fnome(char *pnome, char *pcodicefiscale) {
   int cons[4] = {0};
   int c = 0;
   char nome[3] = {0};


   
   for (int i = 0; pnome[i] != '\0' && c < 4; i++) {
       char carattere = toupper(pnome[i]);
       if (carattere != 'A' && carattere != 'E' && carattere != 'I' && carattere != 'O' && carattere != 'U') {
           cons[c] = carattere;
           c++;
       }
   }
\
   if (c >= 4) {
       nome[0] = cons[0];
       nome[1] = cons[2];
       nome[2] = cons[3];
   }
  
   else if (c >= 3) {
       for (int i = 0; i < 3; i++) {
           nome[i] = cons[i];
       }
   }
  
   else {
       for (int i = 0; i < 3 && c < 3; i++) {
           nome[i] = cons[i];
       }


      
       for (int i = 0; pnome[i] != '\0' && c < 3; i++) {
           char carattere = toupper(pnome[i]);
           if (carattere == 'A' || carattere == 'E' || carattere == 'I' || carattere == 'O' || carattere == 'U') {
               nome[c] = carattere;
               c++;
           }
       }
   }


  
   while (c < 3) {
       nome[c] = 'X';
       c++;
   }


  
   for (int i = 0; i < 3; i++) {
       pcodicefiscale[i + 3] = nome[i];
   }
}


void fanno(int *pannonascita, char *pcodicefiscale) {
 
   int anno = *pannonascita;


  
   int cifrefinali = anno % 100;


  
   int decine = cifrefinali / 10;


  
   int unità = cifrefinali % 10;


  
   pcodicefiscale[6] = decine + '0';
   pcodicefiscale[7] = unità + '0';
}


void fmese(int *pmesenascita, char *pcodicefiscale) {
    int mese = *pmesenascita; 
    char lettera_mese;       

    
    if (mese == 1) {
        lettera_mese = 'A';  // Gennaio
    }
    else if (mese == 2) {
        lettera_mese = 'B';  // Febbraio
    }
    else if (mese == 3) {
        lettera_mese = 'C';  // Marzo
    }
    else if (mese == 4) {
        lettera_mese = 'D';  // Aprile
    }
    else if (mese == 5) {
        lettera_mese = 'E';  // Maggio
    }
    else if (mese == 6) {
        lettera_mese = 'H';  // Giugno
    }
    else if (mese == 7) {
        lettera_mese = 'L';  // Luglio
    }
    else if (mese == 8) {
        lettera_mese = 'M';  // Agosto
    }
    else if (mese == 9) {
        lettera_mese = 'P';  // Settembre
    }
    else if (mese == 10) {
        lettera_mese = 'R';  // Ottobre
    }
    else if (mese == 11) {
        lettera_mese = 'S';  // Novembre
    }
    else if (mese == 12) {
        lettera_mese = 'T';  // Dicembre
    }
    else {
        lettera_mese = '?';  
    }

    pcodicefiscale[8] = lettera_mese;
}


void fgiornosesso(int *pgiornonascita, char *psesso, char *pcodicefiscale) {
   
    int giorno = *pgiornonascita;

   
    char sesso = *psesso;

   
    if (sesso == 'F' || sesso == 'f') {
        giorno = giorno + 40; 
    }

   
    int decine = giorno / 10;  

   
    int unita = giorno % 10;  

   
    pcodicefiscale[9] = decine + '0';  
    pcodicefiscale[10] = unita + '0';  
}


void fcomuni(char *pcodicefiscale) {
    FILE *file;
    char linea[100]; 
    char nome_comune[50]; 
    char codice_comune[5]; 
    char comune_utente[50]; 
    int trovato; 

    do {
        trovato = 0; 

        printf("Inserisci il comune di nascita: ");
        scanf("%s", comune_utente);

        file = fopen("comuni_cod.txt", "r");
        if (file == NULL) {
            printf("Errore: non posso aprire il file.\n");
            return;
        }

        
        while (fgets(linea, sizeof(linea), file) != NULL) {
            
            sscanf(linea, "%s %s", nome_comune, codice_comune);

            
            if (strcmp(nome_comune, comune_utente) == 0) {
                trovato = 1;
                break; 
            }
        }

        fclose(file); 

        if (!trovato) {
            printf("Comune non trovato. Riprova.\n");
        }

    } while (!trovato); 

    
    pcodicefiscale[11] = codice_comune[0];
    pcodicefiscale[12] = codice_comune[1];
    pcodicefiscale[13] = codice_comune[2];
    pcodicefiscale[14] = codice_comune[3];
}

char fcontrollo(char *codice) {
    
    int tabellaA[256] = {0};
    tabellaA['0'] = 1;  tabellaA['A'] = 1;
    tabellaA['1'] = 0;  tabellaA['B'] = 0;
    tabellaA['2'] = 5;  tabellaA['C'] = 5;
    tabellaA['3'] = 7;  tabellaA['D'] = 7;
    tabellaA['4'] = 9;  tabellaA['E'] = 9;
    tabellaA['5'] = 13; tabellaA['F'] = 13;
    tabellaA['6'] = 15; tabellaA['G'] = 15;
    tabellaA['7'] = 17; tabellaA['H'] = 17;
    tabellaA['8'] = 19; tabellaA['I'] = 19;
    tabellaA['9'] = 21; tabellaA['J'] = 21;
    tabellaA['K'] = 2;  tabellaA['L'] = 4;
    tabellaA['M'] = 18; tabellaA['N'] = 20;
    tabellaA['O'] = 11; tabellaA['P'] = 3;
    tabellaA['Q'] = 6;  tabellaA['R'] = 8;
    tabellaA['S'] = 12; tabellaA['T'] = 14;
    tabellaA['U'] = 16; tabellaA['V'] = 10;
    tabellaA['W'] = 22; tabellaA['X'] = 25;
    tabellaA['Y'] = 24; tabellaA['Z'] = 23;

    
    int tabellaB[256] = {0};
    tabellaB['0'] = 0;  tabellaB['A'] = 0;
    tabellaB['1'] = 1;  tabellaB['B'] = 1;
    tabellaB['2'] = 2;  tabellaB['C'] = 2;
    tabellaB['3'] = 3;  tabellaB['D'] = 3;
    tabellaB['4'] = 4;  tabellaB['E'] = 4;
    tabellaB['5'] = 5;  tabellaB['F'] = 5;
    tabellaB['6'] = 6;  tabellaB['G'] = 6;
    tabellaB['7'] = 7;  tabellaB['H'] = 7;
    tabellaB['8'] = 8;  tabellaB['I'] = 8;
    tabellaB['9'] = 9;  tabellaB['J'] = 9;
    tabellaB['K'] = 10; tabellaB['L'] = 11;
    tabellaB['M'] = 12; tabellaB['N'] = 13;
    tabellaB['O'] = 14; tabellaB['P'] = 15;
    tabellaB['Q'] = 16; tabellaB['R'] = 17;
    tabellaB['S'] = 18; tabellaB['T'] = 19;
    tabellaB['U'] = 20; tabellaB['V'] = 21;
    tabellaB['W'] = 22; tabellaB['X'] = 23;
    tabellaB['Y'] = 24; tabellaB['Z'] = 25;

    int somma = 0;

    
    for (int i = 0; i < 15; i++) {
        char c = toupper(codice[i]); 

        
        if (i % 2 == 0) {
            somma += tabellaA[c];
        } 
        
        else {
            somma += tabellaB[c];
        }
    }

    
    int resto = somma % 26;
    char carattere_controllo = 'A' + resto;

    return carattere_controllo;
}
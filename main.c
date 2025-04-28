#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produs
{
    char produs[20];
    char tara[20];
    float pretul;
    int cantitatea;
};

void antet()
{
    printf("--------------\n");
    printf("1 - adaugare\n");
    printf("2 - cautare\n");
    printf("3 - vizualizare\n");
    printf("4 - editare\n");
    printf("5 - stergere\n");
    printf("6 - cumparare\n");
    printf("7 - exit\n");
    printf("--------------\n");

}


void submeniu_adaugare()
{
    printf("\n----------------\n");
    printf("Submeniu\n");
    printf("1-Adauga alt produs\n");
    printf("2-Meniu principal\n");
    printf("-------------------\n");
    printf("Introduceti optiunea: ");
}

void adauga_produs(char path[])
{
    system("cls");
    FILE * filePointer;
    filePointer = fopen(path, "a");

    struct Produs produs;

    printf("--------------\n");
    printf("Adaugare\n");
    printf("--------------\n");

    printf("Introduceti numele: ");
    scanf(" %[^\n]", produs.produs);

    printf("Introduceti tara: ");
    scanf(" %[^\n]", produs.tara);

    printf("Introduceti pretul (RON de forma aa.bb): ");
    scanf("%f", &produs.pretul);
    while((int)(produs.pretul * 100) != (produs.pretul * 100))
    {
        printf("Pretul trebuie sa aiba exact doua zecimale (aa.bb). Introdu din nou.\n");
        scanf("%f",&produs.pretul);
    }
    printf("Introduceti cantitatea (Kg/Bucati): ");
    scanf("%d", &produs.cantitatea);

    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.\n");
    }
    else
    {
        fprintf(filePointer, "%s %s %.2f %d\n", produs.produs, produs.tara, produs.pretul, produs.cantitatea);
        fclose(filePointer);
    }

    printf("--------------\n");
    printf("Ati adaugat un produs.\n");
    printf("--------------\n");
    printf("\nApasa Enter pentru a afisa submeniul...\n");
    getchar();
    if (getchar() == '\n')
    {
        system("cls");
        submeniu_adaugare();
        int optiune;
        scanf("%d", &optiune);
        if (optiune == 1)
            adauga_produs(path);
        else
            system("cls");
    }
}

void submeniu_cautare()
{
    printf("-------------------\n");
    printf("Submeniu\n");
    printf("1-Cauta dupa nume\n");
    printf("2-Cauta dupa tara\n");
    printf("3-Iesire\n");
    printf("--------------------\n");
}
void submeniucautare()
{
    printf("-----------------\n");
    printf("Submeniu\n");
    printf("1-Cauta alt produs\n");
    printf("2-Meniu principal\n");
    printf("-----------------\n");
}
void cautare_nume(char path[])
{
    printf("-------------------\n");
    printf("Cautare dupa nume\n");
    printf("-------------------\n");
    FILE * filePointer;
    filePointer = fopen(path, "r");

    FILE * tempPointer;
    tempPointer = fopen("temp.txt", "w");

    struct Produs produs;
    int found = 0;

    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.\n");
    }
    else
    {
        printf("Ce produs cautati?\n");
        char produs_cautat[20];
        scanf("%s", produs_cautat);
        printf("----------------------------\n");
        printf("PRODUS         TARA      PRET       CANTITATEA\n");
        while (fscanf(filePointer, "%s %s %f %d\n", produs.produs, produs.tara, &produs.pretul, &produs.cantitatea) != EOF)
        {
            if (strcmp(produs_cautat, produs.produs) == 0)
            {
                found = 1;
                printf("\033[1;31m%-15s\033[0m", produs.produs);
                printf("\033[1;32m%-10s\033[0m", produs.tara);
                printf("\033[1;33m%-10d\033[0m ", produs.cantitatea);
                printf("\033[1;34m%-25.2f\033[0m\n", produs.pretul);
                fprintf(tempPointer, "%s %s %.2f %d\n", produs.produs, produs.tara, produs.pretul, produs.cantitatea);
            }
        }

        if (!found)
        {
            printf("Produsul nu a fost gasit.\n");
        }

        fclose(filePointer);
        fclose(tempPointer);

        remove(path);
        rename("temp.txt", path);
    }
}

void cautare_tara(char path[])
{
    printf("-------------------\n");
    printf("Cautare dupa tara\n");
    printf("-------------------\n");
    FILE * filePointer;
    filePointer = fopen(path, "r");

    FILE * tempPointer;
    tempPointer = fopen("temp.txt", "w");

    struct Produs produs;
    int found = 0;

    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.\n");
    }
    else
    {
        printf("Ce tara cautati?\n");
        char tara_cautata[20];
        scanf("%s", tara_cautata);
        printf("-----------------------\n");
        printf("PRODUS         TARA      PRET       CANTITATEA\n");
        while (fscanf(filePointer, "%s %s %f %d\n", produs.produs, produs.tara, &produs.pretul, &produs.cantitatea) != EOF)
        {
            if (strcmp(tara_cautata, produs.tara) == 0)
            {
                found = 1;
                printf("\033[1;31m%-15s\033[0m", produs.produs);
                printf("\033[1;32m%-10s\033[0m", produs.tara);
                printf("\033[1;33m%-10d\033[0m ", produs.cantitatea);
                printf("\033[1;34m%-25.2f\033[0m\n", produs.pretul);
                fprintf(tempPointer, "%s %s %.2f %d\n", produs.produs, produs.tara, produs.pretul, produs.cantitatea);
            }
        }

        if (!found)
        {
            printf("Produsul nu a fost gasit.\n");
        }

        fclose(filePointer);
        fclose(tempPointer);

        remove(path);
        rename("temp.txt", path);
    }
}

void cauta_produs(char path[])
{
    system("cls");
    FILE * filePointer;
    filePointer = fopen(path, "r");
    int optiune;
    char linie[50];

    printf("--------------\n");
    printf("Cautare\n");
    submeniu_cautare();
    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.\n");
    }
    else
    {
        scanf("%d", &optiune);
        if (optiune == 3)
        {
            system("cls");
            return;
        }
        else
        {
            if (optiune == 1)
            {
                system("cls");
                cautare_nume(path);
            }
            else if (optiune == 2)
            {
                system("cls");
                cautare_tara(path);
            }
            else
            {
                system("cls");
                printf("Optiune invalida incearca din nou\n");
                submeniu_cautare();
            }
            printf("----------------------------\n");
            printf("\nApasa Enter pentru a afisa submeniul...\n");
            getchar();
            if (getchar() == '\n')
            {
                system("cls");
                submeniu_cautare();
                int optiune;
                scanf("%d", &optiune);
                if (optiune == 1)
                    cauta_produs(path);
                else
                    system("cls");
            }
        }
    }
}
void submeniu_afisare()
{
    printf("\n----------------\n");
    printf("Submeniu\n");
    printf("1-Afiseaza din nou\n");
    printf("2-Meniu principal\n");
    printf("-------------------\n");
    printf("Introduceti optiunea: ");
}
void vizualizare(char path[])
{
    system("cls");
    FILE * filePointer;
    filePointer = fopen(path, "r");

    struct Produs produs;

    printf("--------------\n");
    printf("Afisare\n");
    printf("--------------\n");

    if (filePointer == NULL)
    {
        printf("Fisierul nu poate fi accesat.\n");
    }
    else
    {
        char linie[100];
        fgets(linie, sizeof(linie), filePointer);
        printf("%s", linie);
        while (fscanf(filePointer, "%s %s %f %d\n", produs.produs, produs.tara, &produs.pretul, &produs.cantitatea) != EOF)
        {
            printf("\033[1;31m%-15s\033[0m", produs.produs);
            printf("\033[1;32m%-10s\033[0m", produs.tara);
            printf("\033[1;33m%-10d\033[0m ", produs.cantitatea);
            printf("\033[1;34m%-25.2f\033[0m\n", produs.pretul);
        }
        fclose(filePointer);
    }

    printf("--------------\n");
    printf("Ati afisat produsele.\n");
    printf("--------------\n");
    printf("\nApasa Enter pentru a afisa submeniul...\n");
    getchar();
    if (getchar() == '\n')
    {
        system("cls");
        submeniu_afisare();
        int optiune;
        scanf("%d", &optiune);
        if (optiune == 1)
            vizualizare(path);
        else
            system("cls");
    }
}

void submeniu_stergere()
{
    printf("\n----------------\n");
    printf("Submeniu\n");
    printf("1-Sterge alt produs\n");
    printf("2-Meniu principal\n");
    printf("-------------------\n");
    printf("Introduceti optiunea: ");
}

void stergere(char path[]) {
    system("cls");
    printf("--------------\n");
    printf("Stergerea unui produs\n");
    printf("--------------\n");

    struct Produs produs;
    printf("Introduceti produsul pe care doriti sa il stergeti (numele): ");
    getchar();
    scanf(" %[^\n]", produs.produs);
    produs.produs[strcspn(produs.produs, "\n")] = 0;

    FILE *filePointer;
    filePointer = fopen(path, "r");

    if (filePointer == NULL) {
        printf("Fisierul nu poate fi accesat.\n");
        return;
    }

    FILE *tempPointer;
    tempPointer = fopen("temp.txt", "w");

    struct Produs produs_curent;
    char linie[200];
    int found = 0;
    if (fgets(linie, sizeof(linie), filePointer) != NULL) {
        linie[strcspn(linie, "\n")] = 0;
        fprintf(tempPointer, "%s\n", linie);
    }
    while (fgets(linie, sizeof(linie), filePointer) != NULL) {
        int n = sscanf(linie, "%s %s %f %d", produs_curent.produs, produs_curent.tara, &produs_curent.pretul, &produs_curent.cantitatea);

        if (n == 4) {
            if (strcmp(produs.produs, produs_curent.produs) != 0) {
                fprintf(tempPointer, "%s %s %.2f %d\n", produs_curent.produs, produs_curent.tara, produs_curent.pretul, produs_curent.cantitatea);
            } else {
                found = 1;
            }
        } else {
            printf("Eroare la citirea produsului.\n");
        }
    }

    fclose(filePointer);
    fclose(tempPointer);

    if (found) {
        remove(path);
        rename("temp.txt", path);
        printf("Produsul a fost sters cu succes.\n");
    } else {
        printf("Produsul nu a fost gasit.\n");
        remove("temp.txt");
    }

    printf("--------------\n");
    printf("Ati sters produsul.\n");
    printf("--------------\n");
    printf("\nApasa Enter pentru a afisa submeniul...\n");

    getchar();
    if (getchar() == '\n') {
        system("cls");
        submeniu_stergere();
        int optiune;
        scanf("%d", &optiune);
        if (optiune == 1)
            stergere(path);
        else
            system("cls");
    }
}


void submeniu_editare()
{
    printf("\n----------------\n");
    printf("Submeniu\n");
    printf("1-Editeaza alt produs\n");
    printf("2-Meniu principal\n");
    printf("-------------------\n");
    printf("Introduceti optiunea: ");
}
void editare_optiuni()
{
    printf("1-Editati numele\n");
    printf("2-Editati tara\n");
    printf("3-Editati pretul\n");
    printf("4-Editati cantitatea\n");
    printf("5-Nu mai doresc sa editez\n");
}

void editare(char path[])
{
    system("cls");
    printf("--------------\n");
    printf("Editarea unui produs\n");
    printf("--------------\n");
    struct Produs produs;
    printf("Introduceti produsul pe care doriti sa il editati (numele): ");
    getchar();
    scanf(" %[^\n]", produs.produs);

    FILE *filePointer = fopen(path, "r");
    FILE *tempPointer = fopen("temp.txt", "w");

    struct Produs produs_curent;
    char linie[30];
    int found = 0;
    if (fgets(linie, sizeof(linie), filePointer) != NULL)
    {
        fprintf(tempPointer, "%s", linie);
    }

    while (fscanf(filePointer, "%s %s %f %d\n", produs_curent.produs, produs_curent.tara, &produs_curent.pretul, &produs_curent.cantitatea) != EOF)
    {
        if (strcmp(produs.produs, produs_curent.produs) == 0)
        {
            printf("Produsul a fost gasit!\n");
            found = 1;
            editare_optiuni();
            int optiune;
            printf("\nCe doriti sa editati:");
            scanf("%d", &optiune);

            if (optiune == 1)
            {
                printf("Introduceti numele: ");
                scanf("%s", produs_curent.produs);
            }
            else if (optiune == 2)
            {
                printf("Introduceti tara: ");
                scanf("%s", produs_curent.tara);
            }
            else if (optiune == 3)
            {
                printf("Introduceti pretul (RON): ");
                scanf("%f", &produs_curent.pretul);
            }
            else if (optiune == 4)
            {
                printf("Introduceti cantitatea (Kg/Bucati): ");
                scanf("%d", &produs_curent.cantitatea);
            }
            else
            {
                printf("Optiune invalida. Incearca din nou.\n");
                fclose(filePointer);
                fclose(tempPointer);
                remove("temp.txt");
                return;
            }
        }

        fprintf(tempPointer, "%s %s %.2f %d\n", produs_curent.produs, produs_curent.tara, produs_curent.pretul, produs_curent.cantitatea);
    }

    fclose(filePointer);
    fclose(tempPointer);

    if (found)
    {
        remove(path);
        rename("temp.txt", path);
        printf("Produsul a fost editat cu succes.\n");
    }
    else
    {
        printf("Produsul nu a fost gasit.\n");
        remove("temp.txt");
    }

    printf("--------------\n");
    printf("Ati editat produsul.\n");
    printf("--------------\n");
    printf("\nApasa Enter pentru a afisa submeniul...\n");
    getchar();
    if (getchar() == '\n')
    {
        system("cls");
        submeniu_editare();
        int optiune;
        scanf("%d", &optiune);
        if (optiune == 1)
            editare(path);
        else
            system("cls");
    }
}
void submeniu_cumparare()
{
    printf("\n----------------\n");
    printf("Submeniu\n");
    printf("1-Cumpara alt produs\n");
    printf("2-Meniu principal\n");
    printf("-------------------\n");
    printf("Introduceti optiunea: ");
}
void cumparare(char path[]) {
    system("cls");
    printf("--------------\n");
    printf("Cumpararea unui produs\n");
    printf("--------------\n");

    struct Produs produs;
    printf("Introduceti produsul pe care doriti sa il cumparati (numele): ");
    getchar();
    scanf(" %[^\n]", produs.produs);

    FILE *filePointer = fopen(path, "r");
    if (filePointer == NULL) {
        printf("Fisierul nu poate fi accesat.\n");
        return;
    }

    FILE *tempPointer = fopen("temp.txt", "w");
    if (tempPointer == NULL) {
        printf("Nu se poate deschide fisierul temporar.\n");
        fclose(filePointer);
        return;
    }

    struct Produs produs_curent;
    char linie[200];
    int found = 0;
    if (fgets(linie, sizeof(linie), filePointer) != NULL) {
        fprintf(tempPointer, "%s", linie);
    }

    while (fgets(linie, sizeof(linie), filePointer) != NULL) {
        int n = sscanf(linie, "%s %s %f %d", produs_curent.produs, produs_curent.tara, &produs_curent.pretul, &produs_curent.cantitatea);

        if (n == 4) {
            if (strcmp(produs.produs, produs_curent.produs) == 0) {
                printf("Produsul a fost gasit!\n");
                found = 1;

                int cantitate_cumparata;
                printf("Introduceti cantitatea (Kg/Bucati) pe care doriti sa o cumparati: ");
                scanf("%d", &cantitate_cumparata);

                if (cantitate_cumparata <= 0) {
                    printf("Cantitate invalida.\n");
                    fclose(filePointer);
                    fclose(tempPointer);
                    remove("temp.txt");
                    return;
                }

                if (cantitate_cumparata > produs_curent.cantitatea) {
                    printf("Stoc insuficient! Disponibil: %d\n", produs_curent.cantitatea);
                    fclose(filePointer);
                    fclose(tempPointer);
                    remove("temp.txt");
                    return;
                } else {
                    produs_curent.cantitatea -= cantitate_cumparata;
                    printf("Ati cumparat %d bucati/Kg din produsul %s.\n", cantitate_cumparata, produs_curent.produs);
                    if (produs_curent.cantitatea == 0) {
                        continue;
                    }
                }
            }
            fprintf(tempPointer, "%s %s %.2f %d\n", produs_curent.produs, produs_curent.tara, produs_curent.pretul, produs_curent.cantitatea);
        } else {
            printf("Eroare la citirea produsului.\n");
        }
    }

    fclose(filePointer);
    fclose(tempPointer);

    if (found) {
        remove(path);
        rename("temp.txt", path);
        printf("Cumpararea a fost realizata cu succes.\n");
    } else {
        printf("Produsul nu a fost gasit.\n");
        remove("temp.txt");
    }

    printf("--------------\n");
    printf("Ati finalizat cumpararea.\n");
    printf("--------------\n");
    printf("\nApasa Enter pentru a afisa submeniul...\n");

    getchar();
    if (getchar() == '\n') {
        system("cls");
        submeniu_cumparare();
        int optiune;
        scanf("%d", &optiune);
        if (optiune == 1)
            cumparare(path);
        else
            system("cls");
    }
}
void funct_meniu(char path[])
{
    int optiune;
    scanf("%d",&optiune);
    system("cls");
    switch(optiune)
    {
    case 1:
        adauga_produs(path);
        break;
    case 2:
        cauta_produs(path);
        break;
    case 3:
        vizualizare(path);
        break;
    case 4:
        editare(path);
        break;
    case 5:
        stergere(path);
        break;
    case 6:
        cumparare(path);
        break;
    case 7:
        printf("Iesire din aplicatie.\n");
        exit(0);
    default:
        printf("Optiune invalida! Te rog sa alegi din nou.\n");
    }
}


int main()
{
    char path[] = "fisier.txt";
    do
    {
        antet();
        printf("Introduceti optiunea: ");
        funct_meniu(path);
    }
    while(1);



    return 0;
}

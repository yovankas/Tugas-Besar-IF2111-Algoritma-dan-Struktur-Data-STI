#include <string.h>
#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
{
    S->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsSetEmpty(Set S)
{
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsSetFull(Set S)
{
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotype Elmt)
{
    if (!IsMemberSet(*S, Elmt))
    {
        // Allocate memory for the content of the string
        S->Elements[S->Count] = (char*) malloc((strlen(Elmt) + 1) * sizeof(char));

        // Check if memory allocation was successful
        if (S->Elements[S->Count] == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        // Copy the content of the string
        strcpy(S->Elements[S->Count], Elmt);
        S->Count += 1;
    }

}


/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetElement(Set *S, infotype Elmt)
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMemberSet(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (strcmp(S->Elements[idx], Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = (char *)malloc((strlen(S->Elements[iterator])) * sizeof(char));
        strcpy((S->Elements[iterator - 1]), S->Elements[iterator]);
    }
    S->Count--;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotype Elmt)
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (strcmp(S.Elements[idx], Elmt) == 0)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2)
{
    Set S;
    CreateEmptySet(&S);
    for (int i = 0; i < s1.Count; ++i)
    {
        InsertSet(&S, s1.Elements[i]);
    }
    for (int j = 0; j < s2.Count; ++j)
    {
        InsertSet(&S, s2.Elements[j]);
    }
    return S;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2)
{
    Set S;
    CreateEmptySet(&S);

    for (int i = 0; i < s2.Count; ++i)
    {
        if (IsMemberSet(s1, s2.Elements[i]))
        {
            InsertSet(&S, s2.Elements[i]);
        }
    }

    return S;
}

// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2)
{
    Set S;
    S = SetSubtract(SetUnion(s1, s2), SetIntersection(s1, s2));

    return S;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2)
{
    Set S;
    CreateEmptySet(&S);

    for (int i = 0; i < s1.Count; ++i)
    {
        InsertSet(&S, s1.Elements[i]);
    }

    for (int j = 0; j < s2.Count; ++j)
    {
        if (IsMemberSet(S, s2.Elements[j]))
        {
            DeleteSetElement(&S, s2.Elements[j]);
        }
    }

    return S;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

void CopySet(Set *s1, Set s2)
{
    for (int i = 0; i < s2.Count; i++)
    {
        (*s1).Elements[i] = s2.Elements[i];
    }
    (*s1).Count = s2.Count;
}

void PrintSet(Set S)
{
    int i = 0;
    while (i < S.Count)
    {
        printf("%d. %s\n", i + 1, S.Elements[i]);
        i += 1;
    }
}

infotype ValueSet(Set S, address i)
{
    return (S.Elements[i-1]);
}
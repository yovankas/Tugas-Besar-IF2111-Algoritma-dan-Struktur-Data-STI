#include "album.h"
#include "../../adt/string/string.h"

void CreateEmptyAlbum(Album *M)
{
    (*M).Count = NilAlbum;
}

boolean IsEmptyAlbum(Album M)
{
    return M.Count == NilAlbum;
}

boolean IsFullAlbum(Album M)
{
    return M.Count == MaxElAlbum;
}

valuetype ValueInAlbum(Album M, keytype k)
{
    boolean found = false;
    addressAlbum idx = 0;

    while (!found && idx < M.Count)
    {
        if (strCompare(M.Elements[idx].Key, k) == 0)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void InsertInAlbum(Album *M, keytype k, valuetype v)
{
    if (!IsMemberInAlbum(*M, k))
    {
        // Allocate memory for the key
        (*M).Elements[(*M).Count].Key = (char *)malloc((strLength(k) + 1) * sizeof(char));
        strCopy((*M).Elements[(*M).Count].Key, k);

        // Create a new set for each album
        CreateEmptySet(&((*M).Elements[(*M).Count].Value));

        // Insert the songs into the new set
        for (int i = 0; i < v.Count; i++)
        {
            InsertSet(&((*M).Elements[(*M).Count].Value), v.Elements[i]);
        }

        (*M).Count++;
    }
}

void DeleteInAlbum(Album *M, keytype k)
{
    boolean found = false;
    addressAlbum idx = 0, iterator;

    if (!IsMemberInAlbum(*M, k))
    {
        return;
    }

    while (!found && (idx < (*M).Count))
    {
        if (strCompare((*M).Elements[idx].Key, k))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < (*M).Count; iterator++)
    {
        (*M).Elements[iterator - 1].Key = (char *)malloc((strLength((*M).Elements[iterator].Key)) * sizeof(char));
        strCopy(((*M).Elements[iterator - 1].Key), (*M).Elements[iterator].Key);
        CopySet(&((*M).Elements[iterator - 1].Value), (*M).Elements[iterator].Value);
    }

    (*M).Count--;
}

boolean IsMemberInAlbum(Album M, keytype k)
/* Mengembalikan true jika k adalah member dari M. Pengecekan member dilakukan dengan case insensitive */
{
    boolean found = false;
    addressAlbum idx = 0;

    while (!found && idx < M.Count)
    {
        if (IsEQWord(lowerWord(stringToWord(M.Elements[idx].Key)), lowerWord(stringToWord(k))))
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

// boolean IsEQAlbum(Album m1, Album m2)
// {
//     if (m1.Count != m2.Count)
//     {
//         return false;
//     }
//     else
//     {
//         boolean cek = true;
//         int i = 0;
//         while (cek && i < m1.Count)
//         {
//             if (!IsEQWord(m1.Elements[i].Key, m2.Elements[i].Key) || !IsEQWord(m1.Elements[i].Value, m2.Elements[i].Value))
//             {
//                 cek = false;
//             }
//         }
//         return cek;
//     }
// }

void CopyAlbum(Album *m1, Album m2)
{
    for (int i = 0; i < (*m1).Count; i++)
    {
        (*m1).Elements[i].Key = (char *)malloc((strLength(m2.Elements[i].Key)) * sizeof(char));
        strCopy(((*m1).Elements[i].Key), m2.Elements[i].Key);
        CopySet(&((*m1).Elements[i].Value), m2.Elements[i].Value);
    }
}

void PrintAlbumLagu(Album M, keytype k)
{
    valuetype set;
    set = ValueInAlbum(M, k);
    PrintSet(set);
}

infotype LaguFromAlbum(Album M, keytype k, int id)
{
    valuetype set;
    set = ValueInAlbum(M, k);
    infotype song = ValueSet(set, id);
    return song;
}

int GenerateIDAlbum (Album M, keytype k)
{
    int i = 0;
    int ID;
    while (strCompare(k, M.Elements[i].Key) != 0 && i < M.Count)
    {
        i +=1;
    }
    if (strCompare(k, M.Elements[i].Key) == 0)
    {
        ID = i;
    }
    return ID;
}
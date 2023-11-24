#include "penyanyi.h"
#include "../../adt/string/string.h"

Penyanyi CreateEmptyPenyanyi()
{
    Penyanyi p;
    p.Count = NilPenyanyi;
    return p;
}

boolean IsEmptyPenyanyi(Penyanyi M)
{
    return M.Count == NilPenyanyi;
}

boolean IsFullPenyanyi(Penyanyi M)
{
    return M.Count == MaxElPenyanyi;
}

valuetypePenyanyi ValueInPenyanyi(Penyanyi M, keytype k)
{
    boolean found = false;
    addressPenyanyi idx = 0;

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

void InsertInPenyanyi(Penyanyi *M, keytype k, valuetypePenyanyi v)
{
    if (!IsMemberInPenyanyi(*M, k))
    {
        (*M).Elements[(*M).Count].Key = (char *)malloc((strLength(k) + 1) * sizeof(char));
        strCopy((*M).Elements[(*M).Count].Key, k);
        copyArray(&((*M).Elements[(*M).Count].Value), v);
        (*M).Count++;
    }
}

void DeleteInPenyanyi(Penyanyi *M, keytype k)
{
    boolean found = false;
    addressPenyanyi idx = 0, iterator;

    if (!IsMemberInPenyanyi(*M, k))
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
        copyArray(&((*M).Elements[iterator - 1].Value), (*M).Elements[iterator].Value);
    }

    (*M).Count--;
}

boolean IsMemberInPenyanyi(Penyanyi M, keytype k)
/* Mengembalikan true jika k adalah member dari M. Pengecekan member dilakukan dengan case insensitive */
{
    boolean found = false;
    addressPenyanyi idx = 0;

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

void CopyPenyanyi(Penyanyi *m1, Penyanyi m2)
{
    for (int i = 0; i < (*m1).Count; i++)
    {
        (*m1).Elements[i].Key = (char *)malloc((strLength(m2.Elements[i].Key)) * sizeof(char));
        strCopy(((*m1).Elements[i].Key), m2.Elements[i].Key);
        copyArray(&((*m1).Elements[i].Value), m2.Elements[i].Value);
    }
}

void PrintAlbumPenyanyi(Penyanyi M, keytype k)
{
    valuetypePenyanyi arr;
    arr = ValueInPenyanyi(M, k);
    for (int j = 0; j <= arr.Neff; j++)
    {
        printf("%d. %s\n", j+1, arr.TI[j]);
    }
}
//Here epsilon is represented as ^ in the absence of the character
#include <bits/stdc++.h>
using namespace std;

class rec
{
public:
    char S[10], A[10];
    char left1, left2;

    int i = 0;
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;

    char beta[50], alpha[50];
    char temp1[50], temp2[50];

    int j = 0, k = 0;
    int q = 0, o = 0;

    void direct(char temp2[])
    {
        i = 0;
        int length = strlen(temp2);
        cout << "\nlen= " << length;
        char left = temp2[0];
        cout << "\nleft= " << left;
        j = 0, k = 0;

        for (i = 2; i < length; i++)
        {
            if (temp2[i] == left)
            {
                int c = i + 1;
                while (temp2[c] != '|' && temp2[c] != '\0')
                {
                    alpha[j] = temp2[c];
                    c++;
                    j++;
                }
                alpha[j] = '|';
                j++;
                i = c;
                alpha[j] = '\0';
                flag1 = true;
            }
            else if (temp2[i] != left)
            {
                int z = i;
                while (temp2[z] != '|' && temp2[z] != '\0')
                {
                    beta[k] = temp2[z];
                    z++;
                    k++;
                }
                beta[k] = '|';
                k++;
                i = z;
                beta[k] = '\0';
                flag2 = true;
            }
        }

        cout << "\n----------\n";
        if (flag1 == true)
        {
            cout << "\nalpha= ";
            for (i = 0; alpha[i] != '\0'; i++)
                cout << alpha[i] << " ";
        }
        if (flag2 == true)
        {
            cout << "\nbeta= ";
            for (i = 0; beta[i] != '\0'; i++)
                cout << beta[i] << " ";
        }

        cout << "\n----------form\n";
        cout << "A= ";
        for (i = 0; beta[i] != '\0'; i++)
        {
            if (beta[i] != '|')
                cout << beta[i];
            else
                cout << " A'|";
        }

        cout << "\n-----------\n";
        cout << "A'= ";
        for (i = 0; alpha[i] != '\0'; i++)
        {
            while (alpha[i] != '|')
            {
                cout << alpha[i];
                i++;
            }
            cout << " A'|";
        }
        cout << "^";
        cout << endl;
    }
} r;

int main()
{

    cout << "Enter the no.of productions: ";
    int count;
    cin >> count;
    if (count > 1)
    {

        cout << "\nEnter production 1:\n";
        cin >> r.S;
        cout << "\nEnter production 2:\n";
        cin >> r.A;
        cout << "---------------------------------\n";
        cout << "\nEntered Production 1 is=\t" << r.S;
        cout << "\nEntered Production 2 is=\t" << r.A;

        int len1 = strlen(r.S);
        int len2 = strlen(r.A);
        cout << "\n---------------------------------\n";
        cout << "\nlen1= " << len1 << "\tlen2= " << len2;

        r.S[len1] = '\0';
        r.A[len2] = '\0';
        r.left1 = r.S[0];
        r.left2 = r.A[0];
        cout << "\nleft1= " << r.left1 << "\nleft2= " << r.left2;
        cout << "\n---------------------------------\n";

        r.temp2[r.q] = 'S';
        r.q++;
        r.temp2[r.q] = '=';
        r.q++;

        for (int i = 2; i < len1; i++)
        {
            if (r.S[i] == r.left2)
            {
                r.flag3 = true;
                int h = i + 1;

                while (r.S[h] != '|' && r.S[h] != '\0')
                {
                    r.temp1[r.o] = r.S[h];
                    h++;
                    r.o++;
                }
                for (int p = 2; p < len2; p++)
                {
                    while (r.A[p] != '|' && r.A[p] != '\0')
                    {
                        r.temp2[r.q] = r.A[p];
                        r.q++;

                        p++;
                    }
                    for (int g = 0; g < (strlen(r.temp1)); g++)
                    {
                        r.temp2[r.q] = r.temp1[g];
                        r.q++;
                    }
                    r.temp2[r.q] = '|';
                    r.q++;
                }
                i = h;
            }
            else if (r.S[i] != r.left2)
            {
                r.temp2[r.q] = r.S[i];
                r.q++;
            }
        }
        r.temp2[r.q] = '\0';
        cout << endl;

        int length = strlen(r.temp2);
        for (int i = 0; i < length; i++)
            cout << r.temp2[i];
        r.direct(r.temp2);
    }
    else
    {
        cout << "\nEnter production:\n";
        cin >> r.temp2;
        cout << "---------------------------------\n";
        cout << "\nEntered Production is=\t" << r.temp2;
        r.direct(r.temp2);
    }
    return 0;
}

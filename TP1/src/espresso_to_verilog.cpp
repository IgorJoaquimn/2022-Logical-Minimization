#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char first_letter = 'a';
int in;
using namespace std;

void binary_to_literal(string &str, string &ret)
{
    for (int i = 0; i < in; i++)
    {
        if (str[i] == '-')  continue;
        if (str[i] == '0') ret += "N";
        ret += (char)(first_letter + (i));
        if (i < in - 1)  ret += ",";
    }
    if(ret.rfind(",") == ret.length() - 1) ret = ret.substr(0, ret.length() - 1);
    return;
}


string input(int x)
{
    string ret;
    ret.push_back((char)(first_letter + x));
    return ret;
}

string output(int x)
{
    string ret("o");
    ret += to_string(x);
    return ret;
}

string Nwire(int x)
{
    string ret("N");
    ret.push_back((char)(first_letter + x));
    return ret;
}

string Ny(int x, string y)
{
    string ret("(N");
    ret += y;
    ret += ",";
    ret += y;
    ret += ")";
    return ret;
}

string Andwire(int x, string y)
{
    string ret = y;
    ret += to_string(x);
    return ret;
}

string consecutive_line(string begin, string (*func)(int x))
{
    string ret;
    ret += begin;
    for (int i = 0; i < in; i++)
    {
        ret += func(i);
        if (i != in - 1)
            ret += ",";
    }
    ret += ";";
    return ret;
}

string consecutive_line(string begin, string (*func)(int x,string y), int limit, string letra)
{
    string ret;
    ret += begin;
    for (int i = 0; i < limit; i++)
    {
        ret += func(i,letra);
        if (i != limit - 1)
            ret += ",";
    }
    ret += ";";
    return ret;
}

int main()
{
    char str[60];
    int out, n;
    cin >> str >> in;
    cin >> str >> out;
    cin >> str >> n;
    vector<string> codes[in];
    while (n--)
    {
        string buffer, literal, output;
        cin >> buffer >> output;
        binary_to_literal(buffer, literal);
        for (int i = 0; i < in; i++)
            if (output[i] == '1')
                codes[i].push_back(literal);
    };

    string ent = consecutive_line("" ,&input);   ent  = ent.substr(0,ent.length()-1);
    string eout = consecutive_line("" ,&output); eout = eout.substr(0,eout.length()-1);

    cout << "module multiplicador("  << ent << " , " << eout << ");" << endl << endl;
    cout << consecutive_line("    input " ,&input)  << endl;
    cout << consecutive_line("    output ",&output) << endl;
    cout << consecutive_line("    wire "  ,&Nwire)  << endl;
    cout << endl;

    for (int i = 0; i < in; i++)
    {
        string letter(""); letter.push_back((char)(first_letter + i));
        cout << consecutive_line("    not not_" + letter,&Ny,1,letter) << endl;
    }
    cout << endl;

    for (int i = 0; i < in; i++)
    {
        string letra = "o" + to_string(i);
        cout << consecutive_line("    wire "  ,&Andwire, codes[i].size(),letra) << endl;

        for (int j = 0; j < codes[i].size(); j++)
        {
            string this_and = letra + to_string(j);
            cout << "    and and_" << this_and << " (" << this_and << "," << codes[i][j] << ");" << endl;
        }

        cout << "    or or_" << letra << " (" << letra << ",";
        for (int j = 0; j < codes[i].size(); j++)
        {
            string this_and = letra + to_string(j);
            cout << this_and;
            if (j != codes[i].size() - 1)
                cout << ",";
        }
        cout << ");" << endl;
        cout << endl;
    }

    cout << "endmodule"<< endl;

}

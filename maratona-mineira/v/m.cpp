#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> pont;

    for(int i = 0; i < 10; i++)
    {
        string turno;
        cin >> turno;
        // Strike
        if(turno[0] == 'X')
        {
            pont.push_back(10);
            if(turno.size() > 1)
            {
                pont.push_back((turno[1] == 'X' ? 10 : turno[1] - '0'));
                if(turno[2] == '/')
                    pont.push_back(10 - pont[pont.size() - 1]);
                else
                    pont.push_back((turno[2] == 'X' ? 10 : turno[2] - '0'));
            }   
        }
        // Spare
        else
        {
            pont.push_back(turno[0] - '0');
            pont.push_back((turno[1] == '/' ? 10 - pont[pont.size() - 1] : turno[1] - '0'));
            if(turno.size() == 3) 
                pont.push_back((turno[2] == 'X' ? 10 : turno[2] - '0'));
        }
    }

    pont.push_back(0);
    pont.push_back(0);

    int rodada = 0;
    int placar = 0;
    int ind = 0;
    while(rodada != 10)
    {
        if(pont[ind] == 10)
        {
            placar += 10 + pont[ind + 1] + pont[ind + 2];
            ind++;
        } 
        else if (pont[ind] + pont[ind + 1] == 10)
        {
            placar += 10 + pont[ind + 2];
            ind += 2;
        }
        else
        {
            placar += pont[ind] + pont[ind + 1];
            ind += 2;
        }
        rodada++;
    }

    cout << placar;

    return 0;
}
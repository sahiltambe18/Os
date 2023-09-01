#include <iostream>
#include <queue>
using namespace std;

struct Process
{
    int id;
    int at;
    int bt;
    int wt;
    int tat;
};

void del(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = p[i + 1];
    }
}

void sort(Process p[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                Process t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}

int main()
{

    int n, total;
    int i = 0;
    int pos = 0;
    int count = 0;
    Process p[10], ep[10], exe;

    cout << "enter number of processes" << endl;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        p[j].id = j+1;
        cout << "enter arrival time of procces "<< j+1 << endl;
        cin >> p[j].at;
        cout << "enter burst time of process " << j+1 << endl;
        cin >> p[j].bt;
    }

    ep[pos++] = p[i++];

    total = ep[0].bt;

    for (int j = 0; j <= total; j++)
    {
        exe = ep[0];
        exe.bt = exe.bt - 1;
        count++;
        ep[0] = exe;
        if (exe.bt == 0)
        {
            exe.wt = count - exe.bt - exe.at;
            exe.tat = exe.wt - exe.bt;
            ep[0] = exe;
            for (int t = 0; t < n; t++)
            {
                if(exe.id == p[t].id){
                    int temp = p[t].bt;  // temp to recover bt 
                    p[t] = exe;    // this line will assign bt = 0 as exe.bt = 0
                    p[t].bt = temp;
                }
            }
            
            cout << "process " << exe.id << " ended at : " << count << endl;
            del(ep, pos);
            pos--;
        }

        if (p[i].at <= count)
        {
            // ep[pos++] = p[i++];
            for (int x = i; x < n; x++)
            {
                if (p[x].at <= count)
                {
                    ep[pos++] = p[i++];
                    total += p[x].bt;
                }
            }
            sort(ep, pos);
        }
    }

    cout << "pid\tat\tbt\twt\ttat" << endl;
    float avgWt = 0;
    float avgTat = 0;
    for (int j = 0; j < n; j++)
    {
        Process pr = p[j];
        cout << pr.id << "\t" << pr.at << "\t" << pr.bt << "\t" << pr.wt << "\t" << pr.tat << endl;
        avgWt += pr.wt;
        avgTat += pr.tat;
    }
    avgWt = avgWt / n;
    avgTat = avgTat / n;
    cout << "average waiting time : " << avgWt << endl;
    cout << "average turn around time : " << avgTat << endl;

    return 0;
}



/*
PS C:\Users\Lenovo\Desktop\code\os> cd "c:\Users\Lenovo\Desktop\code\os\" ; if ($?) { g++ sjf.cpp -o sjf } ; if ($?) { .\sjf }
enter number of processes
5
enter arrival time of procces 1
0
enter burst time of process 1
8
enter arrival time of procces 2
3
enter burst time of process 2
4
enter arrival time of procces 3
7
enter burst time of process 3
5
enter arrival time of procces 4
10
enter burst time of process 4
3
enter arrival time of procces 5
12
enter burst time of process 5
6 
process 2 ended at : 7
process 1 ended at : 12
process 4 ended at : 15
process 3 ended at : 20
process 5 ended at : 26
pid     at      bt      wt      tat
1       0       8       12      12
2       3       4       4       4
3       7       5       13      13
4       10      3       5       5
5       12      6       14      14
average waiting time : 9.6
average turn around time : 9.6
PS C:\Users\Lenovo\Desktop\code\os> 
*/

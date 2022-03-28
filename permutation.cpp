#include<bits/stdc++.h>
using namespace std;

void solve(int resposta[], int a[], int start, int end, int iteracoes){
    int maior=0,pos;
    for (int i = start ; i<=end ; i++)
        if(a[i]>maior)
          {maior = a[i]; pos = i;}

    resposta[pos] = iteracoes;

    if(start!=pos) solve(resposta, a, start, pos-1, iteracoes + 1);
    if(end!=pos) solve(resposta, a, pos+1, end, iteracoes + 1);
}

int main(){
    int t,n;
    int a[101];
    cin >> t;
    while(t--)
    {
        int resposta[101]={};
        cin >> n;
        for (int i=1 ; i<=n ; i++)
            cin >> a[i];

        solve(resposta, a, 1, n, 0);

        bool esp = false;
        for (int i=1 ; i<=n ; i++)
        {
            if(esp) cout << ' ';
            else esp = true;
            cout << resposta[i];
        }
        cout << endl;
    }
    return 0;
}
// https://codeforces.com/problemset/problem/1490/D
// Codeforces 1490D.
// Ideia geral:
// Encontre o maior elemento e sua posicao.
// Particiona o vetor em 2 lados, referente a posicao(maior)
// Faca ate os vetores intermediarios terem tamanho 0.

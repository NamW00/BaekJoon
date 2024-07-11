#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string mk;
    cin >> mk;

    string min = "";
    string max = "";

    string tmp = "";

    int length = mk.size();
    
    // max값 구하는 for문 
    
    for (int i = length - 1; i >= 0; --i)
    {
        if (mk[i] == 'K')
        {
            if (!tmp.empty())
            {
                if (tmp[0] != '5')
                {
                    for (int j = 0; j < tmp.length(); ++j)
                    {
                        tmp[j] = '1';
                    }    
                }

                max = tmp + max;
                tmp = "";  
            }
            tmp += '5'; 
        }
        else
        {
            if (tmp.empty())
            {
                tmp += '1';
            }
            if(!tmp.empty())
            {
                tmp += '0';
            }
        }
    }

    if (tmp[0] != '5')
    {
        for (int i = 0; i < tmp.length(); ++i)
        {
            tmp[i] = '1';
        }
    }
    max = tmp + max;
    
    // min값 구하는 for문
    tmp = "";
    for (int i = length - 1; i >= 0; --i)
    {
        if (mk[i] == 'K')
        {
            min = '5' + tmp + min;
            tmp = "";
        }
        else
        {
            if(tmp.empty())
            {
                tmp += '1';
            }
            else
            {
                tmp += '0';
            }
        }  
    }
    min = tmp + min;

    cout << max << endl;
    cout << min << endl;
    
    return 0;
}
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int SIZ = 3005;
// string MK;
// char MIN_VAL[SIZ], MAX_VAL[SIZ];
// int N, st;
// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     cin >> MK;
//     N = MK.size();
//     st = 0;
//     memset(MIN_VAL, (int)'0', sizeof(MIN_VAL));
//     memset(MAX_VAL, (int)'0', sizeof(MAX_VAL));
//     MIN_VAL[N] = '\0';
//     MAX_VAL[N] = '\0';
//     for(int i = 0; i < N; i++){
//         if(MK[i] == 'M')    st++;
//         else{
//             MAX_VAL[i - st] = '5';
//             MIN_VAL[i - st] = '1';
//             MIN_VAL[i] = '5';
//             st = 0;
//         }
//     }
//     if(st){
//         for(int j = N - 1 - st + 1; j < N; j++)
//             MAX_VAL[j] = '1';
//         MIN_VAL[N - 1 - st + 1] = '1';
//     }
//     cout << MAX_VAL << '\n' << MIN_VAL << '\n';
//     return 0;
// }
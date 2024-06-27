#include <iostream>

using namespace std;

int main()
{
    int n;
    double max = 0;
    double score[1001];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
        if (i == 0)
        {
            max = score[0];
        }
        else
        {
            if (max < score[i])
            {
                max = score[i];
            }  
        }
    } 

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (score[i] / max) * 100;
    }
    


    cout << sum / n << endl;
    



    return 0;
}
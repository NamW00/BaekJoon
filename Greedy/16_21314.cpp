#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;



int main()
{
    string mk;
    cin >> mk;

    string Min = "";
    string Max = "";
    string tmp = "";

    int length = mk.size() - 1;

    for (int i = 0; i < length; i++)
    {
        
    }
    
    
    
    

    
    // max값 구하는 for문 
    for (int i = length; i >= 0;)
    {
        if (mk[i] == 'K')
        {
            if (mk[i - 1] == 'K')
            {
                min += (5 * pow(10,length - i));
            }
            else if (mk[i - 1] == 'M')
            {
                while (stack.empty())
                {
                    if (mk[i] == 'K')
                    {
                        break;
                    }
                    count++;
                }   
            }   
            i--;
        }
        else
        {
            while (mk[i] != 'K')
            {
                
            }
            
        }
    }
    for (int i = 0; i < mk.size(); i++)
    {
        stack.push(mk[i]);
    }
    // min값 구하는 for문
    for (int i = 0; i < mk.size(); i++)
    {
        if (mk[i] == 'M')
        {
            /* code */
        }
        
    }
    

    return 0;
}
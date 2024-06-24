#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;
    int N, result, num = 0;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;

        if (str == "push")
        {
            cin >> num;
            stack.push(num);
        }
        else if (str == "pop")
        {
            if (stack.empty()) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = stack.top();
				cout << result << endl;
				stack.pop();  
            }      
        }
        else if (str == "size")
        {
            cout << stack.size() << endl;
        }
        else if (str == "empty")
        {
            if (stack.empty())
            {
                result = 1;
                cout << result << endl;
            }
            else
            {
                result = 0;
                cout << result << endl;
            }
        }
        else if (str == "top")
        {
            if (stack.empty())
            {
                result = -1;
                cout << result << endl;
                
            }
            else
            {
                cout << stack.top() << endl;
            }  
        }
    }
    
    return 0;
}
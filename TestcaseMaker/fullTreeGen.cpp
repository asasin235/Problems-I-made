#include<iostream>
using namespace std;

// use this to get a random number from range [l, r]
int getRandomFromRange(int l, int r)
{
    int x = (l + ((rand() * rand()) % (r - l + 1)));
    return x;
}

int main()
{
    srand(time(0));
    int t = 1;
    cout<<t<<"\n";
    
    while(t--)
    {
        // Depth of the full tree
        // Tree will have 2^depth - 1 nodes
        int depth = 3, c = 0; 
    
        for(int i=0; i <= depth; i++)
        {
            if(i != depth)
            {
                for(int j = 0; j< (1ll<<i) ; j++)
                {
                    long long x = rand();
                    cout<<min((long long)1e5, x)<<" ";
                    c++;
                }
            }   
            else
            {
                for(int j=0; j<(1ll<<i); j++)
                {
                    cout << -1 << ' ';
                }
            }

            // cout << endl;
        }
    }

    cout<<"\n";
}
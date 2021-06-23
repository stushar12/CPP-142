#include<bits/stdc++.h>
using namespace std;


int main()
{
    int test_cases;
    cin>>test_cases;

    while(test_cases--)
    {
        string input;
        cin>>input;

            unordered_map<char,int> ump;
            set<int> s;

            for(int i=0;i<input.length();i++)
            {
                s.insert(input[i]);
            }
            int distinct=s.size();
            int i=0,j=1,ans=INT_MAX,count=0,start=0;

            ump[input[i]]++;
            count++;

            while(i<=j and j<input.length())
            {
                if(count<distinct)
                {
                    if(ump[input[j]]==0)
                    {  
                        count++;
                    }
                        ump[input[j]]++;
                        j++;
                }
                else if(count==distinct)
                {
                    if((j-i)<ans)
                    {
                        ans=j-i;
                        start=i;
                    }
                    if(ump[input[i]]==1)
                    {
                        count--;
                    }
                    ump[input[i]]--;
                    i++;
                }
            }

            while(count==distinct)
            {
                  if((j-i)<ans)
                    {
                        ans=j-i;
                        start=i;
                    }
                    if(ump[input[i]]==1)
                    {
                        count--;
                    }
                    ump[input[i]]--;
                    i++;
            }
    
        cout<<ans<<"  "<<input.substr(start,ans)<<endl;
    }
}

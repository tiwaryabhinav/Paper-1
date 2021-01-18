#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double med;
priority_queue<double> max_heap;
priority_queue<double,vector<double>,greater<double> > min_heap;
void fun(vector<double> &arr,int n,int i)
{
    double temp=arr[i];
     if (max_heap.size() > min_heap.size())
        {
            if (temp < med)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(temp);
            }
            else
                min_heap.push(temp);

            med = (max_heap.top() + min_heap.top())/2.0;
        }
        else if (max_heap.size()==min_heap.size())
        {
            if (temp < med)
            {
                max_heap.push(temp);
                med = (double)max_heap.top();
            }
            else
            {
                min_heap.push(temp);
                med = (double)min_heap.top();
            }
        }
        else
        {
            if (temp > med)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(temp);
            }
            else
                max_heap.push(temp);

            med = (max_heap.top() + min_heap.top())/2.0;
        }

        printf("AFTER INSERTING %d ELEMENT MEDIAN IS %f\n",i+1,med);
}
int main()
{
    vector<double> arr;
    int n;
    cout<<"ENTER NUMBER OF ELEMENTS YOU WANT TO INSERT\n";
    cin>>n;
    cout<<"\nENTER ELEMENTS\n";

    for(int i=0;i<n;i++)
    {
        double u;
        cin>>u;
        arr.push_back(u);
        if(i==0)
        {
            cout<<"AFTER READING FIRST ELEMENT MEDIAN IS "<<u<<"\n";
            max_heap.push(arr[0]);
            med=u;
        }
        else
            fun(arr,arr.size(),i);
    }

    return 0;
}

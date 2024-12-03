#include<bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i)
{
    int largest = i;
    int L=2*i;
    int R= 2*i+1;
    if(L<=n and a[L]>a[largest])
    {
        largest=L;
    }
    if(R<=n and a[R]>a[largest])
    {
        largest=R;
    }
    if(largest!=i)
    {
       
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[], int n)
{
    for(int i=((n+1)/2)-1;i>0; i--)
    {
        heapify(a,n,i);
    }
    cout<<"After Heapify: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=n;i>0;i--)
    {
       
        swap(a[i],a[1]);
        heapify(a,i-1,1);
    }
    cout<<"After Sorted: ";
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    heapSort(a,n);
    
    return 0;
}
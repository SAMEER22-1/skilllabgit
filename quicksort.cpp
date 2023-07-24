#include<iostream>
#include<algorithm>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
        {
            cnt++;
        }
    }
    int pivotindex=s+cnt;
    swap(arr[pivotindex],arr[s]);
    int i=s;
    int j=e;
    while (i<pivotindex&&j>pivotindex)  
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<pivotindex&&j>pivotindex)
        {
            swap(arr[i++],arr[j--]);
        }
        
    }
        return pivotindex;
    

}
void quicksort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main()
{
int arr[8]={1,4,5,8,9,2,90,43};
int n=8;
quicksort(arr,0,n);
for (int i = 0; i <n; i++)
{
    cout<<" "<<arr[i];
}
cout<<endl;

    return 0;
}
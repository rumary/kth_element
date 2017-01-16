#include <iostream>
#include <cmath>
//#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

int  my_sort(int arr[], int n)
{
    int tmp,count=0;
    for(int i = n-1; i>=1;i--)
    {
        for(int j = 0;j<i;j++)
        {
           // cout<<"arr["<<j<<"]="<<arr[j]<<endl;
            //cout<<"arr["<<j+1<<"]="<<arr[j+1]<<endl;
            count++;
//             cout<<count<<"'th iteration"<<endl;
//             cout<<"arr["<<i<<"] ? arr["<<j<<"]"<<endl;
            if(arr[i]<arr[j])
            {
//                cout<<"arr["<<i<<"] = "<<arr[i]<<" < arr["<<j<<"] = "<<arr[j]<<" then swap"<<endl;
                tmp =  arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            //else
            //{
//                cout<<"arr["<<i<<"] = "<<arr[i]<<" !< arr["<<j<<"] = "<<arr[j]<<" then do nothing"<<endl;
            //}
//            for(int r = 0;r<n;++r)
//            {
//                cout<< "arr["<<r<<"] = "<<arr[r]<<endl;
//            }
        }
//        cout<<endl;
    }
    cout<<"i sort "<<n<<" elements. Used "<<count<<" iterations"<<endl;
    for(int r = 0;r<n;++r)
    {
        cout<< "arr["<<r<<"] = "<<arr[r]<<endl;
    }
}
int Gen_arr( int arr[],int n, int max_Rand, int min_Rand)
{
    for(int i = 0;i<n;++i)
    {
        arr[i] = rand()% (max_Rand- min_Rand) + min_Rand;
        cout<< "arr["<<i<<"] = "<<arr[i]<<endl;
    }
}

int kth_Smallest(int arr[], int n, int k)
{
//    sort(arr,arr+n);
    my_sort(arr,n);
    return arr[k-1];

}
int median( int arr[], int n)
{
//    if(n%2==0)
//    {
//        cout<<"arr["<<n<<"/2]= "<<"arr["<<n/2<<"]="<<arr[n/2]<<endl;
//        cout<<"arr["<<n<<"/2 -1]= "<<"arr["<<n/2-1<<"]="<<arr[n/2-1]<<endl;
//    }
//    if(n%2!=0)
//    {
//        cout<<"arr[("<<n<<"-1)/2]= "<<"arr["<<(n-1)/2<<"]="<<arr[(n-1)/2]<<endl;
//    }
    my_sort(arr,n);
    if(n%2==0)
    {
        return (arr[n/2-1]+arr[n/2])/2;
    }
    else return arr[(n-1)/2];
}

int main()
{
    int min_Rand = 1, max_Rand = 100,n;
    srand(time(NULL));
    cout<<"sizeof arr  = ? ";
    cin>>n;
    int arr[n];
    Gen_arr( arr,n,max_Rand, min_Rand);

    int k;
    cout<<"k = ?";
    cin>>k;

    if (k>n) cout<<"error: n must biger then k";
    else
    {

        cout << "K_th smallest element is " <<kth_Smallest(arr,n,k)<<endl;
        cout << "Median is " <<median(arr,n)<<endl;

    }

//    my_sort(arr,n);

    return 0;
}

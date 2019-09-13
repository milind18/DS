//HEAP implementation of priority queue
#include<bits/stdc++.h>

using namespace std;

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

int parent(int i)
{
	return i/2;
}

void max_heapify(vector<int>&arr,int i)
{


	int l=left(i);
	

	int r=right(i);

	int largest;


	if(l<=arr.size()&&arr[l]>arr[i]) largest=l;
	else largest=i;

	if(r<=arr.size()&&arr[r]>arr[largest]) largest=r;
	
	if(largest!=i)	
	{
		int temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		max_heapify(arr,largest);
	}


}

void build_maxheap(vector<int>&arr)
{
	int i=arr.size()/2;

	while(i>=1)
	{
		max_heapify(arr,i);
		i--;
	}
}

int extract_max(vector<int>&arr)
{
	int ans=arr[1];

	arr[1]=arr[arr.size()-1];
	arr.resize(arr.size()-1);
	max_heapify(arr,1);
	return ans;
}


void insert(vector<int>&arr,int key)
{
	arr.resize(arr.size()+1);
	arr[arr.size()-1]=key;
	int i=arr.size()-1;
	while(i>1&&arr[parent(i)]<arr[i])
	{
		int temp=arr[parent(i)];
		arr[parent(i)]=arr[i];
		arr[i]=temp;
		i=parent(i);
	}
}

int main()
{
	
	 int n;
	 cin>>n;
	 int temp;
	 vector<int> arr(0);
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>temp;
		 insert(arr,temp);
	 }
	 
	 
	 cout<<extract_max(arr);
	 cout<<endl;
	 for(int i=1;i<arr.size();i++)
	 {
	 	cout<<arr[i]<<" ";
	 }


	 	return 0;
}
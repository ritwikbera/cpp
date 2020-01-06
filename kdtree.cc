#include<bits/stdc++.h> 
#include<iostream>
#include<chrono>
#include<vector>

using namespace std;
using namespace std::chrono;
using std::vector;

const int k = 2;

struct Node
{
	int point[k];
	Node *left, *right;
};

struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;
	for (int i=0; i<k; i++)
		temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	return temp;	
};

Node* insertRec(Node *root, int point[], unsigned depth)
{
	if(root == NULL)
		return newNode(point);

	unsigned cd = depth%k;

	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth+1);
	else
		root->right = insertRec(root->right, point, depth+1);

	return root;
}

Node* insert(Node* root, int point[])
{
	return insertRec(root, point, 0);
}

int min(int x, int y, int z)
{
	return min(x, min(y, z));
}

int findMinRec(Node* root, int d, unsigned depth)
{
	if(root == NULL)
		return INT_MAX;

	unsigned cd = depth%k;

	if (cd == d){
		if(root-> left == NULL)
			return root->point[d];
		return min(root->point[d], findMinRec(root->left,d,depth+1));
	}

	return min(root->point[d], findMinRec(root->left, d, depth+1),
		findMinRec(root->right, d, depth+1));
}

int findMin(Node* root, int d)
{
	return findMinRec(root, d, 0);
}

bool arePointsSame(int point1[], int point2[])
{
	for(int i=0; i<k; i++)
		if(point1[i] != point2[i])
			return false;

	return true;
}

bool searchRec(Node* root, int point[], unsigned depth)
{
	if(root==NULL)
		return false;
	if(arePointsSame(root->point, point))
		return true;

	unsigned cd = depth%k;

	if(point[cd] < root->point[cd])
		return searchRec(root->left, point, depth+1);
	return searchRec(root->right, point, depth+1);
}

bool search(Node* root, int point[])
{
	return searchRec(root, point, 0);
}

int main(){
	// auto start = high_resolution_clock::now();
	// std::cin.ignore(); //continue on pressing enter
	// auto stop = high_resolution_clock::now(); 
	// auto duration = duration_cast<microseconds>(stop - start);
	// cout << "Time taken by function: "
 //         << duration.count() << " microseconds" << endl; 

	struct Node *root = NULL;
	int points[][k] = {{3,6}, {17,15}, {13,15}, {6,12}, {9,1}, 
	{2,7}, {10, 19}};

	int n = sizeof(points)/sizeof(points[0]);
	for (int i=0; i<n; i++)
		root = insert(root, points[i]);

	int point1[] = {10, 19};
	(search(root, point1))?cout<<"Found\n":cout<<"Not Found\n";
	int point2[] = {12, 19};
	(search(root, point2))?cout<<"Found\n":cout<<"Not Found\n";
	
	cout << "Minimum of 0'th dimension is " << findMin(root, 0) << endl; 
    cout << "Minimum of 1'th dimension is " << findMin(root, 1) << endl; 
	
	return 0;
}

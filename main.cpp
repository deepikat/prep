//
//  main.cpp
//  prep
//
//  Created by Deepika Talwade on 2/4/15.
//  Copyright (c) 2015 Deepika Talwade. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
struct node{
    int val;
    struct node* next;
};

struct node* head = NULL;

void traverse()
{
    while (head != NULL) {
        cout<<head->val<<endl;
        head = head->next;
    }
}

int fun(int n)
{
    int count = 0;
    for (int i = n; i > 0; i /= 2)
        for (int j = 0; j < i; j++)
            count += 1;
    return count;
}
int element = '4';
void binarySearch(int a[], int l, int r)
{
    if(l>r)
    {
        cout<<"Not found :("<<endl;
        return;
    }
    
    int mid = (r+l)/2;
    cout<<endl<< mid << endl;
    if(element == a[mid])
    {
        cout<<"Element found at: "<<mid <<endl;
        return;
    }
    else if (element < a[mid])
    {
    
        binarySearch(a, l, mid-1);
    }
    else if (element > a[mid])
        binarySearch(a, mid+1, r);
    else
    {
        cout<<"Not found :("<<endl;
        return;
    }
    
}
void swapify(int *a1, int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
    return;
}


void heapify(int b[], int size)
{
    /*
     int i ;
    for(i = size/2; i>0; i--)
    {
        if(2*i+1 > size){
            if(b[i] >= b[2*i])
                continue;
            
            if((2*i > size) && (2*i+1 > size))
            {
                continue;
            }
            if (b[2*i] > b[2*i+1])
                swapify(&b[i], &b[2*i]);
        }
        
        if((b[i] >= b[2*i]) && (b[i] >= b[2*i+1]))
            continue;
        
        if((2*i > size) && (2*i+1 > size))
        {
            continue;
        }
        if (b[2*i] > b[2*i+1])
            swapify(&b[i], &b[2*i]);
        
        else if (b[2*i+1] > b[2*i])
            swapify(&b[i], &b[2*i+1]);
    }
     */
    
    int i ;
    for(i = size/2; i>0; i--)
    {
        if(2*i+1 <= size)
        {
            if((b[i] >= b[2*i]) && (b[i] >= b[2*i+1]))
                continue;
            
        
            if (b[2*i] > b[2*i+1])
                swapify(&b[i], &b[2*i]);
        
            else if (b[2*i+1] > b[2*i])
                swapify(&b[i], &b[2*i+1]);
        }
        
        else
        {
            if(b[i] >= b[2*i])
                continue;
            else
                swapify(&b[i], &b[2*i]);
        }
    }
    
    return;
}

void heap_sort(int a[], int size)
{
    if(size == 0)
        return;
    heapify(a, size);
    cout<<"------"<<a[1] <<"-----"<<endl;
    swap(a[1], a[size]);
    heap_sort(a, size-1);
}

int partition(int b[], int leftend, int rightend)
{
    int i = leftend;
    int p = b[leftend];
    for(int j = leftend+1 ; j<=rightend ;j++)
    {
        if(b[j] < p)
        {
            swapify(&b[j], &b[i+1]);
            i++;
        }
    }
    swapify(&b[leftend], &b[i]);
    return i;
}

void quick_sort(int a[], int l, int r)
{
    //int i =l;   // to store left of array
    
    //int j = r;   // to store right end of the array
    
    if(l > r)
        return;

    int partHere = partition(a,l, r);
    cout << partHere << "partition" <<endl;
    quick_sort(a, l, partHere-1);
    quick_sort(a, partHere+1, r);
}

/*
 void split(struct node * root, struct node *front, struct node * rear);

struct node* merge(struct node *front, struct node * rear)
{
    struct node * result =NULL;
    
    if(front == NULL)
        return rear;
    if(rear == NULL)
        return front;
    else
    {
        if(front->val < rear->val)
        {
            result->next = front;
            
        }
        
        
        return result;
    }
}

void mergeSort(struct node* root)
{
    if(root == NULL || root->next == NULL)
        return;
    struct node * front = NULL;
    struct node * rear = NULL;
    split(root, front, rear);
    mergeSort(front);
    mergeSort(rear);
    merge(front,rear);
    
}
*/

int lis(int arr[],int n)
{
    int i;
    int max_elem = 0;
    int max_end ;
    int count = 1;
    
    if(n ==1)
    {
        return count;
    }
    
    for(i=1; i<=n; i++)
    {
        if(arr[i] > arr[i-1] )
        {
            max_elem = arr[i];
            max_end = i;
            count++;
        }
            
    }
    
    return count;
    
}

void remove_vowels()
{
    string rem_vow = "!23#453aaaa(";
    int i=0;
    unsigned long int len = rem_vow.length();
    
    while (i<len)
    {
        //cout<<"  --  " <<rem_vow[i]<<"  --  " <<endl;
     
        char ch = rem_vow[i];
        switch (ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                rem_vow.erase(i,1);
                break;
                
            default:
                i++;
                break;
        }
       /* if (rem_vow[i]== 'a' || rem_vow[i]== 'e' || rem_vow[i]== 'i' || rem_vow[i]== 'o' || rem_vow[i]== 'u' || rem_vow[i]== 'A' || rem_vow[i]== 'E' || rem_vow[i]== 'I' || rem_vow[i]== 'O' || rem_vow[i]== 'U')
        {
            rem_vow.erase(i,1);
        }
        else
            i++;
        */
        
        //i++;
        
    }
    
    cout<<rem_vow<<endl;
}

void check_rotation()
{
    string txt = "waterbottle";
    string ptrn = "bottlewater";
    string double_ptrn = ptrn + ptrn;
    size_t found;
    found =double_ptrn.find(txt);
    if(found != string::npos)
    {
        cout<<"success"<<endl;
        return;
    }
    else
    {
        cout<<"Failure"<<endl;
        return;
    }
    
    
}


bool unique_characters(string ustr)
{
    // Function to check if a given string has unique characters without using additional data structures
    //1. sort the characters in the string
    //2. check adjacent values
    //3. if equal adjacent values, then return true else false
    
    sort(ustr.begin(), ustr.end());
    
    size_t len = ustr.length();
    for(int i=0; i<len-1 ; i++)
    {
        if(ustr[i] == ustr[i+1])
        {
            return false;
        }
        
    }
    return true;
}
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
     struct node *first = new node;
    first->val = 10;
    first->next = NULL;
    head = first;
    struct node *second = new node;
    second->val = 12;
    second->next = NULL;     
    first->next = second;
    struct node *third = new node;
    third->val = 8;
    third->next = NULL;
    second->next = third;
    struct node *fourth = new node;
    fourth->val = 15;
    fourth->next = NULL;
    third->next = fourth;
    traverse();
    
    int arrDP[9] = {10,22,9,33,21,50,41,60,80};
    
    cout<<" count of increasing subarray is " <<lis(arrDP, 8)<<endl;
    
    int a = fun(8);
    cout<< a<<"----";
    
    int arr[] = {10,20,30,40,50,60,70};
    binarySearch(arr, 0, 6);
    
    int arrToSort[] = {0,10,3 ,5, 2, 7, 12, 11};
    heap_sort(arrToSort, 7);
    
    for(int itr = 1; itr <= 7; itr++)
    {
        cout<<endl<< arrToSort[itr];
    }
    cout << endl;
    
    int arrToSortq[] = {12,10,8, 34};
    quick_sort(arrToSortq, 0, 3);
    
    cout<<endl<< "------QSA-----"<<endl;
    for(int itr = 0; itr <= 3; itr++)
    {
        cout<<arrToSortq[itr]<<endl;
    }
    
     */
    
    remove_vowels();
    cout<<endl;
    string ustr = "date";
    cout<<"Unique Characters?"<<endl<<unique_characters(ustr)<<endl;
    
    return 0;
}

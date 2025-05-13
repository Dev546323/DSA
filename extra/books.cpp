#include<iostream>
#include<vector>

using namespace std; 

bool isvalid (vector<int>arr, int n, int m, int mid){ 
    int students =1, pages =0; //assuming we have 1 student to begin with
    for(int i=0;i<n;i++){ //i less than the students present
        if(arr[i]>mid){ // a single student cannot be given books more than the mid value because that would break the contiguous fashion
            return false; 
        }
        if(pages + arr[i]<=mid){ //the pages that i'm giving the student, needs to be less than the max books i can give out
            pages+=arr[i];
        }
        else {
            students++; //if pages are too many, i can simply add a student to divide it between them
            pages= arr[i]; // resetting the pages i give to the student
        }
        
    }
    return students>m ? false : true;  //if more than given number of students are required to correctly divide the pages, return false. 

}

int allocateBooks(vector<int> arr, int m ){
    int n=arr.size();
    
    if(m>n) return -1; //students more than total number of books present
    int end=0; 
    int start=0;
    int ans=-1; //answer

    for(int i:arr){ //the max number of books that can be allocated to a student is the total number of books present. 
        end+=i;
    }
    if(m==1) return end;
    while (start<end){
        int mid= start + (end-start)/2;
        
        if (isvalid(arr,n,m,mid)){
            ans =mid; //checking if mid is a possible solution for the question 
            end=mid-1; // if it is valid, then we need to minimize the number of books given to a student
        }
        else start=mid+1; //if mid isn't a possible value, we need to increase the number of books in order to find a valid option at all. 
    }
    return ans;
}

int main(){
    cout << "Normal 1 = " << allocateBooks({12, 34, 67, 90}, 2) << endl;
cout << "Normal 2 = " << allocateBooks({10, 20, 30, 40}, 2) << endl;
cout << "Single book = " << allocateBooks({100}, 1) << endl;
cout << "Edge case: More students than books = " << allocateBooks({10, 20}, 3) << endl;
cout << "Equal pages = " << allocateBooks({50, 50, 50, 50}, 2) << endl;
cout << "All books 1 page = " << allocateBooks({1, 1, 1, 1, 1, 1}, 3) << endl;
cout << "All students get one book = " << allocateBooks({5, 17, 100, 11}, 4) << endl;
cout << "Optimal split in middle = " << allocateBooks({5, 17, 100, 11}, 2) << endl;
cout << "Split sequence 1 = " << allocateBooks({1, 2, 3, 4, 5}, 2) << endl;
cout << "Split sequence 2 = " << allocateBooks({1, 2, 3, 4, 5}, 3) << endl;

// Stress Test - Large Input, All Books Size 1
vector<int> stress_equal(100000, 1);
cout << "Stress test: All 1s, 1000 students = " << allocateBooks(stress_equal, 1000) << endl;

// Stress Test - Large Range of Book Pages
vector<int> stress_varied;
for (int i = 1; i <= 100000; i++) stress_varied.push_back(i);
cout << "Stress test: Increasing pages, 500 students = " << allocateBooks(stress_varied, 500) << endl;

// Stress Test - Only One Student
vector<int> oneStudent;
for (int i = 0; i < 10000; i++) oneStudent.push_back(rand() % 1000 + 1);
cout << "Stress test: Random pages, 1 student = " << allocateBooks(oneStudent, 1) << endl;


}
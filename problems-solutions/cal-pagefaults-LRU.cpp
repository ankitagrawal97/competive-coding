/* To calculate number of pagefaults occured from a given array of pages
assuming cache size to be n with Least Recently Used Algorithm.
*/
/*Algorithm:
Let capacity be the number of pages that
memory can hold.  Let set be the current
set of pages in memory.

1- Start traversing the pages.
 i) If set holds less pages than capacity.
   a) Insert page into the set one by one until 
      the size  of set reaches capacity or all
      page requests are processed.
   b) Simultaneously maintain the recent occurred
      index of each page in a map called indexes.
   c) Increment page fault
 ii) Else 
   If current page is present in set, do nothing.
   Else 
     a) Find the page in the set that was least 
     recently used. We find it using index array.
     We basically need to replace the page with
     minimum index.
     b) Replace the found page with current page.
     c) Increment page faults.
     d) Update index of current page.

2. Return page faults.*/

#include <bits/stdc++.h>

using namespace std;


int pageFaults(int pages[], int len , int capacity){

	int pagefault = 0;
	unordered_set<int> s; //for cache
	unordered_map<int,int> indexes; //for tracking LRU page
	
	for(int i = 0 ; i < len ; i++){
		
		if(s.size() < capacity){ //check the cache size
			if(s.find(pages[i])==s.end()){ //if cache size is less and encountered page is not found
			s.insert(pages[i]); //insert page
			pagefault++; //increase page fault
		}

			indexes[pages[i]] = i; //map the newly inserted page.
		
		}else{
			if(s.find(pages[i])==s.end()){ //if cache is full and the page encountered doesnot exists
			
			int lru = INT_MAX;
			int val;
			int key = 0;
			for (auto k : s){
				if (indexes[k]< lru) //finding lru page
				{
					lru = indexes[k];
					val = k;
				}
				
			}
				s.erase(val); //remove the page
				s.insert(pages[i]); //insert new page
				pagefault++; //increase pagefault
				
			}
			indexes[pages[i]] = i; //map the newly inserted page
		}
		}
		return pagefault;
	}
	

int main(){
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int n = sizeof(pages)/sizeof(pages[0]); 
    int capacity = 4; 
    cout << pageFaults(pages, n, capacity); 
    return 0; 
	}


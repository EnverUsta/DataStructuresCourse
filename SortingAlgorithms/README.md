**In-Place sorting**
->If you don't make extra memory allocation while sorting, it's called in-place sorting  


**External and Internal Sorting**
->if your elements live in the  memory it's called internal sorting(we're already familiar with this).  
However, if our elements are situated apart from the memory(such as hdd, ssd, CD etc. it's used for massive amounts of data), it's called  external sorting.

Algorithm	Time Complexity  

                  Best  	    Average	      Worst  
                  
Selection Sort  Ω(n^2)	      θ(n^2)	      O(n^2)  
Bubble Sort	    Ω(n)	        θ(n^2)	      O(n^2)  
Insertion Sort	Ω(n)	        θ(n^2)	      O(n^2)  
Heap Sort	      Ω(n log(n))	  θ(n log(n))	  O(n log(n))  
Quick Sort	    Ω(n log(n))	  θ(n log(n))	  O(n^2)  
Merge Sort	    Ω(n log(n))	  θ(n log(n))	  O(n log(n))  
Bucket Sort	    Ω(n+k)	      θ(n+k)	      O(n^2)  
Radix Sort	    Ω(nk)	        θ(nk)	        O(nk)  


Stable => do research about stable

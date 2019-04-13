#include<bits/stdc++.h>
#include <algorithm> 
#include <fstream>
#include <chrono> 
#define MOD 1e9+7

using namespace std;
using namespace std::chrono; 

#define  pp push_back
#define  po pop_back
#define  mp make_pair
//void printvector(std::vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}

ofstream myfile ;

struct page
{
   int val;
   int used_bit;
   page()
   {
   	 val=-1;
   	 used_bit=0;
   }

};

struct virtual_mem
{
	int no_of_pages;
    std::vector<page> v;
    bool isfull;
    bool isempty;
    int no_of_faults;
    int length;
    virtual_mem(int n)
    {
       no_of_pages=n;
       isfull=false;
       isempty=true;
       no_of_faults=0;
       length=0;
    }
};

void page_fault_delay(){
	int counter=0 ;
	for(int i=0;i<500;i++){
  		counter++ ;
	}
}


void LRU_clock(int no_of_pages){
	
	auto start = high_resolution_clock::now(); 
	
	virtual_mem clock_mem(no_of_pages) ;
	page insert_page ;

	std::vector<int> frame_sequence;
    for(int i=0;i<1000000;i++)
    {
      int x;
      cin>>x;
      frame_sequence.push_back(x);
    } 
    
   // printvector(frame_sequence) ;

    int reference_pointer=0 ;
    int replacement_pointer=0 ; 
    int frame_counter=0;
    
  
    while(frame_counter<1000000){

    	if(clock_mem.isempty){
    		insert_page.val=frame_sequence.at(frame_counter) ;
    		insert_page.used_bit=1 ;
    		clock_mem.v.push_back(insert_page) ;
    		clock_mem.isempty=false ;
    		clock_mem.no_of_faults++ ;
    		page_fault_delay() ;
    		clock_mem.length++;
    	//	frame_counter++;

    	} else if(!clock_mem.isempty && !clock_mem.isfull){

    		reference_pointer=0 ;
    		bool check=true ;
    		while(clock_mem.v[reference_pointer].val!=-1){
    			if(clock_mem.v[reference_pointer].val == frame_sequence.at(frame_counter)){
    				if(clock_mem.v[reference_pointer].used_bit==0){
    					clock_mem.v[reference_pointer].used_bit=1 ;
    				} 
    	//			frame_counter++ ;
    				check=false ;
    				break ;
    			}
    			reference_pointer++ ;
    			if(reference_pointer>=clock_mem.length){
    				break ;
    			} 
    		}
    		if(check){
	    		insert_page.val=frame_sequence.at(frame_counter);
	    		insert_page.used_bit=1 ;
	    		clock_mem.v.push_back(insert_page) ;
    			clock_mem.no_of_faults++ ;
    			page_fault_delay() ;
    			clock_mem.length++ ;
    		//	frame_counter++ ;
    		}
    	
    		if(reference_pointer==no_of_pages-1){
    			clock_mem.isfull=true ;
    		}

    	} else {

    		bool check=true ;
    		reference_pointer=0 ;
    		while(reference_pointer<no_of_pages){
    			if(frame_sequence.at(frame_counter) == clock_mem.v[reference_pointer].val){
    				if(clock_mem.v[reference_pointer].used_bit==0){
    					clock_mem.v[reference_pointer].used_bit=1 ;
    				} 
    			//	frame_counter++ ;
    				check=false ;
    				break ;
    			}
    			reference_pointer++ ;
    		}
    		if(check){

    			while(clock_mem.v[replacement_pointer].used_bit == 1){
    				clock_mem.v[replacement_pointer].used_bit=0 ;
    				replacement_pointer=(replacement_pointer+1)%no_of_pages ;
    			}
    			clock_mem.v[replacement_pointer].val = frame_sequence.at(frame_counter) ;
    			clock_mem.v[replacement_pointer].used_bit = 1 ;
    			replacement_pointer=(replacement_pointer+1)%no_of_pages ;
    		//	frame_counter++ ;
    			clock_mem.no_of_faults++ ;
    			page_fault_delay() ;
    		}

    	}
    	frame_counter++ ;
	}
/*for (int i = 0; i < 10; ++i)
	{
		cout<<clock_mem.v[i].val<<" ";
}
cout<<""<<endl;*/
	auto end = high_resolution_clock::now() ;

	myfile<<clock_mem.no_of_faults<<"\t\t\t\t\t\t"
				<<duration_cast<microseconds>(end-start).count()<<endl ;
	//cout<<clock_mem.no_of_faults<<endl ;

}


int32_t main() 
{  	

   	/* for input file 1, uncomment the following code until the first loop
   											 and comment the loop code for input 2 
   																					
   	myfile.open("output1.txt") ;
	myfile<<"The size of the reference string is 1000000"<<endl ;
	myfile<<endl ;
	myfile<<"No. of page frames\t\tNo. of Page-faults\t\tExecution Time(microseconds)"<<endl ;

   	int mult=100 ;  
   	for (int i=1;i<=75;i++){
   		freopen("input1_max6000.txt", "r", stdin);

   		myfile<<"\t\t"<<(i*mult)<<"\t\t\t\t\t" ;
   		LRU_clock(i*mult);	
   	}
   	*/


   	/* for input file 2, uncomment the following code and comment the input 1 code above. */
   	
   	myfile.open("output_pow(10,6).txt") ;
	myfile<<"The size of the reference string is 1000000"<<endl ;
	myfile<<endl ;
	myfile<<"No. of page frames\t\tNo. of Page-faults\t\tExecution Time(microseconds)"<<endl ;

   	for (int i=1;i<=110;i++){
   		freopen("input2_max100.txt", "r", stdin);
          int mult=10;
   		myfile<<"\t\t"<<(i*mult)<<"\t\t\t\t\t" ;
   		LRU_clock(i*mult);	
   	}
   	      

   myfile.close() ;

  return 0;

}


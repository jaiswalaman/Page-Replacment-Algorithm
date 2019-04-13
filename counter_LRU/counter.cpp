#include<bits/stdc++.h>
#define MOD 1e9+7
using namespace std;
#define  pp push_back
#define  po pop_back
#define  mp make_pair
#define clr(a) memset(a,0,sizeof(a))
#define neg(a) memset(a,-1,sizeof(a))
#define fas(a) memset(a,false,sizeof(a))
#define debug(x) cout<<#x<<": "<<x<<endl
#define debug1(x) cout<<#x<<": "<<x<<" "
#define rev(x) reverse(x.begin(), x.end())
#define int long long 
#define F first
#define S second
void printvector(std::vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void printarray(int a[],int n){for (int i = 0; i < n; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
 
std::vector<int> frame_sequence;


void delay()
{
   for (int i = 0; i < 500; ++i)
   {
     
   }
}


struct  page
{
   int val;
   double tim;
   page()
   {
     val=0;
     tim=0;
   }

};


struct cache
{
    
    int no_of_pages;
    std::vector<page> v;
    bool isfull;
    int no_of_faults;
    unordered_map<int,int> reference;
    map<double,int> time_stamp;
    double start_timed;
    cache(int n,double gap)
    {
       no_of_pages=n;
       isfull=false;
       
       no_of_faults=0;
       start_timed=clock();
       reference.clear();
    }


};



 

void run(int n)
{
    
    clock_t start=clock();
     
    cache page_table(n,10);
    for(int i=0;i<frame_sequence.size();i++)
    {
       clock_t g1=clock()-page_table.start_timed;
        int frame=frame_sequence[i];

        if(page_table.reference[frame]==0)
        {
           page_table.no_of_faults++;
           delay();
             
            if(page_table.isfull)
            {
                pair<double,int> temp=*page_table.time_stamp.begin();
                page_table.reference.erase(page_table.v[temp.S-1].val);
                page_table.time_stamp.erase(temp.F);
                page_table.v[temp.S-1].val=frame; 
                page_table.v[temp.S-1].tim=g1;
                page_table.time_stamp[(double)g1]=temp.S;  
                page_table.reference[frame]=temp.S;
            }
            else
            {
                 page temp;
                 temp.val=frame;
                 page_table.v.push_back(temp);
                 if(page_table.v.size()==page_table.no_of_pages)
                 {
                    page_table.isfull=true;
                 }
                 page_table.reference[frame]=page_table.v.size();
                 page_table.time_stamp[(double)g1]=page_table.v.size();
            }
        }
        else
        { 
                      
           int index=page_table.reference[frame];
           index--;
           page_table.time_stamp.erase(page_table.v[index].tim);
           page_table.v[index].tim=(double)g1;
           page_table.time_stamp[(double)g1]=index+1;        

        }


        /*for(int i=0;i<page_table.v.size();i++)
        {
           cout<<page_table.v[i].val<<" ";
        }      

        cout<<" "<<endl;*/
    
    }

//    cout<<page_table.no_of_faults<<endl;
   
    start=clock()-start;
    cout<<(double)start/CLOCKS_PER_SEC<<endl; 
    
 

} 




 int32_t main() 
{

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("real_output.txt","w",stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   
  int val=10;

    
  for(int i=0;i<1e6;i++)
   {
    int x;cin>>x;
    frame_sequence.push_back(x);
    if(i+1==val)
    {
      run(50);
      val=val*10;
    }


   } 
   
   
   

  
  return 0;                                        



}
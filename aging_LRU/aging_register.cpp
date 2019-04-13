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
   int reg_counter;
   page()
   {
   	 val=0;
   	 reg_counter=0;
   }

};


struct cache
{

    int no_of_pages;
    std::vector<page> v;
    bool isfull;
    clock_t last_time_update;
    int no_of_faults;
    double refresh_time;
    cache(int n,double gap)
    {
       no_of_pages=n;
       refresh_time=gap*(0.000001);

       isfull=false;
       last_time_update=clock();
       no_of_faults=0;

    }


};





void run(int n)
{

    clock_t start=clock();

    cache page_table(n,10);
    for(int i=0;i<frame_sequence.size();i++)
    {

      int frame=frame_sequence[i];
      int pointer=-1;
      for(int i=0;i<page_table.v.size();i++)
      {
         if(page_table.v[i].val==frame)
         pointer=i;
      }

      if(pointer==-1)
        {

            page_table.no_of_faults++;
            delay();
            if(page_table.isfull)
        	  {
              int replace=0;
              int mi=(int)1<<8;
              for(int i=0;i<page_table.v.size();i++)
              {
                    if(page_table.v[i].reg_counter<=mi)
                    {
                      replace=i;
                      mi=page_table.v[i].reg_counter;
                    }
              }

        		 page_table.v[replace].val=frame;
        	   page_table.v[replace].reg_counter=(int)1<<7;



        	 }
        	else
        	{

               page temp;
               temp.val=frame;
               temp.reg_counter=(int)1<<7;
               page_table.v.push_back(temp);

               if(page_table.v.size()==page_table.no_of_pages)
               {
               	 page_table.isfull=true;
               }
          }
        }
        else
        {

           int index=pointer;

           page_table.v[index].reg_counter=page_table.v[index].reg_counter|((int)1<<7);
        }






      double gap=((double)(clock()-page_table.last_time_update))/CLOCKS_PER_SEC;

       if(gap>page_table.refresh_time)
       {

  //     	  delay();

           for(int j=0;j<page_table.v.size();j++)
           {
           	  page_table.v[j].reg_counter=page_table.v[j].reg_counter/2;
           }



         page_table.last_time_update=clock();

       }

    }


    start=clock()-start;
    cout<<"Execution time: "<<(double)start/CLOCKS_PER_SEC<<endl;


    cout<<"Page faults: "page_table.no_of_faults<<endl;


}




 int32_t main()
{

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("real_output.txt","w",stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  for(int i=0;i<1e6;i++)
   {
    int x;cin>>x;
   	frame_sequence.push_back(x);
   }


   int max=6000;
   for(int n=1;n<=max;n=n+100)
   {
   	 run(n);

   }


  return 0;



}

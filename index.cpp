#include <iostream>
#include <vector>
#include <limits>
#include<string>
using namespace std;
int main() {
    int i = 0;
    int cost[] = {20, 40, 50};
    std::vector<std::pair<std::string, int>> arr;
    int totalit = 0;
    int totalCt = 0;
    char pr = 'A';

    while (i < 3) {
        int qty;
        std::cout << "Please enter the quantity of product " << pr << ":" ;
        std::cin >> qty;
        arr.push_back(std::make_pair(std::string(1, pr), qty));
        pr = static_cast<char>(pr + 1);
        totalit += qty;
        totalCt += qty * cost[i];
        i++;
    }

    int dis1 = 0;
    int dis2 = 0;
    int dis3 = 0;
    int dis4 = 0;
    string dis1name = "flat_10_discount" ;
    string dis2name = "bulk_5_discount" ;
    string dis3name = "bulk_10_discount" ;
    string dis4name = "tiered_50_discount" ;
    if( totalCt > 200 ) {
    dis1 = 10 ;
}
i = 0 ;
while( i < 3 ) {
    if( arr[ i ].second > 10 && dis2 != 0 ){
        dis2 = totalit * 0.05 ;
    }
    if( arr[ i ].second > 20 && dis3 == 0  ){
        dis3 = totalit * 0.1 ;
    }
    if( totalit > 30 && arr[ i ].second > 15 ) {
        dis4 += ( 0.5 *  ((arr[ i ].second) - 15 ) ) ;
    }
    i++;
}

string finaldisname = "" ;
int maxi = max( dis1 , max( dis2 , max( dis3 , dis4))) ;
if(maxi == dis1 ) {
finaldisname = dis1name ;
}
if(maxi == dis2 ) {
    finaldisname = dis2name ;
}
if(maxi == dis3 ) {
    finaldisname = dis3name ;
}
if(maxi == dis4 ) {
    finaldisname = dis4name ;
}
if( maxi == 0 ) {
    finaldisname = "No Discount Applicable";
}
char ques ;
cout<<"Do you want to wrap this product ? (Y/N) :";
cin>>ques;
int gift = 0 ;
if( ques == 'y' || ques == 'Y') {
    gift++;
    totalCt++;
}

float shipping = ((float)(totalit) / 10.0 ) *  5.0 ;
i = 0 ;
while( i < 3 ) {
cout<<arr[i].first<<" : "<<arr[ i ].second<<" "<<"t : "<<(arr[ i ].second * cost[ i ])<<endl;
i++;
}
cout<<"Total Cost :"<<totalCt<<endl ;
cout<<"Final Discount :"<<finaldisname<<" "<<maxi<<endl;
cout<<"Shipping :"<<shipping<<" "<<"Gift Wrap Fee :"<<gift<<endl;
cout<<"Total Amount :"<<(totalCt - maxi + shipping) ;
    return 0;
}

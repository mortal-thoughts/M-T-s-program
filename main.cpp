#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//日历ver1.0

/*bool is_lunar_year(int year){
    if((year%4!=0)||(year%100==0&&year%400!=0)){
        return 0;
        }
    else return 1;
    }
int the_year_xin_date(int year,int xin_date){
    int count=0;
    int Number=year-2022;
    for(int year_test=2022;year_test<year;year_test++){
        if(is_lunar_year(year_test)){count++;};
    }
    int add_xin_date=(365*Number+count)%7;
    if((xin_date+add_xin_date)==7){
        return 7;
    }
    else return (xin_date+add_xin_date)%7;
}
//已知2022.1.1为周六
int main() {
    int year=1;
    cin>>year;
    int count=1;
    int xin_data=6;
    int data=1;
    int monthNumber=31;
    int month=1;
    int k=0;
    xin_data=the_year_xin_date(year,xin_data);
    cout<<"01"<<" ";
    for(int i=1;i<(3*xin_data-2);i++){
        cout<<" ";
    }
    for(;month<=12;month++){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            monthNumber=31;
            for(int count=1;count<=monthNumber;count++){
                if(data<10){
                    cout<<data<<" "<<" ";
                }
                else{cout<<data<<" ";}
                if(xin_data==7){
                    cout<<endl;
                    if((data+7)>monthNumber&&k==0){
                        if(month==10){cout<<month+1<<" ";k=1;}
                        if(month==1||month==3||month==5||month==7||month==8){cout<<'0'<<month+1<<" ";k=1;}
                        if(month==12){cout<<" "<<" "<<" ";k=1;}
                    }
                    else cout<<" "<<" "<<" ";
                    xin_data=1;
                }
                else xin_data++;
                data++;
            }
            data=1;
            k=0;
        }

        if(month==4||month==6||month==9||month==11){
            monthNumber=30;
            for(int count=1;count<=monthNumber; count++){
                if(data<10){
                    cout<<data<<" "<<" ";
                }
                else{cout<<data<<" ";}
                if(xin_data==7){
                    cout<<endl;
                    if((data+7)>monthNumber&&k==0){
                        if(month==9||month==11){cout<<month+1<<" ";k=1;}
                        if(month==4||month==6){cout<<'0'<<month+1<<" ";k=1;}
                    }
                    else cout<<" "<<" "<<" ";
                    xin_data=1;
                }
                else xin_data++;
                data++;
            }
            data=1;
            k=0;
        }

        if(month==2){
            monthNumber=28;
            if(is_lunar_year(year)){
                monthNumber=29;
            }
            for(int count=1;count<=monthNumber; count++){
                if(data<10){
                    cout<<data<<" "<<" ";
                }
                else{cout<<data<<" ";}
                if(xin_data==7){
                    cout<<endl;
                    if((data+7)>monthNumber&&k==0){
                        cout<<'0'<<month+1<<" ";k=1;
                    }
                    else cout<<" "<<" "<<" ";
                    xin_data=1;
                }
                else xin_data++;
                data++;
            }
            data=1;
            k=0;
        }
    }
    month=1;
    return 0;
}*/

//日历ver1.1
/*bool is_lunar_year(int year) {
    if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) {
        return 0;
    } else return 1;
}
//返回想要年份1月1日的星期
int the_year_xin_date(int first_year,int first_month,int first_xin_date,int first_day,int my_year){
    int count=first_day;
    int mod_count;
    for(int month=1;month<first_month;month++){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            count+=31;
        }
        if(month==4||month==6||month==9||month==11){
            count+=30;
        }
        if(month==2){
            if(is_lunar_year(first_year)){
                count+=29;
            }
            else count+=28;
        }
    }
    if(is_lunar_year(first_year)){
        mod_count=366-count;
    }
    else {mod_count=365-count;}
    for(int year=first_year;year<my_year;year++){
        if(is_lunar_year(year))mod_count+=366;
        else mod_count+=365;
    }
    if((mod_count%7+first_xin_date)==7){
        return 7;
    }
    else return (mod_count%7+first_xin_date)%7;
}
//已知2021.9.13为周六，此程序只能输出2022年之后年份的日历，但可以通过改变已知的年份条件来扩大范围；
int main(){
    //2021.9.13为周六
    int first_year=2021;
    int first_month=9;
    int first_date=13;
    int first_xin_date=1;
    //输入想要的年份，默认2022年
    int year=2022;
    cin>>year;
    int month=1;
    int date=1;
    int xin_date=the_year_xin_date(first_year,first_month,first_xin_date,first_date,year);
    int monthNumber=31;
    int k=0;
    cout<<"01"<<" ";
    for(int i=1;i<(3*xin_date-2);i++){
        cout<<" ";
    }
    for(;month<=12;month++){
        //大月
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            monthNumber=31;
            for(int count=1;count<=monthNumber;count++){
                if(date<10){
                    cout<<date<<" "<<" ";
                }
                else{cout<<date<<" ";}
                if(xin_date==7){
                    cout<<endl;
                    if((date+7)>monthNumber&&k==0){
                        if(month==10){cout<<month+1<<" ";k=1;}
                        if(month==1||month==3||month==5||month==7||month==8){cout<<'0'<<month+1<<" ";k=1;}
                        if(month==12){cout<<" "<<" "<<" ";k=1;}
                    }
                    else cout<<" "<<" "<<" ";
                    xin_date=1;
                }
                else xin_date++;
                date++;
            }
            date=1;
            k=0;
        }
        //小月
        if(month==4||month==6||month==9||month==11){
            monthNumber=30;
            for(int count=1;count<=monthNumber; count++){
                if(date<10){
                    cout<<date<<" "<<" ";
                }
                else{cout<<date<<" ";}
                if(xin_date==7){
                    cout<<endl;
                    if((date+7)>monthNumber&&k==0){
                        if(month==9||month==11){cout<<month+1<<" ";k=1;}
                        if(month==4||month==6){cout<<'0'<<month+1<<" ";k=1;}
                    }
                    else cout<<" "<<" "<<" ";
                    xin_date=1;
                }
                else xin_date++;
                date++;
            }
            date=1;
            k=0;
        }
        //闰月
        if(month==2){
            monthNumber=28;
            if(is_lunar_year(year)){
                monthNumber=29;
            }
            for(int count=1;count<=monthNumber; count++){
                if(date<10){
                    cout<<date<<" "<<" ";
                }
                else{cout<<date<<" ";}
                if(xin_date==7){

                    cout<<endl;
                    if((date+7)>monthNumber&&k==0){
                        cout<<'0'<<month+1<<" ";k=1;
                    }
                    else cout<<" "<<" "<<" ";
                    xin_date=1;
                }
                else xin_date++;
                date++;
            }
            date=1;
            k=0;
        }
    }
    //输出一年后，在将月份变成1
    month=1;
    return 0;
}*/
int main(){
    cout<<0%1;
}
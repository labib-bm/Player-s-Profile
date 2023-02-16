#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
string name[20] = {"Tamim_Iqbal", "Mushfiqur_Rahim", "Mustafizur_Rahman", "Mahmudullah_Riad", "Sabbir_Rahman", "Soumya_Sarker", "Rubel_Hossain", "Liton_Das", "Mosaddek_Hossain", "Mehidy_Hasan", "Mohammad_Saifuddin", "Imrul_Kayes", "Taskin_Ahmed", "Mashrafe_Mortaza", "Sakib_Al_Hasan"};
string birth[20] = {"20-03-1989", "09-06-1987", "06-09-1995", "04-02-1986", "22-11-1991", "25-02-1993", "01-01-1990", "13-10-1994", "10-12-1995", "25-10-1997", "01-11-1996", "02-02-1987", "03-04-1995", "05-10-1983", "24-03-1987"};
int age[20] = {30, 32, 24, 33, 28, 26, 29, 25, 24, 22, 23, 32, 24, 36, 32};
int ODI[20] = {29, 18, 18, 50, 66, 80, 37, 75, 82, 90, 17, 94, 78, 44, 1};
int Test[20] = {27, 26, 57, 44, 66, 101, 74, 102, 78, 96, 24, 83, 96, 57, 1};
int T20I[20] = {64, 52, 36, 29, 66, 53, 50, 103, 41, 104, 107, 109, 121, 61, 3};
void Alphabetic_Order(int n);
void sort_birth_date(int n);
void sort_ODI_rank(int n);
void sort_Test_rank(int n);
void sort_T20I_rank(int n);
void sort_age(int n);
void Update(int n);
void Details(int n);
void Display(int n);
int Delete(int n);
void Display(int n)
{
    int i;
    cout << "Sl.  Name                   Birth Date   Age   ODI   Test    T20" << endl << endl;
    for(i=0;i<n;i++){
            if(i+1<10) cout << 0;
            int k = name[i].size();
        cout << i+1 << ".  " << name[i] << setw(33-k) << birth[i] << "    " << age[i] << setw(6) << ODI[i] << setw(7) << Test[i] << setw(7) << T20I[i] << endl;
    }
}
int Delete(int n)
{
    int i,j,flag=0;
    string s;
    Display(n);
    cout << "Enter Player's Name:" << endl;
    cin >> s;
    for(i=0;i<n;i++){
        if(s==name[i]) {flag=1; break;}
    }
    if(flag==1){
    for(j=i;j<n-1;j++){
                swap(name[j],name[j+1]);
                swap(birth[j],birth[j+1]);
                swap(age[j],age[j+1]);
                swap(ODI[j],ODI[j+1]);
                swap(Test[j],Test[j+1]);
                swap(T20I[j],T20I[j+1]);
    }
    }
    else cout << "Player Not Found" << endl;
    return flag;
}
void Update(int n)
{
    int i,k,z;
    string s;
    Display(n);
    cout << "Choose Player's Name: ";
    cin >> s;
    for(i=0;i<n;i++){
        if(s==name[i]) break;
    }
    if(i<n){
    cout << "Choose Any option to update:\n1. ODI Rank\n2. Test Rank\n3. T20I Rank" << endl;
    cin >> k;
    if(k==1){
        cout << "New ODI Rank: ";
        cin >> z;
        ODI[i]=z;
    }
    else if(k==2){
        cout << "New Test Rank: ";
        cin >> z;
        Test[i]=z;
    }
    else if(k==3){
        cout << "New T20I Rank: ";
        cin >> z;
        T20I[i]=z;
    }
    }
    else cout << "Player not found" << endl;
}
void Details(int n)
{
    int i;
    string s;
    int flag=0;
    Display(n);
    cout << "Enter Name of a Player: ";
    cin >> s;
    for(i=0;i<n;i++){
        if(s==name[i]) {cout << endl << name[i] << "    " << birth[i] << "    " << age[i] << "    " << ODI[i] << "    " << Test[i] << "    " << T20I[i] << endl << endl;
                        flag=1; break;}
    }
    if(flag==0) cout << "Player's not found" << endl << endl;
}
void Alphabetic_Order(int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(name[i]>name[j]){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
        }
    }
    cout << "Sorted in Alphabetic Order: " << endl;
}
void sort_age(int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(age[i]<age[j]){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
            else if(age[i]==age[j]){
                string A = birth[i];
                string B = birth[j];
                int m1 = (A[4]-48)+(A[3]-48)*10;
                int m2 = (B[4]-48)+(B[3]-48)*10;
                if(m1>m2){
                    swap(name[i],name[j]);
                    swap(birth[i],birth[j]);
                    swap(age[i],age[j]);
                    swap(ODI[i],ODI[j]);
                    swap(Test[i],Test[j]);
                    swap(T20I[i],T20I[j]);
                }
                else if(m1==m2){
                    int d1 = (A[1]-48)+(A[0]-48)*10;
                    int d2 = (B[1]-48)+(B[0]-48)*10;
                    if(d1>d2){
                        swap(name[i],name[j]);
                        swap(birth[i],birth[j]);
                        swap(age[i],age[j]);
                        swap(ODI[i],ODI[j]);
                        swap(Test[i],Test[j]);
                        swap(T20I[i],T20I[j]);
                    }
                }
            }
        }
    }
}
void sort_ODI_rank(int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ODI[i]>ODI[j]){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
        }
    }
}
void sort_Test_rank(int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(Test[i]>Test[j]){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
        }
    }
}
void sort_T20I_rank(int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(T20I[i]>T20I[j]){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
        }
    }
}
void sort_birth_date(int n)
{
    int i,j;
    cout << endl;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
                string A = birth[i];
                string B = birth[j];
            int y1 = (A[9]-48)+(A[8]-48)*10+(A[7]-48)*100+(A[6]-48)*1000;
            int y2 = (B[9]-48)+(B[8]-48)*10+(B[7]-48)*100+(B[6]-48)*1000;
            if(y1>y2){
                swap(name[i],name[j]);
                swap(birth[i],birth[j]);
                swap(age[i],age[j]);
                swap(ODI[i],ODI[j]);
                swap(Test[i],Test[j]);
                swap(T20I[i],T20I[j]);
            }
            else if(y1==y2){
                int m1 = (A[4]-48)+(A[3]-48)*10;
                int m2 = (B[4]-48)+(B[3]-48)*10;
                if(m1>m2){
                    swap(name[i],name[j]);
                    swap(birth[i],birth[j]);
                    swap(age[i],age[j]);
                    swap(ODI[i],ODI[j]);
                    swap(Test[i],Test[j]);
                    swap(T20I[i],T20I[j]);
                }
                else if(m1==m2){
                    int d1 = (A[1]-48)+(A[0]-48)*10;
                    int d2 = (B[1]-48)+(B[0]-48)*10;
                    if(d1>d2){
                        swap(name[i],name[j]);
                        swap(birth[i],birth[j]);
                        swap(age[i],age[j]);
                        swap(ODI[i],ODI[j]);
                        swap(Test[i],Test[j]);
                        swap(T20I[i],T20I[j]);
                    }
                }
            }
        }
    }
}
int main(void)
{
    int i,j,n;
    n=15;
    Alphabetic_Order(n);
    Display(n);
    int p;
    while(1){
        cout << "Select any option: \n  Sorted by(1-5)\n    1. Birth Date     2. Age     3. ODI Rank     4. Test Rank     5. T-20I Rank\n  6. Insert New Player's Profile\n  7. Delete Player's Profile\n  8. Update Player's Profile\n  9. Search Player's Details\n  10. Display\n  11. Exit" << endl;
        cin >> p;
        system("CLS");
        if(p==1) {sort_birth_date(n);
                    cout << "Sorted by Date of Birth" << endl;
                    Display(n);
        }
        else if(p==3) {sort_ODI_rank(n);
                    cout << "Sorted by ODI Rank" << endl;
                    Display(n);
        }
        else if(p==4) {sort_Test_rank(n);
                    cout << "Sorted by Test Rank" << endl;
                    Display(n);
        }
        else if(p==5) {sort_T20I_rank(n);
                    cout << "Sorted by T20I Rank" << endl;
                    Display(n);
        }
        else if(p==2) {sort_age(n);
                    cout << "Sorted by Age" << endl;
                    Display(n);
        }
        else if(p==6) {
                n++;
                string nm,dob;
                int ag,odi,test,t20i;
            cout << "Enter player's details:" << endl << "Player's Name :";
            cin >> nm;
            name[n-1]=nm;
            cout << "Player's Date of Birth: ";
            cin >> dob;
            birth[n-1]=dob;
            cout << "Player's Age: ";
            cin >> ag;
            age[n-1]=ag;
            cout << "Player's ODI Rank: ";
            cin >> odi;
            ODI[n-1]=odi;
            cout << "Player's Test Rank: ";
            cin >> test;
            Test[n-1]=test;
            cout << "Player's T20I Rank: ";
            cin >> t20i;
            T20I[n-1]=t20i;
            Alphabetic_Order(n);
        }
        else if(p==7) {
                cout << "Delete" << endl;
                        int k = Delete(n);
                        if(k==1) n--;
                    }
        else if(p==8) Update(n);
        else if(p==9) Details(n);
        else if(p==10) {cout << "Player's Profile:" << endl;
                        Display(n);
                    }
        else if(p==11) break;
    }
    return 0;
}

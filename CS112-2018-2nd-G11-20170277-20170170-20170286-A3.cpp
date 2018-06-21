// FCI – Programming 1 – 2018 - Assignment 3

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
float load[1000];  //data array
float arr[1000];   //sorted data array
int e = 0;   //number of elements
////////////////main functions
void newfile(){
int y =0;
string  filename;
float data[100]={};

cout << "Enter data or e to end"<<endl;
for (int i=0 ; i<100; i++){
float x = 0;
cin>>x;
if (!cin){
cin.clear();
cin.ignore();

break;
        }
else{
data[i] = x;
y++;
}
}
/////////////


cout << "Enter file name: ";
cin.ignore();
getline(cin, filename);
string a = filename + ".txt";
cout << a << " has been created"<<endl;
ofstream file(a.c_str());
for (int i=0 ; i<y ; i++){
    file <<" "<< data[i];
}
file.close();
}

void loadfile(){

load[1000] = {};
float z;
cout << "Enter file name: "<< endl;
string filename;
cin.ignore();
getline(cin, filename);
string a = filename + ".txt";
ifstream file(a.c_str());
if (!file){
    cout <<a<< " not found"<< endl;
}
else {
while (!file.eof()){
file>>z;
load[e] = z;
e++;

}
cout << "data loaded"<< endl;
}

for (int i=0 ;i<e;i++){
    arr[i]=load[i];
}

for (int i=0;i<e;i++){
   for (int r=i;r<e;r++){
    if (arr[r]<arr[i]){
        swap(arr[r],arr[i]);}
                         }
                    }

file.close();
}

void output(){

////////////////individual functions


for (int i=0 ; i<e ; i++){
    cout <<load[i]<< " ";
}
cout << "\n";
}
////////individual functions
float mean_relstdev(){


    float sum=0,mean=0,sigma=0,stdev=0,rel=0;
    for (int i=0;i<e;i++){
       sum += load[i];
    }
    mean = sum/e;
    for (int i=0;i<e;i++)
    {
    sigma += pow((mean-load[i]),2);
    }
    stdev = sqrt(sigma/(e));

    cout <<"Mean: " << mean<<"\nStandard deviation: "<< stdev<< endl;

    rel = stdev/mean*100;

    return rel;
}

void _6(){


    invalid:
int xlen=0, ylen=0, abslen=0;

float inx[100];
float iny[100];
float xsum = 0, ysum=0, prodsum=0, xsqr=0, ysqr=0, cc=0, o=0;
if(e%2==0){
    xlen=e/2;
    ylen=e/2;
}
else {
    xlen=(e+1)/2;
    ylen=(e+1)/2;
   load[e+1]=0;
}
for (int  i=0;i<xlen;i++){
    inx[i]=load[i];
    iny[i]=load[i+ylen];
}
for (int i = 0 ; i<xlen ; i++){//calculating product summation
    prodsum += inx[i]*iny[i];
}
for (int i=0;i<xlen;i++){  //calculating x sum
    xsum += inx[i];
}
for (int i=0;i<ylen;i++){//calculating y sum
    ysum += iny[i];
}
for (int i=0;i<xlen;i++){
    xsqr += pow(inx[i],2);
}
for (int i=0;i<ylen;i++){
    ysqr += pow(iny[i],2);
}
if (xlen>ylen){
    abslen = ylen;
}
else {
    abslen = xlen;
}
o=((abslen*xsqr-pow(xsum,2))*(abslen*ysqr-pow(ysum,2)));
cc = (abslen*prodsum-xsum*ysum)/sqrt(o);
cout << "Correlation coefficient is "<< cc << endl;
cin.clear();
cin.ignore();
}
void no_7(){

cout << "Sorted data:"<< endl;
for (int b=0;b<e;++b)
{
    cout<<arr[b]<<" ";
}
cout<<endl;
float median=0,median1=0,median2=0;
if (e%2==0)
{
    median1=arr[((e/2)-1)];
    median2=arr[(e/2)];
    median=((median1+median2)/2);
}
else
{
    median=arr[((e-1)/2)];
}
cout<<"the median: "<<median<<endl;
}
void no_8(){



invalid:

int xlen=0, ylen=0, abslen=0;

double inx[100];
double iny[100];
double xsum = 0, ysum=0, r=0, o=0,xpar=0,ypar=0,summation=0 , summation1=0;
if(e%2==0){
    xlen=e/2;
    ylen=e/2;
}
else {
    xlen=(e+1)/2;
    ylen=(e+1)/2;
    load[e+1]=0;
}

for (int i = 0 ; i<(e/2) ; i++)  //calculating sum of x a
{
    xsum += load[i];
}
cout<<"xsum is : "<<xsum<<endl;                          // calculating mean of x
xpar=xsum/(e/2);
cout<<"xpar is : "<<xpar<<endl;
for (int i=0;i<e;i++) //calculating sum of y
{
    ysum += load[e/2+i];
}
//calculating mean of y
cout<<"ysum is : "<<ysum<<endl;
ypar=ysum/(e/2);
cout<<"ypar is : "<<ypar<<endl;
for (int i=0;i<(e/2);++i)
{
    summation += pow(load[i]-xpar,2);
}
cout<<"summation of x minus xpar power 2 : "<<summation<<endl;
for (int i=e/2;i<e;++i){
    summation1 += pow(load[i]-ypar,2);
}
cout<<"summation of y minus ypar power 2 : "<<summation1<<endl;
double sx ,sy,r1,r2,r3,r4;
sx=sqrt(summation/((e/2)-1));
cout<<"sx : "<<sx<<endl;
sy=sqrt(summation1/((e/2)-1));
cout<<"sy : "<<sy<<endl;
for(int i=0;i<xlen;++i)
{
    r1=((load[i]-xpar)/sx);
    r2=((load[i]-ypar)/sy);
    r3+=r1*r2;

}
r4=r3/((e/2)-1);
cout<<"r4 : "<<r4<<endl;
double slope, attitude,equation ;
slope=r4*(sy/sx);
cout<<"The slope is (b)-: "<<slope<<endl;
attitude=ypar-(xpar*slope);
cout<<" The attitude (a)-  : "<<attitude<<endl;
for(int i=0 ; i< ylen ;++i){
equation=attitude+(slope*load[i]);
cout << "The equation equal : "<<equation<<endl;
}}
void no_9(){
int xlen=0, ylen=0, abslen=0;

double inx[100];
double iny[100];
double xsum = 0, ysum=0, r=0, o=0,xpar=0,ypar=0,summation=0 , summation1=0;
if(e%2==0){
    xlen=e/2;
    ylen=e/2;
}
else {
    xlen=(e+1)/2;
    ylen=(e+1)/2;
   load[e+1]=0;
}
for (int i = 0 ; i<(e/2) ; i++)  //calculating sum of x a
{
    xsum += load[i];
}                          // calculating mean of x
xpar=xsum/(e/2);
for (int i=0;i<e;i++) //calculating sum of y
{
    ysum += load[e/2+i];
}
//calculating mean of y
ypar=ysum/(e/2);
for (int i=0;i<(e/2);++i)
{
    summation += pow(load[i]-xpar,2);
}
for (int i=e/2;i<e;++i){
    summation1 += pow(load[((e/2)+i)]-ypar,2);
}
double sx ,sy,r1,r2,r3,r4;
sx=sqrt(summation/((e/2)-1));
sy=sqrt(summation1/((e/2)-1));
for(int i=0;i<e;++i)
{
    r1=((load[i]-xpar)/sx);
    r2=((load[((e/2)+i)]-ypar)/sy);
    r3+=r1*r2;

}
r4=r3/((e/2)-1);
double slope, attitude,equation ;
slope=r4*(sy/sx);
attitude=ypar-(xpar*slope);
for(int i=0 ; i< (e/2) ;++i){
equation=attitude+(slope*load[i]);
double mean_sqaure=0 ,ymean1=0,ymean2;
double y_mean[100];
for(int i=0 ; i< (e/2) ;++i){
equation=attitude+(slope*load[i]);
y_mean[i]=equation;
}
for (int i=0 ;i<e;++i)
{
ymean1=pow((y_mean[i]-load[(e/2)+i]),2);
ymean2+=ymean1;
}
double finish;
finish=ymean2/(e/2);
cout<<"The Finish equal : "<<finish<<endl ;
}}

float quartiles(){

    cout << "Sorted data:"<<endl;
    for (int l=0 ;l<e;l++){
        cout << arr[l]<<" ";
    }
    cout << endl;
       ///////////////
 float q1=0,q2=0,q3=0,IQR=0 ;
if ((e+1)%4==0){
    q1=arr[((e+1)/4)-1];
    q2=arr[((e+1)/2)-1];
    q3=arr[((e+1)*3/4)-1];
}
else if(e%2==0) {
    q1=(arr[(e/4)-1]+arr[(e/4)])/2;
    q2=(arr[(e/2)-1]+arr[(e/2)])/2;
    q3=(arr[(e*3/4)-1]+arr[(e*3/4)])/2;
}
else
{
    int z,v;
    z=(e-1)/4;
    v=(e-1)*3/4;
    q1=(arr[z-1]+arr[z])/2;
    q2=arr[((e+1)/2)-1];
    q3=(arr[v]+arr[v+1])/2;

}
    cout << "Q1: "<<q1<<endl;
    cout << "Q2: "<<q2<< endl;
    cout << "Q3: "<<q3<< endl;
  IQR = q3-q1;
  return IQR;
}

void mode(){
 int modes[100];
 for (int i=0;i<e;i++){
        modes[i]=0;
    for (int r=0;r<e;r++){
        if (load[i]==load[r]){
            modes[i]++;
    }
   }
 }

 int x=modes[0];
 int index=0;
 for (int i=0;i<e;i++){
    if (modes[i]>x){
        x=modes[i];
        index=i;
    }
    else if (modes[i]==x){

        if (load[i]==load[index]){
            continue;
        }
        else {
            modes[i]=0;
            modes[index]=0;
        }
    }
 }
 if (modes[index]==0){
    cout << "No mode"<< endl;
 }
 else {
 cout << "mode: "<< load[index]<< endl;}
}

//////////////menu function

int main()
{
cout << "Welcome"<<endl;
while (true){
        int c=0;
  cout << "\n1-Enter a new data set \n2-Load a data set \n3-Display a data set \n4-Quartiles \n5-Interquartile range \n6-Correlation coefficient\n7-The Median\n8-Linear regression coefficient \n9-Mean square error of linear coefficient  \n10-Mean and standard deviation \n11-Relative standard deviation\n12-Mode"<< endl;

      cin >> c;
switch(c){
case 1:
    newfile();
    break;

case 2:
    loadfile();
    break;

case 3:
    output();
    break;

case 4:
    quartiles();
    break;

case 5:
    cout << "From these values"<< endl;
    cout <<  "\nWe get\nIQR: "<<quartiles()<< endl;
    break;
case 6:
    _6();
    break;

case 7 :
    no_7();
    break;
case 8 :
    no_8();
    break;
case 9:
    no_9();
    break;
case 10:
    mean_relstdev();
    break;

case 11:
    cout << "From these values"<< endl;
    cout << "\nWe get\nRelative standard deviation: "<< mean_relstdev()<<" %" << endl;
    break;

case 12:
    mode();
    break;
}
}    return 0;
}


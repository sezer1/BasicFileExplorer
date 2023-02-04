#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <sstream>
#include <locale>
#include <stdlib.h>

#define LOWER 1024
#define UPPER 65536

using namespace std;


int removeDuplicatedValues(string array[], int size)
{

    int newsize = size;
    string str;
    for(int i = 0; i < size; i++)
    {

        str = array[i];

        for(int j = i + 1; j < newsize; j++)
        {
            if(array[j] == str)
            {

                for(int k = j; k < size - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                newsize--;
            }
        }
    }
    return newsize;
}

int search(string arr[], string s, int n)
{
    int counter = 0;

    for(int j = 0; j < n; j++)

        // Checking if string given in query
        // is present in the given string.
        // If present, increase times
        if (s == arr[j])
            counter++;

   return counter;
}

int arraytimes(string arr[], string q[],int n, int m,int array[])
{

    for(int i = 0; i < m; i++){
        array[i]=search(arr, q[i], n);
    }
}


string convertToString(char* a, int size)
{
    int i;
    int si;
    string s[100];
    for (i = 0;i<200;i++) {
    for(si=0;si<200;si++){
                 s[i] = s[i] + a[si];
    }
return s[i];
    }


}





int getdir(string f, vector<string> &files)
{
 DIR *d;
 struct dirent *direction;
 d= opendir(f.c_str());

direction=readdir(d);

while ( direction!=NULL)
{
   files.push_back(string(direction->d_name));

 /* cout << direction->d_ino << endl; */
   direction=readdir(d);

}

closedir(d);

return 0;
}

void getdirb(string f, vector<string> &files)
{
 DIR *b;
 struct  dirent *direction;

 b= opendir(f.c_str());

direction=readdir(b);
while ( direction!=NULL){
files.push_back(string(direction->d_name));
direction= readdir(b);
 /* cout << direction->d_ino << endl; */
}
closedir(b);

}

void getdird(string f, vector<string> &files)
{
 DIR *de;
 struct  dirent *direction;
de=opendir(f.c_str());
direction=readdir(de);
while ( direction!=NULL)
{
   files.push_back(string(direction->d_name));
   direction=readdir(de);
 /* cout << direction->d_ino << endl; */
}
closedir(de);
}

void getdiro(string f, vector<string> &files)
{
 DIR *o;
 struct  dirent *direction;
o = opendir(f.c_str());

direction=readdir(o);
    while ( direction!=NULL)
{
   files.push_back(string(direction->d_name));
   direction=readdir(o);
 /* cout << direction->d_ino << endl; */
}
closedir(o);

}

int main()
{


     setlocale(LC_ALL,"Turkish");
fstream new_file;

vector<string> data =  vector <string>();
vector<string> files=  vector<string>();
vector<string> files1= vector<string>();
vector<string> files2= vector<string>();
vector<string> files3= vector<string>();
string f = string("C:\\Users\\Sezer\\Desktop\\arge\\universite");
string b = string("C:\\Users\\Sezer\\Desktop\\arge\\universite\\Bölümler");
string d = string("C:\\Users\Sezer\\Desktop\\arge\\universite\\Dersler");
string o = string("C:\\Users\\Sezer\\Desktop\\arge\\universite\\Öğretim Elemanları");
string datas;

getdir(f,files);
getdirb(b,files1);
getdird(d,files2);
getdiro(o,files3);



char dataf[1000][1000];

FILE *file;


string concat= "\\";
  string k=f;
  string cc = k+concat;
  string sez;
  string a;
  int line=0;

for (unsigned int i = 0;i<files.size();i++)
{
   if(files[i]=="Bölümler"){
        k=b;
        cc = k+concat;
   for(unsigned int j=2; j<files1.size();j++){

    sez=files1[j];
      a=cc+sez;

    file = fopen(a.c_str(),"r");

 if (file==NULL){
    printf("error opening file");
 }
    while (!feof(file)&& !ferror(file)){
    if(fgets(dataf[line],1000,file)!= NULL)
    line++;

  }

   fclose(file);
   }

   }

   if(files[i]=="Dersler"){
      k=d;
      cc = k+concat;
      for(unsigned int t=3; t<files2.size();t++){
             sez=files2[t];
             a=cc+sez;

    file = fopen(a.c_str(),"r");
 if (file==NULL){
    printf("error opening file");
 }

    while (!feof(file)&& !ferror(file)){
    if(fgets(dataf[line],1000,file)!= NULL)
    line++;
  }


   }
    fclose(file);
   }

   if(files[i]=="Öğretim Elemanları"){
     k=o;
     cc = k+concat;

      for(unsigned int g=3; g<files3.size();g++){

          sez=files3[g];

          a  =cc+sez;

    file = fopen(a.c_str(),"r");
 if (file==NULL){
    printf("error opening file");
 }


    while (!feof(file)&& !ferror(file)){
    if(fgets(dataf[line],10000,file)!= NULL)
    line++;
  }

 fclose(file);

   }

   }


}

FILE *file1;
char datab[200][200];

 //char key[] = {keyo.c_str()};

string stringgathering;
 char *pch;
 char *pch1;
int databl=0;
 for(int satir=0; satir<line;satir++){

 pch  = strchr(dataf[satir],'[');

 pch1 = strchr(dataf[satir],']');

 while(pch != NULL && pch1!=NULL){
//for(int satiric=0; dataf[satir][satiric]<1000;satiric++){
  int b;
  int a=0;
  int fark=0;
 // printf("\nfound at %d\n",pch-dataf[satir]+1);

 if(dataf[satir][pch-dataf[satir]+1]!='[')
 break;

 while(dataf[satir][pch-dataf[satir]+a]!=dataf[satir][pch1-dataf[satir]-2]){

    a++;
 //   printf("%c",dataf[satir][pch-dataf[satir]+a-1]);
     datab[databl][a-1]=dataf[satir][pch-dataf[satir]+2+a-1];

 }
databl++;
 if(dataf[satir][pch-dataf[satir]]=='[')
 pch= pch+1;
 pch1= pch1+1;

pch=strchr(pch+1,'[');
pch1=strchr(pch1+1,']');
 }
 }



int ayni=0;
char datauniq[200][200];
int databsize=200;
int newsize;
string uniquedata[200];
string uniquedata1[200];
string yetim[200];
string istenen[200];
string txtformat[200];

int a_size;
newsize=databsize;


for(int satir=0;satir<200;satir++){
   a_size = sizeof(datab[satir]) / sizeof(char);
 uniquedata[satir]=convertToString(datab[satir],a_size);
}



int length = removeDuplicatedValues(uniquedata, 200);

for(int yet=0;yet<length;yet++){
    uniquedata1[yet]=uniquedata[yet];
}

    int n = sizeof(uniquedata) / sizeof(uniquedata[0]);
    int m = sizeof(uniquedata1) / sizeof(uniquedata1[0]);


int arraytimesmain[200];
arraytimes(uniquedata, uniquedata1, n, m,arraytimesmain);

for(int i=0;i<200;i++){
    cout<<uniquedata1[i]<<endl;
}



   return 0;
}

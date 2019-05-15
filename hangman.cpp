#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstdio>
#include <ctime>
#define N 50000
using namespace std;
int global = 0;
struct fileinfo
{
	string data;
	 int length;
	 int valid;
};
struct node
{
    char character;
    int num;
    node* nex;
};
class linkedletter
{
private:
    node *star,*endhead;
public:
    linkedletter()
    {
        star = NULL;
        endhead = NULL;
    }
    ~linkedletter(){
        delete star;
        delete endhead;
    }
    int binary(int mat[][3],int l,int u,int key){
        int mid;
        while(l<=u){
            mid = l+((u-l)/2);
            if(mat[mid][0]==key)
                return mid;
            else if(key<mat[mid][0])
                u = mid-1;
            else
                l = mid+1;
        }
    }
      void countwords(fileinfo arrays[],int matrix[][3],int matlen,int random[]){
        int f=0,l=0;
        static int bigar[N][27]={0};
        for(int i=0;i<N;i++){
            for(int j=0;j<arrays[i].length;j++){
                char cc = (arrays[i].data).at(j);
                int x = int(cc);
                (bigar[i][x-97])++;
            }
        }
        /*for(int i=0;i<N;i++){
            for(int j=0;j<26;j++)
                cout << bigar[i][j] << " ";
            cout << endl;
        }*/
        for(int i=0;i<N;i++)
        {
            star = NULL;
            endhead = NULL;
            int c = random[i];
            int ll = arrays[c].length;
            int n = binary(matrix,0,matlen,ll);
            for(int k=matrix[n][1];k<=matrix[n][2];k++)
                arrays[k].valid=1;
            l=0;
            while(l<26){
                int sum=0;
                for(int k=matrix[n][1];k<=matrix[n][2];k++)
                    sum = sum+bigar[k][l];
                if(sum!=0){
                    node *tem = new node;
                    char ch = (char)(l+97);
                    tem->character = ch;
                    tem->num = sum;
                     tem->nex = NULL;
                    if(star == NULL){
                        endhead = tem;
                        star = tem;
                        tem = NULL;
                    }
                    else{
                        endhead->nex = tem;
                        endhead = tem;
                        tem = NULL;
                    }
                }
                l++;
            }
       star = sorttt();
    node* cha = NULL;
    cha = star;
    while(cha!=NULL){
        cout << cha->character << " ";
        cout << cha->num << endl;
        cha = cha->nex;
    }
    cout << endl;
        guesser(ll,arrays[c].data,arrays,matrix[n][1],matrix[n][2],star);
    }
    }
     node* sorttt(){
        node *tempp = NULL;
        node *maxx = NULL;
        node *alpha = NULL;
        tempp = star;
        while(tempp!=NULL){
            maxx = NULL;
            alpha = NULL;
            maxx = tempp;
            alpha = tempp->nex;
            while(alpha!=NULL){
                if(maxx->num < alpha->num)
                    maxx = alpha;
                alpha = alpha->nex;
            }
            int x = tempp->num;
            char cc = tempp->character;
            char chh = maxx->character;
            int x2 = maxx->num;
            tempp->character =  chh;
            tempp->num = x2;
            maxx->character = cc;
            maxx->num = x;
            tempp = tempp->nex;
        }
        return star;
    }
     void deletelinkedletter(fileinfo arrays[],int l,int u,char ch,int ii){
        for(int i=l;i<=u;i++){
            if((arrays[i].valid==1) && (arrays[i].data).at(ii)!=ch)
                arrays[i].valid = 0;
        }
    }
    void deleteifmissed(fileinfo arrays[],int l,int u,char ch,int ln){
         for(int i=l;i<=u;i++){
            if(arrays[i].valid==1){
            for(int j=0;j<ln;j++){
                if((arrays[i].data).at(j)==ch){
                    arrays[i].valid = 0;
                    break;
                }
            }
         }
    }
    }
    void printarray(char arr[],int ln,int jj){
        for(int i=0;i<ln;i++)
            cout << arr[i] << " ";
        cout << jj <<endl;
    }
     void checker(char arr[],int ll,string wrd,char cc,int *jj,fileinfo arrays[],int l, int u,int *kk){
        int f=0;
        for(int i=0;i<ll;i++){
            if(cc==wrd[i]){
                arr[i] = cc;
                (*kk)++;
                deletelinkedletter(arrays,l,u,cc,i);
                f=1;
            }
        }
        if(f==0){
            (*jj)++;
            deleteifmissed(arrays,l,u,cc,ll);
        }
    }
    int checkingletter(char cc, fileinfo arrays[],int ll,int l,int u){
        int f=0;
        for(int k=l;k<=u;k++){
            if(arrays[k].valid==1){
                for(int i=0;i<ll;i++){
                    if((arrays[k].data).at(i)==cc){
                        f=1;
                        break;
                    }
                }
            }
            if(f==1)
                break;
        }
        return f;
    }
    void guesser(int ln,string word,fileinfo arrays[],int l,int u,node* sta){
        char a[ln];
        for(int i=0;i<ln;i++)
            a[i]='_';
        int j=0,k=0,f=0,flag=0,fl=0;
         printarray(a,ln,j);
        while(sta!=NULL && j<6){
                flag = 0;
           char ch = sta->character;
           if(fl==1)
                flag = checkingletter(ch,arrays,ln,l,u);
           if(flag==1 || fl==0){
                fl=1;
                checker(a,ln,word,ch,&j,arrays,l,u,&k);
                printarray(a,ln,j);
            }
           node* temp = NULL;
           temp = star;
           sta = sta->nex;
           free(temp);
           if(k==ln){
                f=1;
                break;
           }
        }
        if(f==1)
        {
            global++;
        }
        delete[] a;
}
};
void swapp(fileinfo a[],int l,int u){
    int t;
    string str;
    t=a[l].length;
    str=a[l].data;
    a[l].length=a[u].length;
    a[l].data=a[u].data;
    a[u].length=t;
    a[u].data=str;
}
int partitionn(fileinfo a[],int l,int u){
    int pivot = a[u].length;
    int i = l-1;
    for(int j=l;j<u;j++){
        if(a[j].length<=pivot){
            i++;
            swapp(a,i,j);
        }
    }
    swapp(a,i+1,u);
    return (i+1);
}
void sortt(fileinfo a[],int ll,int ul){
   int p=0;
   if(ll<ul){
        p = partitionn(a,ll,ul);
        sortt(a,ll,p-1);
        sortt(a,p+1,ul);
   }
}
void movee(fileinfo a[]){
    int i=0,x,f=0,j,arrayy[N];
    srand(time(0));
    x = rand()%N;
    int p=x-1;
    int q=x+1;
    arrayy[0]=x;
    i++;
    while(i<N){
        if(p>=0){
            arrayy[i]=p;
            i++;
            p--;
        }
        if(q<N){
            arrayy[i]=q;
            i++;
            q++;
        }
    }
    int mat[30][3],k=0;
    i=0;
    while(k<N){
        j=0;
        mat[i][j++]=a[k].length;
        mat[i][j++]=k;
        k++;
        while(k<N){
            if(a[k].length!=a[k-1].length)
                break;
            k++;
        }
        mat[i][j++]=k-1;
        i++;
    }
    for(int l=0;l<i;l++){
        for(int j=0;j<3;j++)
            cout << mat[l][j] << " ";
        cout << endl;
    }
    linkedletter b;
    b.countwords(a,mat,i-1,arrayy);
}
int main(){
	int len=0,i=0,counter=N;
	fileinfo arrays[N];
    ifstream thee("Document.txt");
    thee.seekg(0,ios::beg);
    string word;
    while(counter)
    {
        thee >> word;
        arrays[i].data = word;
        arrays[i].length = word.length();
        arrays[i].valid = 1;
        i++;
        counter--;
    }
     sortt(arrays,0,N-1);
     for(int i=0;i<N;i++){
        cout << arrays[i].data << endl;
        cout << arrays[i].length <<endl;
        cout << arrays[i].valid << endl;
     }
     movee(arrays);
    cout<<global<<endl;
    double per = (double)(global*100)/N;
    cout << per << endl;
	return 0;
}

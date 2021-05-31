#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

int SelectTheIntervalPoint(int l, int r){
     return l + (r-l) / 2;
}
  
void Swap(double *table, int i1, int i2){
    if (i1!=i2){
    	double aux = table[i1];
     	table[i1] = table[i2];
     	table[i2] = aux;
	}
}

int SplitArray(double *table, int l, int r){
     int splitindex = SelectTheIntervalPoint(l, r);
     double splitvalue = table[splitindex];
     Swap(table, splitindex, r);

     int currentposition = l;
     for(int i=l;i<=r-1;i++){
        if(table[i] < splitvalue){
             Swap(table, i, currentposition);
             currentposition++;
     	}
 	}
     Swap(table, currentposition, r);
     return currentposition;
}

void Quicksort(double *table, int l, int r){
    if(l < r){
        int i = SplitArray(table, l, r);
        Quicksort(table, l, i-1);
        Quicksort(table, i+1, r);
	}
}
  
int main(){
	SetConsoleTitleA("Quicksort");
	//int option;
	cout<<"Quicksort"<<endl/*<<"0 - result"<<endl<<"1 - sorting"<<endl<<"Enter the number: "*/;
	//cin>>option;
	for(;;){	
		int sizet;
		double* numbers;	
		cout<<"Enter count of items: ";
		cin>>sizet;
		numbers=new double[sizet];
		cout<<"Enter items:"<<endl;
		for(int i=0;i<sizet;i++) cin>>numbers[i];
		cout<<"Table\t\t";
		for(int i=0;i<sizet;i++) cout<<numbers[i]<<" ";
		cout<<"\t"<<endl;
		
		//sorting
		Quicksort(numbers,0,sizet-1);
		//end
		cout<<"Ordered table: "<<endl;
		for(int i=0;i<sizet;i++) cout<<numbers[i]<<" ";
		
		delete[] numbers;
		getch();
		system("cls");
	}
	return 0;
}

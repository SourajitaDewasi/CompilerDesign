//This code is contributed by Sourajita Dewasi
#include <iostream>
#include <string>
#define size 10
using namespace std;

int main() {
	char variable, alpha, beta;
	char prod[10][size];
	int index=3, n=0;
	cout<<" Removal of Left Recursion";
/*In case of indirect left recursions, this code will be able to run only for two lines of
    productions and single production for the non-parent production. Also, don’t use E as terminal. It is used as epsilon here.*/

	cout<<"\n Enter the number of productions";
	cin>>n;
	cout<<"\n Enter the grammar";
	for(int i=0; i<n; i++){
	    cin>>prod[i];
	}

	if(prod[0][0]==prod[1][index]&&prod[0][index]==prod[1][0]){
	    cout<<"\n It is an delayed left recursion";
	    char prodt[12]; int j=index;
	    //cout<<"\n New Grammar will be "<<prod[0][0]<<"->";
	    for(int i=index; prod[1][i]!='\0'; i++){
	        prodt[j]=prod[1][i]; 
	        //cout<<prodt[j];
	        j++;
	        //cout<<prod[1][i];
	    }
	    for(int i=index+1; prod[0][i]!='\0'; i++){
	        prodt[j]=prod[0][i];
	        //cout<<prodt[j];
	        j++;
	        //cout<<prod[0][i];
	    }prodt[j]='\0';
	    
	    prodt[0]=prod[0][0]; prodt[1]='-'; prodt[2]='>';
	    cout<<"\n New Grammar will be ";int c=0;
	    for(int i=0; prodt[i]!='\0';i++){
	        cout<<prodt[i];c++;
	        prod[0][i]=prodt[i]; 
	    }prod[0][c]='\0';
	    n--;
	}
    
    
	cout<<"\n Removal of Left Recursion";
	for(int i=0; i<n; i++){

	    cout<<"\n\n Grammar: "<<prod[i];
	    variable=prod[i][0];
	    if(variable==prod[i][index]){  
            alpha=prod[i][index+1];
            cout<<" has left recursion";
            while(prod[i][index]!=0 && prod[i][index]!='|'){
                index++;
            }
            if(prod[i][index]!=0){
                beta=prod[i][index+1];
                cout<<"\n Without left recursion:";
                cout<<"\n "<<variable<<"->"<<beta<<variable<<"'";
                cout<<"\n "<<variable<<"'->"<<alpha<<variable<<"'|E";
            }
            else{
                cout<<"\n Grammar can't be reduced by left factoring";
            }
	    }
	    else{
	        cout<<"\n Given Grammar is not left recursive ";
	    }
	    index=3;

    }
	return 0;
}

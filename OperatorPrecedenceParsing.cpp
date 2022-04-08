#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int vars=0, terms=0, temp=0, c=0;
char var[10];
char term[10];
char lead[10][10], trail[10][10];
char opp[10][10];
struct grammar{
int production_number;
char lhs;
char rhs[10][10];
int at[10][10];
}G[10];
void get_prod(){
cout<<" Display Leading and Trailing Terms";
cout<<"\n Enter number of variables "; cin>>vars;
cout<<"\n Enter the variables:";
for(int i=0; i<vars; i++){
cin>>G[i].lhs;
var[i]=G[i].lhs;
}
cout<<"\n Enter the number of terminals: "; cin>> terms;
cout<<"\n Enter the terminals:";
for(int i=0; i<terms; i++){
cin>>term[i];
}
cout<<"\n Production Details";
for(int i=0; i<vars; i++){
cout<<"\n Enter number of production of: "<<G[i].lhs;
cin>>G[i].production_number;
for(int j=0; j<G[i].production_number; j++){
cout<<G[i].lhs<<"->";
cin>>G[i].rhs[j];
}
}
}
void leading_nt(){
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int k=0; k<terms; k++){
if(G[i].rhs[j][0]==term[k]){
lead[i][k]=1;
}
else{
if(G[i].rhs[j][1]==term[k]){
lead[i][k]=1;
}
}
}
}
}
for(int l=0; l<vars; l++){
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int m=1; m<vars; m++){
if(G[i].rhs[j][0]==var[m]){
temp=m;
goto out;
}
}
out:
for(int k=0; k<terms; k++){
if(lead[temp][k]==1){
lead[i][k]=1;
}
}
}
}
}
}
void trailing_nt(){
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
c=0;
while(G[i].rhs[j][c]!='\0'){
c++;
}
for(int k=0; k<terms; k++){
if(G[i].rhs[j][c-1]==term[k]){
trail[i][k]=1;
}
else{
if(G[i].rhs[j][c-2]==term[k]){
trail[i][k]=1;
}
}
}
}
}
for(int l=0; l<vars; l++){
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
c=0;
while(G[i].rhs[j][c]!='\0'){
c++;
}
for(int m=1; m<vars; m++){
if(G[i].rhs[j][c-1]==var[m]){
temp=m;
}
}
for(int k=0; k<terms; k++){
if(trail[temp][k]==1){
trail[i][k]=1;
}
}
}
}
}
}
int main()
{
get_prod();
leading_nt();
trailing_nt();
char l[10];
int row=terms+1;
char arr[row];
for(int i=0; i<vars; i++){
cout<<"\n Leading Non Terminal of "<<G[i].lhs<<": ";
for(int j=0, k=0; j<terms; j++){
if(lead[i][j]==1){
cout<<term[j];
l[k]=term[j]; k++;
}
}
}
char t[10];
for(int i=0; i<vars; i++){
cout<<"\n Trailing Non Terminal of "<<G[i].lhs<<": ";
for(int j=0, k=0; j<terms; j++){
if(trail[i][j]==1){
cout<<term[j];
t[k]=term[j]; k++;
}
}
}
cout<<"\n Operator Table \n";
for(int i=0; i<terms; i++){
arr[i]=term[i];
}
arr[row-1]='$';
cout<<" ";
for(int i=0; i<row; i++){
cout<<" \t"<<arr[i]<<"\t";
}
for(int i=0; i<row; i++){
for(int j=0; j<row; j++){
if(l[i]==arr[j]){
opp[row-1][i]='<';
//cout<<"\t"<<opp[row+1][i]<<"\t"; //for leading symbols
}
if(t[i]==arr[j]){
opp[i][row-1]='>';
}
}
}
//Assigning 1 to terminals in production and -2 to variables in production
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int k=0; k<terms; k++){
for(int m=0; G[i].rhs[j][m]!='\0'; m++){
if(G[i].rhs[j][m]==term[k]){
G[i].at[j][m]=k+1;
}
else{
if(G[i].at[j][m]<0)
G[i].at[j][m]=-2;
}
}
}
/*for(int m=0; G[i].rhs[j][m]!='\0'; m++){
cout<<"\n"<<G[i].rhs[j][m]<<" "<<G[i].at[j][m];
}*/
}
}
int x1,x2,x3=-1;
for(int i=0; i<row-2; i++){
for(int j=0; j<row-2; j++){
opp[i][j]='-';
}
}
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int k=0; G[i].rhs[j][k]!='\0'; k++){
x1=G[i].at[j][k];
x2=G[i].at[j][k+1];
if(G[i].at[j][k+2] != '\0')
x3=G[i].at[j][k+2];
//Assigning ‘=’ symbol in case there is two consecutive terminals
for(int m=0; m<terms; m++){
for(int n=0; n<terms; n++){
if(x1>0 && x2>0 && m==(x1-1) && n==(x2-1) && opp[m][n]=='-'){
opp[m][n]='=';
break;
}
}
}
}
}
}
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int k=0; G[i].rhs[j][k]!='\0'; k++){
x1=G[i].at[j][k];
x2=G[i].at[j][k+1];
if(G[i].at[j][k+2] != '\0')
x3=G[i].at[j][k+2];
//Assigning ‘=’ symbol in case there is two consecutive terminals with a non-terminal in between
for(int m=0; m<terms; m++){
for(int n=0; n<terms; n++){
if(x1>0 && x2==0 && x3>0 && m==(x1-1) && n==(x2-1) && opp[m][n]=='-'){
opp[m][n]='=';
//opp[n][m]='-';
break;
}
//For left-associativity
if(term[m]=='+'&& term[n]=='*'){
opp[m][n]='>';
}
if(term[m]=='*'&& term[n]=='+'){
opp[m][n]='<';
}
}
}
}
}
}
for(int i=0; i<vars; i++){
for(int j=0; j<G[i].production_number; j++){
for(int k=0; G[i].rhs[j][k]!='\0'; k++){
x1=G[i].at[j][k];
x2=G[i].at[j][k+1];
if(G[i].at[j][k+2] != '\0')
x3=G[i].at[j][k+2];
//Assigning ‘<’ to leading symbols next to given terminal and ‘<’ to leading symbols next to given terminal
if(x1>0 && x2==0){
for(int m=0; m<terms; m++){
for(int n=0; n<terms; n++){
if(l[m]==arr[n] && m==(x1-1) && opp[m][n]=='-'){
opp[x1-1][n]='<';
}
if(l[m]==arr[n] && m==(x1-1) && opp[m][n]=='-'){
opp[n][x1-1]='>';
//break;
}/*
else{
if(opp[m][n]!='>'||opp[m][n]!='<')
opp[m][n]='-';
}*/
}
}
}
if(x1==0 && x2>0){
for(int m=0; m<terms; m++){
for(int n=0; n<terms; n++){
if(t[m]==arr[n] && n==(x2-1) && opp[m][n]=='-'){
opp[m][x2-1]='>';
}
if(t[m]==arr[n] && n==(x2-1) && opp[m][n]=='-'){
opp[x2-1][m]='<';
//break;
}
}
}
}
}
}
}
for(int i=0; i<row; i++){
for(int j=0; j<row; j++){
for(int k=0; k<terms; k++){
if((arr[k]=='i'&& arr[i]=='i' && arr[j]!='i')){
opp[i][j]='>';
}
if((arr[k]=='i'&&arr[j]=='i' && arr[i]!='i')&&(arr[k]=='i'&&arr[j]=='i' && arr[i]!='(')){
opp[i][j]='<';
}
}
}
}
for(int i=0; i<row; i++){
cout<<"\n"<<arr[i];
for(int j=0; j<row; j++){
cout<<"\t"<<opp[i][j]<<"\t";
}
}
return 0;
}

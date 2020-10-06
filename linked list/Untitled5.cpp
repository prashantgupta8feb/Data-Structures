 #include <iostream>
using namespace std;
int main(){
   int i = 0;
   cout << "Loop get started";
   while(2){
      cout << "\nThe value of i: "<<i<<"\n";
      i++;
      if(i == 10){ //when i is 10, then come out from loop
         break;
      }
   }
   cout << "\nLoop get ended" ;
}


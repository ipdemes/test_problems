

#include <bits/stdc++.h>

using namespace std;
#if 0
bool is_match (string A, string B){

  size_t lengthA = A.length();
  size_t lengthB =B.length();
  size_t j=0; //B counter
 

  //**check if both are empty:
  if (A.length() == B.length() && A.length() ==0)
		return true;

  //if A i empty, B has '*'
  if (A.length() ==0 && B.length() ==1 && B[0]=='*')
    return true;

  //A is empty and B is not empty and has more than 1 element
  if (A.length() ==0 && B.length () >1  )
    return false;

  //if A i empty, B[0] doesn't have '*'
  if (A.length() ==0 && B.length() ==1 && B[0]!='*')
    return false; 

  //iterate over all elements in the string
  for (size_t i=0; i<lengthA; i++){

    //* if we exceed size of the B
    if (j>=lengthB) return false;

    //if A==B
    if (A[i] == B[j]){
      //this is the last element
      if (i==lengthA-1) return true;
      else { j++; continue;}
    }    

    //if B='*"
    if(B[j]=='*'){
       //*find the next B element that is not *
			 while (j<(lengthB-1)&&(B[j]=='*')){
         j++;
       }

       //if this is the last element in B and it is '*' we can return true
       if (j==(lengthB-1)&& B[j]=='*') return true;

       //the next non '*' element in B is the same as the one in A 
       //( * corresponds to empty char )
    
       if (B[j]==A[i]){
         j++;
         continue;
       }
       else {
         //look at the next B element
         char b= B[j];
         while ((i<lengthA) && (A[i]!=b)){
           i++;
         }
         //after while
         //we found the match
         if ((i<(lengthA-1)) && A[i]==b) {j++; continue;}
         //this is the last element n A
         if (i==(lengthA-1) && A[i]==b){return true;}
         //no match found
         if (i>=lengthA) return false;
      }//if
    }
  }//for
}

#else

 
vector<vector<int>> match;

 bool is_match (string &A, string &B, int lengthA, int lengthB){
   //if  lengthA==0 && lengthB==0
   if (lengthA<0&&lengthB<0) return true;

   if(lengthB<0) return false;

   if (lengthA<0){
      int i =lengthB;
      while (i>0){
        if (B[i]!='*') return false;
        i--;
      }
      return true;
   }

   //check if we already visited this match 
   if (match[lengthA][lengthB]==-1){
#if 1
      //if A and B has the same value
      if (A[lengthA]==B[lengthB])
				return match[lengthA][lengthB]=
					is_match(A, B, lengthA-1, lengthB-1);     
      
      if (A[lengthA]!=B[lengthB] && B[lengthB]!='*')
					return match[lengthA][lengthB]=false;

      if (A[lengthA]!=B[lengthB] && B[lengthB]=='*')
          return match[lengthA][lengthB]= is_match(A, B, lengthA-1, lengthB)||
            is_match(A, B, lengthA, lengthB-1);
#else
      if (B[lengthB]=='*')
        return match[lengthA][lengthB]= is_match(A, B, lengthA-1, lengthB)||
            is_match(A, B, lengthA, lengthB-1);

       if (A[lengthA]!=B[lengthB]) return  match[lengthA][lengthB]=false;
       else
          return match[lengthA][lengthB]= is_match(A, B, lengthA-1, lengthB)||
            is_match(A, B, lengthA, lengthB-1);
#endif      
   }

   //if it was visited already
   return match[lengthA][lengthB];   
 }

 bool is_match (string A, string B){
  size_t lengthA = A.length();
  size_t lengthB =B.length();

  match.clear();
     
  match.resize (lengthA+1);
  for (size_t i=0; i<= lengthA; i++){
    match[i].resize(lengthB+1);
    for (size_t j=0; j<=lengthB; j++)
      match[i][j]=-1;
  }

  std::cout <<match[lengthA-1][lengthB-1]<<endl;

  return match[lengthA][lengthB]=is_match(A, B, lengthA-1, lengthB-1); 

 }

#endif

int main()
{
    string str = "abradacabra";
    string pattern = "ab*cd*abra";
    //string pattern = "*****ba*****ab";
    //string  pattern = "ba*****ab";
    //string pattern = "ba*ab";
    //string pattern = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";
 
    if ( is_match(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}

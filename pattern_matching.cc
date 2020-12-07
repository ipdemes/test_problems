

#include <bits/stdc++.h>

using namespace std;
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
       //if this is the last element in B and it is '*' we can return true
       if (j==(lengthB-1)) return true;

       //the next element in B is the same as the one in A ( * corresponds to em[ty char
       if (B[j+1]==A[i]){
         j=j+2;
         continue;
       }
       else {
         //look at the next B element
         j++;
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

  //we should never come here
  return false;
}

int main()
{
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
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

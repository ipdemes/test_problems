#include <iostream>
#include <fstream>
#include <cstring> // for std::strlen
#include <cstddef>  // for std::size_t -> is a typedef on an unsinged int
#include <climits>
#include <vector>

template <typename T>
T swap( T u){
  static_assert (CHAR_BIT==8, " CHAR BIT not equalt to 8");

 union
 {
   T u;
   unsigned char u8[sizeof(T)];
 } src, dst;

  src.u = u;
  size_t size = sizeof(T);

  for (size_t i = 0; i < size; i++)
    dst.u8[i] = src.u8[size -1 -i];
 
  return dst.u;

}

using namespace std;



int main ()
{


  string filename = "input";
  ifstream file;
	size_t size = 0; 

#if 0
  //swap all bytes in the file:
	file.open( "test.txt", ios::in|ios::binary );
	char* data = 0;

  file.seekg(0, ios::end); // set the pointer to the end
  size = file.tellg();
  file.seekg(0, ios::beg);
  data = new char[ size+1];

  file.read( data, size );
  data[size]='\0';

  for (size_t i=0; i<=size/2; i++)
  {

    char tmp = data[size-i-1];
    data[size-i-1]=data[i];
    data[i]=tmp;
  }

  file.close();

#else
    //swap bytes for each entry in a file
    file.open( "test.txt", ios::in);
    vector<int> data;

    int tmp;
    while (file >>tmp){
      int tmp_s =swap<int>(tmp);
      data.push_back(tmp_s);
    }

    file.close();

#endif

  return 1;
}

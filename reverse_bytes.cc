#include <iostream>
#include <fstream>
#include <cstring> // for std::strlen
#include <cstddef>  // for std::size_t -> is a typedef on an unsinged int

using namespace std;
int main ()
{
  string filename = "input";
  ifstream file;
	size_t size = 0; 

	file.open( "test.txt", ios::in|ios::binary );
	char* data = 0;

  file.seekg(0, ios::end); // set the pointer to the end
  size = file.tellg();
  file.seekg(0, ios::beg);
  data = new char[ size+1];

  file.read( data, size );
  data[size]='/0';

cout << "size = " <<size<<std::endl;

  for (size_t i=0; i<size/2; i++)
  {

std::cout <<" i = " << i << "last = "<< size-i-1<<std::endl;
std::cout <<  data[i] <<" , " <<data[size-i-1]<<std::endl;
    char tmp = data[size-i-1];
    data[size-i-1]=data[i];
    data[i]=tmp;
  }

  file.close();

  return 1;
}

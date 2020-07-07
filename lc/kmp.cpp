#include <iostream>
#include <vector>
using namespace std;

vector<int> GetPSVect(const char* sub) {
	size_t curMax = 0;
	for ( size_t i = 1, j = 0; i < strlen( sub ); i++, j++ ) 
	{
		if (sub[i]==sub[j])
		{
			
			j = j + 1 == i ? j : j + 1;
		} else {
			j = 0;
		}
	}
}

vector<int> FindIndex( const char * str, const char * sub) {
	

}
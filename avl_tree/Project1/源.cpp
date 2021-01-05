#include<iostream>
#include<algorithm>
using namespace std;
class note 
{
public:
	int _height(note*it)
	{		
		int left_h;
		int right_h;
		if ( it == NULL)
		{
			return height;
		}
		else 
		{
			++height;
			left_h = _height(it->left);
			right_h = _height(it->right);
			return left_h > right_h ? left_h : right_h;
		}
		
	}
	int _val;
	note* left;
	note* right;
	note(int val) :_val(val){}
	int height = 0;
private:

};
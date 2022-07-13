#include <iostream>					//����������� ����������
#include <string>					//���������� ��� �����
#include <vector>					//���������� ��� ������������ ��������
#include <algorithm>
#include <random>

/*
	����������� ������������ � �����������
	��������� == < =

*/

class Beast {
public:
	Beast():Beast(0,"", false, 0.0){}
	Beast(int id,
	std::string name,
	bool solidity,
	double weight) 
		:id(id),
		name(name),
		solidity(solidity),
		weight(weight) {}

	int id;
	std::string name;
	bool solidity;
	double weight;
};


int main() {
	setlocale(LC_ALL, "Russian");
	using namespace std;

	vector<Beast> circus;
	circus.reserve(10);
	for (size_t i = 0; i < circus.capacity(); i++)
	{
		circus.emplace_back(i+8, "kitten", false, 7.2);
	}
	for_each(circus.begin(), circus.end(), [](Beast& arg) {		//���� � �� ��, �� ��� �����, � ����� ���������������.
		cout << arg.id << ' ' << arg.name << ' ' << arg.solidity << ' ' << arg.weight << endl;
		}
	);	
	shuffle(circus.begin()+1, circus.end()-1, random_device());
	
	//for (auto&& a : circus) {
	//	cout << a << endl;				//���� � �� ��
	//}
	auto res = find_if(
		circus.begin(),
		circus.end(),
		[](const Beast & arg)->bool{
			if (arg.id == 15) {
				return true;
			}
			return false;
		});
	
	if (res == circus.end()) {
		cout << "We finde nothing!";
	}
	else{
		cout << "We find on thet place: " << res._Ptr << endl;
	}

	return 0;
}
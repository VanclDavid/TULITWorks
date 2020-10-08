#include <string>
#include <vector>

using namespace std;

class User
{
public:
	User(vector<string> data) {
		if (data.size() < 7) {
			delete this;
		}

		this->position = stoi(data[0]);
		this->name = data[1];
		this->surname = data[2];
		this->gender = data[3];
		this->country = data[4];
		this->age = stoi(data[5]);
		this->date = data[6];
		this->id = stoi(data[7]);
	}

private:
	int id;
	int position;
	int age;
	string name;
	string surname;
	string gender;
	string country;
	string date;
	
};


#pragma once
#include <string>
#include <list>


class FormPrvek
{
private:
	int id = NULL;
	std::string val;
	std::string html;
public:
	virtual std::string getHtml() = 0;
};

class Form
{

private:
	std::list<FormPrvek*> list_formprvek;
	int pocet = 0;
public:
	void renderHtml();
	void addFormPrvek(FormPrvek* fp);
};



class Input : public FormPrvek {
private:
	std::string html = "<input></input>";
public:
	std::string getHtml() override;
};

class PasswordTag : public FormPrvek {
private:
	std::string html = "<password></password>";
public:
	std::string getHtml() override;
};

class ChceckBox : public FormPrvek {
private:
	std::string html = "<checkbox></checkbox>";
public:
	std::string getHtml() override;
};

//doimplementovat
class User {

private:

	std::string user_name;

	int user_rights; // int within range <0 - 10>

	int user_contract_type; // int within range <0 - 5>

};
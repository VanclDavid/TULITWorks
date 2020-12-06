#pragma once
#include <string>
class Form {
private:
	std::string name;
	Form(std::string name);
	void printElements(User user);
};
class HtmlElement {
private:
	std::string name;
public:
	HtmlElement(std::string name);
	std::string getName() const;
	virtual std::string generate() const = 0;
};
class Input :public HtmlElement {
public:
	explicit Input(std::string name);
	std::string generate() const override;
};
class CheckBox :public HtmlElement {
public:
	explicit CheckBox(std::string name);
	std::string generate() const override;
};
class InputPswd :public HtmlElement {
public:
	explicit InputPswd(std::string name);
	std::string generate() const override;
};
class User {
private:
	std::string user_name;
	int user_rights;
	int user_contract_type;
public:
		explicit User(std::string user_name, int user_rights, int user_contract_type);
		std::string getName();
		std::string getRights();
		std::string getContractType();
};


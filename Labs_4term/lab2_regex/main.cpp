#include "Formularz.h";
#include "Users.h";

int main(){
	Form form;
	
	form.getFullName();
	form.getPassword();
	form.getEmail();
	
	form.sentByPOSTMethod();

	Users users;

	users.getPhoneNumber();
	users.countMales();
	users.getFemaleURL();

	return 0;
}
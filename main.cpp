#include "Ellipsed.h"

void main(){
	Ellipsed *game = new Ellipsed(6);
	int i = 0 ;
	char answer;
	while (!game->isFull()){
		game->add(i+1);
		i++;
	}
	char name[25];
	char *names = name;
	int money = 0;
	cout<<"***LUCKY 2014***"<<endl<<"ENTER YOUR NAME :"<<endl;
	cin>>name;
	cout<<"Enter your money :"<<endl;
	cin>>money;
	game->setName(names);
	game->setMoney(money);
	game->menu();
}
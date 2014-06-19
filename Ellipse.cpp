#include "Ellipsed.h"


Ellipsed::Ellipsed(int m)
{
	max = m ;
	wait = new int[max];
	current = 0 ;
}


Ellipsed::~Ellipsed()
{
	delete []wait;
}

void Ellipsed :: add(int v){
	if ( !isFull() ){
		wait[current++] = v;
	}
}

int Ellipsed :: extract(){
	int temp = -1;
	if ( !isEmpty() ){
		temp = wait[0];
		for (int i = 1 ; i < current ; i++){
			wait[i-1] = wait[i];
		}
		wait[current - 1] = temp;
	}
	return temp;
}

bool Ellipsed :: isEmpty(){
	return current == 0;
}

bool Ellipsed :: isFull(){
	return current == max;
}

void Ellipsed :: show(){
	if (!isEmpty()){
		for ( int i = 0 ; i < current ; i++ ){
			cout <<char(wait[i]) <<" ";
		}
	}
}

void Ellipsed :: result(int firstRand , int index){
	for ( int i = 0 ; i < firstRand ; i++){
		extract();
	}
	masForCombination[index] = wait[0];
	cout<<" "<<char(extract());
}

void Ellipsed :: beforeStart(){
	
	for ( int i = 0 ; i < 6 ; i++ ){
		system("cls");
		cout<<"***LUCKY***"<<endl;
		cout<<"  "<<char(extract())<<"  "<<char(extract())<<"  "<<char(extract());
		cout<<endl<<"YOUR MONEY :"<<money<<endl;
		Sleep(300);
	}
}

void Ellipsed :: game(){	
	int randDigit = 0;
	int randDigit_1 = 0;
	int randDigit_2 = 0;
	srand(time(NULL));
	while(true){
		int index = 0;
		beforeStart();
		randDigit = rand()%1+5;
		randDigit_1 = rand()%10+25;
		randDigit_2 = rand()%25+10;
		system("cls");
		cout<<"***LUCKY***"<<endl;
		result(randDigit,index);
		index++;
		result(randDigit_1,index);
		index++;
		result(randDigit_2,index);
		chekCombination();
		cout<<endl<<"YOUR MONEY :"<<money<<endl;
		cout<<getName()<<" IF TOU WANT TO TRY AGAIN (press ENTER)"<<endl;
		cout<<"GO TO MENU WITH YOUR MONEY (press q)"<<endl;
		char answer = getch();
		switch(answer){
				case 'q':
					menu();
				break;
				default :
					money -= 10;
					break;
			}
	}
}

void Ellipsed :: menu(){
	system("cls");
	cout<<"***LUCKY***"<<endl;
	cout<<"1.Play"<<endl;
	cout<<"2.Rules"<<endl;
	cout<<"3.Exit"<<endl;
	char a = getch();
	switch(a){
	case '1':
		game();
		break;
	case '2':
		rules();
		break;
	case '3':
		cout<<"THANK FOR YOUR GAME !!! YOUR BALANCE : "<<money;
		system("pause");
		exit(0);
		break;
	default:
		system("cls");
		menu();
	}
}


void Ellipsed :: rules(){
	system("cls");
	cout<<"HELLO"<<endl;
	system("pause");
	menu();
}

void Ellipsed :: setName(char *name){
	strcpy(this->name,name);
}

char *Ellipsed ::  getName(){
	return this->name;
}

void Ellipsed :: setMoney(int money){
	this->money = money;
}

int Ellipsed ::  getMoney(){
	return this->money;
}

void Ellipsed :: chekCombination(){
	
	if (masForCombination[0] == masForCombination[1] && masForCombination[0] == masForCombination[2]){
		money += 100;
		cout<<endl<<"YOU WIN 100$"<<endl;
	}

	if (masForCombination[0] == masForCombination[1] || masForCombination[0] == masForCombination[2] || masForCombination[1] == masForCombination[2]){
		money += 20;
		cout<<endl<<"YOU WIN 20$"<<endl;
	}


}

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
using namespace std;
const int maxh=10,maxl=10;
int a[maxh][maxl]= {
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 4, 1, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 3, 0, 3, 4, 1},
	{1, 4, 0, 3, 2, 1, 1, 1},
	{1, 1, 1, 1, 3, 1, 0, 0},
	{0, 0, 0, 1, 4, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0}
};
int x,y,boxnum=0;
void nowmap() {

	for(int i=0; i<maxh; i++)
		for(int j=0; j<maxl; j++) {
			if(a[i][j]==2) {
				x=i;
				y=j;

			}
			if(a[i][j]==3)
				boxnum++;
		}

}
void printmap() {

	for(int i=0; i<maxh; i++) {
		for(int j=0; j<maxl; j++) {
			if(a[i][j]==0)
				cout<<" ";
			if(a[i][j]==1)
				printf("#");

			if(a[i][j]==2)
				printf("S");
			if(a[i][j]==3)
				printf("¡ô");
			if(a[i][j]==4)
				printf("¡ñ");
			if(a[i][j]==5)
				printf("*");
		}
		printf("\n");
	}
}
void move(int di,int dj) {
	int tx=x+di,ty=y+dj;
	int flag=0;
	if(a[tx][ty]==0) {
		a[x][y]=0;
		a[tx][ty]=2;
		flag=1;
	}
	if(a[tx][ty]==3) {
		if(a[tx+di][ty+dj]==0) {
			a[tx+di][ty+dj]=3;
			a[tx][ty]=2;
			a[x][y]=0;
			flag=1;
		}
		if(a[tx+di][ty+dj]==4) {
			a[tx+di][ty+dj]=5;
			a[x][y]=0;
			a[tx][ty]=2;
			boxnum--;
			flag=1;
		}
	}
	if(flag==1) {
		x=tx;
		y=ty;
	}
}
int main() {

	nowmap();
	char t;

	while(1) {
		cout<<"addd"<<endl;
		system("cls");
		printmap();
		if(boxnum==0)
			break;
		t=getch();
		switch(t) {
			case 'a':
				move(0,-1);
				break;
			case 'd':
				move(0,1);
				break;
			case 'w':
				move(-1,0);
				break;
			case 's':
				move(1,0);
				break;
		}

	}
	return 0;
}

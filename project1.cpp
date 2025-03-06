#include<graphics.h>
#include<bits/stdc++.h>
//#include<mmsystem.h>
using namespace std;

void run();
int jud();
int book[15][15]; 

int main(){
	setinitmode(0);
	initgraph(600,600);
	setcaption("五子棋");
	run();

	return 0;
} 

void run(){
	MUSIC music;
	music.OpenFile("C:/Users/chancy/Desktop/软工实训/软工实训项目1资料/落子.mp3");
	setcolor(BLACK);
	int win1=0;
	int win2=0;
	int round=0;
	setbkcolor(WHITE);
	char c;
	PIMAGE img1,img2,img_out,img_back,img_blank,img_next;
	img1=newimage();
	img2=newimage();
	img_out=newimage();
	img_back=newimage();
	img_blank=newimage();
	img_next=newimage();
    getimage(img1, "chess2.png");
    getimage(img2, "chess1.png");
    getimage(img_out, "退出.png");
    getimage(img_back,"悔棋.png");
    getimage(img_blank,"白底.png");
    getimage(img_next,"下一局.png");
    mouse_msg msg={0}; 
    int stop=0;
	while(true){
		stack<int> x;
		stack<int> y;
		round++;
		putimage(295,30,img1);
		putimage(325,30,img2);
		xyprintf(300,50,"%d  :  %d",win1,win2);
		xyprintf(450,250,"第 %d 局",round);
		int flag=0; 
		int cnt=0;
		setfillcolor(WHITE);
//		rectangle(100,100,400,400);
		for(int i=100;i<=380;i+=20){
			line(100,i,380,i);
			line(i,100,i,380);
		}
//		rectangle(500,500,560,520);
		putimage(500,500,img_out);
		putimage(500,450,img_back);
	    outtextxy(100, 50, "当前执子：");
	    for(; is_run(); delay_fps(60)){
			while(mousemsg()){
				if(cnt%2==0)putimage(170,50,img1);
				else putimage(170,50,img2);
				msg = getmouse();
	            if(msg.is_left() && msg.is_down()){   
	            	
	            	if(msg.x>=500&&msg.x<=560&&msg.y>=500&&msg.y<=520){
	            		closegraph();
	            		return;
					}
					if(msg.x>=500&&msg.x<=560&&msg.y>=450&&msg.y<=470&&cnt>0){
						cnt--;
						int tmpx=x.top();
						int tmpy=y.top();
						book[tmpx][tmpy]=0;
						x.pop();
						y.pop();
						putimage(90,90,img_blank);
						for(int i=100;i<=380;i+=20){
							line(100,i,380,i);
							line(i,100,i,380);
						}
						for(int i=0;i<15;i++){
							for(int j=0;j<15;j++){
								if(book[i][j]==1){
									putimage(i*20-8+100,j*20-8+100,img1);
								}else if(book[i][j]==2){
									putimage(i*20-8+100,j*20-8+100,img2);
								}
							}
						}
					}
					
	            	if(msg.x>90&&msg.y>90&&msg.x<390&&msg.y<390&&book[(msg.x+9)/20-5][(msg.y+9)/20-5]==0){
	            		if(abs((msg.x-100)%20)>=8&&abs((msg.x-100)%20)<=12||abs((msg.y-100)%20)>=8&&abs((msg.y-100)%20)<=12){
	            			continue;
						}
	            		if(cnt%2==0){
	//            			outtextxy(100, 70, "当前执子：黑");
							
//							music.Stop();
	            			putimage((msg.x+9)/20*20-8,(msg.y+9)/20*20-8,img1);
	            			book[(msg.x+9)/20-5][(msg.y+9)/20-5]=1;
//	            			music.Play(150,330);
						}else{
	//						outtextxy(100, 70, "当前执子：白");
//							music.Stop();
							putimage((msg.x+9)/20*20-8,(msg.y+9)/20*20-8,img2);
							book[(msg.x+9)/20-5][(msg.y+9)/20-5]=2;
//							music.Play(150,330);
						}
	            		cnt++;
	            		x.push((msg.x+9)/20-5);
	            		y.push((msg.y+9)/20-5);
	            		if(jud()==1){
	            			win1++;
	            			xyprintf(300,50,"%d  :  %d",win1,win2);
	            			setcolor(RED);
	            			outtextxy(100, 450, "黑子胜利!");
	            			setcolor(BLACK);
//	            			outtextxy(100, 500, "按任意键结束游戏，按Enter开始下一局");
	            			putimage(100,500,img_next);
	            			for(; is_run(); delay_fps(60)){
	            				while(mousemsg()){
	            					msg = getmouse();
//									mousemsg();
		            				if(msg.is_left() && msg.is_down()){
		            					if(msg.x>=100&&msg.x<=200&&msg.y>=500&&msg.y<=540){
		            						cleardevice();
		            						for(int i=0;i<15;i++){
											for(int j=0;j<15;j++){
												book[i][j]=0;
											}
										}
		            						flag=1;
		            						break;
										}else if(msg.x>=500&&msg.x<=560&&msg.y>=500&&msg.y<=520){
						            		closegraph();
						            		return;
										}
									}
								}
								if(flag)break;
							}
	            			break;
						}else if(jud()==2){
							win2++;
							xyprintf(300,50,"%d  :  %d",win1,win2);
							setcolor(RED);
							outtextxy(100, 450, "白子胜利!");
							setcolor(BLACK);
//							outtextxy(100, 500, "按任意键结束游戏，按Enter开始下一局");
	            			putimage(100,500,img_next);
							for(; is_run(); delay_fps(60)){
	            				while(mousemsg()){
	            					msg = getmouse();
//									mousemsg();
		            				if(msg.is_left() && msg.is_down()){
		            					if(msg.x>=100&&msg.x<=200&&msg.y>=500&&msg.y<=540){
		            						cleardevice();
		            						for(int i=0;i<15;i++){
											for(int j=0;j<15;j++){
												book[i][j]=0;
											}
										}
		            						flag=1;
		            						break;
										}else if(msg.x>=500&&msg.x<=560&&msg.y>=500&&msg.y<=520){
						            		closegraph();
						            		return;
										}
									}
								}
								if(flag)break;
							}
	            			break;
						}else if(cnt==225){
							setcolor(RED);
							outtextxy(100, 450, "平局");
							setcolor(BLACK);
//							outtextxy(100, 500, "按任意键结束游戏，按Enter开始下一局");
	            			putimage(100,500,img_next);
	            			for(; is_run(); delay_fps(60)){
	            				while(mousemsg()){
	            					msg = getmouse();
//									mousemsg();
		            				if(msg.is_left() && msg.is_down()){
		            					if(msg.x>=100&&msg.x<=200&&msg.y>=500&&msg.y<=540){
		            						cleardevice();
		            						for(int i=0;i<15;i++){
											for(int j=0;j<15;j++){
												book[i][j]=0;
											}
										}
		            						flag=1;
		            						break;
										}else if(msg.x>=500&&msg.x<=560&&msg.y>=500&&msg.y<=520){
						            		closegraph();
						            		return;
										}
									}
								}
								if(flag)break;
							}
	            			break;
						}
					}
				}
				if(flag==1)break;
			}
			if(flag==1)break;
		}
	}
//    putimage(202,202,img1);
//    putimage_withalpha(NULL,img1,102,102);
	
	
}



int jud(){
//	cout<<"jud";
	//判断行
	for(int i=0;i<15;i++){
		int cnt1=0;
		int cnt2=0;
		for(int j=0;j<15;j++){
			if(book[i][j]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[i][j]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断行return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	} 
	//判断列 
	for(int i=0;i<15;i++){
		int cnt1=0;
		int cnt2=0;
		for(int j=0;j<15;j++){
//			cout<<"列：book["<<i<<"]["<<j<<"]="<<book[i][j]<<endl;
			if(book[j][i]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[j][i]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断列return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	} 
	//判断斜向下
	for(int ii=0;ii<15;ii++){
		int cnt1=0;
		int cnt2=0;
		for(int j=0,i=ii;i<15&&j<15;i++,j++){
//			cout<<"斜向下1：book["<<i<<"]["<<j<<"]="<<book[i][j]<<endl;
			if(book[i][j]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[i][j]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断斜向下1 return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	} 
	for(int jj=14;jj>=0;jj--){
		int cnt1=0;
		int cnt2=0;
		for(int i=0,j=jj;i<15&&j<15;i++,j++){
//			cout<<"斜向下2：book["<<i<<"]["<<j<<"]="<<book[i][j]<<endl;
			if(book[i][j]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[i][j]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断斜向下2 return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	} 
	//判断斜向上
	for(int ii=0;ii<15;ii++) {
		int cnt1=0;
		int cnt2=0;
		for(int j=0,i=ii;i>=0&&j<15;i--,j++){
//			cout<<"斜向上1：book["<<i<<"]["<<j<<"]="<<book[i][j]<<endl;
			if(book[i][j]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[i][j]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断斜向上1 return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	}
	for(int jj=0;jj<15;jj++){
		int cnt1=0;
		int cnt2=0;
		for(int i=14,j=jj;i>=0&&j<15;i--,j++){
//			cout<<"斜向上2：book["<<i<<"]["<<j<<"]="<<book[i][j]<<endl;
			if(book[i][j]==1){
				cnt1++;
			}else{
				cnt1=0;
			}
			if(book[i][j]==2){
				cnt2++;
			}else{
				cnt2=0;
			}
			if(cnt1>=5){
//				cout<<"判断斜向上2 return false"<<endl;
				return 1;
			}else if(cnt2>=5){
				return 2;
			}
		}
	}
//	cout<<"return true"<<endl;
	return 0;
}

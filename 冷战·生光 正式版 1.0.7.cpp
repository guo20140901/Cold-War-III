#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<limits>
#include<string>
using namespace std;

const int player_iron_=100;//玩家初始铁量
const int player_polymer_=200;//玩家初始聚合物量
const int player_silicon_=10;//玩家初始硅量 
const int player_metal_=100;//玩家初始金属量
const int player_people_=10;//玩家初始人口
const int player_chip_=4;//玩家初始芯片量
const int player_iro_ore_=1;//玩家初始铁矿量
const int player_silicon_ore_=1;//玩家初始硅矿量
const int player_money_=1000;//玩家初始资金量 
const int player_order_=75;//玩家初始秩序
const int player_hope_=75;//玩家初始希望 
const int player_metal_ore_=1;//玩家初始钢铁工厂 
const int player_chip_ore_=1;//玩家初始芯片工厂 
const int player_eat_=1;//玩家初始每人一季度食物消耗 
const int player_eat_ore_=0;//玩家初始食堂数
const int player_mat_=10;//玩家每月获得物资数
 
int sg; 
int player_iron=player_iron_;
int player_polymer=player_polymer_;
int player_silicon=player_silicon_;
int player_metal=player_metal_;
int player_people=player_people_;
int player_chip=player_chip_;
int player_iro_ore=player_iro_ore_;
int player_silicon_ore=player_silicon_ore_;
int player_money=player_money_;
int player_order=player_order_;
int player_hope=player_hope_;
int player_metal_ore=player_metal_ore_;
int player_chip_ore=player_chip_ore_;
int player_eat=player_eat_;
int player_eat_ore=player_eat_ore_;
int player_mat=player_mat_;

bool open_space=false;
bool kill=false;
bool food=false;
bool kill2=false;
bool food2=false;
 
bool vip=false;
bool money=false;
bool ore=false;
bool metal=false;
 
int key=0; 
int adminkey=20140901;

int people_money=10;
string name="游客";
int gold=0;
 
bool little_home=false;
bool lb_home=false;
bool big_home=false;
bool noon_money=false; 
bool very_money=false;
bool so_money=false;


int play_ago(){
	cout<<"##################"<<endl;
	cout<<"#                #"<<endl;
	cout<<"# ######  #####  #"<<endl;
	cout<<"# #      #     # #"<<endl;
	cout<<"# ###### #     # #"<<endl;
	cout<<"#      #  ###### #"<<endl;
	cout<<"# ######       # #"<<endl;
	cout<<"#              # #"<<endl;
	cout<<"# @@@@@@@ ###### #"<<endl;
	cout<<"#                #"<<endl;
	cout<<"#################";
	Sleep(5000);
	system("cls");
	system("mode con cols=18 lines=5");
	cout<<"##################"<<endl;
	cout<<"#                #"<<endl;
	cout<<"#   LG 三号game  #"<<endl;
	cout<<"#                #"<<endl;
	cout<<"#################";
	Sleep(5000);
	system("cls");
	return 0;
}

int home(){
		cout<<"##################################################################"<<endl;
		printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
		cout<<endl<<"##################################################################"<<endl;
		printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
		printf("# 预产: %3d  #              请选择你的操作:(输入7退出)           #\n",player_iro_ore*10);
		printf("# 硅矿: %2d个 #          1:建造钢铁工厂 [花费50金属] [加工10铁]   #\n",player_silicon_ore);
		printf("# 预产: %3d  #          2:建造芯片工厂 [花费100金属] [加工10硅]  #\n",player_silicon_ore*3);
		printf("# 税收: %4d #      3:寻找新的铁矿 [花费50聚合物] [%50发现铁矿]  #\n",people_money*player_people);
		printf("# 秩序: %3d  #     4:寻找新的硅矿 [花费75聚合物] [%25发现硅矿]   #\n",player_order);
		printf("# 希望: %3d  # 5:建造食堂 [花费50金属,25聚合物] [减少%10食物消耗]#\n",player_hope);
		cout<<"##############                    6:查询现有建筑                 #"<<endl;
		cout<<"# LG公司出品                                                     #"<<endl;
		cout<<"##################################################################"<<endl;
		cout<<"->>";
		cin>>sg;
		cout<<endl;
		switch(sg){
			case 1:
				if(player_metal>=50){
					MessageBox(NULL," 建造钢铁工厂完成!","建造成功",MB_OK|MB_ICONASTERISK); 
					player_metal_ore+=1;
					player_metal-=50;
				}
				else{
					MessageBox(NULL," 资源不足!(错误编码LG002)","建造失败!",MB_OK|MB_ICONHAND); 
				}
				break; 
			case 2:
				if(player_metal>=100){
					MessageBox(NULL," 建造芯片工厂完成!","建造成功",MB_OK|MB_ICONASTERISK);
					player_chip_ore+=1;
					player_metal-=100;
				} 
				else{
					MessageBox(NULL," 资源不足!(错误编码LG003)","建造失败!",MB_OK|MB_ICONHAND);
				}
				break;
			case 3:
				if(player_polymer>=50){
					MessageBox(NULL," 开始搜索铁矿!","搜索铁矿进度",MB_OK);
					sg=rand()%2+1;
					switch(sg){
						case 1:
							MessageBox(NULL," 搜索到一个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
							player_iro_ore+=1;
							player_polymer-=50;
							break;
						case 2:
							MessageBox(NULL,"什么都没搜索到","搜索失败",MB_OK|MB_ICONASTERISK);
							player_polymer-=50;
							break; 
					} 
				}
				else{
					MessageBox(NULL," 资源不足!(错误编码LG004)","搜索失败!",MB_OK|MB_ICONHAND);
				}	 
				break;
			case 4:
				if(player_polymer>=75){
					MessageBox(NULL," 开始搜索硅矿!","搜索铁矿进度",MB_OK);
					sg=rand()%4+1;
					switch(sg){
						case 1:
							MessageBox(NULL," 搜索到一个硅矿!","搜索成功",MB_OK|MB_ICONASTERISK);
							player_silicon_ore+=1;
							player_polymer-=75;
							break;
						case 2:
						case 3:
						case 4:
							MessageBox(NULL,"什么都没搜索到","搜索失败",MB_OK|MB_ICONASTERISK);
							player_polymer-=75; 
					}
				}
				else{
					MessageBox(NULL," 资源不足!(错误编码LG005)","搜索失败!",MB_OK|MB_ICONHAND);
				}
				break;
			case 5:
				if(player_metal>=50&&player_polymer>=25){
					MessageBox(NULL," 建造食堂完成完成!","建造成功",MB_OK|MB_ICONASTERISK); 
					player_eat_ore+=1;
					player_eat*=0.9;
					player_metal-=50;
					player_polymer-=25;
				}
				else{
					MessageBox(NULL," 资源不足!(错误编码LG006)","建造失败!",MB_OK|MB_ICONHAND); 
				}
				break; 
			case 6:
				cout<<"##################################################################"<<endl;
				printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
				cout<<endl<<"##################################################################"<<endl;
				printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
				printf("# 预产: %3d  #              1.钢铁工厂数:%2d                      #\n",player_iro_ore*10,player_metal_ore);
				printf("# 硅矿: %2d个 #                最大加工量:%3d                     #\n",player_silicon_ore,player_metal_ore*10);
				printf("# 预产: %3d  #              2.芯片工厂数:%2d                      #\n",player_silicon_ore*3,player_chip_ore);
				printf("# 税收: %4d #                最大加工量:%3d                     #\n",people_money*player_people,player_chip_ore*10);
				printf("# 秩序: %3d  #              3.食堂数:%2d                          #\n",player_order,player_eat_ore);
				printf("# 希望: %3d  #                食物消耗量:%3d                     #\n",player_hope,player_eat*player_people);
				cout<<"##############             按下任意键返回主界面                  #"<<endl;
				cout<<"# LG公司出品                                                     #"<<endl;
				cout<<"##################################################################"<<endl;
				system("pause");
				break;
			case 7:
				return 0;
				break; 
			default:
				MessageBox(NULL,"输入错误(错误编码LG007)","错误",MB_OK|MB_ICONHAND);
		} 
}

int space(){
		cout<<"##################################################################"<<endl;
		printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
		cout<<endl<<"##################################################################"<<endl;
		printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
		printf("# 预产: %3d  #              请选择你的操作:(输入7退出)           #\n",player_iro_ore*10);
		printf("# 硅矿: %2d个 #     1:建造发射中心 [花费100金属] [解锁太空交互]   #\n",player_silicon_ore);
		printf("# 预产: %3d  #  2:发射卫星 [花费200金属,5个芯片] [发现1~5个铁矿] #\n",player_silicon_ore*3);
		printf("# 税收: %4d #  3:发射火箭 [花费300金属,10个芯片] [发现1~3个硅矿]#\n",people_money*player_people);
		printf("# 秩序: %3d  #  4:发射军事卫星 [花费200金属,5个芯片] [增加秩序]  #\n",player_order);
		printf("# 希望: %3d  #  5:发射广播卫星 [花费300金属,7个芯片] [增加希望]  #\n",player_hope);
		cout<<"##############  6:发射科技卫星 [花费200金属,10个芯片] [增加人口] #"<<endl;
		cout<<"# LG公司出品                                                     #"<<endl;
		cout<<"##################################################################"<<endl;
		cout<<"->>";
		cin>>sg;
		cout<<endl;
		switch(sg){
			case 1:
				if(player_metal>=100){
					MessageBox(NULL," 建造发射中心完成!","建造成功",MB_OK|MB_ICONASTERISK); 
					player_metal-=100;
					open_space=true; 
				}
				else{
					MessageBox(NULL," 资源不足!(错误编码LG008)","建造失败!",MB_OK|MB_ICONHAND); 
				}
				break; 
			case 2:
				if(open_space){
					if(player_metal>=100&&player_chip>=5){
						MessageBox(NULL," 发射完成!","发射成功",MB_OK|MB_ICONASTERISK);
						MessageBox(NULL," 开始搜索铁矿!","搜索铁矿进度",MB_OK);
						sg=rand()%5+1;
						switch(sg){
							case 1:
								MessageBox(NULL," 搜索到五个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_iro_ore+=5;
								player_metal-=200;
								player_chip-=5;
								break;
							case 2:
								MessageBox(NULL," 搜索到四个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_iro_ore+=4;
								player_metal-=200;
								player_chip-=5;
								break;
							case 3:
								MessageBox(NULL," 搜索到三个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_iro_ore+=3;
								player_metal-=200;
								player_chip-=5;
								break; 
							case 4:
								MessageBox(NULL," 搜索到二个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_iro_ore+=2;
								player_metal-=200;
								player_chip-=5;
								break; 
							case 5:
								MessageBox(NULL," 搜索到一个铁矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_iro_ore+=1;
								player_metal-=200;
								player_chip-=5;
								break;  
						} 
						player_chip-=5;
						player_metal-=200;
					} 
					else{
						MessageBox(NULL," 资源不足!(错误编码LG009)","发射失败!",MB_OK|MB_ICONHAND);
					}
				}
				else{
					MessageBox(NULL," 未解锁太空交互(错误编码LG010)","发射失败!",MB_OK|MB_ICONHAND); 
				}
				break;
			case 3:
				if(open_space){
					if(player_metal>=300&&player_chip==10){
						MessageBox(NULL," 发射完成!","发射成功",MB_OK|MB_ICONASTERISK);
						MessageBox(NULL," 开始搜索硅矿!","搜索硅矿进度",MB_OK);
						sg=rand()%5+1;
						switch(sg){
							case 1:
								MessageBox(NULL," 搜索到三个硅矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_chip_ore+=3;
								player_metal-=300;
								player_chip-=10;
								break;
							case 2:
								MessageBox(NULL," 搜索到两个硅矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_chip_ore+=2;
								player_metal-=300;
								player_chip-=10;
								break;
							case 3:
								MessageBox(NULL," 搜索到一个硅矿!","搜索成功",MB_OK|MB_ICONASTERISK);
								player_chip_ore+=1;
								player_metal-=300;
								player_chip-=10; 
						} 
						player_chip-=5;
						player_metal-=200;
					} 
					else{
						MessageBox(NULL," 资源不足!(错误编码LG011)","发射失败!",MB_OK|MB_ICONHAND);
					}
				}
				else{
					MessageBox(NULL," 未解锁太空交互(错误编码LG012)","发射失败!",MB_OK|MB_ICONHAND); 
				}
				break;
			case 4:
				if(open_space){
					if(player_metal>=200){
						MessageBox(NULL," 军事卫星发射完成!","发射成功",MB_OK|MB_ICONASTERISK); 
						player_metal-=200;
						player_chip-=5;
						player_order+=25; 
					}
					else{
						MessageBox(NULL," 资源不足!(错误编码LG0013)","发射失败!",MB_OK|MB_ICONHAND); 
					}
				}
				else{
					MessageBox(NULL," 未解锁太空交互(错误编码LG014)","发射失败!",MB_OK|MB_ICONHAND); 
				}
				break;
			case 5:
				if(open_space){
					if(player_metal>=200){
						MessageBox(NULL," 广播卫星发射完成!","发射成功",MB_OK|MB_ICONASTERISK); 
						player_metal-=300;
						player_chip-=7;
						player_hope+=50; 
					}
					else{
						MessageBox(NULL," 资源不足!(错误编码LG0015)","发射失败!",MB_OK|MB_ICONHAND); 
					}
				}
				else{
					MessageBox(NULL," 未解锁太空交互(错误编码LG016)","发射失败!",MB_OK|MB_ICONHAND); 
				}
				break; 
			case 6:
				if(open_space){
					if(player_metal>=200){
						MessageBox(NULL," 科技卫星发射完成!","发射成功",MB_OK|MB_ICONASTERISK); 
						player_metal-=200;
						player_chip-=10;
						player_people+=10; 
					}
					else{
						MessageBox(NULL," 资源不足!(错误编码LG017)","发射失败!",MB_OK|MB_ICONHAND); 
					}
				}
				else{
					MessageBox(NULL," 未解锁太空交互(错误编码LG018)","发射失败!",MB_OK|MB_ICONHAND); 
				}
			case 7:
				return 0;
				break; 
			default:
				MessageBox(NULL,"输入错误(错误编码LG019)","错误",MB_OK|MB_ICONHAND);
		}
}

int decree(){
	cout<<"##################################################################"<<endl;
	printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
	cout<<endl<<"##################################################################"<<endl;
	printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
	printf("# 预产: %3d  #                    请选择你的操作:                #\n",player_iro_ore*10);
	printf("# 硅矿: %2d个 # 1:压迫(与盛餐不可并存)[降低秩序希望][减少食物消耗]#\n",player_silicon_ore);
	printf("# 预产: %3d  # 2:盛餐(与压迫不可并存)[提高秩序希望][增大食物消耗]#\n",player_silicon_ore*3);
	printf("# 税收: %4d # 3:酷刑(需解锁压迫)[降低希望提升秩序][暂无食物效果]#\n",people_money*player_people);
	printf("# 秩序: %3d  # 4:祈福(需解锁盛餐)[提高希望降低秩序][增大食物消耗]#\n",player_order);
	printf("# 希望: %3d  #5:军队(需消耗200聚合物)[提高较多秩序][增大食物消耗]#\n",player_hope);
	cout<<"############## 6:裁军(需消耗2000资金)[减少较多秩序][减少食物消耗]#"<<endl;
	cout<<"# LG公司出品                                                     #"<<endl;
	cout<<"##################################################################"<<endl;
	cout<<"->>";
	cin>>sg;
	cout<<endl;
	switch(sg){
		case 1:
			if(!food){
				if(!kill){
					MessageBox(NULL," 签订压迫法令完成!","签署成功",MB_OK|MB_ICONASTERISK);
					kill=true;
					player_eat*=0.9; 
					player_hope-=25;
					player_order-=25;
				}
				else{
					MessageBox(NULL," 你已经签署过了!(错误编码LG020)","签署失败!",MB_OK|MB_ICONHAND);
				}
			}
			else{
				MessageBox(NULL," 压迫与盛餐不可并存!(错误编码LG021)","签署失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 2:
			if(!kill){
				if(!food){
					MessageBox(NULL," 签订盛餐法令完成!","签署成功",MB_OK|MB_ICONASTERISK);
					food=true;
					player_eat*=1.1; 
					player_hope+=25;
					player_order+=25;
				}
				else{
					MessageBox(NULL," 你已经签署过了!(错误编码LG022)","签署失败!",MB_OK|MB_ICONHAND);
				}
			}
			else{
				MessageBox(NULL," 盛餐与压迫不可并存!(错误编码LG023)","签署失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 3:
			if(kill){
				if(!kill2){
					MessageBox(NULL," 签订酷刑法令完成!","签署成功",MB_OK|MB_ICONASTERISK);
					kill2=true;
					player_eat*=0.7; 
					player_hope-=50;
					player_order+=25;
				}
				else{
					MessageBox(NULL," 你已经签署过了!(错误编码LG024)","签署失败!",MB_OK|MB_ICONHAND);
				}
			}
			else{
				MessageBox(NULL," 未解锁压迫!(错误编码LG025)","签署失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 4:
			if(food){
				if(!food2){
					MessageBox(NULL," 签订祈福法令完成!","签署成功",MB_OK|MB_ICONASTERISK);
					food2=true;
					player_eat*=1.3; 
					player_hope+=50;
					player_order-=25;
				}
				else{
					MessageBox(NULL," 你已经签署过了!(错误编码LG026)","签署失败!",MB_OK|MB_ICONHAND);
				}
			}
			else{
				MessageBox(NULL," 未解锁盛餐!(错误编码LG027)","签署失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 5:
			if(player_polymer>=200){
				MessageBox(NULL," 签订军队法令完成!","签署成功",MB_OK|MB_ICONASTERISK); 
				player_polymer-=2000;
				player_eat*=1.3;
				player_order+=75; 
			}
			else{
				MessageBox(NULL," 资源不足!(错误编码LG028)","签署失败!",MB_OK|MB_ICONHAND); 
			}
			break; 
		case 6:
			if(player_money>=2000){
				MessageBox(NULL," 签订裁军法令完成!","签署成功",MB_OK|MB_ICONASTERISK); 
				player_money-=200;
				player_eat*=0.7;
				player_order-=75; 
			}
			else{
				MessageBox(NULL," 资源不足!(错误编码LG029)","签署失败!",MB_OK|MB_ICONHAND); 
			}
			break; 
		case 7:
			return 0;
			break; 
		default:
			MessageBox(NULL,"输入错误(错误编码LG030)","错误",MB_OK|MB_ICONHAND);
	}
}

int speak(){
	cout<<"##################################################################"<<endl;
	printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
	cout<<endl<<"##################################################################"<<endl;
	printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
	printf("# 预产: %3d  #           请选择你的操作(物资配额:%2d):            #\n",player_iro_ore*10,player_mat);
	printf("# 硅矿: %2d个 #            1:25单位铁<=1单位物资                  #\n",player_silicon_ore);
	printf("# 预产: %3d  #             2:10单位硅<=1单位物资                 #\n",player_silicon_ore*3);
	printf("# 税收: %4d #            3:10单位聚合物<=1单位物资              #\n",people_money*player_people);
	printf("# 秩序: %3d  #            4:25单位聚合物<=100资金                #\n",player_order);
	printf("# 希望: %3d  #            5:100单位金属<=500资金                 #\n",player_hope);
	cout<<"##############              6:15单位芯片<=1000资金               #"<<endl;
	cout<<"# LG公司出品                                                     #"<<endl;
	cout<<"##################################################################"<<endl;
	cout<<"->>";
	cin>>sg;
	cout<<endl;
	switch(sg){
		case 1:
			if(player_mat>0){
				MessageBox(NULL," 兑换了25单位铁!","兑换成功",MB_OK|MB_ICONASTERISK);
				player_mat-=1;
				player_iron+=25; 
			}
			else{
				MessageBox(NULL," 物资配额不足(错误编码LG030)","兑换失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 2:
			if(player_mat>0){
				MessageBox(NULL," 兑换了10单位硅!","兑换成功",MB_OK|MB_ICONASTERISK);
				player_mat-=1;
				player_silicon+=25; 
			}
			else{
				MessageBox(NULL," 物资配额不足(错误编码LG031)","兑换失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 3:
			if(player_mat>0){
				MessageBox(NULL," 兑换了10单位聚合物!","兑换成功",MB_OK|MB_ICONASTERISK);
				player_mat-=1;
				player_polymer+=10; 
			}
			else{
				MessageBox(NULL," 物资配额不足(错误编码LG032)","兑换失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 4:
			if(player_money>=100){
				MessageBox(NULL," 购买了25单位聚合物!","购买成功",MB_OK|MB_ICONASTERISK);
				player_polymer+=25;
				player_money-=100; 
			}
			else{
				MessageBox(NULL," 资金不足(错误编码LG033)","购买失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 5:
			if(player_money>=500){
				MessageBox(NULL," 购买了100单位金属!","购买成功",MB_OK|MB_ICONASTERISK);
				player_metal+=100;
				player_money-=500; 
			}
			else{
				MessageBox(NULL," 资金不足(错误编码LG034)","购买失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 6:
			if(player_money>=1000){
				MessageBox(NULL," 购买了15单位芯片!","购买成功",MB_OK|MB_ICONASTERISK);
				player_chip+=15;
				player_money-=1000; 
			}
			else{
				MessageBox(NULL," 资金不足(错误编码LG035)","购买失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 7:
			return 0;
			break; 
		default:
			MessageBox(NULL,"输入错误(错误编码LG036)","错误",MB_OK|MB_ICONHAND);
	}
} 

int speak2(){
	cout<<"##################################################################"<<endl;
	printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
	cout<<endl<<"##################################################################"<<endl;
	printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
	printf("# 预产: %3d  #           请选择你的操作(物资配额:%2d):            #\n",player_iro_ore*10,player_mat);
	printf("# 硅矿: %2d个 #             1:100单位铁=>250资金                  #\n",player_silicon_ore);
	printf("# 预产: %3d  #             2:25单位硅=>250资金                   #\n",player_silicon_ore*3);
	printf("# 税收: %4d #             3:50单位聚合物=>250资金               #\n",people_money*player_people);
	printf("# 秩序: %3d  #             4:50单位聚合物=>1单位物资             #\n",player_order);
	printf("# 希望: %3d  #             5:100单位金属=>1单位物资              #\n",player_hope);
	cout<<"##############             6:15单位芯片=>1单位物资               #"<<endl;
	cout<<"# LG公司出品                                                     #"<<endl;
	cout<<"##################################################################"<<endl;
	cout<<"->>";
	cin>>sg;
	cout<<endl;
	switch(sg){
		case 1:
			if(player_iron>=100){
				MessageBox(NULL," 出售了100单位铁!","出售成功",MB_OK|MB_ICONASTERISK);
				player_money+=250;
				player_iron-=100; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG037)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 2:
			if(player_silicon>=25){
				MessageBox(NULL," 出售了25单位硅!","出售成功",MB_OK|MB_ICONASTERISK);
				player_money+=250;
				player_silicon-=25; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG038)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 3:
			if(player_polymer>=50){
				MessageBox(NULL," 出售了50单位聚合物!","出售成功",MB_OK|MB_ICONASTERISK);
				player_money+=250;
				player_polymer-=50; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG039)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 4:
			if(player_polymer>=50){
				MessageBox(NULL," 出售了50单位聚合物!","出售成功",MB_OK|MB_ICONASTERISK);
				player_mat+=1;
				player_polymer-=50; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG040)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break;
		case 5:
			if(player_metal>=100){
				MessageBox(NULL," 出售了100单位金属!","出售成功",MB_OK|MB_ICONASTERISK);
				player_mat+=1;
				player_metal-=100; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG041)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 6:
			if(player_chip>=15){
				MessageBox(NULL," 出售了15单位芯片!","出售成功",MB_OK|MB_ICONASTERISK);
				player_mat+=1;
				player_chip-=15; 
			}
			else{
				MessageBox(NULL," 资源不足(错误编码LG042)","出售失败!",MB_OK|MB_ICONHAND);
			}
			break; 
		case 7:
			return 0;
			break; 
		default:
			MessageBox(NULL,"输入错误(错误编码LG043)","错误",MB_OK|MB_ICONHAND);
	}
}

int last_day(){
	//成绩结算
	if(player_people>=50&&little_home==false){
		MessageBox(NULL,"解锁小国成就!","成就一",MB_OK);
		gold+=25;
		little_home=true;
	} 
	if(player_people>=100&&lb_home==false){
		MessageBox(NULL,"解锁中国成就!","成就二",MB_OK);
		gold+=50;
		lb_home=true;	
	}
	if(player_people>=200&&big_home==false){
		MessageBox(NULL,"解锁大国成就!","成就三",MB_OK);
		gold+=75;
		big_home=true;	
	}
	if(player_money==0&&noon_money==false){
		MessageBox(NULL,"解锁月光族成就!","成就四",MB_OK);
		gold+=50;
		noon_money=true;	
	}
	if(player_money>=10000&&very_money==false){
		MessageBox(NULL,"解锁富翁成就!","成就五",MB_OK);
		gold+=75;
		very_money=true;	
	}
	if(people_money==999&&so_money==false){
		MessageBox(NULL,"解锁抢钱成就!","成就六",MB_OK);
		gold+=75;
		so_money=true;	
	}
	//加工结算
	if(player_iron<=player_metal_ore*10){
		player_metal+=player_iron;
		player_iron=0; 
	} 
	else{
		player_metal+=player_metal_ore*10;
		player_iron-=player_metal_ore*10; 
	}
	if(player_silicon<=player_chip_ore*10){
		player_chip+=player_silicon;
		player_silicon=0; 
	} 
	else{
		player_chip+=player_silicon_ore*10;
		player_silicon-=player_chip_ore*10; 
	}
	//物资清理，刷新 
	if(player_polymer<=player_eat*player_people){
		player_polymer=0; 
	} 
	else{
		player_polymer-=player_eat*player_people;
	}
	if(people_money<(player_order+player_hope)/2) {
		player_money+=people_money*player_people;
	}
	if(player_polymer==0){
		player_people-=1;
		player_hope-=25;
		player_order-=25;
		if(player_hope<10){
			player_people-=3;
		}
	} 
	if(player_hope>=50&&player_order>=50){
		player_people+=10;
	}
	if(player_hope<25){
		player_order-=50;
	}
	if(player_order<25){
		player_hope-=50;
	}
	player_iron+=player_iro_ore*10;
	player_silicon+=player_silicon_ore*3;
	//事件发生
	if(player_hope<=25){
		if(MessageBox(NULL," 群众们的希望极为低下,一些敌人密谋起来,决定推翻你的残暴统治,你决定:\n 1:(是)镇压叛变,秩序少量增加\n 2:(否)安抚民众,希望少量增加","暴动",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
		    player_order+=10;	
		}
		else{
			player_hope+=10;
		}
	} 
	if(player_order<=25){
		if(MessageBox(NULL," 城市里的秩序极为混乱,一些恐怖分子趁机作乱,在城里绑人,你决定:\n 1:(是)处死恐怖分子,秩序少量增加,人口减少3人\n 2:(否)不管不问,秩序少量减少","恐怖袭击",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
		    player_order+=10;	
		    player_people-=3; 
		}
		else{
			player_order-=10;
		}
	}
	if(player_polymer<10&&player_polymer>0){
		MessageBox(NULL," 一位官员忧心重重的找到你,食物已经撑不起几个月的消耗了","粮荒",MB_OK);
	}
	if(player_polymer==0){
		MessageBox(NULL," 粮仓已经空了,已经开始饿7死人了","粮捷",MB_OK);
	} 
	if(player_hope<=50&&player_hope>25){
		if(MessageBox(NULL," 两位工人喝醉了酒,耽误了工作,他们自愿加班作为补偿,你决定:\n 1:(是)处罚他们,秩序少量增加\n 2:(否)宽怨他们,希望少量增加","醉酒",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
		    player_order+=10; 
		}
		else{
			player_hope+=10;
		}
	}
	if(player_order<=50&&player_order>25){
		if(MessageBox(NULL," 一位工人持枪闯进了你的办公室,打死了1位官员,你决定:\n 1:(是)严查来历,秩序大量增加,人口减少2人\n 2:(否)关入监牢并体恤官员亲属,希望大量增加,人口减少一人","刺杀",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
		    player_order+=25;	
		    player_people-=2; 
		}
		else{
			player_hope+=25;
			player_people-=1;
		}
	}
	if(people_money>=(player_order+player_hope)/2){
		if(MessageBox(NULL,"由于税收过重，人民无法容忍，强烈要求降低税收，并给与补贴，你决定：\n 1:(是)答应要求，税收降到3，并给与每人10元补贴\n 2:(否)拒绝要求，秩序与希望大幅下降","税收危机",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
			people_money=3;
			player_money-=player_people*10;
		} 
		else{
			player_order-=(people_money-player_order/2);
			player_hope-=(people_money-player_hope/2);
		}
	} 
	else{}
} 

bool game_over(){
	//结局一:死亡
	if(player_people<=0){
		system("cls");
		printf("\a"); 
		system("color 4");
		cout<<"===>>> 死了! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 人死了! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 全都死了! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 曾今诺大的星球上 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 连渣都不剩了! <<<==="<<endl;
		Sleep(1000);
		system("cls");
		cout<<"##############"<<endl;
		cout<<"#            #"<<endl;
		cout<<"# GAME OVER! #"<<endl;
		cout<<"#            #"<<endl;
		cout<<"##############"<<endl;
		MessageBox(NULL,"解锁失败结局:死亡","结局一",MB_OK);
		return false;
	} 
	//结局二:人口大国 
	if(player_people>=250){
		printf("\a"); 
		system("cls");
		system("color 6");
		cout<<"===>>> 苏维埃苏联协会来到了你的帝国! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 他们祝贺你完成了国家交给你的任务! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你返回了你的祖国! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 并安度了晚年 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 成为了一代英雄! <<<==="<<endl;
		Sleep(1000);
		system("cls");
		cout<<"##############"<<endl;
		cout<<"#            #"<<endl;
		cout<<"#  GAME WIN! #"<<endl;
		cout<<"#            #"<<endl;
		cout<<"##############"<<endl;
		MessageBox(NULL,"解锁成功结局:英雄","结局二",MB_OK);
		return false;
	} 
	//结局三：暴政
	if(player_hope<=0&&player_order<=0){
		system("cls");
		printf("\a"); 
		system("color 4");
		cout<<"===>>> 叛乱 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 全球各地都发起了叛乱! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你自以为自己的秩序无人匹敌! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 直到革命的火种开始发热 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你们的国家也被推翻了! <<<==="<<endl;
		Sleep(1000);
		system("cls");
		cout<<"##############"<<endl;
		cout<<"#            #"<<endl;
		cout<<"# GAME OVER! #"<<endl;
		cout<<"#            #"<<endl;
		cout<<"##############"<<endl;
		MessageBox(NULL,"解锁失败结局:叛乱","结局三",MB_OK);
		return false;
	}
	//结局四：希望 
	if(player_hope>150&&player_order>=150){
		system("cls");
		printf("\a"); 
		system("color 6");
		cout<<"===>>> 庆典 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你的国家因为有着过度的业绩! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 被冷战生光委员会选为年度最佳国家! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你也因这骄人的业绩 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 被欢迎回国! <<<==="<<endl;
		Sleep(1000);
		system("cls");
		cout<<"##############"<<endl;
		cout<<"#            #"<<endl;
		cout<<"# GAME  WIN! #"<<endl;
		cout<<"#            #"<<endl;
		cout<<"##############"<<endl;
		MessageBox(NULL,"解锁胜利结局:亲民","结局四",MB_OK);
		return false;
	}  
	if(player_money<=0){
		system("cls");
		printf("\a"); 
		system("color 8");
		cout<<"===>>> 破产 <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 世界各地的经济危机开始作乱! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 国家政府财产亏空! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 所有的原因的矛头都指向你! <<<==="<<endl;
		Sleep(1000);
		cout<<"===>>> 你被逮捕了! <<<==="<<endl;
		Sleep(1000);
		system("cls");
		cout<<"##############"<<endl;
		cout<<"#            #"<<endl;
		cout<<"# GAME OVER! #"<<endl;
		cout<<"#            #"<<endl;
		cout<<"##############"<<endl;
		MessageBox(NULL,"解锁失败结局:破产","结局五",MB_OK);
		return false;
	}
}

bool good(){
	system("color 6");
	cout<<"####################"<<endl;
	cout<<"#     成就系统     #"<<endl;
	cout<<"####################"<<endl;
	cout<<"# 小国:人口达到50  #"<<endl;
	cout<<"# 奖励:25金豆 ["<<(little_home?"√":"×")<<"] #"<<endl;
	cout<<"# 中国:人口达到100 #"<<endl;
	cout<<"# 奖励:50金豆 ["<<(lb_home?"√":"×")<<"] #"<<endl;
	cout<<"# 大国:人口达到200 #"<<endl;
	cout<<"# 奖励:75金豆 ["<<(big_home?"√":"×")<<"] #"<<endl;
	cout<<"# 月光族:花光资金  #"<<endl;
	cout<<"# 奖励:50金豆 ["<<(noon_money?"√":"×")<<"] #"<<endl;
	cout<<"# 富翁:拥有1W资金  #"<<endl;
	cout<<"# 奖励:75金豆 ["<<(very_money?"√":"×")<<"] #"<<endl;
	cout<<"# 抢钱:税率999资金 #"<<endl;
	cout<<"# 奖励:75金豆 ["<<(so_money?"√":"×")<<"] #"<<endl;
	cout<<"####################"<<endl;
	system("pause"); 
}  

int close(){
	std::string exeName = "冷战·生光 正式版 1.0.6.exe";  // 带空格的程序名
	std::string command = "taskkill /F /IM \"" + exeName + "\"";  // 用引号包裹防止空格问题
	system(command.c_str());  // 转换为const char*传给system()
}

int control(){
	cout<<"##################"<<endl;
	cout<<"#    控制面板    #"<<endl;
	cout<<"##################"<<endl;
	cout<<"#   VIP用户:"<<(vip?"是":"否")<<"   #"<<endl; 
	cout<<"#  按下1开通VIP  #"<<endl;
	cout<<"##################"<<endl;
	cout<<"#  金币作弊:"<<(money?"开":"关")<<"   #"<<endl;
	cout<<"#  矿场作弊:"<<(ore?"开":"关")<<"   #"<<endl;
	cout<<"#  加工作弊:"<<(metal?"开":"关")<<"   #"<<endl;
	cout<<"# 按下2 3 4使用  #"<<endl;
	cout<<"##################"<<endl; 
	cout<<"#  锁定游戏:5键  #"<<endl;
	cout<<"#  查看用户:6键  #"<<endl;
	cout<<"#  退出游戏:7键  #"<<endl;
	cout<<"# 退出控制面板:8 #"<<endl;
	cout<<"##################"<<endl; 
	cin>>sg;
	switch(sg){
		case 1:
		if(MessageBox(NULL,"是否购买VIP?","购买界面",MB_YESNO|MB_ICONASTERISK)==IDYES){
			vip=true;
			MessageBox(NULL,"购买成功!","购买成功",MB_OK);
	    }
	    else{
	    	MessageBox(NULL,"购买取消!","购买失败",MB_OK);	
		}
		break;
		case 2:
		if(vip){
			if(!money){
				MessageBox(NULL,"已开启金币作弊模式","金币作弊",MB_OK);
				player_money=9999;
				money=true;
			} 
			else{
				MessageBox(NULL,"已关闭金币作弊模式","金币作弊",MB_OK);
				player_money=1000;
				money=false;
			}
		} 
		else{
			MessageBox(NULL,"未开通VIP(错误编码LG044)","错误",MB_OK|MB_ICONHAND);
		}
		break;
		case 3:
			if(vip){
				if(!ore){
					MessageBox(NULL,"已开启矿场作弊模式","矿场作弊",MB_OK);
					player_iron=99;
					ore=true;
				} 
				else{
					MessageBox(NULL,"已关闭矿场作弊模式","矿场作弊",MB_OK);
					player_money=1;
					ore=false;
				}
			} 
			else{
				MessageBox(NULL,"未开通VIP(错误编码LG045)","错误",MB_OK|MB_ICONHAND);
			}
		    break;
		case 4:
			if(vip){
				if(!metal){
					MessageBox(NULL,"已开启加工作弊模式","加工作弊",MB_OK);
					player_iro_ore=99;
					metal=true;
				} 
				else{
					MessageBox(NULL,"已关闭加工作弊模式","加工作弊",MB_OK);
					player_iro_ore=1;
					metal=false;
				}
			} 
			else{
				MessageBox(NULL,"未开通VIP(错误编码LG046)","错误",MB_OK|MB_ICONHAND);
			}
			break;
		case 5:
			cout<<"请输入锁屏密码->";
			cin>>key;
			system("cls");
			cout<<"请确认锁屏密码->";
			cin>>sg;
			if(sg==key){
				system("cls");
				MessageBox(NULL,"锁屏成功","锁屏",MB_OK);
				while(true){
					cout<<"输入密码(输入0忘记密码)"<<endl;
					cout<<"->"; cin>>sg;
					if(sg){
						if(sg!=key){
							MessageBox(NULL,"解屏失败","锁屏",MB_OK);
						}
						else{
							MessageBox(NULL,"解屏成功","锁屏",MB_OK);
							break;
						}
					} 
					else{
						cout<<"输入管理员密码->";cin>>sg;
						if(sg!=adminkey){
							MessageBox(NULL,"解屏失败","锁屏",MB_OK);
						}
						else{
							MessageBox(NULL,"解屏成功","锁屏",MB_OK);
							break;
						}
					}
				}  
			}
			else{
				MessageBox(NULL,"锁屏失败","失败",MB_OK|MB_ICONHAND); 
			}
			break;
		case 6:
			cout<<"##################"<<endl;
			cout<<"#    控制面板    #"<<endl;
			cout<<"##################"<<endl;
			printf("#   税率:%3d     #\n",people_money);
			cout<<"#  按下1修改税率 #"<<endl; 
			cout<<"##################"<<endl; 
			cout<<"#   用户名:"<<name<<"  #"<<endl;
			printf("#   金豆:%3d     #\n",gold);
			cout<<"#  成就系统:2键  #"<<endl; 
			cout<<"#  退出用户:3键  #"<<endl;
			cout<<"# 退出控制面板:4 #"<<endl;
			cout<<"##################"<<endl; 
			cin>>sg;
			switch(sg){
				case 1:
					cout<<"请输入税率:1~999"<<endl;
					cin>>sg;
					if(sg>0&&sg<1000){
						cout<<"更改成功!"<<endl;
						people_money=sg; 
					}
					else{
						cout<<"不在范围!"<<endl;
					}
	                break;
	            case 2:
	           		good(); 
					break;	
	            case 3:
	            	control();
	            	break;
	            case 4:
	            	break;
			}
			break;
		case 7:
			close();			 
			break;
		case 8:
		    break; 
		default:
			MessageBox(NULL,"输入错误(错误编码LG047)","错误",MB_OK|MB_ICONHAND);
	}
}

int play_game(){
	bool play=true;
	while(play){
		system("color 2");
		system("cls");
		system("mode con cols=80 lines=25");
		if(player_polymer==0){
			system("color C");
		}
		else if(player_people<10){
			system("color 4");
		}
		else if(player_money==0){
			system("color 5");
		}
	 	cout<<"##################################################################"<<endl;
		printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
		cout<<endl<<"##################################################################"<<endl;
		printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
		printf("# 预产: %3d  #             请选择你的操作:(按下7打开控制面板)    #\n",player_iro_ore*10);
		printf("# 硅矿: %2d个 #                    1:基地空间操作                 #\n",player_silicon_ore);
		printf("# 预产: %3d  #                    2:太空空间操作                 #\n",player_silicon_ore*3);
		printf("# 税收: %4d #                    3:法令条款操作                 #\n",people_money*player_people);
		printf("# 秩序: %3d  #                    4:外交购买操作                 #\n",player_order);
		printf("# 希望: %3d  #                    5:外交出售操作                 #\n",player_hope);
		cout<<"##############                    6:下一季度操作                 #"<<endl;
		cout<<"# LG公司出品                                                     #"<<endl;
		cout<<"##################################################################"<<endl;
		cout<<"->>";
		cin>>sg;
		cout<<endl;
		system("cls");
		switch(sg){
			case 1:
				home();
				break;
			case 2:
				space();
				break;
			case 3:
				decree();
				break;
			case 4:
				speak();
				break;
			case 5:
				speak2();
				break;
			case 6:
				last_day();
				break; 
			case 7:
				control();
				break; 
			default:
				MessageBox(NULL,"输入错误(错误编码LG001)","错误",MB_OK|MB_ICONHAND);
				cin.clear();   // 清除错误状态
        		// 清空缓冲区所有字符，直到遇到换行
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		play=game_over(); 
	}
	cout<<"====>>> 按下任意键回到主界面 <<<===="<<endl;
	system("pause");
}

int gengxin(){
	system("color E");
	system("cls");
	cout<<"########################\n";
	cout<<"#  冷战-生光III V1.0.7 #\n";
	cout<<"########################\n";
	cout<<"#   <V1.0.7更新日志>   #\n";
	cout<<"#   1.[新增]更新日志   #\n";
	cout<<"#   2.[新增]主界面     #\n";
	cout<<"#   3.[新增]赞助功能   #\n"; 
	cout<<"#   4.[新增]颜色特效   #\n"; 
	cout<<"########################\n";
	system("pause"); 
}

int zanzhu(){
	system("color 6");
	system("cls");
	system("start http://oj.52steam.run/d/XCXX/coin/gift");
	cout<<"########################\n";
	cout<<"#  冷战-生光III V1.0.7 #\n";
	cout<<"########################\n";
	cout<<"#    当前赞助人列表:   #\n";
	cout<<"#   1.                 #\n";
	cout<<"#   2.                 #\n";
	cout<<"#   3.                 #\n"; 
	cout<<"########################\n";
	cout<<"# 我的ID为222,别打错了 #\n";
	cout<<"########################\n";
	system("pause"); 
}

int play_initialize(){
	player_iron=player_iron_;
	player_polymer=player_polymer_;
	player_silicon=player_silicon_;
	player_metal=player_metal_;
	player_people=player_people_;
	player_chip=player_chip_;
	player_iro_ore=player_iro_ore_;
	player_silicon_ore=player_silicon_ore_;
	player_money=player_money_;
	player_order=player_order_;
	player_hope=player_hope_;
	player_metal_ore=player_metal_ore_;
	player_chip_ore=player_chip_ore_;
	player_eat=player_eat_;
	player_eat_ore=player_eat_ore_;
	player_mat=player_mat_;
	
	open_space=false;
	kill=false;
	food=false;
	kill2=false;
	food2=false;
	
	vip=false;
	money=false;
	ore=false;
	metal=false;
	
	key=0; 
	adminkey=20140901;
	
	people_money=10;
	play_game();
	return 0;
}

int play_again(){
	bool play=true;
	system("mode con cols=80 lines=25");
	while(play){
		system("cls");
		system("color B");
		cout<<"########################\n";
		cout<<"# 冷战·生光III V1.0.7 #\n";
		cout<<"########################\n";
		cout<<"#                      #\n";
		cout<<"#      1.新的游戏      #\n";
		cout<<"#      2.更新日志      #\n";
		cout<<"#      3.赞助我们      #\n";
		cout<<"#      4.退出游戏      #\n";
		cout<<"#                      #\n";
		cout<<"########################\n";
		cout<<"-->";
		cin>>sg;
		switch(sg){
			case 1:
				play_initialize();
				break;
			case 2:
				gengxin();
				break;
			case 3:
				zanzhu();
				break;
			case 4:
				play=false;
		}
		Sleep(1000);
		system("cls");
	}
	cout<<"<感谢使用> THANK YOU\n";
	return 0;
}

int main(){
	srand(time(0));
	system("mode con cols=19 lines=11");
	play_ago();	
	play_again();
	return 20140901; 
} 

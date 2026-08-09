#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<time.h>

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
	cout<<"##################"<<endl;
	Sleep(5000);
	system("cls");
	cout<<"##################"<<endl;
	cout<<"#                #"<<endl;
	cout<<"#   LG 三号game  #"<<endl;
	cout<<"#                #"<<endl;
	cout<<"##################"<<endl;
	Sleep(5000);
	system("cls");
	return 0;
}

int play_again(){
	cout<<"###############"<<endl;
	cout<<"#             #"<<endl;
	cout<<"# 开始战斗!!! #"<<endl;
	cout<<"#             #"<<endl;
	cout<<"###############"<<endl;
	Sleep(1000);
	system("cls");
}

int home(){
		cout<<"##################################################################"<<endl;
		printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
		cout<<endl<<"##################################################################"<<endl;
		printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
		printf("# 预产: %3d  #              请选择你的操作:(输入7退出)           #\n",player_iro_ore*10);
		printf("# 硅矿: %2d个 #          1:建造钢铁工厂 [花费50金属] [加工10铁]   #\n",player_silicon_ore);
		printf("# 预产: %3d  #          2:建造芯片工厂 [花费100金属] [加工10硅]  #\n",player_silicon_ore*3);
		printf("# 税收: %4d #      3:寻找新的铁矿 [花费50聚合物] [%50发现铁矿]  #\n",player_people*10);
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
				printf("# 税收: %4d #                最大加工量:%3d                     #\n",player_people*10,player_chip_ore*10);
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
		printf("# 税收: %4d #  3:发射火箭 [花费300金属,10个芯片] [发现1~3个硅矿]#\n",player_people*10);
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
	printf("# 税收: %4d # 3:酷刑(需解锁压迫)[降低希望提升秩序][暂无食物效果]#\n",player_people*10);
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
				player_polymer-=200;
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
	printf("# 税收: %4d #            3:10单位聚合物<=1单位物资              #\n",player_people*10);
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
	printf("# 税收: %4d #             3:50单位聚合物=>250资金               #\n",player_people*10);
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
	player_money+=player_people*10;
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
} 

bool game_over(){
	//结局一:死亡
	if(player_people<=0){
		printf("\a"); 
		system("cls");
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
}

int play_game(){
	bool play=true;
	while(play){
	 	cout<<"##################################################################"<<endl;
		printf("# 铁:%3d 硅:%3d 钢:%3d 芯片:%3d 聚合物:%3d # 资金:%3d 人口:%3d #",player_iron,player_silicon,player_metal,player_chip,player_polymer,player_money,player_people);
		cout<<endl<<"##################################################################"<<endl;
		printf("# 铁矿: %2d个 #                                                   #\n",player_iro_ore);
		printf("# 预产: %3d  #                    请选择你的操作:                #\n",player_iro_ore*10);
		printf("# 硅矿: %2d个 #                    1:基地空间操作                 #\n",player_silicon_ore);
		printf("# 预产: %3d  #                    2:太空空间操作                 #\n",player_silicon_ore*3);
		printf("# 税收: %4d #                    3:法令条款操作                 #\n",player_people*10);
		printf("# 秩序: %3d  #                    4:外交购买操作                 #\n",player_order);
		printf("# 希望: %3d  #                    5:外交出售操作                 #\n",player_hope);
		cout<<"##############                    6:下一季度操作                 #"<<endl;
		cout<<"# LG公司出品                                                     #"<<endl;
		cout<<"##################################################################"<<endl;
		cout<<"->>";
		cin>>sg;
		cout<<endl;
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
			default:
				MessageBox(NULL,"输入错误(错误编码LG001)","错误",MB_OK|MB_ICONHAND);
		}
		play=game_over(); 
	}
}

int main(){
	srand(time(0));
	play_ago();	
	play_again();
	play_game();
} 

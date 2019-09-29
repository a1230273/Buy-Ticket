#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

std::string GetStringBetweenTwoString(std::string s, std::string Start, std::string End){
	std::string strNew;
	if (s.find(Start)!=std::string::npos){
		unsigned first = s.find(Start);
		if (s.find(End)!=std::string::npos){
			unsigned last = s.find(End);
			strNew = s.substr (first + Start.length(),last-Start.length()-first);
	}else
		strNew = "not this skill";
	}else
	strNew = "not this skill";
	return strNew;
}

std::string buy_ticket(std::string station1, std::string station2){
	std::string strBuy;
	std::string strArr[] = {"南港","台北","桃園","新竹","苗栗","台中","彰化","雲林","嘉義","台南","高雄"};
	std::vector<std::string> strVec(strArr, strArr + 11);
for(int i = 0; i < strVec.size(); i++) {
    if(station1 == strArr[i]){
			for(int j = 0; j < strVec.size(); j++) {
				if(station2 == strArr[j]){
					strBuy = "Ticket get";
					return strBuy;
				}
			}strBuy = "station not exist";
			return strBuy;
		}
	}strBuy = "station not exist";
	return strBuy;
}

int main(void)
{
	printf("\n┎‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-----‐‐┑");
	printf("\n   使用說明：" );
	printf("\n   * 直接輸入：幫我訂xx站到xx站的高鐵票" );
	printf("\n   指令說明：" );
	printf("\n   * buy：買票" );
	printf("\n   * station：查看站名" );
	printf("\n   * exit：離開" );
	printf("\n┕‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-----‐‐‐‐┙");
	printf("\n\n請輸入指令>\n");

	char *line;
	char *args[80];
	std::string s;
	std::string str;

	while(1){
		fflush(stdout);
		getline(std::cin, s);
		line = (char*)s.c_str();
		if(strcmp(line, "") != 0){
			if(strcmp(line, "exit") == 0 ){
				exit(0);
			}
			else if(strcmp(line, "station") == 0 ){
				printf("南港,台北,桃園,新竹,苗栗,台中,彰化,雲林,嘉義,台南,高雄\n" );
			}
			else if(strcmp(line, "buy") == 0 ){

				printf("請輸入：幫我訂xx站到xx站的高鐵票\n" );
				getline(std::cin, str);

				std::string st = "幫我訂";
				std::string en = "站到";
				std::string st2 = "站到";
				std::string en2 = "站的高鐵票";

				std::string sta1 = GetStringBetweenTwoString(str, st, en);
				std::string sta2 = GetStringBetweenTwoString(str, st2, en2);

				if(sta1 == "not this skill" || sta2 == "not this skill"){
					std::cout << "not this skill" << '\n';
				}else{
					std::string output = buy_ticket(sta1,sta2);
					std::cout << output << '\n';
				}
			}
		}
	}
	return 0;
}

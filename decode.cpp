//TopCoder SRM 1, 300

#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> decode(std::string message) {
	std::vector<std::string> vec(2);
	int messageArr[message.length()];
	for(int i = 0; i < message.length(); i++) {
		messageArr[i] = message[i] - 48;
	}
	
	//Assume P[0] = 0
	int P[message.length()];
	P[0] = 0;
	std::string flag = "";
	
	for(int i = 0; i < message.length(); i++)	{
		if(i == message.length() - 1) {
			if(P[i] + P[i-1] != message[i]) {
				flag = "NONE";
				break;
			}
		} else if(i == 0) {
			P[1] = message[0] - P[0];
			if((P[1]) > 1) {
				flag = "NONE";
				break;
			}
		} else {
			P[i+1] = message[i] - P[i-1] - P[i];
			if(P[i+1] > 1) {
				flag = "NONE";
				break;
			}
		}
	}
	
	if(flag == "NONE") {
		vec[0] = "NONE";
	} else {
		for(int i = 0; i < message.length(); i++) {
			char c = P[i] + 48;
			vec[0][i] = c;
		}
	}
	
	flag = "";
	//Assume P[0] = 1
	P[0] = 1;
	for(int i = 0; i < message.length(); i++)	{
		if(i == message.length() - 1) {
			if(P[i] + P[i-1] != message[i]) {
				flag = "NONE";
				break;
			}
		} else if(i == 0) {
			P[1] = message[0] - P[0];
			if((P[1]) > 1) {
				flag = "NONE";
				break;
			}
		} else {
			P[i+1] = message[i] - P[i-1] - P[i];
			if(P[i+1] > 1) {
				flag = "NONE";
				break;
			}
		}
	}
	if(flag == "NONE") {
		vec[1] = "NONE";
	} else {
		for(int i = 0; i < message.length(); i++) {
			char c = P[i] + 48;
			vec[1][i] = c;
		}
	}
	
	return vec;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define NUM_OF_CHAT 10

using std::string;

class ReplyAdmin {
private:
	string* chats;
	int idx;

public:
	ReplyAdmin() {
		chats = new string[10];
		idx = 0;
	}

	~ReplyAdmin() {
		delete[] chats;
	}

	int getChatCount();
	string* Return_chat();
	void sorting(int del_s, int del_f); 
	void sorting(int del);
	bool addChat(string _chat);
	bool removeChat(int _index);
	bool removeChat(int* _indices, int _count);
	bool removeChat(int _start, int _end);
};

int ReplyAdmin::getChatCount(void) {
	return idx + 1;
}

string* ReplyAdmin::Return_chat() {
	return chats;
}

bool ReplyAdmin::addChat(string _chat) {
	if (idx == 10) {
		return false;
	}
	else {
		chats[idx] = _chat;
		idx++;
		return true;
	}
}

bool ReplyAdmin::removeChat(int _index) {
	if (idx >= _index) {
		chats[_index].clear();
		idx--;
		sorting(_index);
		return true;
	}
	else {
		return false;
	}
}

bool ReplyAdmin::removeChat(int* _indices, int _count) {
	int i;
	int flag = 0;
	for (i = 0; i < _count; i++) {
		if (chats[_indices[i]].empty() == false) {
			flag = 1;
			chats[_indices[i]].clear();
			sorting(_indices[i]);
			idx--;
		}
	}
	
	if (flag == 1) return true;
	else return false;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
	int i;
	if (idx < _start) {
		return false;
	}
	else {
		for (i = _start; i <= _end; i++) {
			chats[i].clear();
		}
		sorting(_start, _end);
		idx -= _end - _start + 1;
		return true;
	}
}

int main() {
	ReplyAdmin Admin;
	std::vector<int> remove_num;
	string chat;
	bool result;

	while (1) {
		std::getline(std::cin, chat);
		if (chat.find("#remove") == 0) {
			if (chat.length() == 9) {
				result = Admin.removeChat(atoi(chat.substr(8).c_str()));
			}

			else if (chat.find("-") == 9 ) {
				result = Admin.removeChat(atoi(chat.substr(8).c_str()), atoi(chat.substr(10).c_str()));
			}

			else {
				string num = chat.substr(8);
				int i;
				for (i = 0; i < num.size() + 1; i++) {
					if(i % 2 == 0)
						remove_num.push_back(atoi(num.substr(i,1).c_str()));
				}
				std::sort(remove_num.rbegin(), remove_num.rend());
				result = Admin.removeChat(remove_num.data(), remove_num.size());
			}

			if (result == false) {
				std::cout << "Error!\n";
			}

			else if (result == true) {
				int i;
				string* chat_list = Admin.Return_chat();
				for (i = 0; i < Admin.getChatCount() - 1; i++) {
					std::cout << i << ' ' << chat_list[i] << '\n';
				}
			}
		}

		else if (chat.find("#quit") == 0) {
			break;
		}

		else {
			Admin.addChat(chat);

			int i;
			string* chat_list = Admin.Return_chat();
			for (i = 0; i < Admin.getChatCount() - 1; i++) {
				std::cout << i << ' ' << chat_list[i] << '\n';
			}
		}
	}
}

void ReplyAdmin::sorting(int del_s, int del_f) {
	int i;
	int interval = del_f - del_s + 1;
	for (i = del_s + interval; i < idx; i++) {
		chats[i - interval] = chats[i];
	}
}

void ReplyAdmin::sorting(int del) {
	int i;
	for (i = del; i < idx; i++) {
		chats[i] = chats[i + 1];
	}
}

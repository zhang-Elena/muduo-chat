#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//json序列化实例1
string func1() {
	json js;
	js["msg_type"] = 2;
	js["from"] = "zhang san";
	js["to"] = "li si";
	js["msg"] = "hello, what are you doing";

	string sendBuf = js.dump();
	//cout << sendBuf.c_str() << endl;
	return sendBuf;
}

//json序列化实例2
string func2() {
	json js;
	//添加数组
	js["id"] = { 1,2,3,4,5 };
	//添加key-value
	js["name"] = "zhang san";
	//添加对象
	js["msg"]["zhang san"] = "hello world";
	js["msg"]["li si"] = "hello everyone";
	//上面等同于下面这句添加数组对象
	js["msg"] = { {"zhang san","hello world"}, {"li si","hello everyone"} };
	//cout << js << endl;
	return js.dump();

}

//json序列化实例3
string func3() {
	json js;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	js["list"] = vec;

	map<int, string> m;
	m.insert({ 1,"co" });
	m.insert({ 2,"jo" });
	m.insert({ 3,"ko" });

	js["path"] = m;

	//json数据对象 =》 序列化json字符串
	string sendbuf = js.dump();
	//cout << sendbuf.c_str() << endl;
	return sendbuf;
}

/*
int main() {
	string recvBuf1 = func1();
	//数据反序列化 json字符串=》反序列化 数据对象 （看作容器，方便访问）
	json jsbuf1 = json::parse(recvBuf1);

	cout << jsbuf1["msg_type"] << endl;
	cout << jsbuf1["to"] << endl;
	cout << jsbuf1["from"] << endl;
	cout << jsbuf1["msg"] << endl;

	string recvBuf2 = func2();
	//数据反序列化 json字符串=》反序列化 数据对象 （看作容器，方便访问）
	json jsbuf2 = json::parse(recvBuf2);

	cout << jsbuf2["id"] << endl;
	cout << jsbuf2["name"] << endl;
	cout << jsbuf2["msg"] << endl;
	auto msgjs = jsbuf2["msg"];
	cout << msgjs["zhang san"] << endl;


	string recvBuf3 = func3();
	//数据反序列化 json字符串=》反序列化 数据对象 （看作容器，方便访问）
	json jsbuf3 = json::parse(recvBuf3);

	vector<int> vec = jsbuf3["list"];
	for (auto& c : vec) {
		cout << c << ends;
	}
	cout << endl;

	map<int, string> mymap = jsbuf3["path"];
	for (auto& m : mymap) {
		cout << m.first << " " << m.second << endl;
	}
	return 0;
}
*/
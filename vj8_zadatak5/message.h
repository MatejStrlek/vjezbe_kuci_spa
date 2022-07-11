#pragma once
#include <string>
#include <sstream>

using namespace std;

struct message
{
	string text;
	int priority;
	message(string text, int priority) {
		this->text = text;
		this->priority = priority;
	}
	string to_string() const
	{
		stringstream ss;
		ss << priority << " - " << text;
		return ss.str();
	}
};

struct message_comparer_desc
{
	bool operator() (const message& m1, const message& m2) const
	{
		return m1.priority > m2.priority;
	}
};
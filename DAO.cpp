#include <fstream>
using namespace std;
DAO::DAO(string fileURL) {
	this.fileURL = fileURL;
}

T DAO::find(int id) {
	string line;
	ifstream file(fileURL);
	while(getline(file, line)) {
		if checkLine(id, line)
			return readObject(line);
	}
	return null;
}

vector<T> DAO::findAll() {
	T object;
	vector<T> objects;
	ifstream file(fileURL);
	while(getline(file, line)) {
		object = readObject(line);
		if (object != null)
			objects.push_back(object);
	}
	return objects;
}

void DAO::delete(T* object) {
	int id = object.getId();
	string dataLine = dataLine(id);
	removeLine(dataLine);
}

string DAO::dataLine(int id) {
	string line;
	ifstream file(fileURL);
	while(getline(file, line)) {
		if checkLine(id, line)
			return line;
	}
}


bool DAO::checkLine(int id, string line) {
	regex r(to_string(id) + "\\s.*");
	return regex_search(line, r);
}

T readObject(string line) {
// Implementado por la subclase
}

vector<string> separateWords(string command) {
	vector<string> words;
	stringstream ss(command);
	string word;
	while (ss >> word)
		words.push_back(word);
	return words;
}









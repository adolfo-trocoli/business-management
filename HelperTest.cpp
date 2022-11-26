#include "Helper.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;

unordered_map<string, string> loadConfiguration();

int main() {
	unordered_map<string, string> mapa = loadConfiguration();

	for (auto kv : mapa) {
		cout << kv.first << endl;
		cout << kv.second << endl << endl; 
	}
	cout << mapa.size() << endl;

	Helper h(mapa);
	h.help();
	h.help("add");
	h.help("delete");
	return 0;
}

unordered_map<string, string> loadConfiguration() {
    unordered_map<string, string> config_param_map;
    string fileURL = ".config";
    ifstream file(fileURL);
    string line;
    regex r("([\\w-_]+):([\\w.-_]*)");
    smatch m;
    while(getline(file, line)) {
        //if(line.at(0) == '#')
        //    continue;
        if(regex_search(line, m, r))
            config_param_map.insert({m[1], m[2]});
    }
    return config_param_map;
}

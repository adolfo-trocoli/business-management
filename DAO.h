#ifndef DAO_h
#define DAO_h
#include <string>
using namespace std;

/**
 * DAO template class used as a Persistence API to a simple database implemented
 * with a file text for each class that has to be persisted. It is an abstract
 * because some of the private helper functions must be implemented by a subclass 
 * specific to a type.
 * 
 */
template <class T>
class DAO {
	public:
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

		bool DAO::delete(T* object) {
			int id = object.getId();
			string dataLine = dataLine(id);
			if (dataLine == null) return false;
			return removeLine(dataLine);
		}

		/**
		 * Updates the state of the given object in the database.
		 * If the object doesn't exist, it creates it as a new one.
		 * */
		void update(T object) {
			int id = object.getId();
			string dataLine = dataLine(id);
			if (dataLine != null)
				removeLine(dataLine);
			writeObject(object);
		}

		void create (T object) {
			ofstream file(fileURL);
			file << object.print() << endl;
		}

	protected:
        string fileURL;
        loadData(string fileURL);
        virtual T readObject(string line) = 0;
        string dataLine(int id) {
        	string line;
        	ifstream file(fileURL);
        	while(getline(file, line)) {
        		if checkLine(id, line)
        			return line;
        	}
        }
        bool checkLine(int id, string line) {
        	regex r(to_string(id) + "\\s.*");
        	return regex_search(line, r);
        }
        vector<string> separateWords(string command) {
        	vector<string> words;
        	stringstream ss(command);
        	string word;
        	while (ss >> word)
        		words.push_back(word);
        	return words;
        }    
        bool removeLine(string dataLine) {
			ifstream file(fileURL);
		    ofstream temp;
		    temp.open("temp8647509834758.txt");
		    string line;
		    while (getline(file,line)) {
		        if (line != dataLine) {
		            temp << line << endl;
		        }
		    }
		    temp.close();
		    file.close();
		    remove(fileURL);
		    rename("temp8647509834758.txt", fileURL);
		}
		void writeObject(T object) {
			ofstream file(fileURL);
			file << object.print() << endl;
		}
};
#endif
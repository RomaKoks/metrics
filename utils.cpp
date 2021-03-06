#include "utils.h"
extern int SIZE;
void read_data_csv(string path, unordered_map<int, double> *data) {

    char delim;
    ifstream in;
    in.open(path, ifstream::in);

    string line, cell;
    in >> line;
    int ind;
    double val;

    if(line.find(',') != string::npos) delim = ',';
    if(line.find('\t') != string::npos) delim = '\t';
    if(line.find(';') != string::npos) delim = ';';

    int state = 0;
    while(!in.eof()) {
        in >> line;


        stringstream line_stream(line);
        while(getline(line_stream, cell, delim)) {

            if(state % 2 == 0) {
                try {
                ind = stoi(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Out of range";

                }
            } else {
                try {
                val = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data)[ind] = val;
            }

            state++;

        }

        if(cell.empty() && !line_stream) {

                cout<<"error:Empty cell "<< ind <<endl;
                throw "error:Empty cell";

            }
    }

    in.close();
}

void read_mapping(string path, unordered_map<string, double> *data) {

    char delim;
    ifstream in;
    in.open(path, ifstream::in);

    string line, cell;
    in >> line;
    string ind;
    double val;

    if(line.find(',') != string::npos) delim = ',';
    if(line.find('\t') != string::npos) delim = '\t';
    if(line.find(';') != string::npos) delim = ';';

    int state = 0;
    while(!in.eof()) {
        in >> line;


        stringstream line_stream(line);
        while(getline(line_stream, cell, delim)) {

            if(state % 2 == 0) {
                ind = cell;
            } else {
                try {
                val = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data)[ind] = val;
            }

            state++;

        }

        if(cell.empty() && !line_stream) {

                cout<<"error:Empty cell "<< ind <<endl;
                throw "error:Empty cell";

            }
    }

    in.close();
}

void read_data_coord(string path, unordered_map<string, coord> *data) {

    char delim;
    ifstream in;
    in.open(path, ifstream::in);

    string line, cell;
    in >> line;
    string ind;
    double x, y;
    if(line.find(',') != string::npos) delim = ',';
    if(line.find('\t') != string::npos) delim = '\t';
    if(line.find(';') != string::npos) delim = ';';

    int state = 0;
    while(!in.eof()) {
        in >> line;
        stringstream line_stream(line);
        while(getline(line_stream, cell, delim)) {
            if(state % 3 == 0) {
                try {
                ind = cell;
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Out of range";

                }
            } else if(state % 3 == 1) {
                try {
                x = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data)[ind].lat = x;
            } else {
                try {
                y = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data)[ind].lon = y;
            }

            state++;

        }

        if(cell.empty() && !line_stream) {

                cout<<"error:Empty cell"<<endl;
                throw "error:Empty cell";

            }
    }

    in.close();
}

void read_data_coord_2(string path, unordered_map<string, coord> *data1, unordered_map<string, coord> *data2) {

    char delim;
    ifstream in;
    in.open(path, ifstream::in);

    string line, cell;
    in >> line;
    string ind;
    double x, y;
    if(line.find(',') != string::npos) delim = ',';
    if(line.find('\t') != string::npos) delim = '\t';
    if(line.find(';') != string::npos) delim = ';';

    int state = 0;
    while(!in.eof()) {
        in >> line;
        stringstream line_stream(line);
        while(getline(line_stream, cell, delim)) {
            if(state % 5 == 0) {
                try {
                ind = cell;
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Out of range";

                }
            } else if(state % 5 == 1) {
                try {
                x = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data1)[ind].lat = x;
            } else if(state % 5 == 2) {
                try {
                y = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data1)[ind].lon = y;
            } else if(state % 5 == 3) {
                try {
                x = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data2)[ind].lat = x;
            } else {
                try {
                y = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";

                }
                (*data2)[ind].lon = y;
            }

            state++;

        }

        if(cell.empty() && !line_stream) {

                cout<<"error:Empty cell"<<endl;
                throw "error:Empty cell";

            }
    }

    in.close();
}

int* read_indexes(string path) {
    ifstream in;
    in.open(path, ifstream::in);
    int size, i = 0;
    int *ind;
    in >> size;
    ind = new int[size];

    for(int i = 0; i < size; i++) {
        in >> ind[i];
    }


    in.close();

    SIZE = size;
    return ind;
}

string* read_indexes_coords(string path) {
    ifstream in;
    in.open(path, ifstream::in);
    int size, i = 0;
    string *ind;
    in >> size;
    ind = new string[size];

    for(int i = 0; i < size; i++) {
        in >> ind[i];
    }


    in.close();

    SIZE = size;
    return ind;
}

void map_data(unordered_map<string, double> mapping, unordered_map<string, double> table, unordered_map<int, double> *transformed) {
    int idx;
    double val;
    for(auto it : table) {
        idx = mapping[it.first];
        (*transformed)[idx] = it.second;
    }
}

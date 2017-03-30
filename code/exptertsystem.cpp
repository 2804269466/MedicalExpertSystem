#include "expertsystem.h"

struct symptomIDInfo {
	int id;
	int type;
	int class_of_A;
};

struct diseaseIDInfo {
	int id;
	int level;
};


struct SystemCfVector {
	double evidence_cf[MAX_SYMPTOM_TYPE];
};


struct EvidenceSpecific {
	int evidence_specific_size;
	int evidence_specific[MAX_SYMPTOM_TYPE];
	map<string, SystemCfVector> secondlevelRule;
};



map<string, double> inputcf;// UI接口
map<string, double> inputdegree;
set<string> inputstr;
priority_queue<UIRes> ui_result;

map<string, diseaseIDInfo> diseaseID;//疾病编码
map<string, set<string>> diseaseType;//疾病类别树

map<string, symptomIDInfo> symptomID;//symptomName - (symptomType(A,S), symptomID)

map<string, EvidenceSpecific> secondlevel;//各科属规则库

int evidence_abstract_size = 0;//主病类数量
int evidence_abstract[MAX_SYMPTOM_TYPE] = { 0 };//第一层次分类主病症指标
map<string, SystemCfVector> firstlevelRule;//第一层分类的各项CF 如呼吸系统疾病 - [0.8,0.7……]

double FirstLevelThreshold;//归属度阈值
double SecondLevelThreshold;//结果值阈值

double user_abstract[MAX_SYMPTOM_TYPE];
double user_abstract_weight[MAX_SYMPTOM_TYPE];

double user_specific[MAX_SYMPTOM_TYPE];
double user_specific_weight[MAX_SYMPTOM_TYPE];

struct FirstLevelRes {
	string maindiseasename;
	double similarity;

	friend bool operator < (FirstLevelRes a, FirstLevelRes b) {
		return a.similarity > b.similarity;
	}
};

struct SecondLevelRes {
	string sdiseasename;
	double res_cf;
	
	friend bool operator < (SecondLevelRes a, SecondLevelRes b) {
		return a.res_cf > b.res_cf;
	}
};


priority_queue<FirstLevelRes> firstlevelres;//科属归属度
priority_queue<SecondLevelRes> secondlevelres;//疾病推断结果值

string wstr2str(const wstring &wstr)
{

    string result;
    int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
    char* buffer = new char[len + 1];
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
    buffer[len] = '\0';
    result.append(buffer);
    delete[] buffer;
    return result;

}

wstring str2wstr(const string& s)
{
    setlocale(LC_ALL, "chs");
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest, _Source, _Dsize);
    std::wstring result = _Dest;
    delete[]_Dest;
    setlocale(LC_ALL, "C");
    return result;
}

void ui_map_change(string symptom, double cf, double degree){
    if(cf < 0.000001 || degree < 0.000001){
        inputstr.erase(symptom);
    }
    else{
        inputstr.insert(symptom);
    }
    inputcf[symptom] = cf;
    inputdegree[symptom] = degree;
}

void ui_map_output(){
    cout << "total size : " << inputstr.size() << endl;
    set<string>::iterator iter;
    for(iter = inputstr.begin(); iter != inputstr.end(); iter++){
        string get_s = *iter;
        cout << get_s << "  " << inputcf[get_s] << "  " << inputdegree[get_s] << endl;
    }
}


bool read_symptomID(string filepath, string filename) {
	string symptomID_file = filepath + filename;

	ifstream symptomID_open(symptomID_file);
	if (!symptomID_open) {
		cout << "symptom.txt not exist" << endl;
		return false;
	}

	string get_line;
	getline(symptomID_open, get_line, '\n');
	getline(symptomID_open, get_line, '\n');
	getline(symptomID_open, get_line, '\n');
	int line_cnt = 0;
	while (getline(symptomID_open, get_line, '\n')) {
		if (get_line.length() <= 1) continue;
		int split_pos[4] = { 0 };
		int now_cnt = 0;
		for (int i = 0; i < get_line.length(); i++) {
			if (get_line[i] == '#') {
				split_pos[now_cnt++] = i;
				if (now_cnt == 4) break;
			}
		}

		string symptomName = get_line.substr(split_pos[0] + 1, split_pos[1] - split_pos[0] - 1);
		string symptomID_s = get_line.substr(split_pos[1] + 1, split_pos[2] - split_pos[1] - 1);
		int symptomID_i = atoi(symptomID_s.c_str());

		string symptomType_s;
		if (split_pos[3] == 0) {
			symptomType_s = get_line.substr(split_pos[2] + 1, get_line.length() - split_pos[2] - 1);
		}
		else {
			symptomType_s = get_line.substr(split_pos[2] + 1, split_pos[3] - split_pos[2] - 1);
		}

		string symptomClass_s;
		int symptomClass_i = -1;

		int symptomType_i = -1;
		if (symptomType_s == "S") {
			symptomType_i = SYMPTOM_SPECIFIC;
			symptomClass_s = get_line.substr(split_pos[3] + 1, get_line.length() - split_pos[3] - 1);
			symptomClass_i = atoi(symptomClass_s.c_str());
		}
		else {
			symptomType_i = SYMPTOM_ABSTRACT;
		}

		symptomIDInfo temp;
		temp.id = symptomID_i;
		temp.type = symptomType_i;
		temp.class_of_A = symptomClass_i;

		symptomID[symptomName] = temp;

		line_cnt++;
	}

	//cout << symptomID["头晕"].id << "   " << symptomID["头晕"].type << endl;
	symptomID_open.close();
	return true;
}

bool read_diseaseID(string filepath, string filename) {
	string diseaseID_file = filepath + filename;

	ifstream diseaseID_open(diseaseID_file);
	if (!diseaseID_open) {
		cout << "diseasaID.txt not exist!" << endl;
		return false;
	}
	string get_line;

	getline(diseaseID_open, get_line, '\n');
	int line_cnt = 0;
	while (getline(diseaseID_open, get_line, '\n')) {
		if (get_line.length() <= 1) continue;
		int split_pos[3] = { 0 };
		int now_cnt = 0;
		for (int i = 0; i < get_line.length(); i++) {
			if (get_line[i] == '#') {
				split_pos[now_cnt++] = i;
				if (now_cnt == 3) break;
			}
		}

		string diseaseID_s = get_line.substr(split_pos[1] + 1, split_pos[2] - split_pos[1] - 1);
		int diseaseID_i = atoi(diseaseID_s.c_str());
		//cout << diseaseID_i << endl;
		string diseaseName_s = get_line.substr(split_pos[0] + 1, split_pos[1] - split_pos[0] - 1);

		string diseaseLevel_s = get_line.substr(split_pos[2] + 1, get_line.length() - split_pos[2] - 1);
		int diseaseLevel_i = atoi(diseaseLevel_s.c_str());

		//cout << diseaseName_s << endl;

		diseaseIDInfo temp;
		temp.id = diseaseID_i;
		temp.level = diseaseLevel_i;

		diseaseID[diseaseName_s] = temp;
		line_cnt++;
	}

	//cout << "Disease Size : " << diseaseID.size() << endl;
	diseaseID_open.close();
	return true;
}

bool read_diseaseType(string filepath, string filename) {
	string diseaseType_file = filepath + filename;

	ifstream diseaseType_open(diseaseType_file);
	if (!diseaseType_open) {
		cout << "diseaseType.txt not exist!" << endl;
		return false;
	}

	int line_cnt = 0;
	string get_line;
	getline(diseaseType_open, get_line, '\n');

	while (getline(diseaseType_open, get_line, '\n')) {
		if (get_line.length() <= 1) continue;

		int split_pos[4];
		int now_cnt = 0;
		for (int i = 0; i < get_line.length(); i++) {
			if (get_line[i] == '#') {
				split_pos[now_cnt++] = i;
				if (now_cnt == 4) break;
			}
		}

		//cout << get_line << endl;
		string diseaseName = get_line.substr(split_pos[0] + 1, split_pos[1] - split_pos[0] - 1);
		string diseaseID_s = get_line.substr(split_pos[1] + 1, split_pos[2] - split_pos[1] - 1);
		int diseaseID_i = atoi(diseaseID_s.c_str());
		string diseaseName_f = get_line.substr(split_pos[2] + 1, split_pos[3] - split_pos[2] - 1);
		string diseaseID_f_s = get_line.substr(split_pos[3] + 1, get_line.length() - split_pos[3] - 1);
		int diseaseID_f_i = atoi(diseaseID_f_s.c_str());

		if (diseaseID_f_s.length() > 0 && diseaseName_f.length() > 0) {
			diseaseType[diseaseName_f].insert(diseaseName);
		}

		line_cnt++;
	}

	diseaseType_open.close();
	return true;
}

bool read_rule_A(string filepath, string filename) {

	string rule_A_file = filepath + filename;

	ifstream rule_A_open(rule_A_file);

	if (!rule_A_open) {
		cout << "disease_symptom_A.txt not exist!" << endl;
		return false;
	}
	string get_line;
	getline(rule_A_open, get_line, '\n');
	//int evidence_size = 0;
	//int evidence_id[MAX_SYMPTOM_TYPE];
	getline(rule_A_open, get_line, '\n');//得到各Abstract类ID

	boost::regex e("[0-9]+");//正则匹配各ID
	std::string::const_iterator start, end;
	start = get_line.begin();
	end = get_line.end();
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;

	while (boost::regex_search(start, end, what, e, flags)) {
		string temp_id = string(what[0].first, what[0].second);
		int temp_id_i = atoi(temp_id.c_str());
		
		evidence_abstract[evidence_abstract_size++] = temp_id_i;
		start = what[0].second;
	}

	//cout << evidence_abstract_size << endl;
	while (getline(rule_A_open, get_line, '\n')) {
		int split_pos[2] = { 0 };
		int split_size = 0;
		for (int i = 0; i < get_line.length(); i++) {
			if (get_line[i] == '#') {
				split_pos[split_size++] = i;
				if (split_size == 2) {
					break;
				}
			}
		}
		string main_disease_name = get_line.substr(split_pos[0] + 1, split_pos[1] - split_pos[0] - 1);
		//cout << main_disease_name << endl;
		string abstract_vector = get_line.substr(split_pos[1] + 1, get_line.length() - split_pos[1] - 1);

		boost::regex e_("[0-9.]+");//正则匹配各cf
		std::string::const_iterator start_, end_;
		start_ = abstract_vector.begin();
		end_ = abstract_vector.end();
		boost::match_results<std::string::const_iterator> what_;
		boost::match_flag_type flags_ = boost::match_default;

		int temp_evidence_size = 0;
		SystemCfVector temp_vector;
		while (boost::regex_search(start_, end_, what_, e_, flags_)) {
			string temp = string(what_[0].first, what_[0].second);
			double temp_cf = atof(temp.c_str());
			temp_vector.evidence_cf[temp_evidence_size++] = temp_cf;
			start_ = what_[0].second;
		}

		firstlevelRule[main_disease_name] = temp_vector;

	}

	rule_A_open.close();
	return true;
}

bool read_rule_S(string filepath, string filename) {
	string rule_S_file = filepath + filename;

	ifstream rule_S_open(rule_S_file);
	if (!rule_S_open) {
		cout << "disease_symptom_S.txt not exist!" << endl;
		return false;
	}
	string get_line;
	int flag_find = 0;

	string now_disease;
	EvidenceSpecific temp;
	while (getline(rule_S_open, get_line, '\n')) {
		if (get_line.length() <= 1) continue;
		if (get_line[0] == '#' && get_line[1] == '#') {
			flag_find++;
			if (flag_find == 1) {
				memset(temp.evidence_specific, 0, MAX_SYMPTOM_TYPE);
				temp.evidence_specific_size = 0;
				temp.secondlevelRule.clear();
			}

			else if (flag_find == 2) {
				int split_pos[3] = { 0 };
				int split_size = 0;
				for (int i = 0; i < get_line.length(); i++) {
					if (get_line[i] == '#') {
						split_pos[split_size++] = i;
						if (split_size == 3) {
							break;
						}
					}
				}

				string diseaseName = get_line.substr(split_pos[1] + 1, split_pos[2] - split_pos[1] - 1);
				now_disease = diseaseName;
				secondlevel[diseaseName] = temp;


				boost::regex e("[0-9]+");//正则匹配各ID
				std::string::const_iterator start, end;
				start = get_line.begin();
				end = get_line.end();
				boost::match_results<std::string::const_iterator> what;
				boost::match_flag_type flags = boost::match_default;

				while (boost::regex_search(start, end, what, e, flags)) {//读取各详细症状ID
					string temp_id = string(what[0].first, what[0].second);
					int temp_id_i = atoi(temp_id.c_str());

					secondlevel[now_disease].evidence_specific[secondlevel[now_disease].evidence_specific_size++] = temp_id_i;

					start = what[0].second;
				}

				flag_find = 0;
			}

			continue;
		}

		int split_pos[2];
		int split_size = 0;
		for (int i = 0; i < get_line.length(); i++) {
			if (get_line[i] == '#') {
				split_pos[split_size++] = i;
				if (split_size == 2) break;
			}
		}

		string sdiseaseName = get_line.substr(split_pos[0] + 1, split_pos[1] - split_pos[0] - 1);

		boost::regex e_("[0-9.]+");//正则匹配各具体疾病（如高血压)cf
		std::string::const_iterator start_, end_;
		start_ = get_line.begin();
		end_ = get_line.end();
		boost::match_results<std::string::const_iterator> what_;
		boost::match_flag_type flags_ = boost::match_default;

		int cf_size = 0;
		while (boost::regex_search(start_, end_, what_, e_, flags_)) {
			string get_cf = string(what_[0].first, what_[0].second);
			double get_cf_f = atof(get_cf.c_str());

			secondlevel[now_disease].secondlevelRule[sdiseaseName].evidence_cf[cf_size] = get_cf_f;
			//cout << secondlevel[now_disease].secondlevelRule[sdiseaseName].evidence_cf[cf_size] << endl;
			cf_size++;
			//system("pause");
			start_ = what_[0].second;
		}
	}


	rule_S_open.close();
	return true;
}

int system_prepare() {
	bool diseaseID_flag = read_diseaseID("", "diseaseID.txt");
	if (!diseaseID_flag) {
		cout << "system error!" << endl;
		return -1;
	}

	bool diseaseType_flag = read_diseaseType("", "diseaseType.txt");
	if (!diseaseType_flag) {
		cout << "system error!" << endl;
		return -1;
	}

	bool symptomID_flag = read_symptomID("", "symptom.txt");
	if (!symptomID_flag) {
		cout << "system error!" << endl;
		return -1;
	}

	bool rule_A_flag = read_rule_A("", "disease_symptom_A.txt");
	if (!rule_A_flag) {
		cout << "system error!" << endl;
		return -1;
	}

	bool rule_S_flag = read_rule_S("", "disease_symptom_S.txt");
	if (!rule_S_flag) {
		cout << "system error!" << endl;
		return -1;
	}
	return 0;
}


void user_interface() {

	string input_str[MAX_SYMPTOM_TYPE];
    double temp_weight_vector[MAX_SYMPTOM_TYPE];
    int input_size = inputstr.size();

    set<string>::iterator iter;
    int temp_cnt = 0;
    for(iter = inputstr.begin(); iter != inputstr.end(); iter++){
        input_str[temp_cnt] = *iter;
        temp_weight_vector[temp_cnt] = inputcf[*iter] * inputdegree[*iter];
        temp_cnt++;
    }


	// get user abstract
	for (int i = 0; i< input_size; i++) {
		string now_symptom = input_str[i];
		int class_A = symptomID[now_symptom].class_of_A;
		
		int find_pos = -1;
		for (int j = 0; j < evidence_abstract_size; j++) {
			if (evidence_abstract[j] == class_A) {
				find_pos = j;
				break;
			}
		}

		if (find_pos != -1) {
			user_abstract[find_pos] = 1;
			if (user_abstract_weight[find_pos] < 0.00001) {
				user_abstract_weight[find_pos] = temp_weight_vector[i];
			}
			else {
				user_abstract_weight[find_pos] = sqrt((user_abstract_weight[find_pos] * user_abstract_weight[find_pos] + temp_weight_vector[i] * temp_weight_vector[i]) / 2);
			}
		}


	}
	
	//计算第一层的相似度
	map<string, SystemCfVector>::iterator iter_;
	for (iter_ = firstlevelRule.begin(); iter_ != firstlevelRule.end(); iter_++) {
		string now_cal_disease = iter_->first;

		double Mole = 0;
		double Deno_1 = 0;
		double Deno_2 = 0;
		for (int i = 0; i < evidence_abstract_size; i++) {
			Mole += firstlevelRule[now_cal_disease].evidence_cf[i] * user_abstract_weight[i];
			Deno_1 += firstlevelRule[now_cal_disease].evidence_cf[i] * firstlevelRule[now_cal_disease].evidence_cf[i];
			Deno_2 += user_abstract_weight[i] * user_abstract_weight[i];
		}

		//??????? not decide Z
		double Sim_Res = Mole / (sqrt(Deno_1));

		FirstLevelRes temp_res;
		temp_res.maindiseasename = now_cal_disease;
		temp_res.similarity = Sim_Res;

		firstlevelres.push(temp_res);

		while (!firstlevelres.empty()) {
			//计算第二层cf值
			FirstLevelRes get_head = firstlevelres.top();
			cout << get_head.maindiseasename << "   " << get_head.similarity << endl;

			//大于进入第二层的阈值

			if (get_head.similarity > FirstLevelThreshold) {
				double now_similarity = get_head.similarity;
				string now_main = get_head.maindiseasename;
				
				EvidenceSpecific now_second = secondlevel[now_main];
				
				//reset user specific
				for (int i = 0; i < now_second.evidence_specific_size; i++) {
					user_specific[i] = 0;
					user_specific_weight[i] = 0;
				}

				//get user specific
				for (int i = 0; i < input_size; i++) {
					string find_str = input_str[i];
					int now_symptom_id = symptomID[find_str].id;

					int find_pos = -1;
					for (int j = 0; j < now_second.evidence_specific_size; j++) {
						if (now_second.evidence_specific[j] == now_symptom_id) {
							find_pos = j;
							break;
						}
					}

					if (find_pos != -1) {
						user_specific[find_pos] = 1;
						user_specific_weight[find_pos] = temp_weight_vector[i];
					}

				}

				map<string, SystemCfVector>::iterator iter_cal;//对于now_main范围内每种具体的病计算其cf值
				for (iter_cal = now_second.secondlevelRule.begin(); iter_cal != now_second.secondlevelRule.end(); iter_cal++) {
					int both_legal_cnt = 0;
					int max_leagal_cnt = 0;
					double D_MIN = 100000;
					for (int k = 0; k < now_second.evidence_specific_size; k++) {
						if (iter_cal->second.evidence_cf[k] > 0.000001) {
							max_leagal_cnt++;
							if (user_specific_weight[k] > 0.000001) {
								both_legal_cnt++;
								if ((iter_cal->second.evidence_cf[k] * user_specific_weight[k]) < D_MIN) {
									D_MIN = iter_cal->second.evidence_cf[k] * user_specific_weight[k];
								}
							}
						}

					}
					//??????? not decide
					double this_rule_cf = 0.5 + 0.5 * (both_legal_cnt * 1.0) / max_leagal_cnt;
					if (D_MIN != 100000) {
						D_MIN = D_MIN * this_rule_cf * now_similarity;

						SecondLevelRes new_second_res;
						new_second_res.res_cf = D_MIN;
						new_second_res.sdiseasename = iter_cal->first;

						secondlevelres.push(new_second_res);
					}
				}
			}
			firstlevelres.pop();
		}

	}
}

void view_result() {
    cout << "view result" << endl;
	while (!secondlevelres.empty()) {
		SecondLevelRes get_head = secondlevelres.top();
        UIRes get_res;
        if(get_head.res_cf > VERY){
            get_res.possibility = TYPE_VERY;
            get_res.sdiseasename = get_head.sdiseasename;
            ui_result.push(get_res);
        }
        else if(get_head.res_cf > PROBABLY){
            get_res.possibility = TYPE_PROBABLY;
            get_res.sdiseasename = get_head.sdiseasename;
            ui_result.push(get_res);
        }
        else if(get_head.res_cf > NOTLIKELY){
            get_res.possibility = TYPE_NOTLIKELY;
            get_res.sdiseasename = get_head.sdiseasename;
            ui_result.push(get_res);
        }
		cout << get_head.sdiseasename << "  " << get_head.res_cf << endl;

		secondlevelres.pop();
	}
}

priority_queue<UIRes> ui_res_map(){
    return ui_result;
}

void reset_environment(){
    inputcf.clear();
    inputdegree.clear();
    inputstr.clear();

    while(!ui_result.empty()){
        ui_result.pop();
    }

    for(int i = 0; i < MAX_SYMPTOM_TYPE; i++){
        user_abstract[i] = 0;
        user_abstract_weight[i] = 0;
        user_specific[i] = 0;
        user_specific_weight[i] = 0;
    }

    while(!firstlevelres.empty()){
        firstlevelres.pop();
    }

    while(!secondlevelres.empty()){
        secondlevelres.pop();
    }

}

/*int main() {
	
	system_prepare();

	user_interface();

	view_result();
    //map<string, symptomIDInfo>::iterator iter;
    //for (iter = symptomID.begin(); iter != symptomID.end(); iter++) {
        //cout << "  " << iter->first << "  " << iter->second.id << "  " << iter->second.type << "  " << iter->second.class_of_A << endl;
//	}

	system("pause");
	return 0;
}*/

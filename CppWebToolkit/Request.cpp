#include "Request.h"



Request::Request(){}


Request::~Request(){}

void Request::GetEnv(){
	long content_len = 0;
	char* query_cstr;
	char* method;
	char* str_len;
	char* str_post;
	size_t len = 0;
	string val1;
	string val2;
	string req_method_get;
	string req_method_post;
	String q_str;
	vector<String*> pairs;
	vector<String*> kv;
	map<string, string> getMap;

	method = getenv("REQUEST_METHOD");
	query_cstr = getenv("QUERY_STRING");

	req_method_get = "GET";
	req_method_post = "POST";

	if(req_method_get.compare(method) == 0){
		if(query_cstr != nullptr){
			q_str = String(query_cstr);
			if(q_str.contains(&String("&"))){

				pairs = q_str.split('&');

				len = pairs.size();
				for(size_t i = 0; i < len; i++){
					kv = pairs[i]->split(&String("="));

					val1 = UriDecode(kv[0]->getStringValue());
					val2 = UriDecode(kv[1]->getStringValue());

					getMap.insert(pair<string, string>(val1, val2));
				}
			} else{
				kv = q_str.split(&String("="));

				val1 = UriDecode(kv[0]->getStringValue());
				val2 = UriDecode(kv[1]->getStringValue());

				getMap.insert(pair<string, string>(val1, val2));
			}

			get_kvs = getMap;
		}
	} else if(req_method_post.compare(method) == 0){
		str_len = getenv("CONTENT_LENGTH");
		content_len = atol(str_len);

		str_post = new char[content_len + 1];
		fgets(str_post, content_len + 1, stdin);

		if(str_post != nullptr){
			q_str = String(str_post);
			if(q_str.contains(&String("&"))){

				pairs = q_str.split('&');

				len = pairs.size();
				for(size_t i = 0; i < len; i++){
					kv = pairs[i]->split(&String("="));

					val1 = UriDecode(kv[0]->getStringValue());
					val2 = UriDecode(kv[1]->getStringValue());

					getMap.insert(pair<string, string>(val1, val2));
				}
			} else{
				kv = q_str.split(&String("="));

				val1 = UriDecode(kv[0]->getStringValue());
				val2 = UriDecode(kv[1]->getStringValue());

				getMap.insert(pair<string, string>(val1, val2));
			}

			post_kvs = getMap;
		}
	}


}

GET Request::GetValues(){
	GET g;

	g.setMap(this->get_kvs);

	return g;
}

POST Request::PostValues(){
	POST p;

	p.setMap(this->post_kvs);

	return p;
}

std::string Request::UriDecode(const std::string & sSrc){
	// Note from RFC1630: "Sequences which start with a percent
	// sign but are not followed by two hexadecimal characters
	// (0-9, A-F) are reserved for future extension"

	const unsigned char * pSrc = (const unsigned char *)sSrc.c_str();
	const int SRC_LEN = sSrc.length();
	const unsigned char * const SRC_END = pSrc + SRC_LEN;
	// last decodable '%' 
	const unsigned char * const SRC_LAST_DEC = SRC_END - 2;

	char * const pStart = new char[SRC_LEN];
	char * pEnd = pStart;

	while(pSrc < SRC_LAST_DEC){
		if(*pSrc == '%'){
			char dec1, dec2;

			dec1 = *(pSrc + 1) & 0xF0 >> 4;
			dec2 = *(pSrc + 2) & 0x0F >> 0;

			if(-1 != dec1 && -1 != dec2){
				*pEnd++ = (dec1 << 4) + dec2;
				pSrc += 3;
				continue;
			}
		}

		*pEnd++ = *pSrc++;
	}

	// the last 2- chars
	while(pSrc < SRC_END)
		*pEnd++ = *pSrc++;

	std::string sResult(pStart, pEnd);
	delete[] pStart;
	return sResult;
}

string dec2hex(unsigned long long i){
	stringstream ss;
	ss << hex << uppercase << i;
	//ss << hex << lowercase << i;
	//ss << showbase << hex << lowercase << i; //prepends 0x
	//string s; ss >> s; return s; //alternate way to extract string
	return ss.str();
}

string dec2hex_c(unsigned int i) //has limit of 32 bit integer
{
	char s[20];
	sprintf(s, "%X", i);//uppercase
						//sprintf(s, "%x", i);//lowercase
	return string(s);
}
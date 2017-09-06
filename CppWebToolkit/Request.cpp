#pragma once
#include "Request.h"

namespace dnc{
	namespace Web{

		Request::Request(){}


		Request::~Request(){}

		std::string Request::ToString() {
			return std::string("System.Web.Request");
		}

		std::string Request::GetTypeString() {
			return std::string("Request");
		}

		void Request::GetEnv(){
			long content_len = 0;
			char* query_cstr;
			char* method;
			char* str_len;
			char* str_post;
			size_t len = 0;
			std::string val1;
			std::string val2;
			std::string req_method_get;
			std::string req_method_post;
			String q_str;
			Collections::Generic::List<String> pairs;
			Collections::Generic::List<String> kv;
			std::map<std::string, std::string> getMap;

			method = getenv("REQUEST_METHOD");
			query_cstr = getenv("QUERY_STRING");

			req_method_get = "GET";
			req_method_post = "POST";

			if(req_method_get.compare(method) == 0){
				if(query_cstr != nullptr){
					q_str = query_cstr;
					if(q_str.Contains("&")){

						pairs = q_str.Split('&');

						len = pairs.Count();
						for(size_t i = 0; i < len; i++){
							kv = pairs[i].Split("=");

							val1 = UriDecode(kv[0].GetStringValue());
							val2 = UriDecode(kv[1].GetStringValue());

							getMap.insert(std::pair<std::string, std::string>(val1, val2));
						}
					} else{
						kv = q_str.Split(&String("="));

						val1 = UriDecode(kv[0].GetStringValue());
						val2 = UriDecode(kv[1].GetStringValue());

						getMap.insert(std::pair<std::string, std::string>(val1, val2));
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
					if(q_str.Contains("&")){

						pairs = q_str.Split('&');

						len = pairs.Count();
						for(size_t i = 0; i < len; i++){
							kv = pairs[i].Split("=");

							val1 = UriDecode(kv[0].GetStringValue());
							val2 = UriDecode(kv[1].GetStringValue());

							getMap.insert(std::pair<std::string, std::string>(val1, val2));
						}
					} else{
						kv = q_str.Split(&String("="));

						val1 = UriDecode(kv[0].GetStringValue());
						val2 = UriDecode(kv[1].GetStringValue());

						getMap.insert(std::pair<std::string, std::string>(val1, val2));
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

		std::string dec2hex(unsigned long long i){
			std::stringstream ss;
			ss << std::hex << std::uppercase << i;
			//ss << hex << lowercase << i;
			//ss << showbase << hex << lowercase << i; //prepends 0x
			//string s; ss >> s; return s; //alternate way to extract string
			return ss.str();
		}

		std::string dec2hex_c(unsigned int i) //has limit of 32 bit integer
		{
			char s[20];
			sprintf(s, "%X", i);//uppercase
								//sprintf(s, "%x", i);//lowercase
			return std::string(s);
		}
	}
}
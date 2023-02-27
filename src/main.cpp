// #include <nlohmann/json.hpp>
// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <curl/curl.h>
// using namespace std;

// using json = nlohmann::json;


// static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
// {
//     ((std::string*)userp)->append((char*)contents, size * nmemb);
//     return size * nmemb;
// }

// string getUrl(const char *x)
// {
// 	CURL *curl;
// 	CURLcode res;
// 	string readBuffer;

// 	curl = curl_easy_init();
// 	if(curl) {
// 		curl_easy_setopt(curl, CURLOPT_URL, x);
// 		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
// 		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
// 		res = curl_easy_perform(curl);
// 		curl_easy_cleanup(curl);

// 		// std::cout << readBuffer << std::endl;
// 	}
// 	return readBuffer;
// }

// int main()
// {
//     string symbol = "AAPL";
//     // cout << "Enter the symbol: ";
//     // cin >> symbol;
//     string fname = symbol + ".json";

// 	// ifstream t("data.json");
// 	// stringstream buffer;
// 	// buffer << t.rdbuf();
// 	string buffer = getUrl(("https://query2.finance.yahoo.com/v7/finance/options/" + symbol).c_str());  // ^SPX

// 	json j_complete = json::parse(buffer);
// 	// cout << setw(4) << j_complete << endl;

// 	ofstream myfile(fname);
// 	if (myfile.is_open())
// 	{
// 		myfile << setw(4) << j_complete << endl;
// 	}

// 	json result = j_complete["optionChain"]["result"][0];
// 	json expirationDates = result["expirationDates"];
// 	json strikes = result["strikes"];
// 	json calls = result["options"][0]["calls"];
// 	json puts = result["options"][0]["puts"];

// 	cout << setw(4) << calls << endl;
// 	// cout << setw(4) << puts << endl;

// 	// cout <<  << endl;
	

// 	return 0;
// }

#include <iostream>

int main()
{
	int x = 1;
	int y = 2;
	std::cout << x + y << std::endl;
	return 0;
}
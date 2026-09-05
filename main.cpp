#include "utils/logger.h"
#include <array>
#include "utils/rng.h"
#include <vector>
#include <cstdint>
#include <iostream>

//note: Eswatini used to be called Swaziland
//note: Cabo Verde also has been called Cape Verde but it is an old name for it which was used in english, instead Cabo Verde should be used over Cape Verde
//note: Myanamar used to be called Burma, (its old name is Burma)

namespace {

	typedef std::array<std::string, 3> capitals_t; /*[04/09/2026] no country has more than 3 capitals hence make the array size 3*/

	const std::array<std::string, 197> k_countries = { "Zimbabwe","Zambia","Yemen","Venezuela","Vietnam","Vatican City","Vanuatu","Uzbekistan","Uruguay","United States of America", "United Kingdom","United Arab Emirates","Ukraine","Uganda","Tuvalu","Thailand","Tajikistan","Turkmenistan","Turkey","Tunisia","Trinidad and Tobago","Tonga","Togo","Tanzania","Taiwan","Timor-Leste","The Gambia","Serbia","Saudi Arabia","Slovakia","Slovenia","Spain","South Korea","South Africa","South Sudan","Sudan","Syria","Suriname","Sierra Leone","Singapore","Switzerland","Sweden","Sri Lanka","Saint Kitts and Nevis","Saint Lucia", "Saint Vincent and the Grenadines", "Samoa", "San Marino", "Sao Tome and Principe","Senegal","Seychelles","Solomon Islands", "Somalia", "Russia","Republic of the Congo","Romania","Rwanda", "Qatar","Pakistan","Palau","Palestine","Panama","Papua New Guinea","Paraguay","Peru","Portugal","Poland","Philippines","Oman","Namibia","Nauru","Nepal","Netherlands","New Zealand","Nicaragua","Niger","Nigeria","North Korea","North Macedonia","Norway","Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall Islands","Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montenegro","Morocco","Mozambique","Myanmar","Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Kazakhstan","Kenya","Kiribati","Kosovo","Kuwait","Kyrgyzstan","Jamaica","Japan","Jordan","Iceland","India","Indonesia","Iran","Iraq","Ireland","Israel","Italy","Ivory Coast","Haiti","Honduras","Hungary","Gabon","Georgia","Germany","Ghana","Greece","Grenada","Guatemala","Guinea","Guinea-Bissau","Guyana","Fiji","Finland","France","Ecuador","Egypt","El Salvador","Equatorial Guinea","Eritrea","Eswatini","Ethiopia","Estonia","Denmark","Djibouti","Dominica","Dominican Republic","Democratic Republic of the Congo","Cabo Verde","Cambodia","Cameroon","Canada","Central African Republic","Chad","Chile","China","Colombia","Comoros","Costa Rica","Croatia","Cuba","Cyprus","Czechia","Bahamas","Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bhutan","Bolivia","Bosnia and Herzegovina","Botswana","Brazil","Brunei","Bulgaria","Burkina Faso","Burundi","Afghanistan","Albania","Algeria","Andorra","Angola","Antigua and Barbuda","Argentina","Armenia","Australia","Austria","Azerbaijan" };
	
	const std::array<capitals_t, 197> k_capitals = { capitals_t{"Harare", "", ""}, capitals_t{"Lusaka", "", ""}, capitals_t{"Sanaa", "", ""}, capitals_t{"Caracas", "", ""}, capitals_t{"Hanoi", "", ""}, capitals_t{"Vatican City", "", ""}, capitals_t{"Port Vila", "", ""}, capitals_t{"Tashkent", "", ""}, capitals_t{"Montevideo", "", ""}, capitals_t{"Washington DC", "", ""}, capitals_t{"London", "", ""}, capitals_t{"Abu Dhabi", "", ""}, capitals_t{"Kyiv", "", ""}, capitals_t{"Kampala", "", ""}, capitals_t{"Funafuti", "", ""}, capitals_t{"Bangkok", "", ""}, capitals_t{"Dushanbe", "", ""}, capitals_t{"Ashgabat", "", ""}, capitals_t{"Ankara", "", ""}, capitals_t{"Tunis", "", ""}, capitals_t{"Port of Spain", "", ""}, capitals_t{"Nuku'alofa", "", ""}, capitals_t{"Lome", "", ""}, capitals_t{"Dodoma", "", ""}, capitals_t{"Taipei", "", ""}, capitals_t{"Dili", "", ""}, capitals_t{"Banjul", "", ""}, capitals_t{"Belgrade", "", ""}, capitals_t{"Riyadh", "", ""}, capitals_t{"Bratislava", "", ""}, capitals_t{"Ljubljana", "", ""}, capitals_t{"Madrid", "", ""}, capitals_t{"Seoul", "", ""}, capitals_t{"Pretoria", "Cape Town", "Bloemfontein"}, capitals_t{"Juba", "", ""}, capitals_t{"Khartoum", "", ""}, capitals_t{"Damascus", "", ""}, capitals_t{"Paramaribo", "", ""}, capitals_t{"Freetown", "", ""}, capitals_t{"Singapore", "", ""}, capitals_t{"Bern", "", ""}, capitals_t{"Stockholm", "", ""}, capitals_t{"Sri Jayawardenepura Kotte", "", ""}, capitals_t{"Basseterre", "", ""}, capitals_t{"Castries", "", ""}, capitals_t{"Kingstown", "", ""}, capitals_t{"Apia", "", ""}, capitals_t{"San Marino", "", ""}, capitals_t{"Sao Tome", "", ""}, capitals_t{"Dakar", "", ""}, capitals_t{"Victoria", "", ""}, capitals_t{"Honiara", "", ""}, capitals_t{"Mogadishu", "", ""}, capitals_t{"Moscow", "", ""}, capitals_t{"Brazzaville", "", ""}, capitals_t{"Bucharest", "", ""}, capitals_t{"Kigali", "", ""}, capitals_t{"Doha", "", ""}, capitals_t{"Islamabad", "", ""}, capitals_t{"Ngerulmud", "", ""}, capitals_t{"Jerusalem", "", ""}, capitals_t{"Panama City", "", ""}, capitals_t{"Port Moresby", "", ""}, capitals_t{"Asuncion", "", ""}, capitals_t{"Lima", "", ""}, capitals_t{"Lisbon", "", ""}, capitals_t{"Warsaw", "", ""}, capitals_t{"Manila", "", ""}, capitals_t{"Muscat", "", ""}, capitals_t{"Windhoek", "", ""}, capitals_t{"Yaren", "", ""}, capitals_t{"Kathmandu", "", ""}, capitals_t{"Amsterdam", "", ""}, capitals_t{"Wellington", "", ""}, capitals_t{"Managua", "", ""}, capitals_t{"Niamey", "", ""}, capitals_t{"Abuja", "", ""}, capitals_t{"Pyongyang", "", ""}, capitals_t{"Skopje", "", ""}, capitals_t{"Oslo", "", ""}, capitals_t{"Antananarivo", "", ""}, capitals_t{"Lilongwe", "", ""}, capitals_t{"Kuala Lumpur", "", ""}, capitals_t{"Male", "", ""}, capitals_t{"Bamako", "", ""}, capitals_t{"Valletta", "", ""}, capitals_t{"Majuro", "", ""}, capitals_t{"Nouakchott", "", ""}, capitals_t{"Port Louis", "", ""}, capitals_t{"Mexico City", "", ""}, capitals_t{"Palikir", "", ""}, capitals_t{"Chisinau", "", ""}, capitals_t{"Monaco", "", ""}, capitals_t{"Ulaanbaatar", "", ""}, capitals_t{"Podgorica", "", ""}, capitals_t{"Rabat", "", ""}, capitals_t{"Maputo", "", ""}, capitals_t{"Naypyidaw", "", ""}, capitals_t{"Vientiane", "", ""}, capitals_t{"Riga", "", ""}, capitals_t{"Beirut", "", ""}, capitals_t{"Maseru", "", ""}, capitals_t{"Monrovia", "", ""}, capitals_t{"Tripoli", "", ""}, capitals_t{"Vaduz", "", ""}, capitals_t{"Vilnius", "", ""}, capitals_t{"Luxembourg City", "", ""}, capitals_t{"Astana", "", ""}, capitals_t{"Nairobi", "", ""}, capitals_t{"South Tarawa", "", ""}, capitals_t{"Pristina", "", ""}, capitals_t{"Kuwait City", "", ""}, capitals_t{"Bishkek", "", ""}, capitals_t{"Kingston", "", ""}, capitals_t{"Tokyo", "", ""}, capitals_t{"Amman", "", ""}, capitals_t{"Reykjavik", "", ""}, capitals_t{"New Delhi", "", ""}, capitals_t{"Jakarta", "", ""}, capitals_t{"Tehran", "", ""}, capitals_t{"Baghdad", "", ""}, capitals_t{"Dublin", "", ""}, capitals_t{"Jerusalem", "", ""}, capitals_t{"Rome", "", ""}, capitals_t{"Yamoussoukro", "", ""}, capitals_t{"Port-au-Prince", "", ""}, capitals_t{"Tegucigalpa", "", ""}, capitals_t{"Budapest", "", ""}, capitals_t{"Libreville", "", ""}, capitals_t{"Tbilisi", "", ""}, capitals_t{"Berlin", "", ""}, capitals_t{"Accra", "", ""}, capitals_t{"Athens", "", ""}, capitals_t{"Saint George's", "", ""}, capitals_t{"Guatemala City", "", ""}, capitals_t{"Conakry", "", ""}, capitals_t{"Bissau", "", ""}, capitals_t{"Georgetown", "", ""}, capitals_t{"Suva", "", ""}, capitals_t{"Helsinki", "", ""}, capitals_t{"Paris", "", ""}, capitals_t{"Quito", "", ""}, capitals_t{"Cairo", "", ""}, capitals_t{"San Salvador", "", ""}, capitals_t{"Malabo", "", ""}, capitals_t{"Asmara", "", ""}, capitals_t{"Mbabane", "Lobamba", ""}, capitals_t{"Addis Ababa", "", ""}, capitals_t{"Tallinn", "", ""}, capitals_t{"Copenhagen", "", ""}, capitals_t{"Djibouti City", "", ""}, capitals_t{"Roseau", "", ""}, capitals_t{"Santo Domingo", "", ""}, capitals_t{"Kinshasa", "", ""}, capitals_t{"Praia", "", ""}, capitals_t{"Phnom Penh", "", ""}, capitals_t{"Yaounde", "", ""}, capitals_t{"Ottawa", "", ""}, capitals_t{"Bangui", "", ""}, capitals_t{"N'Djamena", "", ""}, capitals_t{"Santiago", "", ""}, capitals_t{"Beijing", "", ""}, capitals_t{"Bogota", "", ""}, capitals_t{"Moroni", "", ""}, capitals_t{"San Jose", "", ""}, capitals_t{"Zagreb", "", ""}, capitals_t{"Havana", "", ""}, capitals_t{"Nicosia", "", ""}, capitals_t{"Prague", "", ""}, capitals_t{"Nassau", "", ""}, capitals_t{"Manama", "", ""}, capitals_t{"Dhaka", "", ""}, capitals_t{"Bridgetown", "", ""}, capitals_t{"Minsk", "", ""}, capitals_t{"Brussels", "", ""}, capitals_t{"Belmopan", "", ""}, capitals_t{"Porto-Novo", "", ""}, capitals_t{"Thimphu", "", ""}, capitals_t{"Sucre", "", ""}, capitals_t{"Sarajevo", "", ""}, capitals_t{"Gaborone", "", ""}, capitals_t{"Brasilia", "", ""}, capitals_t{"Bandar Seri Begawan", "", ""}, capitals_t{"Sofia", "", ""}, capitals_t{"Ouagadougou", "", ""}, capitals_t{"Gitega", "", ""}, capitals_t{"Kabul", "", ""}, capitals_t{"Tirana", "", ""}, capitals_t{"Algiers", "", ""}, capitals_t{"Andorra la Vella", "", ""}, capitals_t{"Luanda", "", ""}, capitals_t{"Saint John's", "", ""}, capitals_t{"Buenos Aires", "", ""}, capitals_t{"Yerevan", "", ""}, capitals_t{"Canberra", "", ""}, capitals_t{"Vienna", "", ""}, capitals_t{"Baku", "", ""} };

	uint8_t get_capitals_count(uint8_t index) {
	
		uint8_t capitals_count = 0;

		for (const std::string &capital : k_capitals[index]) {

			if (capital == "")

				continue;

			++capitals_count;
		}

		return capitals_count;
	}

	std::string get_capitals_string(uint8_t index) {
	
		std::string capitals_string = "";

		uint8_t capitals_count = get_capitals_count(index);

		const capitals_t &capitals = k_capitals[index];

		switch (capitals_count) {
		
		case 1: capitals_string = capitals[0]; break;

		case 2: capitals_string = capitals[0] + " and " + capitals[1]; break;

		case 3: capitals_string = capitals[0] + ", " + capitals[1] + " and " + capitals[2]; break;
		}

		return capitals_string;
	}

	void capitals_quiz() {
	
		logger::info("Started Capitals Quiz");

		std::vector<std::uint8_t> indices;

		for (uint8_t i = 0; i != 197; ++i)

			indices.push_back(i);

		bool slash_quit = false;

		std::vector<uint8_t> indidces_got_wrong;

		uint8_t questions_attempted = 0;

		uint8_t questions_correct = 0;

		std::string previous_answer = "";

		for (uint8_t i = 0; i != 197; ++i) {

			std::int32_t index1 = rng::get_int(0, indices.size() - 1);

			std::uint8_t index2 = indices[index1];

			indices.erase(indices.begin() + index1);

			const std::string &country = k_countries[index2];

			const capitals_t &capitals = k_capitals[index2];

			const uint8_t k_capitals_count = get_capitals_count(index2);

			if (k_capitals_count == 0) {

				logger::error("failed to find any capitals for the country: " + country);

				continue;
			}

			uint8_t capitals_guessed_count = 0;

			std::array<std::string, 3> capitals_already_guessed{};

			logger::info(std::string("What ") + (k_capitals_count > 1 ? "are" : "is") + " the capital" + (k_capitals_count > 1 ? "s" : "") + " of " + country);

			++questions_attempted;

			for (uint8_t j = 0; j != k_capitals_count; ++j) {

				std::string input;

				while (true) {

					std::getline(std::cin, input);

					if (input == "/previous answer" || input == "/previous ans" || input == "/prev answer" || input == "/prev ans" || input == "/pa") {

						logger::info(previous_answer);
					}
					else if (input == "/amount left" || input == "/al") {
					
						logger::info(std::to_string(197 - j));
					}
					else break;
				}

				if (input == "/quit" || input == "/q") {

					slash_quit = true;

					--questions_attempted;

					break;
				}

				const std::string capitals_string = get_capitals_string(index2);

				previous_answer = capitals_string;

				if (input == "/answer" || input == "/ans" || input == "/a") {

					const uint8_t k_capitals_count = get_capitals_count(index2);

					logger::info(capitals_string);

					break;
				}

				bool was_correct = false;

				if (input != "" && input != capitals_already_guessed[0] && input != capitals_already_guessed[1])

					for (const std::string &capital : capitals) {

						if (capital == input) {

							capitals_already_guessed[j] = capital;

							++questions_correct;

							was_correct = true;

							logger::info(std::string("Correct") + std::string(", ") + std::to_string(++capitals_guessed_count) + "/" + std::to_string(k_capitals_count) + " guessed");

							break;
						}
					}

				if (was_correct)

					continue;

				else {

					logger::info("Incorrect" + std::string(", ") + std::to_string(capitals_guessed_count) + "/" + std::to_string(k_capitals_count) + " guessed");

					indidces_got_wrong.push_back(index2);

					break;
				}
			}

			if (slash_quit)

				break;
		}

		logger::info(std::string("You got ") + std::to_string(questions_correct) + "/" + std::to_string(questions_attempted) + " correct");

		for (uint8_t index : indidces_got_wrong) {

			const uint8_t k_capitals_count = get_capitals_count(index);

			logger::info(std::string("The capital") + (k_capitals_count > 1 ? "s" : "") + " of " + k_countries[index] + (k_capitals_count > 1 ? " were" : " was") + " " + get_capitals_string(index));
		}

		logger::info("Ended Capitals Quiz");
	}
}

int main() {

	capitals_quiz();

	while (true) {

		std::string input;
		
		std::getline(std::cin, input);

		if (input == "/start" || input == "/s") {

			capitals_quiz();
		}
		else break;
	}

	return 0;
}
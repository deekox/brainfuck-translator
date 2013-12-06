#include "Generator.h"
#include <algorithm>
#include <iostream>

Generator::Generator(const std::string & txt) :
	content{txt}
{
	analyze(content);
	for_each(rvec.begin(), rvec.end(), [] (Range & x) {
			x.descrb();});
}

Generator::~Generator()
{
	std::cout << "~Genereator\n";
}

void Generator::analyze(const std::string &str) {
	std::map<int, int> cnt;
	std::map<int, int>::iterator p;
	for_each(str.begin(), str.end(), [&] (unsigned char c) {
			if ( (p = cnt.find(c)) == cnt.end())
				cnt.insert(std::make_pair(c, 1));
			else
				++(p->second);
		});
	std::cout << "char set size: " << cnt.size() << std::endl;
	for_each(cnt.begin(), cnt.end(), [] (std::pair<int, int> p) {
			std::cout << "'" << (char)p.first << "'("
			          << (int)p.first << ") " << p.second
			          << std::endl;
		});

	int delta = 3;
	int bst = 999;
	int at = 0;
	for (int cor = -delta; cor <= delta; ++cor) {
		int v = mkrng(cnt, rvec, cor, false);
		if (v < bst) {
			bst = v;
			at = cor;
		}
	}
    mkrng(cnt, rvec, at, true);
}

int Generator::mkrng(std::map<int, int> &cnt,
           std::vector<Range> & rv,
           int correction,
           bool real)
{
	int rngsiz = round(sqrt(cnt.size())) + correction;
	if (rngsiz < 1) return 1000;
	if (real)
		rvec.reserve(rngsiz);
	int twght;
	int insertions = 0;
	auto p = cnt.begin();
	while (1) {
		int rng = (char)p->first + rngsiz;
		auto lb = cnt.lower_bound(rng);
		if (real) {
			
			twght = 0;
			for (auto xx = p; xx != lb; ++xx)
				twght += xx->second;
					
			--lb;
			rvec.push_back(Range((int)p->first,
			                     (int)lb->first, twght));
//			cout << "[" << p->first << ", " << lb->first << "]\n";
			++lb;
		}
		++insertions;
		p = lb;
		if (p == cnt.end())
			break;

	}
	return abs(insertions - rngsiz);
}


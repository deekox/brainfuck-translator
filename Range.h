// -*-c++-*-
#ifndef RANGE_H
#define RANGE_H

class Range {
	int start;
	int end; //including
	int weight;

	int position; // pozycja w rvec

	int memidx; // index komorki pamieci
	
public:
	Range(int st, int ed, int wght);

	inline void setPos(int pos) {
		position = pos;
	}
	inline int getPos() const {
		return position;
	}
	
	inline void setMemIdx(int mi) {
		memidx = mi;
	}
	inline int getMI() const {
		return memidx;
	}
	
	inline bool inRange(int val) const {
		return (val >= start) && (val <= end);
	}
	void descrb() const;
};

#endif //RANGE_H

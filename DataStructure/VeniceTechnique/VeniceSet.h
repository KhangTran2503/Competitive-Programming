#ifndef _VENICESET_H
#define _VENICESET_H
#include <set>

template<class Type>
class VeniceSet{
	private:
		std::multiset<Type> S;
		Type water_level = static_cast<Type>(0);
	public:
		VeniceSet(){};
		~VeniceSet(){};
		void add(Type val){
			S.insert(val + water_level);
		}
		
		void remove(Type val){
			S.erase(S.find(val + water_level));
		}
		
		void updateAll(Type val){
			water_level += val;
		}
		
		Type getmin(){
			return (*S.begin()) - water_level;
		}
		
		int size(){
			return (int)S.size();
		}
};

#endif

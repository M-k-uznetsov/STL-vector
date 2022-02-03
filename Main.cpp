#include "Container.h"
#include "Algorithms.h"
#include "Iterator.h"
#include "Exception.h"


struct Goods {
	uint32_t m_id; 
	std::string m_name; 
	std::string m_manufacturer; 
	std::string m_warehouse_address; 
	double m_weight; 
	
	
	

	Goods(uint32_t _id = 0, const std::string& _name = " ", const std::string & _manufacturer = " ", const std::string & _warehouse_address = " ", double _weight = 0) :
		m_id(_id), m_name(_name), m_manufacturer(_manufacturer), m_warehouse_address(_warehouse_address), m_weight(_weight)
	{}
};

class f {
public:
	auto operator() (const Goods& g) {
		return g.m_manufacturer == "Rinner";
	};
};

int main() {
	try {
	    
		auto print = [](const auto& g) {
			std::cout << g.m_id << "\n";
			std::cout << g.m_name << "\n";
			std::cout << g.m_manufacturer << "\n";
			std::cout << g.m_warehouse_address << "\n";
			std::cout << g.m_weight << std::endl;
		};
		std::cout << "----------1(creation of structure)----------" << std::endl;

		std::cout << "----------2----------" << std::endl;
		Vector<Goods> cont_1{ {1,"milk","Almarai","12034602",130}, {2,"chocolate","chocolate","1248052578",200} };
		forEach(cont_1.begin(), cont_1.end(), print);

		std::cout << "----------3----------" << std::endl;
		Goods g1{ 3,"pasta", "La Molisana", "12323546542", 100 };
		Goods g2{ 4,"crisps","Pringles","1245424423", 50 };
		Goods g3{ 5,"table","Rinner","235436457232", 20 };
		Vector<Goods> cont_2;
		cont_2.pushBack(g1);
		cont_2.pushBack(g2);
		cont_2.insert(cont_2.end(), g3);
		

		forEach(cont_2.begin(), cont_2.end(), print);

		std::cout << "----------4----------" << std::endl;
		cont_1.insert(cont_1.end(), cont_2.begin(), cont_2.end());
		forEach(cont_1.begin(), cont_1.end(), print);

		std::cout << "----------5----------" << std::endl;
		sort(cont_1.begin(), cont_1.end(), [](const auto& g) {
			return g.m_name;
			});
		forEach(cont_1.begin(), cont_1.end(), print);

		std::cout << "----------6----------" << std::endl;
		Vector<Goods>::Iterator res = findIf(cont_1.begin(), cont_1.end(), [](const auto& g) {
		    

			return g.m_weight == 100;
			});
		print(*res);

		std::cout << "----------7----------" << std::endl;
		(*res).m_warehouse_address = "101010101010101010";
		forEach(cont_1.begin(), cont_1.end(), print);

		std::cout << "----------8----------" << std::endl;
		Vector<Goods> cont_3(1,Goods());
		copyIf(cont_1.begin(), cont_1.end(), cont_3.begin(), f());
		forEach(cont_3.begin(), cont_3.end(), print);
	}
	catch (const std::exception& exept) { 
		std::cout << exept.what();
	}

	return 0;
}

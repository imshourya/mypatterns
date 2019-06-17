
#include<iostream> 
using namespace std; 

//house Plan interface 
class HousePlan
{
public:
	
	virtual void setBHK(string bhk)=0;
	virtual void setWindow(string window)=0;
	virtual void setDoor(string door)=0;
	virtual void setBathroom(string bathroom)=0;
	virtual void setKitchen(string kitchen)=0;
	virtual void setFloor(string floor)=0;
	virtual void setLightning(string light)=0;
	virtual void setWiring(string wiring)=0;
};

//Concrete house using House Plan 
class House :public HousePlan
{
    public :
	string BHK ,Window , Door , Bathroom ,  Kitchen , Floor , Lightning , Wiring;
	
	void setBHK(string bhk) { this->BHK = bhk ;}
	void setWindow(string window) { this->Window = window ;}
	void setDoor(string door) { this->Door = door ;}
	void setBathroom(string bathroom) { this->Bathroom = bathroom ;}
	void setKitchen(string kitchen) { this->Kitchen = kitchen ;}
	void setFloor(string floor) { this->Floor = floor ;}
	void setLightning(string light) { this->Lightning = light ;}
	void setWiring(string wiring) { this->Wiring = wiring ;}

};


//House builder Abstract class
class HouseBuilder
{
	public :
	virtual void buildBHK()=0;
	virtual void buildWindow()=0;
	virtual void buildDoor()=0;
	virtual void buildBathroom()=0;
	virtual void buidKitchen()=0;
	virtual void buildFloor()=0;
	virtual void buildLightning()=0;
	virtual void buildWiring()=0;
	virtual  House * getHouse()=0;

};
// concrete house builders
class NormalHouseBuilder : public HouseBuilder
{
	private: House* house ;
	public :
	NormalHouseBuilder (){ house = new House;}
	void buildBHK(){  house->setBHK("1 bhk");}
	void buildWindow(){ house->setWindow("Normal Window ");}
	void buildDoor(){ house->setDoor("Normal Door ");}
	void buildBathroom(){ house->setBathroom("Normal Bathroom ");}
	void buidKitchen(){ house->setKitchen("Normal Kitchen ");}
	void buildFloor(){ house->setFloor("Normal Floor ");}
	void buildLightning(){ house->setLightning("Normal Lightning ");}
	void buildWiring(){ house->setWiring("Normal Wiring ");}
	House* getHouse()
	{
		std::cout << house->BHK << std::endl;
		std::cout << house->Window << std::endl;
		std::cout << house->Door  <<std::endl;
		std::cout << house->Bathroom <<std::endl;
		std::cout << house->Kitchen<<std::endl;
		std::cout << house->Floor<<std::endl;
		std::cout << house->Lightning<<std::endl;
		std::cout << house->Wiring<<std::endl;
		return house;
	}
	
};


class LavishHouseBuilder : public HouseBuilder
{
	private: House* house ;
	public :
	LavishHouseBuilder (){ house = new House;}
	void buildBHK(){  house->setBHK("2 bhk");}
	void buildWindow(){ house->setWindow("Lavish Window ");}
	void buildDoor(){ house->setDoor("Lavish Door ");}
	void buildBathroom(){ house->setBathroom("Lavish Bathroom ");}
	void buidKitchen(){ house->setKitchen("Lavish Kitchen ");}
	void buildFloor(){ house->setFloor("Lavish Floor ");}
	void buildLightning(){ house->setLightning("Lavish Lightning ");}
	void buildWiring(){ house->setWiring("Lavish Wiring ");}
	House* getHouse()
	{
		std::cout << house->BHK << std::endl;
		std::cout << house->Window << std::endl;
		std::cout << house->Door  <<std::endl;
		std::cout << house->Bathroom <<std::endl;
		std::cout << house->Kitchen<<std::endl;
		std::cout << house->Floor<<std::endl;
		std::cout << house->Lightning<<std::endl;
		std::cout << house->Wiring<<std::endl;
		return house;
	}
	
};
//Director class
class Contractor 
{
	private: HouseBuilder *housebuilder;
	public :
	Contractor() {}
	void setHouseBuilder(HouseBuilder* hb){ housebuilder =  hb;}
	void buildHouse()
	{
		housebuilder->buildBHK();
		housebuilder->buildWindow();
		housebuilder->buildDoor();
		housebuilder->buildBathroom();
		housebuilder->buidKitchen();
		housebuilder->buildFloor();
		housebuilder->buildLightning();
		housebuilder->buildWiring();
		
	}
};

int main ()
{
	Contractor *c = new Contractor();
	HouseBuilder *x = new NormalHouseBuilder();
	c->setHouseBuilder(x);
	c->buildHouse();
	x->getHouse();
	x = new LavishHouseBuilder();
	c->setHouseBuilder(x);
	c->buildHouse();
	x->getHouse();
	delete c;
	delete x;
	return 0;
}

